/*************************************************************
* Name: Carlos De Faria
* PID: 6050200
*
* Description:
* This program is designed to run multiple processes with the goal of finding how many prime numbers
* exist between 1 and 50000 and print each prime number. Also, it will print the total time that 
*
*
* Certification: I Hereby certify that this work is mine.
*************************************************************/
#include <stdio.h>
#include <mpi.h> /*MPI header file*/ 
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char** argv)
{

	FILE *file;
	/* variable id = process rank and p = number of processes*/
	int i, j, count, div, id, p;
	long prime, fprime; 
	const int n = 50000;
	long primeNums[n]; // change to 50,000???
	fprime =0;
	int k, index=0;
	/* initialize MPI */
	MPI_Init(&argc, &argv);
	/* determine process rank - unique id of each process - range(0...p-1)*/
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	/*Determine number of processes*/
	MPI_Comm_size(MPI_COMM_WORLD, &p);	
	
	//do i need a fflush(stdout) here??
	
	/*Calculation for each unique process go through */
	for(j = id; j < n; j += p) /*have each process go through a different index */
	{
		prime = j;
		count =0;
		for(div = j; div>=1; div--)
		{
			if(j%div ==0)
			{
				count++;
			}
		}
		if(count == 2)
		{
			primeNums[index] = prime;
			index++;
			
		}
	}

	printf("\nPrime in rank %d:",id);
	for(i=0;i<index;i++){
		printf("%d ", primeNums[i]);
	}
	
	printf("\n");
	MPI_Barrier(MPI_COMM_WORLD);
	/* MPI_Reduce arguements (address of 1st reduction elm, address of 1st reduction result,
	 * count of reductions to preform, data type of elm, MPI_op(reduction operator),
	 * int root (process getting results), communicator);
	 * -- data reduction involves reducing a set of numbers into smaller
	 *    set of numbers via a function.
	 * -- in this example, Only the process 0 will get the result 
	 */
	 
	MPI_Reduce(&index, &fprime, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
	
	/*shutting down MPI - frees MPI resources*/
	MPI_Finalize();

	/*master process*/
	if(!id)
	{
		printf("\n");
		printf("Total Primes: %d\n", fprime);
	}

	return 0;
}