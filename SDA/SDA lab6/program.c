#include "header.h"

const char denumire[][20] = {"Moldova1","ProTV", "CTC", "THT", "Canal 3"};
const char tara[][20] = {"Moldova", "Romania", "Ucraina", "Turcia"};
const char gen[][20] = {"Filme", "Stiri", "pentru Copiii", "18+"};

void append(struct tree **head, char *denumire, char *tara, unsigned long telefon, char *gen, float rating){
	if(!(*head)){
		(*head) = (struct tree*)malloc(sizeof(struct tree));
		(*head) -> data.denumire = (char*)malloc((strlen(denumire) + 1) * sizeof(char));
		strcpy((*head) -> data.denumire, denumire);

		(*head) -> data.tara = (char*)malloc((strlen(tara) + 1) * sizeof(char));
		strcpy((*head) -> data.tara, tara);

	(*head) -> data.telefon = telefon;

		(*head) -> data.gen = (char*)malloc((strlen(gen) + 1) * sizeof(char));
		strcpy((*head) -> data.gen, gen);

		(*head) -> data.rating = rating;

		(*head) -> left = (*head) -> right = NULL;
		return;
	}

	if(strcmp((*head) -> data.denumire, denumire) <= 0)
		append(&(*head) -> left, denumire, tara, telefon, gen, rating);

	if(strcmp((*head) -> data.denumire, denumire) > 0)
		append(&(*head) -> right, denumire, tara, telefon, gen, rating);
}

void citire(struct tree **head, int num){
	srand(time(NULL));
	for(int i = 0; i < num; i++){
		append(&(*head), denumire[rand() % 5], tara[rand() % 4], rand() % 100000 + 899999, gen[rand() % 4], rand() % 10 + 1);
	}
}

void printIn(struct tree *head){
	if(head){
		printIn(head -> left);
		printf("%s %s %u %s %.2f\n",head -> data.denumire, head -> data.tara, head -> data.telefon, head -> data.gen, head -> data.rating);
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
		struct canal newCanal;

		printf("Dati denumirea noua al canalului:");
		scanf("%s", str);
		newCanal.denumire = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(newCanal.denumire, str);

		printf("Dati tara noua al canalului:");
		scanf("%s", str);
		newCanal.tara = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(newCanal.tara, str);

		printf("Dati genul nou al canalului:");
		scanf("%s", str);
		newCanal.gen = (char*)malloc((strlen(str) + 1) * sizeof(char));
		strcpy(newCanal.gen, str);

		printf("Dati telefonul nou al canalului:");
		scanf("%u", &newCanal.telefon);

		printf("Dati ratingul nou al canalului:");
		scanf("%f", &newCanal.rating);

		free(temp -> data.denumire);
		free(temp -> data.tara);
		free(temp -> data.gen);

		temp -> data = newCanal;
		return;
	}

	printf("Canal cu astfel de denumire nu a fost gasit.\n");
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
	free((*head) -> data.gen);
	free(*head);
}

void clearTree(struct tree **head){
	deleteTree(&(*head) -> left);
	deleteTree(&(*head) -> right);

	(*head) = NULL;
}
