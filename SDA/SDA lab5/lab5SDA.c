#include <stdlib.h>
#include <stdio.h>

struct list{
	int data;
	struct list *next;
};

void append(struct list **head, int data){
	struct list *temp = (struct list*)malloc(sizeof(struct list));
	temp -> data = data;
	temp -> next = NULL;

	if(!(*head)){
		*head = temp;
		return;
	}

	struct list *last = *head;
	temp -> data = data;
	temp -> next = NULL;

	while(last -> next)
		last = last -> next;

	last -> next = temp;
}

void afisare(struct list *head){
	while(head){
		printf("%d ", head -> data);
		head = head -> next;
	}

	printf("\n");
}

struct list* numDiv(struct list *head){
	struct list *newList = NULL;

	struct list *temp = head;

	while(temp){
		if(temp -> data % 8 == 0)
			append(&newList, temp -> data);
		temp = temp -> next;
	}

	temp = head;

	while(temp){
		if(temp -> data % 4 == 0)
			append(&newList, temp -> data);
		temp = temp -> next;
	}

	temp = head;

	while(temp){
		if(temp -> data % 2 == 0)
			append(&newList, temp -> data);
		temp = temp -> next;
	}

	temp = head;

	while(temp){
		if(temp -> data % 2 != 0 && temp -> data < 0)
			append(&newList, temp -> data);
		temp = temp -> next;
	}

	return newList;
}

int numNode(struct list *head){
	int n = 0;

	if(!head)
		return 0;

	while(head){
		n++;
		head = head -> next;
	}

	return n;
}

int main(){
	struct list *head = NULL;

	for(int i = -20; i < 20; i++)
		append(&head,i);

	printf("Lista initiala:\n");
	afisare(head);

	struct list *newList = numDiv(head);

	printf("\nLista noua:\n");
	afisare(newList);

	struct list *temp = newList, *l1 = NULL, *l2 = NULL, *l3 = NULL;

	int node = numNode(head) / 3, i = 1;

	while(temp){
		if(i <= node)
			append(&l1, temp -> data);

		if(node < i && i <= 2 * node)
			append(&l2, temp -> data);

		if(2 * node < i && i <= numNode(head))
			append(&l3, temp -> data);

		i++;
		temp = temp -> next;
	}

	printf("\nl1) ");
	afisare(l1);
	printf("l2) ");
	afisare(l2);
	printf("l3) ");
	afisare(l3);

	return 0;
}
