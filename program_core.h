
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
	char *Elect_Confg;
	int Groups;
};
struct chemistry_Periodic_Elements array[119];
struct chemistry_Periodic_Elements temp[119];
int size_Of_Array;



//Functions.
void set_Groups();
void mixing();
void print();
void createArray();
void testEntry();
void grouping();
void sort_Periodic_Table();
double getElement(char Symbol[], int subscript);
