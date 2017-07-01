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
	float c;			//Electronic Negativity.
	char Elect_Confg[25];
	int Groups;
	int layer;			//Not very Necessary.
	float mp;			//Melting Point. in Degrees Celsius.
};
// Important arrays and variables.
struct chemistry_Periodic_Elements array[119];
struct chemistry_Periodic_Elements temp[119];
int size_Of_Array;



											//Functions.
// gather_elements.c
void print();
void createArray();
void sort_Periodic_Table();

//	element_search.c
double get_Element_Value(char *element);
void mixing();
double getElement(char Symbol[], int subscript);
double compund_element();
int get_value_of_subscript(char *element, int l);
double get_Total_Atomic_Weight(char *element, int size, int subscript);