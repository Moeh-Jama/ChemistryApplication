//https://www.reddit.com/r/dailyprogrammer/comments/5seexn/20170206_challenge_302_easy_spelling_with/?utm_content=title&utm_medium=hot&utm_source=reddit&utm_name=dailyprogrammer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "program_core.h"

/*
	Author: Mohamed Jama.
	Date: --/--/17.
*/


int iteration =0;
void write_element_sheet();

int print_greeting()
{
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
	printf("\t5.Group.\n");
	printf("\t6.Exit\n");
	int choice;
	printf("\nEnter: ");
	scanf("%d", &choice);

	return choice;
}
int main(void){
	// the program will run for as long as setTrue is equal to 0!
	int setTrue = 0;
	double get;
	while (setTrue == 0)
	{
		int choice = print_greeting();
		printf("\nLAST IS: %s\n", array[103].Element);
		switch(choice)
		{
			case 1: mixing(); break;
			case 2: print(); break;
			case 3: sort_Periodic_Table(); break;
			case 4: get = get_Element_Value(); break;
			case 5: printf("Grouping: Not Completed!\n"); break;
			case 6: printf("Goodbye!"); setTrue =1; break;
			default: printf("Error Invalid Entry\n"); exit(0);
		}
	}
	return 0;
}

void write_element_sheet()
{	
	char space[] = "\n"; 
	FILE *fptr;
	if((fptr=fopen("properties_of_elements.txt", "w"))==NULL)
	{
		puts("File cannot be opened!");
	}
	else{
		for(int i=0; i<size_Of_Array; i++)
		{
			fprintf(fptr, "%-15d\t%-15d\t%-15s%-15s\t%d\t%-10.4f\t%-15s\t%.4f\t%.2f\r", array[i].Groups, array[i].layer, array[i].Element, array[i].Symbol, array[i].Z, array[i].Atomic_Weight, array[i].Elect_Confg, array[i].mp, array[i].c);
			fputs(space, fptr);
		}
	}
	fclose(fptr);
}
void createArray()
{
	FILE *fptr;
	if((fptr=fopen("properties_of_elements.txt", "r"))==NULL)
	{
		puts("File cannot be opened!");
	}
	else{
		int i=0;
		while(!feof(fptr))
		{
			fscanf(fptr, "%d%d%s%s%d%f%s%f%f", &array[i].Groups, &array[i].layer, array[i].Element, array[i].Symbol, &array[i].Z, &array[i].Atomic_Weight, array[i].Elect_Confg, &array[i].mp, &array[i].c);
			printf("[%f]\n", array[i].mp);
			i++;
		}
		size_Of_Array=i;
	}
	fclose(fptr);
}
void sort_Periodic_Table()
{
	printf("CHoose a sorting method\tTo be Continued.\n");
	struct chemistry_Periodic_Elements temp_two[103];
	for(int i=0; i<size_Of_Array; i++)
	{
		for(int j=i+1; j<size_Of_Array; j++)
		{
			if(array[i].Z>array[j].Z)
			{
				temp_two[0] =array[i];
				array[i]= array[j];
				array[j]= temp_two[0];
			}
		}
	}
}
void print(){
	//printf("%-15s%-15s%-15s\t%-5s\t%s,\t%s\n", "Group", "Element","Symbol","Z","Atomic Weight","c");
	for(int i=0; i<size_Of_Array; i++)
	{
		printf("[%d] %-8d\t%-8d\t%-8s%-8s\t%d\t%-8.4f\t%-8s\t%.4f\t%.2f\r",(i+1), array[i].Groups, array[i].layer, array[i].Element, array[i].Symbol, array[i].Z, array[i].Atomic_Weight, array[i].Elect_Confg, array[i].mp, array[i].c);
	}
}
