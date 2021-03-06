#include "opp_class.h"
#include <iostream> // include iostream file. (pre-defined input/output functions )
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>

/*
 * https://beginnersbook.com/2017/08/c-plus-plus-tutorial-for-beginners/
 */

// namespace
using namespace T;
using namespace std;

// global variables
char gVar = 'A';


char myFunc(char gVar = 'B') {
    //char gVar = 'B';
    return gVar;
}

/*
 * 9) functions
 *      return_type function_name (parameters) {
 *          ...
 *      }
 *
 *      if defining func before main(), no need to do declaration;
 *      if defining after main(), have to declare the function first!
 */

// Declearing the function sum
int sum(int, int);

// Factorial function for testing recursive function
int factorial(int n){
    if (n<=1){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}


// the main function. 'int' means it will return an integer. That's why should return 0 at the end.
int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << "Display me!"; // cout - an object belongs to iostream, which displays the content between double quotes.
    cout << "Global variables: " << gVar << endl;
    char gVar = 'Z';
    cout << "Changed global variables: " << gVar << endl;
    cout << "Changed global variables by functions: " << myFunc('C') << endl;


    /* 1) declaring variables
     *
     * data_type v1=xx, v2=xx;
     *      or
     * data_type v1, v2;
     * v1 = xx;
     * v2 = xx;
     *
     *
     * 2) Data types
     *      Built in data types:
     *          int, char, bool, double, float
     *      User-defined data types:
     *          struct, union, enum
     *      Derived data types:
     *          Array, Function; Pointer
     *
     * 3) Operators
     *      + - * / % = += -= /= %= ++ --
     *      && || ! == != > < >= <=
     *
     * 4) Six bitwise operators:
     *      & compare bits, equal -> 1, else -> 0
     *      | compare bits, either bit is 1 -> 1, else ->0
     *      ^ compare bits, not equal ->1, else ->0
     *      ~ change bits, 1 -> 0, 0 -> 1
     *      << shift bits to left, remove left most and add 0 at the end
     *      >> shift bits to right, remove the end bit and add 0 at the left
     *
     * 5) Ternary operator:
     *      variable num1 = (expression) ? v1 : v2
     *      if the expression result is true, num1 = v1, else num1 = v2
     *
     */
    int num1=20, num2 = 90;
    float num3 = 20.3;      // single precision, 4 bytes
    double num4 = 20.909; // double precision, 8 bytes
    cout << "num1 + num3 = " << (num1+num3) << endl;

    bool a = true;
    bool b = false;
    cout << "a||b: " << (a||b) << endl;

    int num5 = 11; // 11 = 00001011
    int num6 = 22; // 22 = 00010110
    cout << "num5 & num6: " << (num5 & num6) << endl;
    cout << "num5 | num6: " << (num5 | num6) << endl;
    cout << "num5 ^ num6: " << (num5 ^ num6) << endl;
    cout << "~num5 : " << (~num5) << endl;
    cout << "num5 << 2 : " << (num5 << 2) << endl;
    cout << "num5 >> 2 : " << (num5 >> 2) << endl;


    cout << "num1: " << num1 << "; num2: " << num2 << endl;
    int num7 = (num1 < num2) ? 100 : 200;
    cout << "num7: " << num7 << endl;
    num7 = (num1 > num2) ? 100 : 200;
    cout << "num7: " << num7 << endl;


    /*
     * 6) if statement
     *   a. if (conditions) {
     *          ...
     *      };
     *
     *   b. if (conditions) {
     *          ...
     *      } else {
     *          ...
     *      };
     *
     *   c. if (condition 1) {
     *          ...
     *      } else if (condition 2) {
     *          ...
     *      } else {
     *          ...
     *      };
     *
     *  7) switch (variable or integer expression) {
     *      case constant:
     *          ...
     *          break;
     *      case constant:
     *          ...
     *          break;
     *      default:
     *          ...
     *  };
     */

    if (num1 > num2) {
        cout << "num1 > num2" << endl;
    } else if (num1 == num2) {
        cout << "numb1 == num2 " << endl;
    } else {
        cout << "numb1 < num2 " << endl;
    };


    int i = 2;
    switch (i+1) {
        case 1: cout << "Case 1" << endl; break;
        case 2: cout << "Case 2" << endl; break;
        case 3: cout << "Case 3" << endl; break;
        case 4: cout << "Case 4" << endl; break;
        default: cout << "Default " << endl;
    };


    /*
     * 8) loop
     *    a. for loop
     *       for (init; condition; increment/decrement) {
     *          ...
     *       }
     *       NOTE: It's possible to omit any or all the expressions, but should keep the ";"!
     *
     *    b. while loop
     *       init;
     *       while (condition) {
     *            ...
     *            increment/decrement
     *       }
     *
     *    c. do while loop
     *       do {
     *          ...
     *       } while (condition);
     *
     *    d. continue/break
     *
     *    e. goto (don't use this one)
     *
     *    f. range based for loop
     *      for (range_declaration : range_expression) loop_statement
     *
     */

    /* 10) Multidimensional arrary
    *   int arr[2][3];    // 2*3 elements, 2 rows, 3 columns
    */

    // declear an array, with/without array size are OK.
    int arr[] = {21, 9, 10, 99, 201};
    //int arr[5] = {21, 9, 10, 99, 201};

    //int marr[2][3] = {10, 11, 12, 13, 14, 15};
    int marr[2][3] = {{10, 11, 12}, {13, 14, 15}}; // both ways work

    // vector
    cout << "\n...............Test for std::vector...............\n";

    display prt;                                            // use homemade func to show the variables

    std::vector<int> v1;
    std::vector<int> v2 = {1,2,3,4};                        // init vector

    cout << "The original v2 is: " << endl;
    //for (auto const &i : v2) cout << i << " ";              // iterate with range based for loop
    //cout << endl;
    prt.show(v2);

    int head = v2.front();                                  // 1st element
    int tail = v2.back();                                   // last element

    v2.insert(v2.begin(), 0);                               // insert to head
    v2.insert(v2.begin()+3, 7);                             // insert to 4th position
    v2.push_back(8);                                        // insert to back
    cout << "After insert at begin and push back: " << endl;
    //for (auto const &i : v2) cout << i << " ";              // iterate with range based for loop
    //cout << endl;
    prt.show(v2);

    v2.erase(v2.begin()+3);                                 // erase 4th element
    v2.pop_back();                                          // erase last element
    //for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++){ // iterate with iterator
    //    cout << *it << " ";
    //}
    //cout << endl;
    prt.show(v2);


    v2[1] = 3;
    v2[4] = 2;                                              // vector not automatically resize!
    cout << "The length of v2 is: " << v2.size() << endl;
    cout << "The capacity of v2 is: " << v2.capacity() << endl;
    //for (auto const &i: v2)
    //    cout << i << " ";
    //cout << endl;
    prt.show(v2);

    v2.resize(10);                                           // resize by hand, resize will add 0s
    v2[4] = 2;
    cout << "The length of v2 is: " << v2.size() << endl;
    cout << "The capacity of v2 is: " << v2.capacity() << endl;
    //for (auto const &i: v2)
    //    cout << i << " ";
    //cout << endl;
    prt.show(v2);

    // Deque (Double end queue)
    cout << "\n...............Test for std::deque...............\n";
    std::deque<int> d = {1,2,3,4};
    d.push_front(0);                                         //similar to vector, but has push_front
    d.push_front(1);                                         // and pop_front
    d.pop_front();
    d.insert(d.begin()+3, 9);
    //for (auto const &i : d) cout << i << " ";
    //cout << endl;
    prt.show(d);


    // list
    cout << "\n...............Test for std::list...............\n";
    std::list<int> l = {1,3,3,3,2,4};
    std::list<int> l2 = {9,7,8,5,3,2,1, 11};
    l.push_front(0);                                        // insert head
    //l.insert(l.begin()+3, 8);                               // insert to 4th
    l.push_back(9);                                         // intert to tail
    prt.show(l);
    l.erase(l.begin());
    //l.splice(l.begin(), l2);
    //cout << "after splice:\n";
    //prt.show(l);
    l.remove(9);
    cout << "after remove 9:\n";
    prt.show(l);
    l.merge(l2);
    cout << "after merge l2:\n";
    prt.show(l);
    l.sort();
    cout << "after sort:\n";
    prt.show(l);
    l.unique();                                             //unique doesn't work, when after merge??
    cout << "after unique:\n";
    prt.show(l);
    l.reverse();
    cout << "after reverse:\n";
    prt.show(l);

    // map
    cout << "\n...............Test for std::map...............\n";
    std::map<string, string> m;
    m.insert(pair<string, string>("key1", "value1"));       // insert string pair to map
    m["k2"] = "v2";
    string value = m.at("key1");                            // get the values of key1
    cout << "the value at key1 is: " << value << endl;
    prt.show(m);
    m.erase("key1");                                        // erase key1, value1
    prt.show(m);
    bool exists = (m.find("key1") != m.end());              // find if an element exist
    cout << exists << endl;


    // set
    cout << "\n...............Test for std::set...............\n";
    std::set<int> s = {1,3,3,3,2,4};
    s.insert(20);                                        // insert
    prt.show(s);

    s.erase(3);
    prt.show(s);
    exists = (s.find(21) != s.end());
    cout << "21 is in s? " << exists << endl;

    // stack    First-in Last-out !
    cout << "\n...............Test for std::stack...............\n";
    std::stack<int> st;
    st.push(19);                                        // insert
    st.push(20);                                        // insert
    st.push(21);                                        // insert
    st.pop();                                           // pop the last one

    cout << "The size of the stack is: " << st.size() << endl;
    cout << "The top of the stack is: " << st.top() << endl;

    // queue    First-in First-out!
    cout << "\n...............Test for std::queue...............\n";
    std::queue<int> q;
    q.push(19);                                        // insert
    q.push(20);                                        // insert
    q.push(21);                                        // insert
    q.pop();                                           // pop the first one

    cout << "The size of the queue is: " << q.size() << endl;
    cout << "The head of the queue is: " << q.front() << endl;
    cout << "The tail of the queue is: " << q.back() << endl;


    cout << "\n...............Test for loops...............\n";
    cout << "for loop" << endl;
    for (int i=0; i<5; i++) {
        cout << arr[i] << endl;
    };

    cout << "while loop" << endl;
    i = 0;
    while (i < 5) {
        cout << arr[i] << endl;
        i += 1;
    }

    cout << "do while loop" << endl;
    i = 0;
    do {
        cout << arr[i] << endl;
        i += 1;
    } while (i < 3);
    cout << "What if you print something not in the array?" << endl;
    cout << arr[6] << endl;

    cout << "nested for loop to show elements in a 2D array" << endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << "marr["<<i<<"]["<<j<<"]:" <<marr[i][j]<<endl;
        }
    }


    // call functions
    cout << "Sum of int (2,5): " << sum(2, 5) << endl;
    cout << "Call functions in cmath pow(2,10): " << pow(2, 10) << endl;

    // recursive function
    int num8;
    //cout << "Enter a number: ";
    //cin >> num8;
    num8 = 5;
    cout << "Factorial of entered number: " << factorial(num8);


    // String object
    string str = "This is a string";
    str.push_back('!');
    cout << "init string: " << str << endl;
    cout << "String with PUSH back (!):" << str << endl;
    str.pop_back();
    cout << "String with POP back (!):" << str << endl;


    /* 11) Pointer
    *   data_type *pointer_name, var; // declear
    *   *pointer_name = &var;         // assign the address of var to the pointer
    *
    *   Pointer is much useful when combine with array.
    */
    int *p, var=101;
    p = &var;   // if var is an array, just use p = var;
    cout << "Address of var: " << &var << endl;
    cout << "Address of var: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Value of p: " << *p << endl;

    // Traversing the array using pointers
    int *pa;
    int arr1[5] = {1,2,3,4,5};
    pa = arr1; // assignment the address of the array to the pointer.
    for (int i=0; i<5; i++) {
        cout << "arr1[" <<i<< "] = " << *pa << endl;
        pa++;
    };


    /*
     * 12) class
     */
    Demo obj;                           //init the obj with class Demo
    obj.displayValues();
    obj.setMyValues(23, 'A');
    obj.displayValues();
    cout << obj.getNum() << endl;
    cout << obj.getChar() << endl;


    Math1 calc;
    cout << "The add up of " << num1 << " and " << num8 << " is: " << calc.ADD(num1, num8) << endl;
    cout << "The times of " << num1 << " and " << num8 << " is: " << calc.MULTIPLY(num1, num8) << endl;
    cout << "The sum of " << num1 << " and " << num8 << " and 23 is: " << calc.SUM(num1, num8, 23) << endl;

    RGB s1, s2;
    s1.r = 20;
    s1.g = 100;
    cout << "Struct s1: " << s1.r << " " << s1.g << " " << s1.b << endl;

    RGB s3 = setRGB(11, 32, 34);
    printRGB(s2);
    printRGB(s3);

    // enumeration
    direction dir;
    dir = South;
    cout << "The direction is: " << dir << "\n";

    printf("The direction is: %s, %d\n", "a", num1);


    // eight queens problem
    eightQ obj2;
    obj2.findSolutions();

    return 0; // 0 successful, 1 failed
}


// Defining the function sum
int sum(int num1, int num2) {
    return num1 + num2;
}

