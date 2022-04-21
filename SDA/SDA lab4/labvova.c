#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.c"
#include "header.h"

void menu(){
	printf("1) Introducerea elementelor de la tastatura.\n");
	printf("2) Cautarea elementului in lista.\n");
	printf("3) Modificarea campurilor unui element din lista.\n");
	printf("4) Determinarea adresei ultimului element din lista.\n");
	printf("5) Determinarea lungimii listei.\n");
	printf("6) Interschimbarea a doua elemente indicare in lista.\n");
	printf("7) Sortarea listei.\n");
	printf("8) Eliberarea memoriei listei.\n");
	printf("0) Iesirea din program.\n");
}

int main(){
	struct list *head = NULL;

	int num, option;
	char str[30], str2[30];

	srand(time(NULL));

	system("cls");
	printf("Dati numarul de canale:");
	scanf("%d",&num);

	citire(&head,num);

	do{
		system("cls");
		afisare(head);
		printf("\n");
		menu();
		printf("Alegeti optiunea:");
		scanf("%d",&option);

		switch(option){
			case 1:
				printf("Dati numarul de canale cate doriti sa adaugati in lista:");
				scanf("%d",&num);

				citire(&head,num);
			break;

			case 2:
				printf("Dati denumirea canalului caare doriti sal gasiti:");
				scanf("%s", str);
				struct list *temp = search(head, str);
				if(temp)
					printf("%s %s %u %s %f\n", temp -> data.denumire, temp -> data.tara, temp -> data.telefon, temp -> data.gen, temp -> data.rating);
				else printf("Elementul nu a  fost gasit\n");
			break;

			case 3:
				printf("Dati denumirea canalului pe care doriti sal schimbati.");
				scanf("%s", str);

				change(&head, str);
			break;

			case 4:
				lastElement(head);
			break;

			case 5:
				lenList(head);
			break;

			case 6:
				printf("Dati denumirea primului canal:");
				scanf("%s", str);

				printf("Dati denumirea la al 2-lea canal:");
				scanf("%s", str2);

				interschimbare(&head, str, str2);
			break;

			case 7:
				sort(&head);
			break;

			case 8:
				clearList(&head);
			break;

			case 0:
			break;
		}

		printf("\nPress any key to continue...");
		getch();
	}while(option != 0);

	return 0;
}
