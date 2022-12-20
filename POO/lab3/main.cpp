#include <iostream>
#include <string>

using namespace std;

class Date {
public:
    int an, luna, zi;

    Date(int a = 0, int b = 0, int c = 0) {
        an = a;
        luna = b;
        zi = c;
    }
    bool chek_bisect(){
        if(an % 400 == 0) return true;
        else if(an % 100 == 0) return false;
        else if(an % 4 == 0) return true;
        else return false;
    }
    friend const Date &operator++(Date &i);

    friend const Date operator++(Date &i, int);

    friend const Date &operator--(Date &i);

    friend const Date operator--(Date &i, int);

    Date operator+(const Date &other) {
        Date temp;
        temp.an = this->an + other.an;
        temp.luna = this->luna + other.luna;
        temp.zi = this->zi + other.zi;
        return temp;
    }

    Date operator-(const Date &other) {
        Date temp;
        temp.an = this->an - other.an;
        temp.luna = this->luna - other.luna;
        temp.zi = this->zi - other.zi;
        return temp;
    }

    void display() {
        cout << "Anul ="<<an<<endl << "Luna =" << luna <<endl<< "Zi =" << zi << endl;
    }
};
const Date operator--(Date &i,int){
    Date oldValue(i.an, i.luna,i.zi);
    i.zi--;
    i.an--;
    i.luna;
    return oldValue;
}


const Date& operator--(Date &i){
    i.an--;
    i.zi--;
    i.luna;
    return i;
}


const Date operator++(Date &i, int) {
    Date oldValue(i.an, i.luna, i.zi);
    i.zi++;
    i.an++;
    i.luna++;
    return oldValue;
}

const Date &operator++(Date &i) {
    i.an++;
    i.luna++;
    i.zi++;
    return i;
}

int main() {
    Date first(2001, 4, 12), second(2003, 5, 9);
    Date resul =first.operator+(second);
    resul=resul+4;
    resul.display();
    bool check=resul.chek_bisect();
    if (check == true){
        cout << "Anul este bisect";
    }
    else cout<<"Anul nu este bisect";
    return 0;
}
