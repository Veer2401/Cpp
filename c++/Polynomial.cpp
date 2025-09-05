#include <iostream>
using namespace std;

struct Poly{
    int exp,coef;
};

void addPoly(Poly p1[], Poly p2[], Poly p3[]){
    int i=0,j=0,k=0;

    while(p1[i].exp != -1 || p2[j].exp != -1){
        if(p1[i].exp > p2[j].exp){
            p3[k].exp = p1[i].exp;
            p3[k].coef = p1[i].coef;
            i++;
            k++;
        } else if(p1[i].exp < p2[j].exp) {
            p3[k].exp = p2[j].exp;
            p3[k].coef = p2[j].coef;
            j++;
            k++;
        }
        else {
            int sum = p1[i].coef + p2[j].coef;

            if(sum != 0){
                p3[k].coef = sum;
                p3[k].exp = p1[i].exp;
                k++;
            }
            i++;
            j++;
        }
    }
    p3[k].exp = -1;
}


int main() {
    Poly p1[50], p2[50], p3[50];
    int n1, n2;

    
    cout << "Enter number of terms in first polynomial: ";
    cin >> n1;
    cout << "Enter exponent and coefficient for each term (in decreasing order of exponents):\n";
    for (int i = 0; i < n1; i++) {
        cout << "Term " << i + 1 << " (exp coef): ";
        cin >> p1[i].exp >> p1[i].coef;
    }
    p1[n1].exp = -1;

    
    cout << "\nEnter number of terms in second polynomial: ";
    cin >> n2;
    cout << "Enter exponent and coefficient for each term (in decreasing order of exponents):\n";
    for (int i = 0; i < n2; i++) {
        cout << "Term " << i + 1 << " (exp coef): ";
        cin >> p2[i].exp >> p2[i].coef;
    }
    p2[n2].exp = -1;

   
    addPoly(p1, p2, p3);

    cout << "\nResultant polynomial: ";
    for (int i = 0; p3[i].exp != -1; i++) {
        cout << p3[i].coef << "x^" << p3[i].exp;
        if (p3[i + 1].exp != -1) {
            cout << " + ";
        }
    }
    cout << endl;

    return 0;
}