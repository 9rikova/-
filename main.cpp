/*
Девятерикова Александра, М8О-201Б-18

Вариант 4: Реализовать класс FuzzyNumber для работы с нечеткими числами, которые представляются тройками
чисел (x – el, x, x + er ). Для чисел A = (A – al, A, A + ar) и B = (B – bl, B, B + br) арифметические операции
выполняются по следующим формулам:
- сложение A + B = (A + B – al – bl, A + B, A + B + ar + br);
- вычитание A – B = (A – B – al – bl, A – B, A – B + ar + br);
- умножение A · B = (A * B – B * al – A * bl + al * bl, A * B, A * B + B * al + A * bl + al * bl);
- обратное число A = (1 / (A + ar ), 1 / A, 1 / (A – al )), A > 0;
- деление A / B = ((A – al ) / (B + br ), A / B, (A + ar ) / (B – bl )), B > 0;
Считать el = er, то есть число представлено парой <x, e>.
Реализовать операции сравнения по х.
*/

#include <iostream>

using namespace std;

class FuzzyNumber{
    double el, x, er;
public:
    void Set(double &a, double &ae){el = a - ae; x = a; er = a + ae;};
    void Show() {cout << "(" << el << ", " << x << ", " << er << ")";};
    FuzzyNumber operator+(FuzzyNumber A);
    FuzzyNumber operator-(FuzzyNumber A);
    FuzzyNumber operator*(FuzzyNumber A);
    FuzzyNumber operator/(FuzzyNumber A);
    FuzzyNumber Inverse();
    bool operator>(FuzzyNumber A);
    bool operator<(FuzzyNumber A);
};

FuzzyNumber FuzzyNumber::operator+(FuzzyNumber A){
    FuzzyNumber temp;
    temp.el = A.el + el;
    temp.x = A.x + x;
    temp.er = A.er + er;
    return temp;
}

FuzzyNumber FuzzyNumber::operator-(FuzzyNumber A){
    FuzzyNumber temp;
    temp.el = el - A.er;
    temp.x = x - A.x;
    temp.er = er - A.el;
    return temp;
}

FuzzyNumber FuzzyNumber::operator*(FuzzyNumber A){
    FuzzyNumber temp;
    temp.el = A.el * el;
    temp.x = A.x * x;
    temp.er = A.er * er;
    return temp;
}

FuzzyNumber FuzzyNumber::operator/(FuzzyNumber A){
    FuzzyNumber temp;
    temp.el = el / A.er;
    temp.x = x / A.x;
    temp.er = er / A.er;
    return temp;
}

FuzzyNumber FuzzyNumber::Inverse(){
    FuzzyNumber temp;
    temp.el = 1 / er;
    temp.x = 1 / x;
    temp.er = 1 / el;
    return temp;
}

bool FuzzyNumber::operator>(FuzzyNumber A){
    return (x > A.x);
}

bool FuzzyNumber::operator<(FuzzyNumber A){
    return (x < A.x);
}

void Read2(FuzzyNumber &A, FuzzyNumber &B){
    double a, ae, b, be;
    cout << "Enter the first fuzzy number (as pair): ";
    cin >> a >> ae;
    A.Set(a, ae);
    cout << "Enter the second fuzzy number (as pair): ";
    cin >> b >> be;
    B.Set(b, be);
}

void Menu(){
    cout << "\n\tMENU" << endl
         << "1. Sum of numbers" << endl
         << "2. Subtraction of numbers" << endl
         << "3. Multiplication of numbers" << endl
         << "4. Division of numbers" << endl
         << "5. Find the inverse number" << endl
         << "6. Compare numbers" << endl
         << "7. Menu" << endl
         << "0. Exit" << endl;
}

int main(){
    FuzzyNumber A, B, C;
    double a, ae, b, be;
    int user_command = 7;
    while (user_command){
        switch (user_command){
        case 1:
            Read2(A, B);
            C = A + B;
            C.Show();
            break;
        case 2:
            Read2(A, B);
            C = A - B;
            C.Show();
            break;
        case 3:
            Read2(A, B);
            C = A * B;
            C.Show();
            break;
        case 4:
            cout << "Enter the first fuzzy number (as pair): ";
            cin >> a >> ae;
            A.Set(a, ae);
            cout << "Enter the second fuzzy number (as pair): ";
            cin >> b >> be;
            if(b<=0){
                cerr << "ERROR: the second number must be positive";
                break;
            }
            B.Set(b, be);
            C = A / B;
            C.Show();
            break;
        case 5:
            cout << "Enter the fuzzy number (as pair): ";
            cin >> a >> ae;
            if (a<=0){
                cerr << "ERROR: number must be positive";
                break;
            }
            A.Set(a, ae);
            A = A.Inverse();
            A.Show();
            break;
        case 6:
            Read2(A, B);
            if (A > B){
                A.Show();
                cout << " > ";
                B.Show();
                break;
            }else if (A < B){
                A.Show();
                cout << " < ";
                B.Show();
                break;
            }else{
                A.Show();
                cout << " = ";
                B.Show();
                break;
            }
        case 7:
            Menu();
            break;
        default:
            cerr << "ERROR: wrong command" << endl;
            break;
        }
        cout << "\nEnter command number: ";
        cin >> user_command;
    }
}
