#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TelMob{
	char model[20];
	char tara_p[30];
	float pret;
}TM;

TM *pTM = NULL;
int n;

int size = 0;
int firstRun = 1;
char *fisier = "canale.dat";

void Citire(){
    if(size == 0)
        printf("Nu a fost alocata memorie. Nu este posibil de citit datele despre telefoane.\n");
    else{
        printf("Introduceti datele despre %d telefoane: \n", size);
        for(int i=0; i<size; i++){
            printf("Telefonul %d:\n", i+1);
            printf("Model: ");
            fflush(stdin);
            scanf("%s", pTM[i].model);
            printf("Tara producatoare: ");
            fflush(stdin); 
            gets(pTM[i].tara_p);
			printf("Pret: ");fflush(stdin); 
            scanf("%f", &pTM[i].pret);
			}	
    	}
        printf("Au fost citite datele despre %d telefoane.\n", size);
	}


void Afisare(){
    if(size == 0)
        printf("Nu a fost alocata memorie. Nu este posibil de afisat datele despre canale.\n");
    else{
        printf("Lista canalelor: \n");
        for(int i=0; i<size; i++){
			printf("| Nr. | Model | Tara | Pret |\n");
			printf("|%3d |%s |%s |%12.2f |\n",i+1,pTM[i].model,pTM[i].tara_p,pTM[i].pret);
        }
    }
}


void AlocMem(){
    do{
        printf("Introduceti numarul canalelor: ");
        scanf("%d", &size);
    }while(size <= 0);

    pTM = (TM *)malloc(size * sizeof(TM));
    if(pTM == NULL){
        printf("\nNu s-a reusit alocarea memorie. Se va realiza iesirea din program!\n");
        exit(1);
    }else
        printf("\nA fost alocata memorie pentru %d telefoane.\n", size);
}




void search(){
	int b = 1;
	for(int i = 0; i < size; i++){
		if(strcmp("Coreea de Sud",pTM[i].tara_p) == 0){
			b = 0;
			printf("| Nr. | Denumirea | Tara | Pret |\n");
			printf("|%3d |%s |%s |%12.2f |\n",i+1,pTM[i].model,pTM[i].tara_p,pTM[i].pret);
		}
    }
	if(b == 1)
		printf("\nNu a fost gasite telefoane cu astfel de tara producatoare!");
}


void PointToFis(){
    FILE *f;
    int i;
    f = fopen(fisier, "wb");
    for(i=0; i<size; i++)
        fwrite(&pTM[i], sizeof(TM), 1, f);
    fclose(f);
}

void FisToPoint(){
    FILE *f;
    TM telef;
    int i = 0;
    f = fopen(fisier, "rb");
    if(f == NULL){
        printf("Fisierul nu exista! Mai intai creati-l!\n");
        return;
    }
   
    while(fread(&telef, sizeof(TM), 1, f))
        i++;
    size = i;
    pTM = (TM *)malloc(size * sizeof(TM));
    fseek(f, 0, 0);
    i = 0;
    while(fread(&pTM[i], sizeof(TM), 1, f))
        i++;
    fclose(f);
}

int main(){

AlocMem();
Citire(); 
PointToFis();
FisToPoint();
search();
}