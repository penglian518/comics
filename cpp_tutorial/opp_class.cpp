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

