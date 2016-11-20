#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



# define  MAX 1000
#define MORSE_MAX 6
/*#include "func.h"*/

typedef struct {
	char letra;
	char morse[MORSE_MAX];
}Data;

Data* data_base(int n_elem)
{
	int i = 0;
	FILE *fp;
	char morse[MORSE_MAX];
	char line[MAX];

	fp = fopen("morse.txt", "r");
	fscanf(fp, "%d\n", &n_elem);
	Data* data = (Data*)malloc(sizeof(Data)*n_elem);

	for(i = 0; i < n_elem; i++)
	{
		fgets(line, MAX, fp);
		sscanf(line,"%c %s x", &data[i].letra, morse);
		strcpy(data[i].morse, morse);
		
	}

	fclose(fp);
	
	return data;
}


void morsing(char *input , Data* data)
{
	int i = 0;
	
	while(i < strlen(input))
	{
		if(input[i] != ' ')
		{
			if((int)toupper(input[i]) >= 'A' && (int)toupper(input[i]) <= 'Z' )
			{
				printf("%s ", data[	(int)toupper(input[i]) - 'A'].morse	);
			}
		}
		else
		{
			printf("/ ");
		}
		i++;
	}
	printf("\n");
}

void wording(char * input, Data* data, int n_elem)
{
	char *word = (char*)malloc(sizeof(char)*MAX);
	int i = 0, j;

	for(i=0; i < strlen(input); i++)
	{
		j = i;
		if (input[i] == '\n')
		{
			printf("\n");
		}
		else if (input[i] == '/')
		{
			printf(" ");
		}
		while(input[i] != ' ' && input[i] != '\0' && input[i] != '/' && input[i] != '\n')
		{
			word[i-j] = input[i];
			i++;
		}
		word[i-j] = '\0';

		

		for(j = 0; j < 36; j++)
		{
			if(strcmp(word, data[j].morse) == 0)
			{
				printf("%c", data[j].letra);
				break;
			}
		}

	}
	printf("\n");

	free(word);


}

int main() {
	char* input = (char*)malloc(sizeof(char)*MAX);
	int* n_elem = NULL;
	Data * data = data_base((int)n_elem);


	printf("Prima para:\n\tConverter para morse - 0\n\tConverter para alfabeto - 1\n\t[0,1] - ");
	do
	{
		fgets(input, MAX, stdin);
	}while(input[0]!= '0' && input[0] != '1');
 
	switch(input[0])
	{
		case '0':
			printf("Intruduza o texto a converter: ");
			fgets(input, MAX, stdin);
			morsing(input, data);
			break;

		case '1':
			printf("Intruduza o codigo a converter: ");
			fgets(input, MAX, stdin);
			wording(input, data, (int)n_elem);
			break;
	}
	free(input);
	free(data);

	free(n_elem);
	return 0;
}