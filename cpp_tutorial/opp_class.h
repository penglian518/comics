//
// Created by Lian, Peng on 2019-02-27.
//

#ifndef UNTITLED_OPP_CLASS_H
#define UNTITLED_OPP_CLASS_H

namespace T {

    // class Demo
    class Demo {
    private:
        int num;
        char ch1;
    public:
        // constructor of Demo
        Demo(int num=0, char ch1='A');

        // member functions
        void setMyValues(int num, char ch1);
        void displayValues();
        int getNum(){ return num;};
        char getChar(){ return ch1;};

        // destructor of Demo
        ~Demo();
    };



    // class Math
    class Math {
    private:
        float num1;
        float num2;
        float num3;

    public:
        // constructor
        Math();
        // member func
        float ADD (float num1, float num2);             // ADD func
        float ADD (float num1, float num2, float num3); // polymorphism of ADD func, both 2 or 3 numbers will work.

        friend class Math1;                             // friend allows class Math1 to access to the private data

    };


    // Math1 is a class that inheritance from Math
    class Math1 : public Math {

    public:
        // constructor
        Math1();
        // member function
        float MULTIPLY (float num1, float num2);
        float SUM(float num1, float num2, float num3);

    };


    // structure
    struct RGB {
        short r{0};
        short g{0};
        short b{0};
    };

    // a function to assign value to the structure
    RGB setRGB(short r, short g, short b);
    // a function to print the structure
    void printRGB(RGB s1);

    // enumeration
    enum direction {East, West, North, South};

}
#endif //UNTITLED_OPP_CLASS_H