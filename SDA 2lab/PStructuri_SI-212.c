#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char nume[20];
    float nota;
}Student;
Student *pStud = NULL;
int size = 0;
int firstRun = 1;
char *fisier = "fis_stud_SI-212.dat";
 
void AlocMem(){
    char rasp;
    if(size != 0){
        printf("Lista studentilor va fi stearsa irevocabil. Continuati?[d/n]");
        rasp = getche();
        if(rasp == 'd')
            ElibMem();
        else{
            printf("Bine ca v-ati razgandit!\n");
            return;
        }
    }

    do{
        printf("Introduceti numarul studentilor: ");
        scanf("%d", &size);
    }while(size < 0);

    pStud = (Student *)malloc(size * sizeof(Student));
    if(pStud == NULL){
        printf("Nu s-a reusit alocarea memorie. Se va realiza iesirea din program!\n");
        exit(1);
    }else
        printf("A fost alocata memorie pentru %d studenti!\n", size);
}

void Citire(){
    if(size == 0)
        printf("Nu a fost alocata memorie. Nu este posibil de citit datele despre studenti!\n");
    else{
        printf("Introduceti datele despre %d studenti: \n", size);
        for(int i=0; i<size; i++){
            printf("Studentul %d:\n", i);
            printf("Numele: "); scanf("%s", pStud[i].nume);
            printf("Nota: "); scanf("%f", &pStud[i].nota);
        }
        printf("Au fost citite datele despre %d studenti!\n", size);
    }
}

void Afisare(){
    if(size == 0)
        printf("Nu a fost alocata memorie. Nu este posibil de afisat datele despre studenti!\n");
    else{
        printf("Lista studentilor: \n");
        for(int i=0; i<size; i++){
            printf("%2d. %10s. Nota: %4.2f\n", i, pStud[i].nume, pStud[i].nota);
        }
    }
}

void ElibMem(){
    if(pStud){
        free(pStud);
        pStud = NULL;
        size = 0;
        printf("A fost eliberata memoria alocata pentru pointerul la studenti!\n");
    }else
        printf("Nu a fost alocata memorie, nu avem ce elibera!\n");
}

void AdaugStud(){
    size++;
    pStud = (Student *)realloc(pStud, size * sizeof(Student));
    printf("Introduceti datele despre studentul adaugat: \n", size);
    printf("Numele: "); scanf("%s", pStud[size - 1].nume);
    printf("Nota: "); scanf("%f", &pStud[size - 1].nota);
    printf("Au fost citite datele despre studentul nou!\n");
}

void ElimStud(){
    char nume[20];
    if(size == 0)
        printf("Nu ati alocat memorie! Nu avem ce elimina!\n");
    else if(size == 1){
        printf("Lista contine doar un student (%s). Dupa eliminarea acestuia va deveni vida!\n", pStud->nume);
        ElibMem();
    }else{
        Afisare();
        int n;
        printf("Introduceti numarul studentului pe care il eliminati: ");
        scanf("%d", &n);
        if(n < 0 || n >= size){
            printf("Numar incorect!\n");
            return;
        }
        strcpy(nume, pStud[n].nume);
        for(int i=n; i<size-1; i++)
            pStud[i] = pStud[i+1];
        size--;
        pStud = (Student *)realloc(pStud, size * sizeof(Student));
        printf("Studentul \"%s\" a fost eliminat!\n", nume);
    }
}

void SortByNume(){
    if(size == 0){
        printf("Nu ati alocat memorie! Nu avem ce sorta!\n");
        return;
    }
    Student temp;
    int sortat;
    do{
        sortat = 1;
        for(int i=0; i<size-1; i++)
            if(strcmp(pStud[i].nume, pStud[i+1].nume) > 0){
                sortat = 0;
                temp = pStud[i];
                pStud[i] = pStud[i+1];
                pStud[i+1]= temp;
            }
    }while(sortat == 0);
    printf("Lista studentilor a fost sortata in ordine alfabetica a numelui!\n");
    Afisare();
}

void SortByNota(){
    if(size == 0){
        printf("Nu ati alocat memorie! Nu avem ce sorta!\n");
        return;
    }
    Student temp;
    int sortat;
    do{
        sortat = 1;
        for(int i=0; i<size-1; i++)
            if(pStud[i].nota < pStud[i+1].nota){
                sortat = 0;
                temp = pStud[i];
                pStud[i] = pStud[i+1];
                pStud[i+1]= temp;
            }
    }while(sortat == 0);
    printf("Lista studentilor a fost sortata in ordine descrescatoare a notei!\n");
    Afisare();
}

void PointToFis(){
    FILE *f;//0. Declararea unei variabile de tip pointer la fisier
    //Student stud;
    int i;
    f = fopen(fisier, "wb");//1. Deschiderea fisierului binar pentru a scrie in el
    for(i=0; i<size; i++)
        fwrite(&pStud[i], sizeof(Student), 1, f);//2. Scrierea datelor din pointer in fisierul binar
    fclose(f);//3. Inchiderea fisierului
    printf("Datele despre %d studenti au fost inscrise in fisier!\n", i);
}

void FisToPoint(){
    FILE *f;//0. Declararea unei variabile de tip pointer la fisier
    Student stud;
    int i = 0;
    f = fopen(fisier, "rb");//1. Deschiderea fisierului binar pentru a citi din el
    if(f == NULL){
        printf("Fisierul nu exista! Mai intai creati-l!\n");
        return;
    }
    //printf("Lista studentilor: \n");
    while(fread(&stud, sizeof(Student), 1, f))//2. Citirea datelor despre student din fisierul binar
        i++;
    size = i;
    ElibMem();
    pStud = (Student *)malloc(size * sizeof(Student));
    fseek(f, 0, 0);//Ne intoarcem la inceputul fisierului
    i = 0;
    while(fread(&pStud[i], sizeof(Student), 1, f))
        i++;
    fclose(f);//3. Inchiderea fisierului
    printf("Datele despre %d studenti au fost transferate din fisier in pointer!\n", i);
}


int Meniu(){
    if(firstRun)
        firstRun = 0;
    else{
        system("pause");
        system("cls");
    }
    printf("Alocare memorie..............1\n");
    printf("Citire date studenti.........2\n");
    printf("Afisare lista studenti.......3\n");
    printf("Eliberare memorie............4\n");
    printf("Adaugare student.............5\n");
    printf("Eliminare student............6\n");
    printf("Sortare lista studenti.......7\n");

    printf("Salvare pointer in fisier....8\n");
    printf("Incarcare fisier in pointer..9\n");


    printf("Iesire din program...........0\n");
    int m;
    scanf("%d", &m);
    return m;
}

int subMeniu(){
    int m;
    printf("Dupa nume....1\n");
    printf("Dupa nota....2\n");
    scanf("%d", &m);
    return m;
}

int main()
{
    int m, sm;
    char rasp;

    printf("Doriti sa incarcati datele din fisier in pointer?[d/n]-> ");
    rasp = getche();
    printf("\n");
    if(rasp == 'd')
        FisToPoint();

    do{
        m = Meniu();
        switch(m){
            case 1: AlocMem(); //break;
            case 2: Citire(); break;
            case 3: Afisare(); break;
            case 4: ElibMem(); break;
            case 5: AdaugStud(); break;
            case 6: ElimStud(); break;

            case 7:
                    sm = subMeniu();
                    if(sm == 1) SortByNume();
                    else if(sm == 2) SortByNota();
                    else printf("Criteriu incorect!\n");
            break;

            case 8: PointToFis(); break;
            case 9: FisToPoint(); break;

            case 0:
                //ElibMem();
                printf("Autorul programului este Vitalie M.\n");
                printf("Salvati datele din pointer in fisier?[d/n]-> ");
                //fflush(stdin);
                rasp = getche();
                printf("\n");
                if(rasp == 'd')
                    PointToFis();
                ElibMem();
                break;

            default: printf("Optiune incorecta! Mai incercati!\n");
        }
    }while(m != 0);

    return 0;
}
