#include <iostream>

using namespace std;

class FuzzyNumber{
    double e1, x, er;
public:
    void Set(double &a, double &ae){e1 = a - ae; x = a; er = a + ae;};
    void Show() {cout << "(" << e1 << ", " << x << ", " << er << ")";};
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
    temp.e1 = A.e1 + e1;
    temp.x = A.x + x;
    temp.er = A.er + er;
    return temp;
}

FuzzyNumber FuzzyNumber::operator-(FuzzyNumber A){
    FuzzyNumber temp;
    temp.e1 = e1 - A.er;
    temp.x = x - A.x;
    temp.er = er - A.e1;
    return temp;
}

FuzzyNumber FuzzyNumber::operator*(FuzzyNumber A){
    FuzzyNumber temp;
    temp.e1 = A.e1 * e1;
    temp.x = A.x * x;
    temp.er = A.er * er;
    return temp;
}

FuzzyNumber FuzzyNumber::operator/(FuzzyNumber A){
    FuzzyNumber temp;
    temp.e1 = e1 / A.er;
    temp.x = x / A.x;
    temp.er = er / A.er;
    return temp;
}

FuzzyNumber FuzzyNumber::Inverse(){
    FuzzyNumber temp;
    temp.e1 = 1 / er;
    temp.x = 1 / x;
    temp.er = 1 / e1;
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
