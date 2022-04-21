#include "header.h"

void append(struct list **head, char *denumire, char *tara, unsigned long telefon, char *gen, float rating){
	struct list *newData = (struct list*)malloc(sizeof(struct list));
	newData -> data.denumire = (char*)malloc((strlen(denumire)+1)*sizeof(char));
	strcpy(newData -> data.denumire, denumire);

	newData -> data.tara= (char*)malloc((strlen(tara)+1)*sizeof(char));
	strcpy(newData -> data.tara, tara);

	newData -> data.gen= (char*)malloc((strlen(gen)+1)*sizeof(char));
	strcpy(newData -> data.gen, gen);

	newData -> data.telefon = telefon;
	newData -> data.rating = rating;

	newData -> next = NULL;

	if(!(*head)){
		*head = newData;
		return;
	}

	struct list *temp = *head;

	while(temp -> next)
		temp = temp -> next;

	temp -> next = newData;
}

void citire(struct list **head, int num){
	srand(time(NULL));
	char denumire[20], tara[20], gen[20];
	unsigned long telefon;
	float rating;

	for(int i = 0; i < num; i++){
		printf("Dati numele canalului: ");
		scanf("%s", denumire);

		printf("Dati tara canalului: ");
		scanf("%s", tara);

		printf("Dati genul canalului: ");
		scanf("%s", gen);

		printf("Dati telefonul nou al canalului: ");
		scanf("%u", &telefon);

		printf("Dati ratingul nou al canalului: ");
		scanf("%f", &rating);

		append(&(*head), denumire, tara, telefon, gen, rating);
	}
}

void afisare(struct list *head){
	int i = 1;
	while(head){
		printf("%d) %s %s %u %s %f\n", i++, head -> data.denumire, head -> data.tara, head -> data.telefon, head -> data.gen, head -> data.rating);
		head = head -> next;
	}
}

struct list *search(struct list *head, char *denumire){
	int i = 1;
	while(head){
		if(!strcmp(head -> data.denumire, denumire))
			return head;

		i++;
		head = head -> next;
	}
	return NULL;
}

void change(struct list **head, char *denumire){
	struct list *newData = (struct list*)malloc(sizeof(struct list));
	char str[50];

	struct list *temp = search(*head, denumire);

	if(!temp){
		printf("Elementul nu a fost gasit in lista\n");
		return;
	}

	printf("Dati numele nou al canalului: ");
	scanf("%s", str);
	newData -> data.denumire = (char*)malloc((strlen(str)+1)*sizeof(char));
	strcpy(temp -> data.denumire, str);

	printf("Dati tara noua al canalului: ");
	scanf("%s", str);
	newData -> data.tara= (char*)malloc((strlen(str)+1)*sizeof(char));
	strcpy(temp -> data.tara, str);

	printf("Dati genul nou al canalului: ");
	scanf("%s", str);
	newData -> data.gen= (char*)malloc((strlen(str)+1)*sizeof(char));
	strcpy(temp -> data.gen, str);

	printf("Dati telefonul nou al canalului: ");
	scanf("%u", &temp -> data.telefon);

	printf("Dati ratingul nou al canalului: ");
	scanf("%f", &temp -> data.rating);
}

void lastElement(struct list *head){
	while(!(head -> next))
		head = head -> next;

	printf("Adresa ultimului element este: %d\n", &head);
}

void lenList(struct list *head){
	int len = 0;
	while(head){
		len++;
		head = head -> next;
	}

	printf("Lista are %d elemente.\n", len);
}

void interschimbare(struct list **head, char *den1, char *den2){
	struct list *el1 = search(*head, den1);
	struct list *el2 = search(*head, den2);

	if(el1 && el2){
		struct elev temp = el1 -> data;
		el1 -> data = el2 -> data;
		el2 -> data = temp;
		printf("Elementele au fost interschimbate cu succes!\n");
		return;
	}

	printf("Unul sau ambele elemente nu exista in lista\n");
}

void sort(struct list **head){
	struct list *curentStudent = *head, *index = NULL;
	struct elev temp;

	while(curentStudent != NULL){
		index = curentStudent -> next;

		while(index != NULL){
			if(strcmp(curentStudent -> data.denumire, index -> data.denumire) > 0){
				temp = curentStudent -> data;
				curentStudent -> data = index -> data;
				index -> data = temp;
			}

			index = index -> next;
		}
		curentStudent = curentStudent -> next;
	}
}

void clearList(struct list **head){
	struct list *temp;

	while((*head)){
		temp = *head;
		(*head) = (*head) -> next;

		free(temp -> data.denumire);
		free(temp -> data.tara);
		free(temp -> data.gen);
		free(temp);
	}

	free(*head);
	printf("Lista a fost eliberata cu succes!\n");
}
