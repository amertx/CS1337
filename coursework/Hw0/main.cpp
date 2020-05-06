/*
 
 HW2: Arrays, Expressions, Output Formatting, Control Statements
 ----------------------
 Author: Amer Din
 Class Name: 1337 CS I
 Date: 2/9/2020
 Description: This program will enable a user to evaluate an equation f(x) over a range of x values (xmin, xmax) and display a table with all values showcased, In addition it will find the minimum, maximum, mean, median, mode and range values of f(x). The user will enter the values for xmin and xmax, the program will show at least 21 rows in the table.
 
 */


//libraries
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//symbolic constants
#define PI 3.14156
#define POINTS 21

int main() {
    // insert code here...
    // PART A
    double minimumValue;
    double maximumValue;
    double incrementValue;
    
    //array to store y values
    double dataPoints[POINTS];
    
    //initial inputs
    cout << "Enter a minimum and maximum value: " << endl;
    cin >> minimumValue >> maximumValue;
    //check for if maxvalue is less than minvalue
    double value;
    
    
    //increment value for x
    incrementValue = (maximumValue-minimumValue)/ (POINTS-1);
    double xValue = minimumValue;
    
    
    //for loop iteration over values
    xValue = minimumValue;
    cout << "X-Value | Y-Value" << endl;
    cout << "-----------------" << endl;
    for(int i = 0; i < POINTS; i++){
        //truncated to 3 decimal values and rounded
        dataPoints[i] = floor(((2*PI*sin(6.036*xValue))/32 + (PI*cos(24.44*xValue))/64)*1000)/1000;
        cout << fixed << setprecision(1) << right << setw(5) << xValue << fixed << setprecision(3) << setw(12) << dataPoints[i] << endl;
        xValue += incrementValue;
    }
    cout << "-----------------" << endl;
    
    
    //PART B
    double min = dataPoints[0];
    double max = dataPoints[0];
    double summation = dataPoints[0];
    for(int i = 0; i < POINTS; i++){
        //check for maximum value
        if(dataPoints[i] > max){
            max = dataPoints[i];
        }
        //checks for minimum values
        if(dataPoints[i] < min){
            min = dataPoints[i];
        }
        //adds values into a total for division below for average
        summation+=dataPoints[i];
    }
    
    //output of all calculations
    cout << "Minimum Value: " << min << endl;
    cout << "Maximum value: " << max << endl;
    cout << "Range: " << (max-min) << endl;
    cout << "Average: " << (summation/POINTS) << endl;
    
    
    //Median calculation
    //bubble sort
    int size = sizeof(dataPoints)/sizeof(dataPoints[0]);
    bool swap = false;
    double median=0;
    do{
        swap = false;
        for(int i = 0; i < size - 1; i++){
            if(dataPoints[i] > dataPoints[i+1]){
                double temp = dataPoints[i]; //6
                dataPoints[i] = dataPoints[i+1]; //3
                dataPoints[i+1] = temp; //6
                swap = true;
            }
            median = dataPoints[POINTS/2];
        }
    }while(swap);
    cout << "Median: " << median << endl;
    
    //mode calculation
    int sizeMode = sizeof(dataPoints)/sizeof(dataPoints[0]);
    bool swapMode = false;
    int tallies[POINTS];
    int mostFrequent;
    int indexMostFrequent;
    double mode;
    for(int i = 0; i < POINTS; i++){
        tallies[i] = 0;
    }
    //tally system
    double indexValue= dataPoints[0];
    
    for(int i = 0; i < POINTS; i++){
        //mode
        for(int j=i; j < POINTS; j++){
            if ( dataPoints[i] == dataPoints[j]) {
                tallies[i]++;
            }}
        
        if(tallies[i] > mostFrequent){
            mostFrequent = tallies[i];
            indexMostFrequent = i;
        }
    }
    
    if (mostFrequent >1) {
        mode = dataPoints[indexMostFrequent];
    }
    else{
        mode = 11;
    }
    
    //Output if mode is not equal to
    if(mode == 11){
        cout << "There is no mode in the dataset" << endl;
    }else{
        cout << "Mode: " << mode << endl;
    }
    

    
    
    
    return 0;
}
