/*Lab n#1
 * name: Carlos De Faria
 * PID#: 6050200
 *
 * This program defines a shopping list with items respectively identified with a item number,the description and price. 
 * after prompting the user for the amount of items desired,  the program prints the shopping list with the respective final price.
 */
#include<stdio.h>


int main(void){
	
	//variables for the item identification number.
	int itemNum1=345;
	int itemNum2=7474;
	int itemNum3=987;
	int itemNum4=2342;
	int itemNum5=999;
	//description of each item.
	char *desc[5];
	desc[0]="Bookshelf";
	desc[1]="Pencil";
	desc[2]= "Chair";
	desc[3]= "Computer";
	desc[4]= "Pen";
	//price variables.
	double price1=78.51;
	double price2= 1.99;
	double price3= 129.99;
	double price4= 1295.40;
	double price5= 2.0;
	//this records the amount of item(s).
	int count[5]= {0,0,0,0,0};
	//instant variables.
	int i = 0;
	int j = 0;
	
	//this will prompt for the num of items desired and save them into the
	//count array.
	printf("Select the amount of bookshelf(s)\n");
	scanf("%d", &count[0]);
	printf("You have selected %d amount of bookshelf(s)\n",count[0]);

	printf("Select the amount of pencil(s)\n");
	scanf("%d", &count[1]);
	printf("You have selected %d amount of pencil(s)\n", count[1]);
	
	printf("Select the amount of chair(s)\n");
	scanf("%d", &count[2]);
	printf("You have selected %d amount of chair(s)\n",count[2]);

	printf("Select the amount of computer(s)\n");
	scanf("%d", &count[3]);
	printf("You have selected %d amount of computer(s)\n",count[3]);
	
	printf("Select the amount of pen(s)\n");
	scanf("%d", &count[4]);
	printf("You have selected %d amount of pen(s)\n", count[4]);

	//this will print a table with all the values registered and calculate the final price per item	
	printf("Item num\tDescription\tPrice\t\tCount\tExtendedPrice\n");
	printf("000%d\t\t%s\t$%.2f\t\t%d\t$%.2f\n",itemNum1,desc[0],price1,count[0],price1*count[0]);
	printf("00%d\t\t%s\t\t$%.2f\t\t%d\t$%.2f\n",itemNum2,desc[1],price2,count[1],price2*count[1]);
	printf("000%d\t\t%s\t\t$%.2f\t\t%d\t$%.2f\n",itemNum3,desc[2],price3,count[2],price3*count[2]);
	printf("00%d\t\t%s\t$%.2f\t%d\t$%.2f\n",itemNum4,desc[3],price4,count[3],price3*count[3]);
	printf("000%d\t\t%s\t\t$%.2f\t\t%d\t$%.2f\n",itemNum5,desc[4],price5,count[4],price5*count[4]);	
	

return 0;
}
		







	
	



	  
