#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "program_core.h"

/*
	Author: Mohamed Jama.
	Date: 00/04/2017.

	Functionality: The purpose of this file is to parse and collect data of an entered
	Element or Compound. This File is purely gathering User Data and searching it in an TextFile.

	Features:
		(1): Calculate two elements/compounds entered by the user and return its Atomic Weight.
		(2): Calculate Subscripts accurately.
*/


double get_Element_Value(char *element){
	// numerical Variables.
	int i=0, size;
	int local_pos=0;
	double total_Atomic_Weight=0.0;
	int super_subscript =1;

	// Get the number of elements.
	while(element[i++] != '\0');
	size = --i;
	for(int uppercase_index =0; uppercase_index<size; uppercase_index++)
	{
		//If the char is uppercase then do the following operations to it and the consecutive chars.
		if(element[uppercase_index] <= 90 && element[uppercase_index]>=65)
		{
			char temp[100];
			// Storing the upper Case letter of the String.
			temp[0] = element[uppercase_index];
			//int temp_index= 1;
			int temp_size=1;
			int subscript=0;
			local_pos = uppercase_index+1;
			// Getting the symbol.
			for(int symbol_index=uppercase_index+1; element[symbol_index]>=90; symbol_index++)
			{
				temp[temp_size++]=element[symbol_index];
				//temp_size++;
				local_pos++;
			}
			// The character is tested whether or not it is a Number.
			if(element[local_pos]>=48 && element[local_pos]<=57)
			{
				// The function will return the correct value.
				subscript=get_value_of_subscript(element, local_pos);
			}
			else{	
				// If there is no subscript we'll leave the number of elements present as just 1.
				subscript=1;
			}
			total_Atomic_Weight += get_Total_Atomic_Weight(temp, temp_size, subscript);
			if(total_Atomic_Weight == -1)
				break;
		}
		
		if(element[0]>=48 && element[0]<=57){
			super_subscript = get_value_of_subscript(element, uppercase_index);
		}
	}
	printf("Atomic Weight of Substance is: %.5f\n", (super_subscript*total_Atomic_Weight));
	return (super_subscript*total_Atomic_Weight);
}

double get_Total_Atomic_Weight(char *element, int size, int subscript)
{
	char *temp_two;
	double atomic_weight=0;
	temp_two = (char*)malloc(size);
	for(int t=0; t<size; t++)
		temp_two[t]=element[t];
	atomic_weight = getElement(temp_two, subscript);
	return atomic_weight;
}	

int get_value_of_subscript(char *element, int local_pos)
{
	//Getting the total size of a Subscript i.e the char 13 gives the integer value 13.
	int subscript=0;
	char sum[100];
	int sum_index=0;
	for(int number_index = local_pos; element[number_index]>=48 && element[number_index]<=57; number_index++)
	{
		//Getting the size of the subscript i.e. 123 is 3 characters long, and storign it in sum.
		sum[sum_index++] = element[number_index];
	}
	for(int adding_sum=0; adding_sum!=sum_index; adding_sum++)
	{
		//if multiple numbers then do this i.e. 13 = 10+3; or 475 = 400 + 70 +5;
		subscript += (sum[adding_sum]-48)* pow(10.0, (sum_index-adding_sum)-1);
	}
	return subscript;
}
double getElement(char Symbol[],int subscript)
{
	//Here we get the element from the array, compare it with the 
	double result;
	int found = 1;
	for (int i = 0; i < size_Of_Array; ++i)
	{
		//Compare the symbol given and the one in database. //We replaced element with Symbol in the above.
		int ret1 = strcmp(array[i].Symbol, Symbol);
		if(ret1==0)
		{
			printf("The Element is: %s\n",array[i].Element);
			printf("Its Total Atomic weight is: %.2f\n", (array[i].Atomic_Weight * subscript));
			printf("The melting point is: %.1f\n", (array[i].mp));
			result = (array[i].Atomic_Weight * subscript);
			found = 0;
		}
	}
	if (found != 0)
	{
		printf("\n**********IMPORTANT NOTICE**********\n");
		printf("Element %s could not be found.\nPlease enter carefully next time.", Symbol);
		printf("\n**********IMPORTANT NOTICE**********\n");
		return (-1.0);
	}
	return result;
}
void mixing()
{
	double total_Weight = 0;
	// User gives us two elements.
	printf("\nEnter two Element Symbols to Combine and get the atomic weight of the result.\n");
	char first_Element[100], second_Element[100];	
	// calling function twice. get two total_Weights.
	printf("Enter the first element please, no spaces.\n");
	scanf("%s", first_Element);
	total_Weight += get_Element_Value(first_Element);
	printf("Enter the second element please, no spaces.\n");
	scanf("%s", second_Element);
	total_Weight += get_Element_Value(second_Element);

	// Element name and total combined atomic weight is printed here.
	printf("Total weight is: %lf\n", total_Weight);
}