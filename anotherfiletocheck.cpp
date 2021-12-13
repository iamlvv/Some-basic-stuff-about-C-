#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* next = NULL;
};
struct LList {
    Node* head = NULL;
};
class Fraction {
private:
    int numerator, denominator;
    
public:
    Fraction() {
        this->numerator = 0;
        this->denominator = 0;
    }
    
    Fraction(int numerator, int denominator) {
        this->denominator = denominator;
        this->numerator = numerator;
    }
    
    Fraction(const Fraction& other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    int getNumerator() {
        return numerator;
    }
    void setNumerator(int numerator) {
        this -> numerator = numerator;
    }
    int getDenominator() {
        return denominator;
    }
    void setDenominator(int denominator) {
        this -> denominator = denominator;
    }
    Fraction getReciprocal() {
        int gcd = __gcd(this->numerator, this->denominator);
        int tu = this->denominator / gcd;
        int mau = this->numerator / gcd;
        return Fraction(tu, mau);
    }
    
    Fraction operator+(const Fraction& rhs) {
        int dem = this->denominator * rhs.denominator;
        int num = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
        int rgcd = __gcd(num, dem);
        dem = dem / rgcd;
        num  = num / rgcd;
        return Fraction(num, dem);
    }

    Fraction operator-(const Fraction& rhs) {
        int dem = this->denominator * rhs.denominator;
        int num = this->numerator * rhs.denominator - rhs.numerator * this->denominator;
        int check = __gcd(num, dem);
        dem = dem / check;
        num = num / check;
        return Fraction(num, dem);
    }

    Fraction operator*(const Fraction& rhs) {
        int dem = this->denominator * rhs.denominator;
        int num = this->numerator * rhs.numerator;
        int ucln = __gcd(num, dem);
        dem = dem / ucln;
        num = num / ucln;
        return Fraction(num, dem);
    }

    Fraction operator/(const Fraction& rhs) {
        int dem = this->denominator * rhs.numerator;
        int num = this->numerator * rhs.denominator;
        int ucln1 = __gcd(num, dem);
        dem = dem / ucln1;
        num = num / ucln1;
        return Fraction(num, dem);
    }
    Fraction operator=(const Fraction& rhs) {
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
        return *this;
    }

    void reduce() {
        int gcd = __gcd(this->numerator, this->denominator);
        this->numerator = this->numerator/ gcd;
        this->denominator = this->denominator / gcd;
    }
    void print() { 
        cout << this->numerator << "/" << this->denominator << endl; 
    }
};

int main() {
    Fraction a(1, 3);
Fraction b(2, 7);
Fraction c = a + b;
c.print();
    return 0;
}