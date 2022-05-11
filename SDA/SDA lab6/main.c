#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "program.c"
#include "header.h"

void menu(){
	printf("1) Adaugarea elementrlor in lista.\n");
	printf("2) Cautarea nodului in arbore.\n");
	printf("3) Modificarea informatiei unui nod din arbore.\n");
	printf("4) Determinarea numarului de noduri.\n");
	printf("5) Determinarea inaltimii arborelui.\n");
	printf("6) Eliberarea memoriei alocata pentru arbore.\n");
	printf("0) Iesirea din program.\n");
}

int main(){
	struct tree *head = NULL;

	int num, option;
	char str[30], str2[30];

	srand(time(NULL));

	system("cls");
	printf("Dati numarul de canale:");
	scanf("%d",&num);

	citire(&head,num);

	do{
		system("cls");
		printIn(head);
		printf("\n");
		menu();
		printf("Alegeti optiunea:");
		scanf("%d",&option);

		switch(option){
			case 1:
				printf("Dati numarul de canale:");
				scanf("%d",&num);

				citire(&head,num);
			break;

			case 2:
				printf("Dati denumirea canalului care doriti sal cautati:");
				scanf("%s",str);

				struct tree *temp = search(head, str);

				printIn(temp);
			break;

			case 3:
				printf("Dati denumirea canalului care doriti sal modificati:");
				scanf("%s",str);

				change(&head, str);
			break;

			case 4:
				numNode(head);
				printf("Arborele are %d noduri.", count);
				count = 0;
			break;

			case 5:
				printf("Inaltimea arborelui este: %d.",heightOfTree(head));
			break;

			case 6:
				clearTree(&head);
			break;

			case 0:
			break;
		}

		printf("\nPress any key to continue...");
		getch();
	}while(option != 0);
	/*
	printf("123");

	append(&head, "qwe", "dhgdfgh", 123123, "gdsf", 12.2);
	append(&head, "safgs", "dhgdfgh", 123123, "gdsf", 12.2);
	append(&head, "ljf", "dhgdfgh", 123123, "gdsf", 12.2);
	append(&head, "fdgh", "dhgdfgh", 123123, "gdsf", 12.2);


	printIn(head);
	*/

	// struct tree *temp = search(head, "ljf");
	//
	// if(temp)
	// 	printf("%s \n", temp -> data.denumire);
	//

	//change(&head, "ljf");
	//printIn(head);

	// numNode(head);
	// printf("%d\n", count);
	//
	// int height = heightOfTree(head);
	// printf("%d", height);
	//
	// clearTree(&head);
	// printIn(head);
	return 0;
}
