#ifndef HEADER_H
#define HEADER_H

struct canal{
	char *denumire;
	char *tara;
	unsigned long telefon;
	char *gen;
	float rating;
};

struct tree{
	struct canal data;
	struct tree *left, *right;
};


void append(struct tree **head, char *denumire, char *tara, unsigned long telefon, char *gen, float rating);
void printIn(struct tree *head);
struct tree *search(struct tree *head, char *denumire);
void change(struct tree **head, char *denumire);
void numNode(struct tree *head);
int heightOfTree(struct tree *head);
void clearTree(struct tree **head);
void citire(struct tree **head, int num);

#endif
