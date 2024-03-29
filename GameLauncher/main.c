#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

#include "ttt.h"
#include "vg.h"
#include "schiffeV.h"
#include "tetris.h"

#define MAX_LEN 128

#define YELLOW  "\x1b[33m"
#define RESETCOLOUR   "\x1b[0m"

void print_image(FILE* fptr);

int main(void)
{
	int auswahl = 0;
	char puffer;
	 
	do {
		system("cls");
		printf(YELLOW);
		print_image("image.txt");
		printf(RESETCOLOUR);
		printf("\n--- Welches Spiel m\x094\chtest du spielen? ---\n\n");
		printf("[1] Tic-Tac-Toe\n");
		printf("[2] Vier gewinnt\n");
		printf("[3] Schiffe versenken\n");
		printf("[4] Tetris\n");
		printf("[5] Beenden\n\n");
		printf("Eingabe: ");
		scanf("%d%c", &auswahl, &puffer);
		
		switch (auswahl) {
		case 1:
			gameTTT();
			break;
		case 2:
			gameVierGewinnt();
			break;
		case 3:
			gameSchiffeVersenken();
			break;
		case 4:
			startTetris();
			break;
		case 5:
			printf("\n--- Ende ---");
			break;
		default:
			printf("Ungueltige Eingabe!\n");
			auswahl = 0;
			break;
		}
	} while (auswahl < 5);


	return 0;
}

void print_image(char* filename)
{
	FILE* fptr = NULL;
	char read_string[MAX_LEN];

	if ((fptr = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "error opening %s\n", filename);
		return 1;
	}

	while (fgets(read_string, sizeof(read_string), fptr) != NULL)
		printf("%s", read_string);


	fclose(fptr);
}
