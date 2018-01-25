/*
Name: Carlos De Faria
PID#: 6050200

This mini calculator program takes input from the user to produce an output equivalent to the operations performed on the number. using a set of flags to determine which operations will be performed:
-[-a]indicates adittion and must be accompanied by the number that is going to be added. 
-[-d]indicates divition and must be accompanied by the number that is going to be divided.
-[-m]indicates multiplication and must be accompanied by the number to be multiplied.
-[-s]indicates substraction and must be accompanied by the number to be substracted.
-[-x]indicates square and indicates that the value will be mulpiplied by itself.


I HEREBY CERTIFY THAT THIS WORK IS MINE. CARLOS DE FARIA
*/

#include <stdio.h>
#include <stdlib.h>

int debug = 0;

int
main(int argc, char **argv)
{
//instant variables
	extern char *optarg;
	extern int optind;
	int c;
//flag declaration
	int aflag=0, dflag=0, mflag = 0,sflag=0, xflag=0;
	static char usage[] = "usage: %s[-a num][-d num][-m num][-s num][-x]value";
	int anum=0.0, dnum=0.0, mnum=0.0, snum=0.0;
	double value = 0.0;
	while ((c = getopt(argc, argv, "a:d:m:s:x")) != -1)
		switch (c) {
		case 'a':
			aflag = 1;
			anum = atoi(optarg);
			break;
		case 'd':
			dflag = 1;
			dnum = atoi(optarg);
			break;
		case 'm':
			mflag = 1;
			mnum = atoi(optarg);
			break;
		case 's':
			sflag = 1;
			snum = atoi(optarg);
			break;
		case 'x':
			xflag = 1;
			break;
		case '?': 
			value = atof(optarg);
			break; 
		}


		value =atof(argv[optind]);
//validate value and nums
		if(value < 1 || value > 99){
			printf("The value you entered is not valid!\n Value should be a possitive integer between 1 - 99\n");
		return 0;
		}
	
		if(anum!=0 &&(anum < 1 || anum> 20)){
			printf("The number to be added should be an integer between 1 - 20\n");
		return 0;
		}

		if(dnum!=0 &&(dnum < 1 || dnum > 20)){
        	        printf("The number to be divided should be an integer between 1 - 20\n");
		return 0;
		}

		if(mnum!=0 &&(mnum < 1 || mnum > 20)){
                	printf("The number to be multiplied should be an integer between 1 - 20\n");
		return 0;
		}

		if(snum!=0 &&(snum < 1 || snum > 20)){
                	printf("The number to be substracted should be an integer between 1 - 20\n");
		return 0;
		}
//addition,substraction,square,multiplication and division depending on the flags. 
		if(xflag != 0){
			value = value * value;
		}
		if(mflag != 0){
			value = value * mnum;
		}
		if(dflag != 0){
			value = value/dnum;
		}
		if(aflag != 0){
			value = value + anum;
		}
		if(sflag != 0){
			value = value - snum;
		}
		printf("result = %.2f\n",value);
		
return 0;
}

