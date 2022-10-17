#include <iostream>
#include <string>

using namespace std;
class Registru;
class Student{
private:
    string nume;
    string prenume;
    int varsta;
public:
    friend Registru;
    friend void add_students(Registru &other);
    //friend ostream &operator<<(ostream &out, const Registru &other); //sem2
};

class Registru{
private:
    string grupa;
    int nr_studenti;
    Student *arr_students;
public:
    Registru(){
        grupa="NONE";
        nr_studenti = 0;
        arr_students = new Student[nr_studenti];
    }
    Registru(string grup, int nr_student){
        grupa = grup;
        nr_studenti=nr_student;
        arr_students = new Student[nr_studenti];
    }

    void afisare(){
        cout << "Grupa: "<<grupa<<endl;
        cout<<"Nr studenti:"<< nr_studenti<<endl;
        for (int i =0 ;i<nr_studenti;i++){
            cout<<"Numele:"<<arr_students[i].nume<<endl;
            cout<<"Prenumele:"<<arr_students[i].prenume<<endl;
            cout<<"Varsta:"<<arr_students[i].varsta<<endl;
            cout<<"---------------------------------------------"<<endl;
        }

    }
    //Seminar 2
    Registru operator+(const Registru &other){
        Registru temp(this->grupa+other.grupa,this->nr_studenti+other.nr_studenti);
        temp.arr_students = new Student[nr_studenti];
        for (int i = 0 ;i<nr_studenti;i++){
            temp.arr_students[i].nume=this->arr_students[i].nume+other.arr_students[i].nume;
            temp.arr_students[i].prenume=this->arr_students[i].prenume+other.arr_students[i].prenume;
            temp.arr_students[i].varsta=this->arr_students[i].varsta+other.arr_students[i].varsta;
        }
        return temp;
    }

    // Seminar 1
    friend void add_students(Registru &other);
    // Seminar 2
    //friend ostream &operator<<(ostream &out,const Registru &other);

    //Seminarul 3
    bool operator==(const Registru &other){
        if (this->grupa==other.grupa)
            if (this->nr_studenti==other.nr_studenti)
                for (int i = 0; i<nr_studenti;i++){
                    if (this->arr_students[i].nume==other.arr_students[i].nume)
                        if (this->arr_students[i].prenume==other.arr_students[i].prenume)
                            if (this->arr_students[i].varsta==other.arr_students[i].varsta)
                                return true;
                }
        return false;
    }

    bool operator!=(const Registru &other){
        if (this->grupa!=other.grupa)
            if (this->nr_studenti!=other.nr_studenti)
                for (int i = 0; i<nr_studenti;i++){
                    if (this->arr_students[i].nume!=other.arr_students[i].nume)
                        if (this->arr_students[i].prenume!=other.arr_students[i].prenume)
                            if (this->arr_students[i].varsta!=other.arr_students[i].varsta)
                                return true;
                }
        return false;

    }
};
//Seminar 1
void add_students(Registru &other){
    for (int i=0;i<other.nr_studenti;i++){
        cout<<"Student->"<<i+1<<endl;
        cout<<"Introduceti numele:";
        cin>>other.arr_students[i].nume;
        cout<<"Introduceti prenumele:";
        cin>>other.arr_students[i].prenume;
        cout<<"Introduceti varsta:";
        cin>>other.arr_students[i].varsta;
    }
}
//Seminar 2
// ostream &operator<<(ostream &out,const Registru &other){
//     out<<"Grupa: "<<other.grupa<<endl<<"Nr studenti: "<<other.nr_studenti<<endl;
//     for (int i = 0; i<other.nr_studenti;i++){
//         out<<"Numele: "<<other.arr_students[i].nume<<endl<<"Prenumele: "<<other.arr_students[i].prenume<<endl<<"Varsta: "<<other.arr_students[i].varsta<<endl;
//     }
//     return out;
// }

int main() {
    Registru reg1("SI-211", 2), reg2("TI-214", 2);
    add_students(reg1);
    add_students(reg2);
    reg1=reg1+reg2;
//    reg1.afisare();
    cout<<reg1;
    cout<<reg1!=reg2;
    return 0;
}