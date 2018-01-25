#define FLUSH while (getchar()!='\n')
#include<stdio.h>
/**********************************************************
 * This program is designed to perform bitwise operators into
 * a number from input,changing a bit of a number and displaying
 * the final result. the user will be prompted for performing 
 * multiple operations.
 *************************************************************/
int main(){
//Variable declarations
long long int decNum;
long long int binNum;
int bitc;
char choice;
int check = 1;
//Loop to perform bitwise operations 
while(check ==1){
	//user prompt for decimal number
	printf("Enter a decimal number between 1-1000: ");
	scanf("%li",&decNum);

	printf("enter the bit that you would like to change from 0-31: ");
	scanf("%d",&bitc);
	//bitwise operation to flip a bit
	decNum ^= (1u << bitc);
	printf("%li\n",decNum);
	printf("would you like to do another operation?(y/n)\n");
	scanf(" %c",&choice);
	if(choice == 'n'||choice == 'N')
		check = 0;//if user imput is n or N the loop exits
}

return 0;
}


