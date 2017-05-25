//https://www.reddit.com/r/dailyprogrammer/comments/5seexn/20170206_challenge_302_easy_spelling_with/?utm_content=title&utm_medium=hot&utm_source=reddit&utm_name=dailyprogrammer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct chemistry_Periodic_Elements{
	char Element[20];
	char Symbol[5];
	int Z;
	float Atomic_Weight;
	float c;
};
struct chemistry_Periodic_Elements array[103];
struct chemistry_Periodic_Elements temp[103];
int size_Of_Array;
void mixing();
void print();
void createArray();
void testEntry();
void sort_Periodic_Table();
double getElement(char element[], int subscript);
int iteration =0;
int main(void){
	if(iteration==0)
	{
		createArray();
		iteration++;
	}

	printf("Choose one of the following: \n");
	printf("\t1.Combine two elements.\n");
	printf("\t2.Print Periodic Table.\n");
	printf("\t3.Sort Periodic listing.\n");
	printf("\t4.Enter some element.\n");
	int choice;
	printf("\nEnter: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: mixing(); main(); break;
		case 2: print(); main(); break;
		case 3: sort_Periodic_Table(); main();break;
		case 4: testEntry(); main(); break;
		default: printf("Error Invalid Entry\n"); exit(0);
	}


	return 0;
}
void testEntry(){

	printf("Enter an element please, no spaces.\n");
	char element[5];
	scanf("%s", element);
	//element = "HeAg";
	// Getting the size of the element.
	int i=0, size;
	while(element[i++] != '\0');
	size = --i;
	//printf("size of Array is: %d\n", size);

	int cur_pos=0;
	int upperCases=0;
	int k=0;
	int l=0;
	double total_Atomic_Weight;
	for(int j = 0;j<size; j++)
	{
			if(element[j] <= 90 && element[j]>=65)
			{
				char temp[20];
				char *temp_two;
				temp[0] = element[j];
				int n= cur_pos+1;
				int ar_size=1;
				int subscript;
				l = j+1;
				for(int k=j+1; element[k]>=90; k++)
				{
					temp[n++]=element[k];
					ar_size++;
					l++;
				}
				//printf("\nar_size = %d, k=%d, element char: %c\n",ar_size, k, element[l]);

				if(element[l]>=48 && element[l]<=57)
				{
					if(element[l+1]>=48 && element[l+1]<=57)
					{
						int first = (element[l]-48)*10;
						subscript = first +element[l+1]-48;
					}
					else{
						subscript = element[l]-48;
					}
					
				}
				
				else{
					subscript=1;
					//printf("No subscript found.");
				}
				temp_two = (char*)malloc(ar_size);
				for(int t=0; t<ar_size; t++)
					temp_two[t]=temp[t];
				cur_pos = k;
				//printf("\nSending out [%s] to be found!\n", temp_two);
				total_Atomic_Weight += getElement(temp_two, subscript);
			}
	}
	printf("Atomic Weight of Substance is: %.5f\n", total_Atomic_Weight);
}
double getElement(char element[],int subscript)
{
	//printf("\nsubscript= %d, get Element Function %s \n",subscript, element);
	//Here we get the element from the array, compare it with the 
	double result;
	for (int i = 0; i < size_Of_Array; ++i)
	{

		int ret1 = strcmp(array[i].Symbol, element);
		if(ret1==0)
		{
			printf("The Element is: %s\n",array[i].Element);
			printf("Total Atomic weight is: %.4f\n", (array[i].Atomic_Weight * subscript));

			result= (array[i].Atomic_Weight * subscript);
		}
	}
	return result;

}
void createArray()
{

	FILE *fptr;
	if((fptr=fopen("elements.txt", "r"))==NULL)
	{
		puts("File cannot be opened!");
	}
	else{
		int i=0;
		while(!feof(fptr))
		{
			fscanf(fptr, "%s%s%d%f%f", array[i].Element, array[i].Symbol, &array[i].Z, &array[i].Atomic_Weight, &array[i].c);
			i++;
		}printf("Working:::\n");
		size_Of_Array=i;
	}
	fclose(fptr);
}
void sort_Periodic_Table()
{
	printf("CHoose a sorting method\tTo be Continued.\n");
}
void mixing(){
		printf("\nEnter two Element Symbols to Combine and get the atomic weight of the result.\n");
	char first_Element[5], second_Element[5];
	printf("First Element: ");
	scanf("%s", first_Element);
	printf("\nSecond Element: ");
	scanf("%s", second_Element);

	double total_Weight = 0;
	for (int i = 0; i < size_Of_Array; ++i)
	{

		int ret1 = strcmp(array[i].Symbol, first_Element);
		if(ret1==0)
		{
			total_Weight +=array[i].Atomic_Weight;
		}

		int ret2 = strcmp(array[i].Symbol, second_Element);
		if(ret2==0)
		{
			total_Weight +=array[i].Atomic_Weight;
		}
		
	}
	printf("Combining of: %s and %s\n",first_Element, second_Element);
	printf("Total weight is: %lf\n", total_Weight);
}
void print(){
	printf("%-15s%-15s\t%-5s\t%s,\t%s\n", "Element","Symbol","Z","Atomic Weight","c");
	for(int i=01; i<size_Of_Array; i++)
	{
		printf("%-15s%-15s\t%d\t%-10.4f\t%.2f\n",array[i].Element, array[i].Symbol, array[i].Z, array[i].Atomic_Weight, array[i].c);
	}
}
