/*
 
Average, standard deviation and variance
 ----------------------
 Author: Amer Din
 Class Name: 1337 CS I
 Date: 2/4/2020
 Description: In this program, the user will be prompted to enter the following:
 i)    Min and Max value9
 ii)    Number of samples(N)
 iii)   Increment(I)
 Once the user has entered these data endpoints, tge average, standard deviation and variance will be calculated and be presented to the user

 */

//libraries
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // insert code here...
    //local variables
    double maxValue;
    double minValue;
    double average;
    double standardDeviation;
    int numOfSamples;
    int incrementValue;
    
    //prompt for number of samples
    cout << "Enter the number of samples: " << endl;
    cin >> numOfSamples;
    //input validation
    while(numOfSamples < 0){
        cout << "The number of samples cannot be less than zero, please reenter" << endl;
        cin >> numOfSamples;
    }
    
    //prompt for min and max values
    cout << "Enter a minimum and maximum value " << endl;
    cin >> minValue >> maxValue;
    
    //input validation
    while(minValue > maxValue){
        cout << "The minimum value cannot be greater than the maximum value, Please re-enter the values: " << endl;
        cin >> minValue >> maxValue;
    }

    
    //creation of array that holds the size
    double listOfNums[numOfSamples];

    //prompt for increment value
    cout << "Enter an increment value: " << endl;
    cin >> incrementValue;
    //input validation
    while(incrementValue > (maxValue-minValue)){
        cout << "The increment value cannot be greater than the difference of the min and max values" << endl;
        cin >> incrementValue;
    }
    
    //loop through the array and add the incremental values
    for(int i = 0; i < numOfSamples; i++){
        if(!(minValue+i*(incrementValue) > maxValue)){
           listOfNums[i] = minValue+i*(incrementValue);
        }
    }
    
    //new line
    cout << endl;
    
    
    //CALCULATIONS
    double sum = 0;
    //average
    for(int i = 0; i < numOfSamples; i++){
        sum +=listOfNums[i];
    }
    average = sum /numOfSamples;
    
    //standard deviation
    for(int i = 0; i < numOfSamples; i++){
        standardDeviation += pow(listOfNums[i]- average,2);
    }
    
    double finalStandardDeviation;
    finalStandardDeviation = sqrt(standardDeviation/10);
    
    //variance
    double variance;
    variance = pow(finalStandardDeviation, 2);
    
    //cout << average << endl;
    //cout << finalStandardDeviation << endl;
    //cout << variance << endl;
    cout << "Average " << setw(8) << " Standard Deviation " << setw(8) << " Variance" << endl;
    cout << fixed << setprecision(4) << average << setw(13) << fixed << setprecision(4) << finalStandardDeviation << setw(17) << fixed << setprecision(4) << variance << endl;
        
    
    return 0;
}
