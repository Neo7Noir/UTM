#include <iostream>
#include <string>

using namespace std;
class Registru;
class Student{
private:
    string first_name;
    string last_name;
    int age;
public:
    friend Registru;
    friend void add_students(Registru &other);
    friend ostream &operator<<(ostream &out,const Registru &other);
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
    Registru(string grup,int nr_student){
        grupa = grup;
        nr_studenti=nr_student;
        arr_students = new Student[nr_studenti];
    }
    void print(){
        cout << "Group :"<<grupa<<endl;
        cout<<"Nr students(in reg):"<< nr_studenti<<endl;
        for (int i =0 ;i<nr_studenti;i++){
            cout<<"First name:"<<arr_students[i].first_name<<endl;
            cout<<"Last name:"<<arr_students[i].last_name<<endl;
            cout<<"Age:"<<arr_students[i].age<<endl;
            cout<<"---------------------------------------------"<<endl;
        }

    }
    // Seminar 2
    Registru operator+(const Registru &other){
        Registru temp(this->grupa+other.grupa,this->nr_studenti+other.nr_studenti );
        temp.arr_students = new Student[nr_studenti];
        for (int i = 0 ;i<nr_studenti;i++){
            temp.arr_students[i].first_name=other.arr_students[i].first_name+this->arr_students[i].first_name;
            temp.arr_students[i].last_name=other.arr_students[i].last_name+this->arr_students[i].last_name;
            temp.arr_students[i].age=other.arr_students[i].age+this->arr_students[i].age;
        }
        return temp;
    }
    //Seminarul 3
    bool operator==(const Registru &other){
        if (this->grupa==other.grupa)
            if (this->nr_studenti==other.nr_studenti)
                for (int i = 0; i<nr_studenti;i++){
                    if (this->arr_students[i].first_name==other.arr_students[i].first_name)
                        if (this->arr_students[i].last_name==other.arr_students[i].last_name)
                            if (this->arr_students[i].age==other.arr_students[i].age)
                                return true;
                }
        return false;
    }
    bool operator!=(const Registru &other){
        if (this->grupa!=other.grupa)
            if (this->nr_studenti!=other.nr_studenti)
                for (int i = 0; i<nr_studenti;i++){
                    if (this->arr_students[i].first_name!=other.arr_students[i].first_name)
                        if (this->arr_students[i].last_name!=other.arr_students[i].last_name)
                            if (this->arr_students[i].age!=other.arr_students[i].age)
                                return true;
                    }
        return false;

        }
    friend ostream &operator<<(ostream &out,const Registru &other);
    // Seminar 1
    friend void add_students(Registru &other);
};
//Seminar 1
void add_students(Registru &other){
    for (int i=0;i<other.nr_studenti;i++){
        cout<<"Student->"<<i+1<<endl;
        cout<<"Enter first name:";
        cin>>other.arr_students[i].first_name;
        cout<<"Enter last name:";
        cin>>other.arr_students[i].last_name;
        cout<<"Enter age:";
        cin>>other.arr_students[i].age;
    }
}
//Seminar 2
ostream &operator<<(ostream &out,const Registru &other){
    out<<other.grupa<<","<<other.nr_studenti<<endl;
    for (int i = 0; i<other.nr_studenti;i++ ){
        out<<other.arr_students[i].first_name<<","<<other.arr_students[i].last_name<<","<<other.arr_students[i].age;
    }
    return out;
}
int main() {
    Registru reg1("SI-211", 1),reg2("SI-212",1);
    add_students(reg1);
//    add_students(reg1);
//    add_students(reg2);
//    reg1.print();
//    reg1=reg1+reg2;
//    reg1.print();
    cout<<reg1;
    return 0;
}
