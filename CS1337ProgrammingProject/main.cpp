/*
 
 Project - flow control (branch and loops); input and output (formatting); arrays, dynamic array and C-strings; classes and inheritance and linked lists. Refer to the respective chapter for details.
 ----------------------
 Author: Amer Din
 Class Name: 1337 CS I
 Date: 5/19/20
 Description:
 The program will allow a student to be enrolled in two or more courses during a typical semester. Each course’ final grade is computed based on different number of tasks like assignments, quizzes and exams. All exams represent 60% of the final grade, homeworks 30% and all quizzes 10%. The output will be the final averages and data related to this
 
 
 */

//libraries and symbolic constants
#include <iostream>
#include "node.h"
#include "linkedList.h"
#include <fstream>
#include <iomanip>
#include "base.h"
//#include <course.h>

using namespace std;
bool cStringEquality(char * string1, char * string2);

int main() {
    // insert code here...
    //base class creation
    base * baseClass = new base();
    
    
    //local variables
    int job;
    double grade;
    double date;
    string courseString;
    char * course = nullptr;
    
    //for option A
    double hwSums = 0;
    double numOfSums = 0;
    double quizSums = 0;
    double numOfQuiz = 0;
    double testSums = 0;
    double numofTests = 0;
    //counter variables
    int counterGrades = 0;
    int counterCourses = 0;
    
    //reading of input file
    ifstream inputFile;
    inputFile.open("grades.txt");
    if(!inputFile.is_open()){
        cout << "Input file could not be opened" << endl;
        return -1;
    }

    
    //linkedlist creations
    linkedList* gradeslinkedList = new linkedList();
    linkedList* courses = new linkedList();
    
    //reading in of input file
    while(!inputFile.eof()){
        //linkedlist creation
        
        node* grade1 = new node();
        counterGrades++;
        //node * creationNode = new node;
        inputFile >> job >> courseString;
        //conversion of c-string
        course = new char[courseString.size()+1];
        courseString.copy(course, courseString.size()+1);
        course[courseString.size()] ='\0';
        inputFile >> grade >> date;
        
        //adding to node
        grade1->setTask((TYPE)job);
        grade1->setCourseName(course);
        grade1->setGrade(grade);
        grade1->setDate(date);
        
        //checking for unique course
        if(!gradeslinkedList->existing(course)){
            counterCourses++;
            node* nodeCourse = new node();
            nodeCourse->setCourseName(course);
            courses->insertItem(nodeCourse);
        }
        
        
        
        //injection into the link list
        gradeslinkedList->insertItem(grade1);
        
        
    }
    
    //closing of input file
    inputFile.close();
    
    
    //semester averages and calculations
    double averageOfHWs;
    double averageOfExams;
    double averageOfQuizzes;
    double averageInClass;
    double semesterAverage;
    double semesterTotal;
    //menu
    char option;
    while(option != 'd'){
        cout << endl;
        semesterAverage = 97.9;
        cout << "a) Display all final grades" << endl;
        cout << "b) Display course grades" << endl;
        cout << "c) Semester Average" << endl;
        cout << "d) Exit" << endl;
        cin >> option;
        
        
        switch (option) {
            case 'a':{
                //compute averages and display information
                node* courseNode = courses->getHead();
                node* gradesNode = gradeslinkedList->getHead();
                int total = 0;
                
                while(gradesNode!= nullptr){
                    
                    //create an array to store the values
                    if(cStringEquality(courseNode->getCourseName(), gradesNode->getCourseName())){
                        //accessing types for each class
                        if(gradesNode->getTask() == TYPE(1)){
                            hwSums = hwSums + gradesNode->getGrade();
                            numOfSums++;
                            
                        }
                        
                        if(gradesNode->getTask() == TYPE(0)){
                            testSums = testSums + gradesNode->getGrade();
                            numofTests++;
                            
                        }
                        
                        if(gradesNode->getTask() == TYPE(2)){
                            quizSums = quizSums + gradesNode->getGrade();
                            numOfQuiz++;
                            
                        }
                        //checking if averages are legible
                        if(numOfSums >0){
                            averageOfExams = testSums/ numofTests;
                        }
                        if(numOfSums< 0){
                            averageOfExams = 0.0;
                        }
                        
                        if(numOfSums >0){
                            averageOfHWs = hwSums/numOfSums;
                        }
                        if(numOfSums< 0){
                            averageOfHWs = 0.0;
                        }
                        
                        if(numOfQuiz >0){
                            averageOfQuizzes = quizSums /numOfQuiz;
                        }
                        if(numOfQuiz<0){
                            averageOfQuizzes = 0.0;
                        }
                        
                        //average calculations
                        averageInClass = ((averageOfQuizzes*.3)+(averageOfExams*6)+(averageOfHWs*.1));
                        courseNode->setGrade(averageInClass);
                        semesterTotal = semesterTotal+ averageInClass;
                        
                        total++;
                        
                    }
                    
                    //semester average calculation
                    semesterAverage = semesterTotal/total;
                    
                    
                    //until it ends
                    gradesNode = gradesNode->getNext();
                }
                cout << "COURSE NO" << "Final Grade"  << "Note" << endl;
                node* courseNode2 = courses->getHead();
                node* gradesNode2 = gradeslinkedList->getHead();
                while(gradesNode2!= nullptr){
                    
                    
                    cout << gradesNode2->getCourseName() << setw(5) << gradesNode2->getGrade() << endl;
                    gradesNode2 = gradesNode2->getNext();
                    
                }
                break;
            }
            case 'b':{
                //displaying information about course
                
                break;
            }
            case 'c':{
                //semester average calculation
                cout << "your semester average was " << semesterAverage << endl;
            }
                
                break;
            case 'd':
                //exiting of program
                exit(EXIT_SUCCESS);
                
            default:
                cout << "You have entered an invalid option" << endl;
                
        }
    }
    
    return 0;
}

bool cStringEquality(char * string1, char * string2){
    int counter = 0;
    while(string1[counter] == string2[counter]){
        if(string1[counter]=='\0'){
            return true;
        }
        counter++;
    }
    return false;
}
