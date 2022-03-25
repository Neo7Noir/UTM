#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char nume[20];
    float nota;
}Student;
char *fisier = "stud_SI-212.dat";
int firstRun = 1;


void CreareFis(){
    FILE *f;//0. Declararea unei variabile de tip pointer la fisier
    char rasp;
    Student stud;
    printf("Datele din fisier vor fi sterse irevocabil. Continuati?[d/n]-> ");
    fflush(stdin);
    scanf("%c", &rasp);
    if(rasp != 'd'){
        printf("Bine ca v-ati razgandit! Datele raman intacte!\n");
        return;
    }
    f = fopen(fisier, "wb");//1. Deschiderea fisierului binar pentru scriere (datele existente se sterg)
    int i = 0;
    do{
        printf("Introduceti datele despre studentul %d\n", ++i);
        printf("Numele: "); scanf("%s", stud.nume);
        printf("Nota: "); scanf("%f", &stud.nota);
        fwrite(&stud, sizeof(Student), 1, f);//2. Scrierea datelor in fisierul binar
        printf("Doriti sa mai introduceti date despre studenti?[d/n]-> ");
        fflush(stdin);
        scanf("%c", &rasp);
    }while(rasp == 'd');
    printf("Datele despre %d studenti au fost inscrise in fisier!\n", i);
    fclose(f);//3. Inchiderea fisierului
}

void AfisFis(){
    FILE *f;//0. Declararea unei variabile de tip pointer la fisier
    char rasp;
    Student stud;
    f = fopen(fisier, "rb");//1. Deschiderea fisierului binar pentru citire
    //f = fopen("temp.dat", "rb");//1. Deschiderea fisierului binar pentru citire
    int i = 0;
    if(f == NULL){
        printf("Fisierul nu exista! Mai intai creati-l!\n");
        return;
    }
    printf("Lista studentilor: \n");
    while(fread(&stud, sizeof(Student), 1, f))//2. Citirea datelor din fisierul binar
        printf("%2d. %10s. Nota: %4.2f\n", ++i, stud.nume, stud.nota);
    fclose(f);//3. Inchiderea fisierului
}

void AdaugFis(){
    FILE *f;//0. Declararea unei variabile de tip pointer la fisier
    char rasp;
    Student stud;
    f = fopen(fisier, "ab");//1. Deschiderea fisierului binar pentru adaugare la sfarsit (datele existente NU se sterg)
    int i = 0;
    do{
        printf("Introduceti datele despre studentul nou %d\n", ++i);
        printf("Numele: "); scanf("%s", stud.nume);
        printf("Nota: "); scanf("%f", &stud.nota);
        fwrite(&stud, sizeof(Student), 1, f);//2. Scrierea datelor in fisierul binar
        printf("Doriti sa mai adaugati date despre studenti?[d/n]-> ");
        fflush(stdin);
        scanf("%c", &rasp);
    }while(rasp == 'd');
    printf("Datele despre %d studenti au fost adaugate in fisier!\n", i);
    fclose(f);//3. Inchiderea fisierului
}

int subMeniu(){
    printf("Dupa nume.....1\n");
    printf("Dupa nota.....2\n");
    printf("Renuntare.....0\n");
    int sm;
    scanf("%d", &sm);
    return sm;
}

void ElimStud(){
    int sm = subMeniu();
    char numeElim[20];
    float notaElim;
    FILE *f, *g;
    int elim = 0;//Initial nu avem studenti eliminati
    char *temp = "temp.dat";
    Student stud;

    if(sm == 1){
        printf("Introduceti numele studentilor care vor fi eliminati: ");
        scanf("%s", numeElim);
    }else if(sm == 2){
        printf("Introduceti nota studentilor care vor fi eliminati: ");
        scanf("%f", &notaElim);
    }else{
        printf("Nu eliminam nimic!\n");
        return;
    }

    f = fopen(fisier, "rb");//Deschidem fisierul initial pentru a citi din el
    if(f == NULL){
        printf("Fisierul nu exista! Mai intai creati-l!\n");
        return;
    }
    g = fopen(temp, "wb");//Deschidem fisierul temporar pentru a scrie in el studentii care nu sunt eliminati (care raman)

    while(fread(&stud, sizeof(Student), 1, f))//Citirea datelor din fisierul initial
        if(sm == 1 && strcmp(stud.nume, numeElim) != 0
        || sm == 2 && stud.nota != notaElim)//Daca studentul nu trebuie sa fie eliminat
            fwrite(&stud, sizeof(Student), 1, g);//il inscriem in fisierul temporar
        else
           elim = 1;//Avem studenti eliminati
    fclose(f);
    fclose(g);

    //AfisFis();

    if(elim == 0){//Daca nu avem studenti eliminati nu modificam fisierul initial
        printf("Nu am gasit studenti cu numele sau nota indicata! Nu eliminam nimic!\n");
        return;
    }
    //Daca am eliminat studenti
    f = fopen(temp, "rb");//Deschidem fisierul temporar pentru a a citi din el
    g = fopen(fisier, "wb");//Deschidem fisierul initial pentru scrie in el studentii care au ramas (care nu au fost eliminati)
    int i = 0;
    while(fread(&stud, sizeof(Student), 1, f)){//Citirea datelor din fisierul temporar
        //printf("%2d. %10s. Nota: %4.2f\n", ++i, stud.nume, stud.nota);
        fwrite(&stud, sizeof(Student), 1, g);//si scrierea lor in fisierul initial
    }
    fclose(f);
    fclose(g);
    if(sm == 1)
        printf("Studentii cu numele \"%s\" au fost eliminati din fisier!\n", numeElim);
    else
        printf("Studentii cu nota %4.2f au fost eliminati din fisier!\n", notaElim);

}

int Meniu(){
    if(firstRun)
        firstRun = 0;
    else{
        system("pause");
        system("cls");
    }
    printf("Creare fisier......................1\n");
    printf("Afisare fisier.....................2\n");
    printf("Adaugare in fisier.................3\n");
    printf("Eliminare student din fisier.......4\n");
    printf("Iesire din program.................0\n");
    int m;
    scanf("%d", &m);
    return m;
}



int main()
{
    int m;
    do{
        m = Meniu();
        switch(m){
            case 1: CreareFis(); break;
            case 2: AfisFis(); break;
            case 3: AdaugFis(); break;
            case 4: ElimStud(); break;
            case 0: printf("Autorul progmului este Mititelu Vitalii!\n"); break;
            default: printf("Optiune incorecta! Mai incercati o data!\n"); break;
        }
    }while(m != 0);

    return 0;
}
