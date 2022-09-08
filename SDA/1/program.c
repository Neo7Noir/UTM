#include<stdio.h>
#include "header.h"

void citire(struct tree **head, int num){
    char denumire[20];
    char tara[20];
    char primarul[20];
    char denumirea[20];
    int populatia;
    float suprafata;
	for(int i = 0; i < num; i++){
        printf("Intrdu denumirea: "); fflush(stdin);
        gets(denumirea);
        printf("Intrdu Tara: "); fflush(stdin);
        gets(tara);
        printf("Intrdu primarul: "); fflush(stdin);
        gets(primarul);
        printf("Intrdu populatiaul: ");
        scanf("%d", &populatia);
        printf("Intrdu suprafata: ");
        scanf("%f", &suprafata);
		append(&(*head), denumirea, tara, populatia, primarul, suprafata);
	}
}

void append(struct tree **head, char *denumire, char *tara, int populatia, char *primarul, float suprafata){
	if(!(*head)){
		(*head) = (struct tree*)malloc(sizeof(struct tree));
		(*head) -> data.denumire = (char*)malloc((strlen(denumire) + 1) * sizeof(char));
		strcpy((*head) -> data.denumire, denumire);

		(*head) -> data.tara = (char*)malloc((strlen(tara) + 1) * sizeof(char));
		strcpy((*head) -> data.tara, tara);

	(*head) -> data.populatia = populatia;

		(*head) -> data.primarul = (char*)malloc((strlen(primarul) + 1) * sizeof(char));
		strcpy((*head) -> data.primarul, primarul);

		(*head) -> data.suprafata = suprafata;

		(*head) -> left = (*head) -> right = NULL;
		return;
	}

	if(strcmp((*head) -> data.denumire, denumire) <= 0)
		append(&(*head) -> left, denumire, tara, populatia, primarul, suprafata);

	if(strcmp((*head) -> data.denumire, denumire) > 0)
		append(&(*head) -> right, denumire, tara, populatia, primarul, suprafata);
}


void printIn(struct tree *head){
	if(head){
		printIn(head -> left);
		printf("%s %s %u %s %.2f\n",head -> data.denumire, head -> data.tara, head -> data.populatia, head -> data.primarul, head -> data.suprafata);
		printIn(head -> right);
	}
}

struct tree *search(struct tree *head, char *denumire){
	if(!head || strcmp(head -> data.denumire, denumire) == 0)
		return head;

	if(strcmp(head -> data.denumire, denumire) < 0)
		search(head -> left, denumire);

	if(strcmp(head -> data.denumire, denumire) > 0)
		search(head -> right, denumire);
}

void change(struct tree **head, char *denumire){
	struct tree *temp = search(*head, denumire);

	if(temp){
		char str[50];
		struct Capitala newTown;

		printf("Dati denumirea noua a capitalei:");
		scanf("%s", str);
		newTown.denumire = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(newTown.denumire, str);

		printf("Dati tara noua a capitalei:");
		scanf("%s", str);
		newTown.tara = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(newTown.tara, str);

		printf("Dati primarul nou a capitalei:");
		scanf("%s", str);
		newTown.primarul = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(newTown.primarul, str);

		printf("Dati populatia nou a capitalei:");
		scanf("%d", &newTown.populatia);

		printf("Dati suprafata nou a capitalei:");
		scanf("%f", &newTown.suprafata);

		free(temp -> data.denumire);
		free(temp -> data.tara);
		free(temp -> data.primarul);

		temp -> data = newTown;
		return;
	}

	printf("Capitala cu astfel de denumire nu a fost gasita.\n");
}

int count = 0;

void numNode(struct tree *head){
	if(head){
		numNode(head -> left);
		numNode(head -> right);
		count++;
	}
}

int heightOfTree(struct tree *head){
	if(head == NULL)
		return 0;

	int left = heightOfTree(head -> left);
	int right = heightOfTree(head -> right);

	if(left >= right)
		return left + 1;
	else return right + 1;
}

void deleteTree(struct tree **head){
	if(*head == NULL)
		return;

	deleteTree(&(*head) -> left);
	deleteTree(&(*head) -> right);

	free((*head) -> data.denumire);
	free((*head) -> data.tara);
	free((*head) -> data.primarul);
	free(*head);
}

void clearTree(struct tree **head){
	deleteTree(&(*head) -> left);
	deleteTree(&(*head) -> right);

	(*head) = NULL;
}
