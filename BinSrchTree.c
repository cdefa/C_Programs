/************************************************************************************************ 
*Name: Carlos De Faria
*PID: 6050200
*
*Certification: I hereby certify that this work is mine and only mine.
*	
*Description: 
*This program was designed to read sentences from a file and compare them
*by their asccii value, with the option of case sensitive analysis; at the end the program
*the sentences will be printed into a output file or console in order. 
*If the document doesn't exist the program will read input from the command line.
*	
****************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node Structure declaration 
struct BinSearchTreeNode{
	//Left and right nodes
	struct BinSearchTreeNode *left; 
	struct BinSearchTreeNode *right;
	//String key
	char *key;
	//Counter
	int numOfNodes;
};
/****************Alias*************************/
//Alias names for tree node structure.
typedef struct BinSearchTreeNode BinSearchTreeNode;
//Alias name for a pointer to the node.
typedef BinSearchTreeNode *NodeP;
/***********************************************/


/****************Methods declarations*************************/
//Method declaration for InsertNodeing an element into the tree.
//void InsertNode(NodeP *treeP, char *value, int cflag);
void InsertNode(NodeP *treeP, char *value, int cflag){
	
		if(*treeP == NULL){
			*treeP = malloc(sizeof(BinSearchTreeNode));
		
			if (*treeP != NULL){
				char *tempString = (char *)malloc(sizeof(value));
				stpcpy(tempString,value);
				(*treeP)->key = tempString;
				(*treeP)->left  = NULL;
				(*treeP)->right = NULL;
				(*treeP)->numOfNodes++;
			}
		}else{
			char *input = (*treeP)->key; 
			if(cflag==1){
				if(tempStringCompareCaps(value, input) < 0){
					InsertNode(&(*treeP)->left, value, 1);
					(*treeP)->numOfNodes++;
				}
				else if (tempStringCompareCaps(value, input)  > 0){
					InsertNode(&(*treeP)->right, value, 1);
					(*treeP)->numOfNodes++;
				}

			}else{
				if(tempStringCompare(value, input) < 0){
					InsertNode(&(*treeP)->left, value, 0);
					(*treeP)->numOfNodes++;
				}else if (tempStringCompare(value, input)  > 0){	
					InsertNode(&(*treeP)->right, value, 0);
					(*treeP)->numOfNodes++;
				}
			}
		}
}
//Method declaration for comparing elements without case sensitive.
int tempStringCompare(char *value, char *input){
		int i=0, flag=0, x =0, z=0;
		while(value[x] != '\0'){
			value[x] = tolower(value[x]);
			x++;
		}
		while(input[z] !='\0'){
			input[z] =tolower(input[z]);
			z++;
		}
		while(value[i]==input[i] && value[i] !='\0' && input[i] != '\0'){
			i++;
		}
		if(value[i] < input[i]){
			flag= -1;
		}
		else if(value[i]>input[i]){
			flag= 1;
		}
		return flag;

}
//Method declaration for comparing elements with case sensitive.
	int tempStringCompareCaps(char *value, char *input){
	
		int i=0, flag=0;
		while(value[i]==input[i] && value[i] !='\0' && input[i] != '\0'){
			i++;
		}
		if(value[i] < input[i]){
			flag= -1;
		}
		else if(value[i]>input[i]){
			flag= 1;
		}
		return flag;

	}
//Method declaration for printing the elements of the tree.

void InOrder(NodeP treeP, FILE* out_file){
	if(treeP != NULL)
	{
		InOrder(treeP->left, out_file);
		fprintf(out_file,"%s", treeP->key);
		InOrder(treeP->right, out_file);
	}	
}	

//Method to free the nodes and string of the list 
void freeTheTree(NodeP treeP){
	if (treeP != NULL) {
		//free(treeP->key);
		//treeP->key = NULL;
		freeTheTree(treeP->right);
		freeTheTree(treeP->left);
		free(treeP);
		treeP = NULL;
		
    }
}
		

/***************************************************************/
	
int main(int argc, char **argv){

	/*******************Variables declarations******************/
	//Tree declaration
	NodeP rootP = NULL;

	FILE* file;
	FILE* out_file = stdout;
	
	extern char *optarg;
	extern int optind;	
	
	//Flag declaration 
	int cflag = 0;
	int oflag = 0;
	//Usage
	static char usage[] = "usage: bstsort[-c] [-o output_file_name][input_file_name]";
	
	//instance variables
	char tempString[100]; 
	int c=0;
	/************************************************************/
	
	/**************Getopt for flags and files********************/
	while ((c = getopt(argc, argv, "co:")) != -1){
		switch(c){
			case 'c':
				cflag = 1;
				break;
			case 'o':
				oflag = 1;
				out_file =fopen(optarg, "w");  
				break;
		}
	}
	
	if((optind + 1) > argc){
		printf("Enter multiple string of characters to be sorted:\n");
		file = stdin; 
	}else {
		file = fopen(argv[optind], "r");
	}
	if(!file){
		printf("Error: %s\n",usage);
		exit(101);
	}

	while(fgets(tempString, 100,file) != NULL){	
		InsertNode(&rootP, tempString, cflag);		
	}

	InOrder(rootP, out_file);
	freeTheTree(rootP);
	
	fclose(file);
	fclosef(out_file);
	return 0;

}






	
	

