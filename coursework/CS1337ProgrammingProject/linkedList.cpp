/*

Project - flow control (branch and loops); input and output (formatting); arrays, dynamic array and C-strings; classes and inheritance and linked lists. Refer to the respective chapter for details.
----------------------
Author: Amer Din
Class Name: 1337 CS I
Date: 5/19/20
Description:
The program will allow a student to be enrolled in two or more courses during a typical semester. Each course’ final grade is computed based on different number of tasks like assignments, quizzes and exams. All exams represent 60% of the final grade, homeworks 30% and all quizzes 10%. The output will be the final averages and data related to this


*/
#include <stdio.h>
#include "linkedList.h"
#include <iomanip>
#include <iostream>
using namespace std;

linkedList::linkedList(){
    
}

linkedList::~linkedList(){
    
}

//insertion of node from list
void linkedList::insertItem(node * newNode){
    
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        //If we dont care about the order/append the node
        head->setPrev(newNode);
        newNode->setNext(head);
        head= newNode;
    }
}
//function prototypes
bool linkedList::cStringEquality(char * string1, char * string2){
    int counter = 0;
    while(string1[counter] == string2[counter]){
        if(string1[counter]=='\0'){
            return true;
        }
        counter++;
    }
    return false;
}

bool linkedList::existing(char *nameOfCourse){
    if(head == nullptr){
        return false;
    }
    
    else{
        node* iter = head;
        while(!cStringEquality(iter->getCourseName(), nameOfCourse)){
            iter = iter->getNext();
            if(iter == nullptr){
                return false;
            }
            
        }
        return true;
    }
}





void linkedList::printList(){
    if(head == nullptr){
        return;
    }
    node *temp;
    temp = head;
    while(temp != nullptr){
        cout << temp->getTask() << " " << fixed << setprecision(2) << temp->getCourseName() << " "  << temp->getGrade() << " " << temp->getDate() << endl;
        
        temp = temp->getNext();
        cout << endl;
    }
    
}

//removal of node from list
void linkedList::removeNode(node *obj){
    
    if(head == obj){
        if(head->getNext() == nullptr){
            delete obj;
            head = nullptr;
        }else{
            head->getNext()->setPrev(nullptr);
            head= head->getNext();
            delete obj;
        }
    }
    
    if(obj -> getNext() == nullptr){
        obj->getPrev()->setNext(nullptr);
        delete obj;
    }else{
        obj->getPrev()->setNext(obj->getNext());
        obj->getNext()->setPrev(obj->getPrev());
    }
    
}

//find node
bool linkedList::findNode(node * obj){
    node* activeNode = head;
    bool searched = false;
    int counter = 0;
    while(activeNode->getNext() != nullptr){
        if(activeNode->getNext() == obj){
            counter++;
            searched = true;
            if(counter ==1){
                cout << "Course" << setw(8) << "Grade" << setw(8) << "Type" << setw(8) << "Date" << endl;
            }
            cout << activeNode ->getCourseName() << setw(8) << activeNode->getGrade() << setw(8) << activeNode->getTask() << setw(8) << activeNode->getDate() << endl;
        }
    }
    return searched;
    if(!searched){
        cout << "Item not found" << endl;
    }
}


node* linkedList::getHead(){
    return head;
}





