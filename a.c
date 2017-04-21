//https://www.reddit.com/r/dailyprogrammer/comments/5seexn/20170206_challenge_302_easy_spelling_with/?utm_content=title&utm_medium=hot&utm_source=reddit&utm_name=dailyprogrammer
#include <stdio.h>
#include <string.h>
struct chemistry_Periodic_Elements{
	char Element[20];
	char Symbol[5];
	int Z;
	double Atomic_Weight;
	double c;
};
struct chemistry_Periodic_Elements array[103];
struct chemistry_Periodic_Elements temp[103];
int main(void){

	printf("Enter the Symbol of an Element in the periodic table!\n");
	char element_symbol[20];
	scanf("%s", element_symbol);
	int size_Of_Entry = sizeof(element_symbol);
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
			fscanf(fptr, "%s%s%d%lf%lf", &array[i].Element, &array[i].Symbol, &array[i].Z, &array[i].Atomic_Weight, &array[i].c);
			i++;
		}
		size_Of_Array=i;
	}
	fclose(fptr);
	int i=0;
	int result;
	for(int i=0; i<size_Of_Array; i++)
	{
		int result=strcmp(element_symbol,array[i].Symbol);
		if(result==0){
			printf("Element is: %s \n", array[i].Element);
			printf("Atomic Weight :%lf\n",array[i].Atomic_Weight);
		}
	}
	/*printf("---\n\n\n\n\n\n");
	printf("%-15s%-15s\t%-5s\t%s,\t%s\n", "Element","Symbol","Z","Atomic Weight","c");

	for(int i=01; i<size_Of_Array; i++)
	{
		printf("%-15s%-15s\t%d\t%-10.2f\t%.2f\n",array[i].Element, array[i].Symbol, array[i].Z, array[i].Atomic_Weight, array[i].c);
	}*/
	/*	for(int i=0; i<4; i++){
			for(int i=0; i<size_Of_Array; i++)
			{
				if(array[i].Z >array[i+1].Z)
				{
					temp[i] = array[i];
					array[i] = array[i+1];
					array[i+1] = temp[i];
				}
			}
		}
		printf("************\n");
	FILE *free;
	if((free=fopen("elements.txt", "w+"))==NULL){
		puts("File doesnt exist");
	}else{
		int i=0;
		while(!feof(free) && i<size_Of_Array+1){
			fprintf(free, "%s%s%d%lf%lf", array[i].Element, array[i].Symbol, &array[i].Z, &array[i].Atomic_Weight, &array[i].c);
		i++;
		}
		fclose(free);
		
	}
		printf("Complete\n");
	
	*/
	

	//element_symbol == Phone

	//int get_Array_Symbol_Length=0;//sizeof(array[3].Symbol);
	//printf("\n%d size of first: %s--", get_Array_Symbol_Length, array[3].Symbol);
	

	//printf("%c|", array[3].Symbol[get_Array_Symbol_Length]);
	
	/*char Answer[size_Of_Entry];
		int character =0;
		int answer_length=0;
		for(int i=0; i<size_Of_Array; i++){

			//int get_Array_Symbol_Length = sizeof(array[i].Symbol);
			int k=0;
			while(k<5)
			{
				if(array[i].Symbol[k]!=32){
					//printf("%c|", array[i].Symbol[k]);
					get_Array_Symbol_Length++;
				}
				k++;
			}
			printf("**\n");
			if(array[i].Symbol[character] == element_symbol[character] || (array[i].Symbol[character]-32)==element_symbol[character] || (array[i].Symbol[character]+32)==element_symbol[character])
			{
				int j=0;
				while(j!=get_Array_Symbol_Length){

					Answer[answer_length] = array[i].Symbol[j];
					j++;
				}
				printf("Answer: %s\n",Answer);
			}
		}*/
		
	//int result;
	//element_Symbol[size_Of_Entry]	
/*int result;
	int element_Symbol_Index=0;
	char Answer_Mine[size_Of_Entry];
	int answer_index=0;
	int symbol_length;
	for(int i=0; i<size_Of_Array; i++)
	{
		int k=0;
		//printf("*\n");
		if(element_symbol[element_Symbol_Index]==array[i].Symbol[0] || (element_symbol[element_Symbol_Index]-32)== array[i].Symbol[0] || (element_symbol[element_Symbol_Index]+32)== array[i].Symbol[0]&& answer_index<=size_Of_Entry)
		{
			while(k<=5)
			{
				if(array[i].Symbol[k]!=32){
					//printf("%c|", array[i].Symbol[k]);
					printf("+\n");
					symbol_length++;
					}
				k++;
			}*/
			//symbol_length
			/*int j=0;
			while(j<=symbol_length)
			{
				Answer_Mine[j] = array[i].Symbol[j];
				element_Symbol_Index++;
				j++;
			}
			answer_index+=j;
			*/
			/*k=0;
			int turns=0;
			while(k<symbol_length)
			{
				if(element_symbol[k]==array[i].Symbol[k]){
						turns++;
				}
				k++;
			}

			if(turns==symbol_length)
			{		
				k=0;
				while(k<symbol_length)
				{
					printf("**%c\n", array[i].Symbol[k++]);
				}
			}
	
			//printf("%s\n", array[i].Symbol);
		}
	}

		printf("Answer: %s", Answer_Mine);



	printf("%-15s%-15s\t%-5s\t%s,\t%s\n", "Element","Symbol","Z","Atomic Weight","c");
	for(int i=01; i<size; i++)
	{
		printf("%-15s%-15s\t%d\t%-10.4f\t%.2f\n",array[i].Element, array[i].Symbol, array[i].Z, array[i].Atomic_Weight, array[i].c);
	}*/
	return 0;
}