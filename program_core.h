/*
 * controlFile.c
 *
 *  Created on: Apr 10, 2017
 *      Author: Mohamed Jama.
 */

#ifndef PROGRAM_CORE_H_
#define PROGRAM_CORE_H_



#endif /* CONTROLFILE_C_ */

//Structures, variables and arrays that are global to the program.
struct chemistry_Periodic_Elements{
	char Element[20];
	char Symbol[5];
	int Z;				//Number of protons.
	float Atomic_Weight;
	float c;
	char Elect_Confg[25];
	int Groups;
	int layer;
	float mp;
};
// Important arrays and variables.
struct chemistry_Periodic_Elements array[119];
struct chemistry_Periodic_Elements temp[119];
int size_Of_Array;



//Functions.
void mixing();
void print();
void createArray();
double get_Element_Value();
void sort_Periodic_Table();
double getElement(char Symbol[], int subscript);
double compund_element();
int get_value_of_subscript(char *element, int l);
