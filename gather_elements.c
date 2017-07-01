//https://www.reddit.com/r/dailyprogrammer/comments/5seexn/20170206_challenge_302_easy_spelling_with/?utm_content=title&utm_medium=hot&utm_source=reddit&utm_name=dailyprogrammer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "program_core.h"

/*
	Author: Mohamed Jama.
	Date: 18/04/17.

	Functionality: The main file of the project. Here the user will choose what to do in 
	the Application.

	Features:
		(1): Combine two Elements/Compounds.
		(2): Print & Sort Periodic Table.
		(3): Get Info on a particular Element.
*/

int iteration =0;
void write_element_sheet();

int print_greeting(){
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
	printf("\t5.Exit\n");
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
		
		switch(choice)
		{
			case 1: mixing(); break;
			case 2: /*print();*/printf("Sorry on break!\n"); break;
			case 3: sort_Periodic_Table(); break;
			case 4:{
				printf("Enter an element please, no spaces.\n");
				char element[100];
				scanf("%s", element);
				get = get_Element_Value(element); 
				break;
			} 
			case 5: printf("Goodbye!"); setTrue =1; break;
			default: printf("Error Invalid Entry\n"); exit(0);
		}
	}
	return 0;
}

void write_element_sheet()
{	
	char space[] = "\n"; 
	FILE *fptr;
	if((fptr=fopen("quick_save.txt", "w"))==NULL)
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
			i++;
		}
		size_Of_Array=i;
	}
	fclose(fptr);
}
// This Function is Unnecessary and needs to be taken out.
void sort_Periodic_Table()
{
	printf("Choose a sorting method\tTo be Continued.\n");
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