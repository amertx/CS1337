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
#include "base.h"


//accessor for course name
char* base::getCourseName(){
    return courseName;
}
//access for enum of task
TYPE base::getTask(){
    return task;
}
//accessor for grade
double base::getGrade(){
    return grade;
}
//accessor for date
double base::getDate(){
    return date;
}


//mutator for course name
void base::setCourseName(char* n){
    courseName = n;
}
//mutator of enum type task

void base::setTask(TYPE taskSet){
    task = taskSet;
}
 

//mutator of grades
void base::setGrade(double gradeNew){
    grade = gradeNew;
}
//mutator of date
void base::setDate(double dateNew){
    date = dateNew;
}

base::base(){
    
}

base::~base(){
    
}
