#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "program_core.h"

void testEntry(){

	printf("Enter an element please, no spaces.\n");
	char element[5];
	scanf("%s", element);
	// Getting the size of the element.
	int i=0, size;
	// Get the number of elements.
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
			//If the char is uppercase then do the following operations to it and the consecutive chars.
			if(element[j] <= 90 && element[j]>=65)
			{

				char temp[20];
				char *temp_two;
				temp[0] = element[j];
				int n= cur_pos+1;
				int ar_size=1;
				int subscript=0;
				l = j+1;
				// Getting the symbol.
				for(int k=j+1; element[k]>=90; k++)
				{
					temp[n++]=element[k];
					ar_size++;
					l++;
				}

				if(element[l]>=48 && element[l]<=57)
				{
					int n = l;
					char sum[100];
					int sum_index=0;
					for(n = l; element[n]>=48 && element[n]<=57; n++)
					{
						//Getting the size of the subscript i.e. 123 is 3 characters long, and storign it in sum.
						sum[sum_index++] = element[n];
					}
					for(int adding_sum=0; adding_sum!=sum_index; adding_sum++)
					{
						subscript += (sum[adding_sum]-48)* pow(10.0, (sum_index-adding_sum)-1);
					}
				}
				// If there is no subscript we'll leave the number of elements present as just 1.
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

double getElement(char Symbol[],int subscript)
{
	//Here we get the element from the array, compare it with the 
	double result;
	for (int i = 0; i < size_Of_Array; ++i)
	{
		//Compare the symbol given and the one in database. //We replaced element with Symbol in the above.
		int ret1 = strcmp(array[i].Symbol, Symbol);
		if(ret1==0)
		{
			printf("The Element is: %s\n",array[i].Element);
			printf("Its Total Atomic weight is: %.4f\n", (array[i].Atomic_Weight * subscript));
			result= (array[i].Atomic_Weight * subscript);
		}
	}
	return result;
}
void mixing(){
	// User gives us two elements.
	printf("\nEnter two Element Symbols to Combine and get the atomic weight of the result.\n");
	char first_Element[5], second_Element[5];
	printf("First Element: ");
	scanf("%s", first_Element);
	printf("\nSecond Element: ");
	scanf("%s", second_Element);

	// Here the program finds the symbols then adds their atomic weight to total_weight.
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
	// Element name and total combined atomic weight is printed here.
	printf("Combining of: %s and %s\n",first_Element, second_Element);
	printf("Total weight is: %lf\n", total_Weight);
}
void set_Groups()
{
	int k_a=4;
	int k_b=4;
	for(int i=0; i<size_Of_Array; i++)
	{
		if(array[i].Z>=19)
		{
			if(array[i].Z<57)
			{
				if(array[i].Z % 18==0)
				{
					array[i].Groups = 18;
				}
				else{
					array[i].Groups = array[i].Z % 18;
				}
				
			}
			else if(array[i].Z >=57 && array[i].Z <=71){
				array[i].Groups = k_a;
				printf("*Element is: %s\n", array[i].Symbol);
				k_a++;
			}
			else if(array[i].Z >=72 && array[i].Z <=88)
			{
				array[i].Groups = (array[i].Z % 18)+4;
				if(array[i].Z >=87)
				{
					array[i].Groups = (array[i].Z % 18)-14;
				}
			}
			else if(array[i].Z >=89 && array[i].Z <=103)
			{
				array[i].Groups = k_b;
				k_b++;
			}
			else if(array[i].Z >=104 && array[i].Z <=118)
			{
				array[i].Groups = array[i].Z - 100;
			}
		}
		else{
			if(array[i].Z == 1)
			{
				array[i].Groups = 1;
				array[i+1].Groups = 18;
			}
			else if(array[i].Z == 3)
			{
				array[i].Groups = 1;
				array[i+1].Groups = 2;
			}
			else if(array[i].Z >=5 && array[i].Z<=10)
			{
				array[i].Groups = array[i].Z + 8;
			}
			else if(array[i].Z ==11)
			{
				array[i].Groups = 1;
				array[i+1].Groups = 2;
			}
			else if(array[i].Z >=13 && array[i].Z<=18)
			{
				array[i].Groups = array[i].Z;
			}
		}

	}

			
}
