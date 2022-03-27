#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CanalTV{
	char denumire[20];
	char tara[10];
	unsigned long telefon;
	char gen[15];
	float rating;
}CTV;

CTV *pCanale = NULL;

int size = 0;
int firstRun = 1;
char *fisier = "canale.dat";


int Meniu(){
    if(firstRun)
        firstRun = 0;
    else{
        system("pause");
        system("cls");
    }
    printf("Alocare memorie...............1\n");
    printf("Citire canale.................2\n");
    printf("Afisare lista danale..........3\n");
    printf("Eliberare memorie.............4\n");
    printf("Adaugare canal................5\n");
    printf("Eliminare canal...............6\n");
    printf("Sortare lista de canale.......7\n");
    printf("Salvare pointer in fisier.....8\n");
    printf("Incarcare fisier in pointer...9\n");

    printf("Iesire din program............0\n");
    int menu;
    scanf("%d", &menu);
    return menu;
}

void AlocMem(){
    char rasp;
    if(size != 0){
        printf("Lista canalelor va fi stearsa irevocabil. Continuati?[d/n]\n");
        rasp = getche();
        if(rasp == 'd')
            ElibMem();
        else{
            printf("\nBine, datele nu vor fi sterse.\n");
            return;
        }
    }
    do{
        printf("Introduceti numarul canalelor: ");
        scanf("%d", &size);
    }while(size <= 0);

    pCanale = (CTV *)malloc(size * sizeof(CTV));
    if(pCanale == NULL){
        printf("\nNu s-a reusit alocarea memorie. Se va realiza iesirea din program!\n");
        exit(1);
    }else
        printf("\nA fost alocata memorie pentru %d canale.\n", size);
}

void ElibMem(){
    if(pCanale){
        free(pCanale);
        pCanale = NULL;
        size = 0;
        printf("A fost eliberata memoria alocata pentru pointerul la canale.\n");
    }
	else
        printf("Nu a fost alocata memorie, nu este ce elibera!\n");
}

void Citire(){
    if(size == 0)
        printf("Nu a fost alocata memorie. Nu este posibil de citit datele despre canale.\n");
    else{
        printf("Introduceti datele despre %d canale: \n", size);
        for(int i=0; i<size; i++){
            printf("Canalul %d:\n", i+1);
            printf("Denumirea: "); scanf("%s", pCanale[i].denumire);
            printf("Tara: "); scanf("%s", &pCanale[i].tara);
			printf("Telefon: "); scanf("%lu", &pCanale[i].telefon);
			printf("Gen: "); scanf("%s", &pCanale[i].gen);
			printf("Rating: "); scanf("%f", &pCanale[i].rating);
			if (!(0<=pCanale[i].rating && pCanale[i].rating<=10)){ 
        		while(!(0<=pCanale[i].rating && pCanale[i].rating<=10)){
            	printf("Rating gresit!\nRating:");
            	scanf("%f" ,&pCanale[i].rating);
        		}
			}	
    	}
        printf("Au fost citite datele despre %d canale.\n", size);
	}
}

void Afisare(){
    if(size == 0)
        printf("Nu a fost alocata memorie. Nu este posibil de afisat datele despre canale.\n");
    else{
        printf("Lista canalelor: \n");
        for(int i=0; i<size; i++){
            printf("%2d.| %15s.| Tara: %10s.| Telefon: %10lu.| Gen: %15s.| Rating: %4.2f.|\n", i+1, pCanale[i].denumire, pCanale[i].tara, pCanale[i].telefon, pCanale[i].gen, pCanale[i].rating);
        }
    }
}

void AdaugCanal(){
    size++;
    pCanale = (CTV *)realloc(pCanale, size * sizeof(CTV));
    printf("Introduceti datele despre canalul nou: \n", size);
	printf("Denumirea: "); scanf("%s", pCanale[size - 1].denumire);
    printf("Tara: "); scanf("%s", &pCanale[size - 1].tara);
	printf("Telefon: "); scanf("%lu", &pCanale[size - 1].telefon);
	printf("Gen: "); scanf("%s", &pCanale[size - 1].gen);

	printf("Rating: "); scanf("%f", &pCanale[size - 1].rating);
    //verificarea ratingului
	if (!(0<=pCanale[size - 1].rating && pCanale[size - 1].rating<=10)){ 
        while(!(0<=pCanale[size - 1].rating && pCanale[size - 1].rating<=10)){
            printf("Rating gresit!\nRating:");
            scanf("%f" ,&pCanale[size - 1].rating);
        	}
		}
    printf("Au fost citite datele canalului nou.\n");
}

void ElimCanal(){
    char denumire[20];
    if(size == 0)
        printf("Nu ati alocat memorie! Nu avem ce elimina!\n");
    else if(size == 1){
        printf("Lista contine doar un canal (%s). Dupa eliminarea acestuia va deveni vida!\n", pCanale->denumire);
        ElibMem();
    }
    else{
        Afisare();
        int n;
        printf("Introduceti numarul canalului pe care il eliminati: ");
        scanf("%d", &n);
        n--;
        if(n < 0 || n >= size){
            printf("Numar incorect!\n");
            return;
        }
        strcpy(denumire, pCanale[n].denumire);
        for(int i=n; i<size-1; i++)
            pCanale[i] = pCanale[i+1];
        size--;
        pCanale = (CTV *)realloc(pCanale, size * sizeof(CTV));
        printf("Canalul \"%s\" a fost eliminat!\n", denumire);
    }
}

void SortByDenumire(){
    if(size == 0){
        printf("Nu ati alocat memorie! Nu avem ce sorta!\n");
        return;
    }
    CTV temp;
    int sortat;
    do{
        sortat = 1;
        for(int i=0; i<size-1; i++)
            if(strcmp(pCanale[i].denumire, pCanale[i+1].denumire) > 0){
                sortat = 0;
                temp = pCanale[i];
                pCanale[i] = pCanale[i+1];
                pCanale[i+1]= temp;
            }
    }while(sortat == 0);
    printf("Lista canalelor a fost sortata in ordine alfabetica dupa denumire.\n");
    Afisare();
}

void SortByRatingDesresc(){
    if(size == 0){
        printf("Nu ati alocat memorie! Nu avem ce sorta!\n");
        return;
    }
    CTV temp;
    int sortat;
    do{
        sortat = 1;
        for(int i=0; i<size-1; i++)
            if(pCanale[i].rating < pCanale[i+1].rating){
                sortat = 0;
                temp = pCanale[i];
                pCanale[i] = pCanale[i+1];
                pCanale[i+1] = temp;
            }
    }while(sortat == 0);
    printf("Lista canalelor a fost sortata in ordine crescatoare.\n");
    Afisare();
}

void SortByRatingCresc(){
    if(size == 0){
        printf("Nu ati alocat memorie! Nu avem ce sorta!\n");
        return;
    }
    CTV temp;
    int sortat;
    do{
        sortat = 1;
        for(int i=0; i<size-1; i++)
            if(pCanale[i].rating > pCanale[i+1].rating){
                sortat = 0;
                temp = pCanale[i];
                pCanale[i] = pCanale[i+1];
                pCanale[i+1] = temp;
            }
    }while(sortat == 0);
    printf("Lista canalelor a fost sortata in ordine descrescatoare.\n");
    Afisare();
}

void PointToFis(){
    FILE *f;//0. Declararea unei variabile de tip pointer la fisier
    int i;
    f = fopen(fisier, "wb");//1. Deschiderea fisierului binar pentru a scrie in el
    for(i=0; i<size; i++)
        fwrite(&pCanale[i], sizeof(CTV), 1, f);//2. Scrierea datelor din pointer in fisierul binar
    fclose(f);//3. Inchiderea fisierului
    printf("Datele despre %d canale au fost inscrise in fisier.\n", i);
}

void FisToPoint(){
    FILE *f;
    CTV stud;
    int i = 0;
    f = fopen(fisier, "rb");//1. Deschiderea fisierului binar pentru a citi din el
    if(f == NULL){
        printf("Fisierul nu exista! Mai intai creati-l!\n");
        return;
    }
    //printf("Lista studentilor: \n");
    while(fread(&stud, sizeof(CTV), 1, f))//2. Citirea datelor despre canal din fisier
        i++;
    size = i;
    ElibMem();
    pCanale = (CTV *)malloc(size * sizeof(CTV));
    fseek(f, 0, 0);//Ne intoarcem la inceputul fisierului
    i = 0;
    while(fread(&pCanale[i], sizeof(CTV), 1, f))
        i++;
    fclose(f);//3. Inchiderea fisierului
    printf("Datele despre %d canale au fost transferate din fisier in pointer!\n", i);
}

int subMeniu(){
    int m;
    printf("Dupa denumire....1\n");
    printf("Dupa rating....2\n");
    scanf("%d", &m);
    return m;
}


int main()
{
    int menu, smenu, sm_rasp;
    char rasp;

    printf("Doriti sa incarcati datele din fisier in pointer?[d/n]-> ");
    rasp = getche();
    printf("\n");
    if(rasp == 'd')
        FisToPoint();

    do{
        menu = Meniu();
        switch(menu){
            case 1: AlocMem(); //break;
            case 2: Citire(); break;
            case 3: Afisare(); break;
            case 4: ElibMem(); break;
            case 5: AdaugCanal(); break;
            case 6: ElimCanal(); break;

            case 7:
                    smenu = subMeniu();
                    if(smenu == 1) SortByDenumire();
                    else if(smenu == 2){
                        printf("Cum doriti sa ordonati lista?\n1. Crescator;\n2. Descrescator;\n");
                        scanf("%d", &sm_rasp);
                        if(sm_rasp == 1) SortByRatingCresc();
                        else if(sm_rasp == 2) SortByRatingDesresc();
                        else printf("Nu este asa optiune.\n");
                    }
                    else printf("Criteriu incorect!\n");
            break;

            case 8: PointToFis(); break;
            case 9: FisToPoint(); break;

            case 0:
                printf("Salvati datele din pointer in fisier?[d/n]-> ");
                rasp = getche();
                printf("\n");
                if(rasp == 'd')
                    PointToFis();
                ElibMem();
                break;

            default: printf("Optiune incorecta! Mai incercati!\n");
        }
    }while(menu != 0);

    return 0;
}

