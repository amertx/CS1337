
/*

Project - flow control (branch and loops); input and output (formatting); arrays, dynamic array and C-strings; classes and inheritance and linked lists. Refer to the respective chapter for details.
----------------------
Author: Amer Din
Class Name: 1337 CS I
Date: 5/19/20
Description:
The program will allow a student to be enrolled in two or more courses during a typical semester. Each course’ final grade is computed based on different number of tasks like assignments, quizzes and exams. All exams represent 60% of the final grade, homeworks 30% and all quizzes 10%. The output will be the final averages and data related to this


*/
#ifndef grades_h
#define grades_h

#include "node.h"

#include <iomanip>
#include <iostream>
class linkedList{
    node* head;
    node* tail;
public:
   
    void insertItem(node* obj);
    void removeNode(node* obj);
    bool findNode(node* obj);
    //for debugging purposes
    void printList();
    //function prototypes
    bool cStringEquality(char * string1, char * string2);
    node * getHead();
    linkedList();
      ~linkedList();
    //
    
    
    bool existing(char *nameOfCourse);
};


#endif /* grades_h */
