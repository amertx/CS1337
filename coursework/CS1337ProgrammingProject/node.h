
/*

Project - flow control (branch and loops); input and output (formatting); arrays, dynamic array and C-strings; classes and inheritance and linked lists. Refer to the respective chapter for details.
----------------------
Author: Amer Din
Class Name: 1337 CS I
Date: 5/19/20
Description:
The program will allow a student to be enrolled in two or more courses during a typical semester. Each course’ final grade is computed based on different number of tasks like assignments, quizzes and exams. All exams represent 60% of the final grade, homeworks 30% and all quizzes 10%. The output will be the final averages and data related to this


*/
#ifndef node_h
#define node_h


#include <iomanip>
#include <iostream>
#include "base.h"

using namespace std;


class node: public base{

    node* previous;
    node* next;
    int id;
    
public:
    
    //accessors and mutators
    node* getNext();
    node* getPrev();
    int getID();
    void setID(int idSetting);
    void setNext(node*);
    void setPrev(node*);
    node(int );
    node();
    ~node();
    
    
    
  
    

};


#endif /* node_h */
