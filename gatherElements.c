//https://www.reddit.com/r/dailyprogrammer/comments/5seexn/20170206_challenge_302_easy_spelling_with/?utm_content=title&utm_medium=hot&utm_source=reddit&utm_name=dailyprogrammer
#include <stdio.h>
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
int main(void){

	printf("Enter the Symbol of an Element in the periodic table!\n");
	char element_symbol[20];
	scanf("%s", element_symbol);

	int size_Of_Array;

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



	printf("%-15s%-15s\t%-5s\t%s,\t%s\n", "Element","Symbol","Z","Atomic Weight","c");
	for(int i=01; i<size_Of_Array; i++)
	{
		printf("%-15s%-15s\t%d\t%-10.4f\t%.2f\n",array[i].Element, array[i].Symbol, array[i].Z, array[i].Atomic_Weight, array[i].c);
	}
	return 0;
}
