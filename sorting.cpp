#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Complex {
    private: 
    double real, fake;
    public:
    Complex(double real = 0.0, double fake = 0.0) {
        this->real = 0;
        this->fake = 0;
    }
    Complex(int first, int second) {
        this->real = first;
        this->fake = second;
    }
    double getModulus() {
        return sqrt(this->real * this->real + this->fake * this->fake);
    }
    // string toString() {
        
    //     string ans;
    //     if (this->real == 0 && this->fake == 0) ans = to_string(0);
    //     if (this->real)
    // }
    bool operator>(Complex& x) {
        return this->getModulus() > x.getModulus();
    }
    bool operator>=(Complex& x) {
        return this->getModulus() >= x.getModulus();
    }
    bool operator<(Complex& x) {
        return this->getModulus() < x.getModulus();
    }
    bool operator==(Complex& x) {
        return this->getModulus() == x.getModulus();
    }
    bool operator!=(Complex& x) {
        return this->getModulus() != x.getModulus();
    }
    bool operator<=(Complex& x) {
        return this->getModulus() > x.getModulus();
    }
};
class StraightSelectionSort : public Complex {
    public:
    static void swap(Complex& x, Complex &y) {
        Complex temp = x;
        x = y;
        y = temp;
    }
    static void sort(Complex *list, int length) {
        int current  = 0;
        while (current < length) {
            int min = current;
            int step = current + 1;
            while (step < length) {
                if (list[step] < list[min]) {
                    min = step;
                }
                step += 1;
            }
            swap(list[current], list[min]);
            current += 1;
        }
    }
    static void sort(Complex *list, int length, int left, int right) {
        int current  = left;
        while (current <= right) {
            int min = current;
            int step = current + 1;
            while (step <= right) {
                if (list[step] < list[min]) {
                    min = step;
                }
                step += 1;
            }
            swap(list[current], list[min]);
            current += 1;
        }
    }
};
class StraightInsertSort : public Complex {
    static void sort(Complex *list, int length, int left, int right) {
        if (right > 1) {
            int current = left + 1;
            while (current <= right) {
                Complex temp = list[current];
                int step = current - 1;
                while (step >= 0 && temp < list[step]) {
                    list[step + 1] = list[step];
                    step -= 1;
                }
                list[step + 1] = temp;
                current += 1;
            }
        }
    }
    static void sort(Complex *list, int length) {
        if (length > 1) {
            int current = 1;
            while (current < length) {
                Complex temp = list[current];
                int step = current - 1;
                while (step >= 0 && temp < list[step]) {
                    list[step + 1] = list[step];
                    step -= 1;
                }
                list[step + 1] = temp;
                current += 1;
            }
        }
    }
};
class BubbleSort : public Complex {
    static void swap(Complex& x, Complex &y) {
        Complex temp = x;
        x = y;
        y = temp;
    }
    static void sort(Complex *list, int length) {
        int current = 0;
        bool flag = false;
        while (current < length && flag == false) {
            int step = length - 1;
            flag = true;
            while (step > current) {
                if (list[step] < list[step - 1]) {
                    flag = false;
                    swap(list[step], list[step - 1]);
                }
                step -= 1;
            }
            current += 1;
        }
    }
    static void sort(Complex *list, int length, int left, int right) {
        int current = left;
        bool flag = false;
        while (current < right + 1&& flag == false) {
            int step = right;
            flag = true;
            while (step > current) {
                if (list[step] < list[step - 1]) {
                    flag = false;
                    swap(list[step], list[step - 1]);
                }
                step -= 1;
            }
            current += 1;
        }
    }
};
class ShellSort : public Complex {
    public:
    ShellSort(int *increments, int lengthOfIncrements) {

    }
    static void sortSegment(Complex *list, int length, int increment, int segment = 0) {

    }
    void sort(Complex *list, int length) {

    }
};
int main() {
    Complex *list;
    int length;
    ShellSort::sortSegment(list, length, 4, 0);
ShellSort::sortSegment(list, length, 4, 1);
ShellSort::sortSegment(list, length, 4, 2);
ShellSort::sortSegment(list, length, 4, 3);
return 0;
}