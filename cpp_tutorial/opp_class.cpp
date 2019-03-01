//
// Created by Lian, Peng on 2019-02-27.
//

#include "opp_class.h"  // header in local directory
#include <iostream>     // header in standard library

using namespace T;
using namespace std;


/*
 * 1) Constructor
 *  a. constructor has the same name with the class
 *  b. constructor doesn't have a return type, member function has
 *  c. constructor is automatically called
 *  d. if constructor is missing, compiler will generate it
 *  e. parameterized constructor allows to pass arguments while obj creation
 *
 * 2) Destructor
 *  a. has the same name with class, but with a tilde sign (~) in front.
 *  b. only one in the class
 *  c. do not allow parameters
 *  d. no return type
 */

// constructor of class Demo
Demo::Demo(int num, char ch1){
    cout << "This is the constructor of Demo" << endl;
    this->num = 1;
    this->ch1 = 'B';
}

// member funcs in class Demo
void Demo::setMyValues(int num, char ch1) {
    this->num = num;
    this->ch1 = ch1;
}

// member funcs in class Demo
void Demo::displayValues() {
    cout << "Num: " << num << endl;
    cout << "Char: " << ch1 << endl;
}

// destructor of class Demo
Demo::~Demo() {
    cout << "This is the destructor of Demo" << endl;

}




// constructor of Math
Math::Math() {
    cout << "Welcome to use the Math module!" << endl;
}

float Math::ADD(float num1, float num2){
    return num1 + num2;
}

float Math::ADD(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}


Math1::Math1(){
    cout << "Welcome to use the Math1 module!" << endl;
}

float Math1::MULTIPLY(float num1, float num2) {
    return num1 * num2;
}

float Math1::SUM(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}



// a function to assign value to the structure
RGB T::setRGB(short r, short g, short b) {
    RGB s;
    s.r = r;
    s.g = g;
    s.b = b;
    return s;
}
// a function to print the structure
void T::printRGB(RGB s1){
    cout << "printRGB: " << s1.r << " " << s1.g << " " << s1.b << endl;
};

// constructor of display
display::display(){
}

void display::show(std::vector<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}

void display::show(std::deque<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}

void display::show(std::list<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}

void display::show(std::map<std::string, std::string> l){
    //for (auto const i : l) cout << i << " ";
    for (std::map<string, string>::iterator it = l.begin(); it != l.end(); it++ ){
        cout << it->first << " : " << it->second << endl;
    }
}

void display::show(std::set<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}


// for eight queens problem
eightQ::eightQ(){
    // constructor
}

void eightQ::showSolution() {
    for (int i=0; i<8; i++){
        printf("Occupied postions are: %d, %d\n", this->ROW[i], this->COL[i]);
    }
}

bool eightQ::testSolution(int col[8], int row[8]){
    // given a solution, test it is validate or not
    int results[8] = {};
    bool pass = false;

    for (int i=0; i<8; i++){
        int c = col[i];
        int r = row[i];

        // check against other queens
        int check[8] = {};
        for (int j=0; j<8; j++){
            if (j!=i){
                if (c==col[j]||r==row[j]||abs(c-col[j])==abs(r-row[j])){
                    //pass = false;
                    check[j] = 0;
                    break;
                } else {
                    //pass = true;
                    check[j] = 1;
                }
            }
        }

        // sum the results
        int Rc=0;
        for (auto i: check) Rc+=i;

        // if no confict with others, this queen is ok.
        if (Rc==7){
        results[i] = 1;
        } else {
        results[i] = 0;
        }
    }


    // sum the results
    int R=0;
    for (int i=0; i<8; i++){
        R += results[i];
    }

    // if all queens are no confictions, this solution is ok.
    if (R==8){
        return true;
    } else {
        return false;
    }
}

void eightQ::findSolutions(){
    // init the columns
    for (int i=0; i<8; i++){
        this->COL[i] = i;
    }

    printf("All the solutions for 8 Queens problem are:\n");

    // generate all the possible solutions.
    for (int i0=0; i0<8; i0++){
    for (int i1=0; i1<8; i1++){
    for (int i2=0; i2<8; i2++){
    for (int i3=0; i3<8; i3++){
    for (int i4=0; i4<8; i4++){
    for (int i5=0; i5<8; i5++){
    for (int i6=0; i6<8; i6++){
    for (int i7=0; i7<8; i7++){
        this->ROW[0] = i0;
        this->ROW[1] = i1;
        this->ROW[2] = i2;
        this->ROW[3] = i3;
        this->ROW[4] = i4;
        this->ROW[5] = i5;
        this->ROW[6] = i6;
        this->ROW[7] = i7;

        if (this->testSolution(this->COL, this->ROW)){
            printf("%d,%d,%d,%d,%d,%d,%d,%d\n",ROW[0],ROW[1],ROW[2],ROW[3],ROW[4],ROW[5],ROW[6],ROW[7]);
        }
    }
    }
    }
    }
    }
    }
    }
    }
}












