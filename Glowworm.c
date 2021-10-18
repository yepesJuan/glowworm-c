// Juan Yepes
// Ju994964
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Glowworm.h"

double difficultyRating(void)
{
	return 4.0;
}

double hoursSpent(void)
{
	return 23.0;
}
// Function for when the Glowworm dies.  
void printGlowWormDead(int tail, int head, int maxLength)
{
	int i;

	head %= maxLength;
	tail %= maxLength;

	for(i = 0; i < maxLength; i++)
	{
		if (head < tail)
		{
			if(head == 0 && i == maxLength - 1)
				printf("X");
			else if(i == head)
				printf("x");
			else if(i == head - 1) 
				printf("X");
			else if(i == tail)
				printf("~");
			else if(i > tail)
				printf("o");
			else if(i < head && i < tail)
				printf("o");
			else if(i > head && i < tail)
				printf(" ");
		}
		else
		{
			if(i == tail)
				printf("~");
			else if(i == head - 1)
				printf("X");
			else if(i == head)
			{
				printf("x");
				break;
			}
			else if(i < head - 1 && i > tail)
				printf("o");
			else
				printf(" ");
		}
	} 
	printf("\n");

	for(i = 0; i < maxLength; i++)
		printf("=");			
	
	printf("\n\n");
}
// Fuction for when the Glowworm lives.
void printGlowworm(int tail, int head, int maxLength)
{
	int i;

	head %= maxLength;
	tail %= maxLength;

	for(i = 0; i < maxLength; i++)
	{
		if (head < tail)
		{
			if(head == 0 && i == maxLength - 1)
				printf("O");
			else if(i == head)
				printf("G");
			else if(i == head - 1)
				printf("O");
			else if(i == tail)
				printf("~");
			else if(i > tail)
				printf("o");
			else if(i < head && i < tail)
				printf("o");
			else if(i > head && i < tail)
				printf(" ");
		}
		else
		{
			if(i == tail)
				printf("~");
			else if(i == head - 1)
				printf("O");	
			else if(i == head)
			{
				printf("G");
				break;
			}
			else if(i < head - 1 && i > tail)
				printf("o");
			else
				printf(" ");
		}
	} 
	printf("\n");
	
	for(i = 0; i < maxLength; i++)
		printf("=");	
	printf("\n\n");	
}

int main(int argc, char **argv)
{
	int i, maxLength, len, tail = 0, head = 2;

	printf("%s\n\n", argv[2]);

	printf("Glowworm appears! Hooray!\n");

	maxLength = atoi(argv[1]);

	len = strlen(argv[2]);

	//Initial Glowworm.
	printGlowworm(tail, head, maxLength);

	for(i = 0; i < len; i++)
	{ 
		// Growing behavior.
		// First checks if Glowworm is maximum length.
		if(argv[2][i] == 'o' || argv[2][i] == 'O' || argv[2][i] == '@') 
		{	
		 	if((head == maxLength - 1 && tail == 0) || ((head + 1) % maxLength) == tail % maxLength)  
			{
				printf("Glowworm chills:\n");
				printGlowworm(tail, head, maxLength);
			}
			else
			{
				head++;
				printf("Glowworm grows:\n");
				printGlowworm(tail, head, maxLength);
			}
		}
		// Shrinking behavior.
		// First checks if Glowworm is minimum length.
		else if(argv[2][i] == 's' || argv[2][i] == 'S') 
		{
			if(head == (tail + 2))
			{
				printf("Glowworm chills:\n");
				printGlowworm(tail, head, maxLength);
			}
		 	else
			{		
				head--;	
				printf("Glowworm shrinks:\n");
				printGlowworm(tail, head, maxLength);
			}
		} 
		// Inching forward behavior.
		else if(argv[2][i] == '-' || argv[2][i] == '=') // inching foward
		{
				tail++;
				head++; 
				printf("Glowworm inches forward:\n");
				printGlowworm(tail, head, maxLength);
		}
		// Dying behavior.
		// Different function for when Glowworm dies.
		else if(argv[2][i] == 'x' || argv[2][i] == 'X' || argv[2][i] == '%') // dying
		{
			printf("Glowworm meets its demise. SAD.\n");
			printGlowWormDead(tail, head, maxLength);
			break;
		}
		// Any other character behavior.
		else
		{
			printf("Glowworm chills:\n");
			printGlowworm(tail, head, maxLength);
		}
	}	
	return 0;
}


