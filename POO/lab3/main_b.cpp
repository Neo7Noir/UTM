#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
    string *our_string;
public:
    MyString() {
        our_string = new string;
        cout << "Enter your string->";
        cin >> *our_string;
    }

    MyString(string value = "") {
        our_string = new string;
        if (value == "") {
            cout << "Enter your string->";
            cin >> *our_string;
        } else {
            *our_string = value;
        }
    }


    void print() {
        cout << "Your string->" << *our_string << endl;
    }

//      Supraincarcarea operatorului (=)
    MyString &operator=(const MyString &i) {
        if (our_string != nullptr) {
            delete our_string;
        }
        this->our_string = new string;
        string temp = *i.our_string;
        *this->our_string = temp;
        return *this;
    }
//      Supraincarcarea operatorului (+=)

    MyString &operator+=(const MyString &i) {
        string temp1 = *this->our_string, temp2 = *i.our_string;
        if (our_string != nullptr) {
            delete our_string;
        }
        this->our_string = new string;
        *this->our_string = temp1 + temp2;
        return *this;
    }


//      Supraincarcarea operatorului(+) Posibil scurgere de memorie
//      deoarece cand returnam se activeaza destructorul si ne
//      sterge valorile.

    MyString &operator+(const MyString &i) {
        MyString temp_str("-");
        *temp_str.our_string = *our_string + *i.our_string;
        return temp_str;
    }


//      Supraincarcarea operatorului (==)

    bool operator==(const MyString &i) {
        if (*this->our_string == *i.our_string)  return true;
        else  return false;
    }


//      Supraincarcarea operatorului (!=)
//      returneaza un bool

    bool operator!=(const MyString &i) {
        if (*this->our_string != *i.our_string) return false;
        else  return true;
    }

//      Supraincarcarea operatorului (<)

    bool operator<(const MyString &i) {
        if (*this->our_string < *i.our_string) return true;
        else  return false;
    }


//      Supraincarcarea operatorului (>)

    bool operator>(const MyString &i) {
        if (*this->our_string > *i.our_string) return false;
        else  return true;
    }


//      Supraincarcarea operatorului ([])
    char operator[](int index) {
        string temp = *this->our_string;
        int len_string;
        if (index <= this->our_string->length()) {
            return temp[index - 1];
        } else {
            return '0';
        }
    }


//      Supraincaracarea operatorului de iesire a datelor
//      cu ajutorul functii prietene.
    friend ostream &operator<<(ostream &out, MyString a);

//      Supraincaracarea operatorului de intrare a datelor
//      cu ajutorul functii prietene.
    friend istream &operator>>(istream &in, MyString &a);
};

istream &operator>>(istream &in, MyString &a) {
    cout << "Enter string->";
    in >> *a.our_string;
    return in;
}

ostream &operator<<(ostream &out, MyString a) {
    out << *a.our_string << "\n";
    return out;
}


int main() {
    MyString first("ThisIsFirstObj"), second("ThisIsSecondObj");
//    cout<<t;

//      Exemple de supraincarcarea o operatorilor binari.
    if (first == second)
        cout << "Objects are similar" << endl;
    else
        cout << "The objections are different." << endl;

//      Inca un exemplu dar cu negatie.
    if (first != second)
        cout << "The objections are different." << endl;
    else
        cout << "The objects are the same" << endl;

//    Opearatori mai mare mic
    if (first > second) // aici putem verifica inversul. Schimband in loc de '<' '>'
        cout << "First Obj is larger. " << endl;
    else
        cout << "Second Obj is large" << endl;

//    Operatori de esire si intrare.
    cout << "First Obj->" << first;      //exit
    cout << "Second Obj->" << second;     //exit
    cin >> first;             //input
    cin >> second;            //input
//    Verificarea operatorului de indexare.
    int index = 3;
    char temp = first[index];
    cout << "Index " << index << " element in FirstObj->" << temp << endl;
//      Operatorul +=
    MyString result("SoThisIsResult");
    result += first;
    cout << "This is result after result+=first\t" << result;
//      Operatorul (=) atentie este posibila
//      scurgere de memorie
    result = second;
    cout << "This is result after result=second\t" << result;
    return 0;
}

