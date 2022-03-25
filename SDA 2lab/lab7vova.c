#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CanalTV{
	char *denumire;
	char *tara;
	unsigned long telefon;
	char *gen;
	float rating;
}CTV;

CTV *canale;
int n;

void menu(int *i){
	printf("\n1.Alocarea dinamica a memoriei pentru tabloul de structuri");
	printf("\n2.Introducerea elementelor tabloului de latastatura.");
	printf("\n3.Afisarea elementelor tabloului la ecran.");
	printf("\n4.Adaugarea unui nou element la sfarsit.");
	printf("\n5.Modificarea elementului tabloului.");
	printf("\n6.Cautarea elementului tabloului.");
	printf("\n7.Sortarea tabloului.");
	printf("\n8.Eliminarea elementului indicat din tablou.");
	printf("\n9.Eliberarea memoriei alocate pentru tablou.");
	printf("\n0.Iesirea din program");
	printf("\nAlegeti optiunea - ");
	fflush(stdin);
	scanf("%d",i);
}

CTV *create(){
	printf("Dati numarul de canale - ");
	scanf("%d",&n);
	while(n<0){
		printf("Nu putem avea un numar negativ de canale\nDati alt numar de canale:");
		scanf("%d",&n);
	}

	CTV *canale;
	canale = (CTV*)malloc(n*sizeof(CTV));
	return canale;
}

void citireStruct(int i){
	char str[255];

	printf("Canalul %d\n",i+1);
	printf("Denumirea: ");
	fflush(stdin);
	gets(str);
	canale[i].denumire = (char*)malloc((strlen(str) + 1 ) * sizeof(char));
	strcpy(canale[i].denumire,str);

	printf("Tara: ");
	fflush(stdin);
	gets(str);
	canale[i].tara = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(canale[i].tara,str);

	printf("Genul: ");
	fflush(stdin);
	gets(str);
	canale[i].gen = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(canale[i].gen,str);

	printf("Telefonul: ");
	scanf("%lu",&canale[i].telefon);

	printf("Rating: ");
	scanf("%f",&canale[i].rating);
    if (!(0<=canale[i].rating && canale[i].rating<=10)){ 
        while(!(0<=canale[i].rating && canale[i].rating<=10)){
            printf("Rating gresit!\nRating:");
            scanf("%f" ,&canale[i].rating);
        }
	}
}

void citire(){
	printf("\nCitire canale\n");
	for(int i = 0; i < n; i++)
		citireStruct(i);
}

void afisare(){
	if(n){
		printf("| Nr. | \tDenumirea | \tTara | \tTelefonul | \tGenul | \tRating |\n");
		for(int i = 0; i < n; i++)
			printf("|%3d |%15s |%15s |%5lu |%15s |%12.2f |\n",i+1,canale[i].denumire,canale[i].tara,canale[i].telefon,canale[i].gen,canale[i].rating);
	}
}

void inserare(){
	CTV *tempCanal = realloc(canale, ++n * sizeof(CTV));
	if(tempCanal){
		canale = tempCanal;
		int i = n-1;
		printf("Noul imobil:\n");
		citireStruct(i);
	}else
		printf("Nu e posibil de inserat un element nou");
}

void editare(){
	int i;
	printf("Dari numarul elementului care doriti sal editati : ");
	scanf("%d",&i);
	i--;

	char str[255];

	printf("\nDati noile valori al canalului dat:\n");
	citireStruct(i);
}


void search(){
	int b = 1;
	char str[255];
	printf("Dati denumirea canalului care doriti sal cautati: ");
	fflush(stdin);
	gets(str);
	for(int i = 0; i < n; i++)
		if(strcmp(str,canale[i].denumire) == 0){
			b = 0;
			printf("| Nr. | \tDenumirea | \tTara | \tTelefonul | \tGenul | \tRating |\n");
			printf("|%3d |%15s |%15s |%5lu |%15s |%12.2f |\n",i+1,canale[i].denumire,canale[i].tara,canale[i].telefon,canale[i].gen,canale[i].rating);
		}

	if(b == 1)
		printf("\nNu a fost gasit canal cu astfel de denumire!");
}

void del(){
	int x;
	printf("Dati numarul canalului pe care doriti sal eliminati: ");
	scanf("%d",&x);
	x--;

	for(int i = x; i < n-1; i++)
		canale[i] = canale[i+1];

	n--;
	canale = (CTV*)realloc(canale,n*sizeof(CTV));
	printf("Eliminarea efectuata cu succes");
}

void eliberare(){
	for(int i = 0; i < n; i++){
		free(canale[i].denumire);
		free(canale[i].tara);
		free(canale[i].gen);
	}

	free(canale);
	n = 0;
}



void sort(){
	int option;
	printf("Alegeti cum doriti sa fiba sortat tabelul\n");
	printf("1. Raiting crescator\n2. Raiting descrescator\n");
	scanf("%d",&option);

	int sortat;

	CTV temp;
	switch(option){
		case 1 :
			do
        	{
            	sortat = 1;
            	for (int i = 0; i < n - 1; i++)
            	    if (canale[i].rating > canale[i + 1].rating)
            	    {
            	        sortat = 0;
            	        temp = canale[i];
            	        canale[i] = canale[i + 1];
           		        canale[i + 1] = temp;
                	}
        	} while (sortat == 0);
		break;

		case 2 : 
        	do
        	{
        	    sortat = 1;
        	    for (int i = 0; i < n - 1; i++)
        	        if (canale[i].rating < canale[i + 1].rating)
        	        {
        	            sortat = 0;
       		            temp = canale[i];
            	        canale[i] = canale[i + 1];
            	        canale[i + 1] = temp;
            	    }
        	} while (sortat == 0);
		break;

		default :
			printf("Ati ales optiune incorecta");
		break;
	}
}

int main(){
	int i;
	do{
		menu(&i);
		switch(i){
			case 1 : canale = create(); break;
			case 2 : citire(); break; 
			case 3 : afisare(); break;
			case 4 : inserare(); break;
			case 5 : editare(); break;
			case 6 : search(); break;
			case 7 : sort(); break;
			case 8 : del(); break; 
			case 9 : eliberare(); break;
		}
	}while(i);

	return 0;
}
