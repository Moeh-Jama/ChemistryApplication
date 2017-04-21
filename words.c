#include <stdio.h>

struct getter {
	char he[5];
	char ell[5];
	char oh[5];
};
struct getter ai[2];
int main(void)
{
	char he[5]="hE";
	char ell[5]="l";
	char oh[5]="O";
	char word[5] = "Hello";

	int get_Size=sizeof(he);
	char get[get_Size];
	int k=0;
	int i;

		for(i=0; i<get_Size; i++)
		{
			if(he[i]==word[i] || (he[i]-32)== word[i] || (he[i]+32)==word[i]){
				get[k]=he[i];
				k++;
			}
		}
		get_Size=sizeof(ell);
		for(int i=0; i<get_Size; i++)
		{
			if(ell[i]==word[k] || (ell[i]-32)== word[k] || (ell[i]+32)==word[k]){
				get[k++]=ell[i];
			}
		}
		for(int i=0; i<get_Size; i++)
		{
			if(oh[i]==word[k] || (oh[i]-32)== word[k] || (oh[i]+32)==word[k]){
				get[k++]=oh[i];
			}
		}	
	
	

	printf("%s\n",get);


	return 0;
	}

