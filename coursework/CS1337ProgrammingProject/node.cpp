/*

Project - flow control (branch and loops); input and output (formatting); arrays, dynamic array and C-strings; classes and inheritance and linked lists. Refer to the respective chapter for details.
----------------------
Author: Amer Din
Class Name: 1337 CS I
Date: 5/19/20
Description:
The program will allow a student to be enrolled in two or more courses during a typical semester. Each course’ final grade is computed based on different number of tasks like assignments, quizzes and exams. All exams represent 60% of the final grade, homeworks 30% and all quizzes 10%. The output will be the final averages and data related to this


*/
#include "node.h"

//accessor for getting ID
int node::getID(){
    return id;
}
//accessor for geting next node
node* node::getNext(){
    return next;
}
//accessor for geting previous node
node* node:: getPrev(){
    return previous;
}

void node::setID(int idSetting){
    id = idSetting;
}

void node::setNext(node* nextNode){
    next = nextNode;
}

void node::setPrev(node* previousNode){
    previous = previousNode;
}

//constructors and deconstructors
node::node(int nodeParamter){
    id = nodeParamter;
    next = nullptr;
    previous = nullptr;
}

node::node(){
    id = 0;
    next = nullptr;
    previous = nullptr;
    
    
    
}

node::~node(){
    
}






