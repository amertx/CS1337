/*

Project - flow control (branch and loops); input and output (formatting); arrays, dynamic array and C-strings; classes and inheritance and linked lists. Refer to the respective chapter for details.
----------------------
Author: Amer Din
Class Name: 1337 CS I
Date: 5/19/20
Description:
The program will allow a student to be enrolled in two or more courses during a typical semester. Each course’ final grade is computed based on different number of tasks like assignments, quizzes and exams. All exams represent 60% of the final grade, homeworks 30% and all quizzes 10%. The output will be the final averages and data related to this


*/

#ifndef base_h
#define base_h
enum TYPE{EXAM = 0, HOMEWORK = 1, QUIZ = 2, FINAL_GRADE = 3};
class base{
protected:
    char * courseName; // To store class prefix and number o
    TYPE task;// Enum type to represent EXAM, HW, QUIZ or FINAL o
    double grade;// A double value from 0 to 100
    double date; // A double value representing the date
    
    
public:
    //define the static data member
    static int counter;
    static int getCounter();
    //Getters or accessors
    char * getCourseName();
    TYPE getTask();
    double getGrade();
    double getDate();
    
    //Setter or mutators
    void setCourseName(char* n);
    //A class may have two or more function members wiuth the same
    // name, as long as the listo of parameters is different
    void setTask(TYPE g);
    
    void setDate(double g);
    void setGrade(double g);
    
    
    //The compiler will provide automatically:
    // (empty) constructor and destructor
     base();
    ~base();
};


#endif /* base_h */
