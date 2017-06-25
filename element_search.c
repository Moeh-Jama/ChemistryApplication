#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "program_core.h"

double get_Element_Value(){

	printf("Enter an element please, no spaces.\n");
	char element[15];
	scanf("%s", element);
	// Getting the size of the element.
	int i=0, size;
	// Get the number of elements.
	while(element[i++] != '\0');
	size = --i;

	int cur_pos=0;
	//int upperCases=0;
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
			// The character is tested whether or not it is a Number.
			if(element[l]>=48 && element[l]<=57)
			{
				// The function will return the correct value.
				subscript=get_value_of_subscript(element, l);
			}
			else{	
				// If there is no subscript we'll leave the number of elements present as just 1.
				subscript=1;
			}
			temp_two = (char*)malloc(ar_size);
			for(int t=0; t<ar_size; t++)
				temp_two[t]=temp[t];
			cur_pos = k;
			total_Atomic_Weight += getElement(temp_two, subscript);
			}
	}
	printf("Atomic Weight of Substance is: %.5f\n", total_Atomic_Weight);
	return total_Atomic_Weight;
}

int get_value_of_subscript(char *element, int l)
{
	//Getting the total size of a Subscript i.e the char 13 gives the integer value 13.
	int subscript=0;
	//int n = l;
	char sum[100];
	int sum_index=0;
	for(int n = l; element[n]>=48 && element[n]<=57; n++)
	{
		//Getting the size of the subscript i.e. 123 is 3 characters long, and storign it in sum.
		sum[sum_index++] = element[n];
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
	double total_Weight = 0;
	// User gives us two elements.
	printf("\nEnter two Element Symbols to Combine and get the atomic weight of the result.\n");
	char first_Element[5], second_Element[5];	
	// calling function twice. get two total_Weights.
	total_Weight += get_Element_Value();
	total_Weight += get_Element_Value();

	// Element name and total combined atomic weight is printed here.
	printf("Total weight is: %lf\n", total_Weight);
}
