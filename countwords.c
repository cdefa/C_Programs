/*
 *Name:Carlos De Faria
 *PID: 60502000
 *
 *Certification:
 *I hereby certify that this work is mine and only mine. 
 *
 *Description: 
 *This program was designed to read words from a file and count them, with the option of displaying
 *the longest word, shortest word or both; at the end the program will display a the amount of words 
 *in the document as well. 
 *If the document doesn't exist the program will read input from the command line with the option of 
 *displaying the longest word, shortest word or both, and display the total amount of words.
 */
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){
int i = 0;
char c[50];
int x = 0;
int lflag = 0;
int sflag = 0;
char lword[50];
char sword[50];
//lword = (char*) malloc(40);
//sword = (char*) malloc(40);
int len = 0;
extern int optind;
static char usage[] = "usage %s [-l][-s][filename]";
char* token;
//loop to identify flags for longest and shortest words
while((i = getopt(argc,argv,"ls")) != -1){
	switch (i){
		case 'l':
			lflag = 1;
			break;
		case 's':
			sflag = 1;
			break;
		case '?': 
			break;

	}
}
//function for reading the file and flags displaying longest word, shortest word and total count of words on the document
if(argc > optind){
	FILE *f = fopen(argv[optind],"r");
	if(f != NULL){
		while(fgets (c,50,f)!= NULL){
		token = strtok(c," ");
			while(token){
				x++;
				
				if(lflag != 0 && token != NULL){
					int j = 0;
					if(lflag == 1){
						lflag++;
					}
					else{
						j = strlen(lword);
					}
					int i = strlen(token);
					if(j<i){
						strcpy(lword,token);
					}
				}
		
				if(sflag != 0 && token != NULL){
				int a = 0;
				if(sflag == 1){
					strcpy(sword,token);
					sflag++;
				}	
				else{
					 a = strlen(sword);
				}
				int b = strlen(token);
				if(a>b){
					strcpy(sword,token);
				}
			
				}
			token = strtok(NULL, " ");	
			}
		}
	if(lflag != 0){
		printf("Longest word: %s\n",lword);
	}
	if(sflag != 0){
		printf("Shortest word: %s\n",sword);
	}

	printf("Total words: %d\n",x);	 		
	fclose(f);
	
}
}
//function for reading line out of the command line and displaying the longest, shortest and total amount of words
else{
	char command[50];
	printf("Enter a string\n");
	if(fgets(command,50,stdin)!= NULL){		
		token = strtok(command, " ");
		while(token != NULL ){
			x++;
				
			if(lflag != 0 && token != NULL){
				int j = 0;
				if(lflag == 1){
					lflag++;
				}
				else{
					j = strlen(lword);
				}
				int i = strlen(token);
				if(j<i){
					strcpy(lword,token);
				}
			}
		
		if(sflag != 0 && token != NULL){
			int a = 0;
			if(sflag == 1){
				strcpy(sword,token);
				sflag++;
			}	
			else{
				 a = strlen(sword);
			}
			int b = strlen(token);
			if(a>b){
				strcpy(sword,token);
			}
		}
	token = strtok(NULL, " ");	
	}
	}
	if(lflag != 0){
		printf("Longest word: %s\n",lword);
	}
	if(sflag != 0){
		printf("Shortest word: %s\n",sword);
	}

	printf("Total words: %d\n",x);	 		
}
	

return 0;	


}
