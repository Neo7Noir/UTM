#ifndef HEADER_H
#define HEADER_H

struct elev{
	char *denumire;
	char *tara;
	unsigned long telefon;
	char *gen;
	float rating;
};

struct list{
	struct elev data;
	struct list *next;
};

void append(struct list **head, char *denumire, char *tara, unsigned long telefon, char *gen, float rating);
void citire(struct list **head, int num);
void afisare(struct list *head);
struct list *search(struct list *head, char *denumire);
void change(struct list **head, char *denumire);
void lastElement(struct list *head);
void lenList(struct list *head);
void interschimbare(struct list **head, char *den1, char *den2);
void sort(struct list **head);
void clearList(struct list **head);

#endif
