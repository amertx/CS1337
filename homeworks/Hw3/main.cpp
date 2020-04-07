/*
 
 File Handling Functions Structures
 ----------------------
 Author: Amer Din
 Class Name: 1337 CS I
 Date: 2/26/2020
 Description: In this program, the 911 service will help the dispatcher attending emergency calls to
 1) Find the nearest/closest service where the issue occured
 2) Get in contact with the police department, hospital, or fire station
 */

//libraries and symbolic constants
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//enum definition
enum serviceType{POLICE_DEPARTMENT, HOSPITAL, FIRE_STATION};

//struct definition
struct dataMembers{
    int serviceId;
    double xCoordinate;
    double yCoordinate;
    serviceType service;
    string cityName;
    int calls;
    
};

//dynamic array creation
dataMembers * serviceAnalytics;

//counting lines for the size of the array in a file method
int countLines(string fileName){
    int counter = 0;
    string dummy;
    ifstream inputFile;
    inputFile.open(fileName);
    if(!inputFile.is_open()){
        return -2;
    }
    
    
    while(!inputFile.eof()){
        getline(inputFile, dummy);
        counter++;
    }
    
    inputFile.close();
    return counter;
}

//reading in of file
int readFile(string fileName, dataMembers * serviceAnalytics, int size){
    ifstream input;
    int dummy;
    input.open(fileName);
    if(!input.is_open()){
        return -1;
    }
    
    //reading of file
    int counter = 0;
    
    //while loop reading through each line of the file
    while(!input.eof() && counter < size){
        input >> serviceAnalytics[counter].serviceId >> serviceAnalytics[counter].xCoordinate >> serviceAnalytics[counter].yCoordinate;
        input >> dummy;
        serviceAnalytics[counter].service = (serviceType)dummy;
        input >> serviceAnalytics[counter].cityName >> serviceAnalytics[counter].calls;
        counter++;
    }
    
    input.close();
    return 0;
    
}

int findNearestService(dataMembers * serviceAnalytics, int size, double x, double y){
    int nearestService = 0;
    double closestDistance = sqrt(pow((serviceAnalytics[nearestService].xCoordinate-x), 2) + pow((serviceAnalytics[nearestService].yCoordinate)-y,2));
    
    for(int i = 1; i < size-1; i++){
        int closestCalls = serviceAnalytics[nearestService].calls;
        int compareCalls = serviceAnalytics[i].calls;
        
        double comparisonOfDistances = sqrt(pow((serviceAnalytics[i].xCoordinate-x), 2) + pow((serviceAnalytics[i].yCoordinate)-y,2));
        if(comparisonOfDistances <= closestDistance && compareCalls < closestCalls){
            closestDistance= comparisonOfDistances;
            nearestService = i;
        }
        
    }
    
    return nearestService;
}

int findNearestPoliceDepartment(double x, double y, dataMembers* serviceAnalytics, int size){
    //storing of distances in a array
    double *distance;
    distance = new double[size];
    
    //distance formula
    double xSubtraction;
    double ySubtraction;
    
    int pDeptCount = 0;
    for (int i = 0; i < size; i++) {
        if ((serviceAnalytics + i)->service == POLICE_DEPARTMENT) {
            (serviceAnalytics + pDeptCount)->serviceId = (serviceAnalytics + i)->serviceId;
            (serviceAnalytics + pDeptCount)->xCoordinate = (serviceAnalytics + i)->xCoordinate;
            (serviceAnalytics + pDeptCount)->yCoordinate = (serviceAnalytics + i)->yCoordinate;
            (serviceAnalytics + pDeptCount)->service = (serviceAnalytics + i)->service;
            (serviceAnalytics + pDeptCount)->cityName = (serviceAnalytics + i)->cityName;
            (serviceAnalytics + pDeptCount)->calls = (serviceAnalytics + i)->calls;
            pDeptCount++;
        }
    }
    
    for (int i = 0; i < pDeptCount; i++) {
        xSubtraction = ((serviceAnalytics + i)->xCoordinate) - x;
        ySubtraction = ((serviceAnalytics + i)->yCoordinate) - y;
        
        *(distance + i) = sqrt((xSubtraction * xSubtraction) + (ySubtraction * ySubtraction));
    }
    
    //finding of shortest distance
    double minimumDistance = 300000;
    int minimumIndex = 0;
    for (int i = 0; i < pDeptCount; i++) {
        if ((*(distance + i) < minimumDistance)) {
            minimumDistance = *(distance + i);
            minimumIndex = i;
        }
    }
    
    cout << "The closest POLICE DEPARTMENT to you has the ID #" << (serviceAnalytics + minimumIndex)->serviceId
    << " and it is " << fixed << setprecision(3) << minimumDistance << " miles away. "
    << "Its in " << (serviceAnalytics + minimumIndex)->cityName << ", located at X: " << fixed << setprecision(2) << (serviceAnalytics + minimumIndex)->xCoordinate << " and at Y: " << fixed << setprecision(2) << (serviceAnalytics + minimumIndex)->yCoordinate << " and has recieved " << (serviceAnalytics + minimumIndex)->calls << " calls per day." <<  endl;
    cout << endl;
    
    //deletion of pointers
    delete [] serviceAnalytics;
    delete [] distance;
    
    return (serviceAnalytics + minimumIndex)->serviceId;
}

int findNearestHospital(double x, double y, dataMembers* serviceAnalytics, int size){
    //storing of distances in a array
    double *distance;
    distance = new double[size];
    
    //distance formula
    double xSubtraction;
    double ySubtraction;
    
    int hospitalCount = 0;
    for (int i = 0; i < size; i++) {
        if ((serviceAnalytics + i)->service == HOSPITAL) {
            //pointer using index value and structure
            (serviceAnalytics + hospitalCount)->serviceId = (serviceAnalytics + i)->serviceId;
            (serviceAnalytics + hospitalCount)->xCoordinate = (serviceAnalytics + i)->xCoordinate;
            (serviceAnalytics + hospitalCount)->yCoordinate = (serviceAnalytics + i)->yCoordinate;
            (serviceAnalytics + hospitalCount)->service = (serviceAnalytics + i)->service;
            (serviceAnalytics + hospitalCount)->cityName = (serviceAnalytics + i)->cityName;
            (serviceAnalytics + hospitalCount)->calls = (serviceAnalytics + i)->calls;
            hospitalCount++;
        }
    }
    
    for (int i = 0; i < hospitalCount; i++) {
        xSubtraction = ((serviceAnalytics + i)->xCoordinate) - x;
        ySubtraction = ((serviceAnalytics + i)->yCoordinate) - y;
        
        *(distance + i) = sqrt((xSubtraction * xSubtraction) + (ySubtraction * ySubtraction));
    }
    
    //finding of shortest distance
    double minimumDistance = 300000;
    int minimumIndex = 0;
    for (int i = 0; i < hospitalCount; i++) {
        if ((*(distance + i) < minimumDistance)) {
            minimumDistance = *(distance + i);
            minimumIndex = i;
        }
    }
    
    cout << "The closest HOSPITAL to you has the ID #" << (serviceAnalytics + minimumIndex)->serviceId
    << " and it is " << fixed << setprecision(3) << minimumDistance << " miles away. "
    << "Its in " << (serviceAnalytics + minimumIndex)->cityName << ", located at X: " << fixed << setprecision(2) << (serviceAnalytics + minimumIndex)->xCoordinate << " and at Y: " << fixed << setprecision(2) << (serviceAnalytics + minimumIndex)->yCoordinate << " and has recieved " << (serviceAnalytics + minimumIndex)->calls << " calls per day." <<  endl;
    cout << endl;
    
    //deletion of pointers
    delete [] serviceAnalytics;
    delete [] distance;
    
    return (serviceAnalytics + minimumIndex)->serviceId;
}


int findNearestFireStation(double x, double y, dataMembers* serviceAnalytics, int size){
    //storing of distances in a array
    double *distance;
    distance = new double[size];
    
    //distance formula
    double xSubtraction;
    double ySubtraction;
    
    int fireDepartmentCount = 0;
    for (int i = 0; i < size; i++) {
        if ((serviceAnalytics + i)->service == FIRE_STATION) {
            (serviceAnalytics + fireDepartmentCount)->serviceId = (serviceAnalytics + i)->serviceId;
            (serviceAnalytics + fireDepartmentCount)->xCoordinate = (serviceAnalytics + i)->xCoordinate;
            (serviceAnalytics + fireDepartmentCount)->yCoordinate = (serviceAnalytics + i)->yCoordinate;
            (serviceAnalytics + fireDepartmentCount)->service = (serviceAnalytics + i)->service;
            (serviceAnalytics + fireDepartmentCount)->cityName = (serviceAnalytics + i)->cityName;
            (serviceAnalytics + fireDepartmentCount)->calls = (serviceAnalytics + i)->calls;
            fireDepartmentCount++;
        }
    }
    
    for (int i = 0; i < fireDepartmentCount; i++) {
        xSubtraction = ((serviceAnalytics + i)->xCoordinate) - x;
        ySubtraction = ((serviceAnalytics + i)->yCoordinate) - y;
        
        *(distance + i) = sqrt((xSubtraction * xSubtraction) + (ySubtraction * ySubtraction));
    }
    
    //finding of shortest distance
    double minimumDistance = 300000;
    int minimumIndex = 0;
    for (int i = 0; i < fireDepartmentCount; i++) {
        if ((*(distance + i) < minimumDistance)) {
            minimumDistance = *(distance + i);
            minimumIndex = i;
        }
    }
    
    
    //output statement
    cout << "The closest FIRE STATION to you has the ID #" << (serviceAnalytics + minimumIndex)->serviceId
    << " and it is " << fixed << setprecision(3) << minimumDistance << " miles away. "
    << "Its in " << (serviceAnalytics + minimumIndex)->cityName << ", located at X: " << fixed << setprecision(2) << (serviceAnalytics + minimumIndex)->xCoordinate << " and at Y: " << fixed << setprecision(2) << (serviceAnalytics + minimumIndex)->yCoordinate << " and has recieved " << (serviceAnalytics + minimumIndex)->calls << " calls per day." <<  endl;
    cout << endl;
    
    //deletion of pointers
    delete [] serviceAnalytics;
    delete [] distance;
    
    return (serviceAnalytics + minimumIndex)->serviceId;
}

int main() {
    
    // insert code here...
    char input = 'a';
    char input2 = 'b';
    double xCoordinate;
    double yCoordinate;
    string fileName = "serviceInfo.txt";
    
    //counter reading in number of lines in file and setting the size of array as the counter
    int counter = countLines(fileName);
    if(counter <= 0){
        
        return 1;
    }
    
    serviceAnalytics = new dataMembers[counter];
    
    
    
    //if the file has no size
    if(readFile(fileName, serviceAnalytics, counter)< 0){
        return -1;
    }
    
    cout << "a) Enter your location (x,y)" << endl;
    cout << "b) Find the nearest service" << endl;
    cout << "c) Find the nearest POLICE DEPARTMENT" << endl;
    cout << "d) Find the nearest HOSPITAL" << endl;
    cout << "e) Find the nearest FIRE STATION" << endl;
    cout << "f) Exit" << endl;
    cin >> input;
    
    while(input != 'a'){
        cout << "You must enter option A before any of the rest" << endl;
        cin >> input;
    }
    
    //enter coordinates
    cout << "X-coordinate: ";
    cin >> xCoordinate;
    cout << "Y-coordinate: ";
    cin >> yCoordinate;
    
    //rest of the options
    while(input != 'a' || input != 'f'){
        cout << "b) Find the nearest service" << endl;
        cout << "c) Find the nearest POLICE DEPARTMENT" << endl;
        cout << "d) Find the nearest HOSPITAL" << endl;
        cout << "e) Find the nearest FIRE STATION" << endl;
        cout << "f) Exit" << endl;
        cin >> input2;
        cout << endl;
        
        
        
        switch (input2) {
            case 'b': {
                int nearestService = findNearestService(serviceAnalytics, counter, xCoordinate, yCoordinate);
                cout << "The closest service has an ID " << serviceAnalytics[nearestService].serviceId << " and is in " << serviceAnalytics[nearestService].cityName << " is located at X: " << serviceAnalytics[nearestService].xCoordinate << " and Y: " << serviceAnalytics[nearestService].yCoordinate << " and has recieved " << serviceAnalytics[nearestService].calls << " calls." << endl;
                break;
            }
            case 'c':{
                //function call to nearest police department
                int nearestPoliceDepartment = findNearestPoliceDepartment(xCoordinate, yCoordinate, serviceAnalytics, counter);
                break;
                
            }
            case 'd':{
                //function call to nearest hospital
                int nearestHospital = findNearestHospital(xCoordinate, yCoordinate, serviceAnalytics, counter);
                break;
            }
            case 'e':{
                //function call to nearest fire station
                int nearestFireStation = findNearestFireStation(xCoordinate, yCoordinate, serviceAnalytics, counter);
                break;
            }
            case 'f':{
                exit(EXIT_SUCCESS);
            }
                break;
                
        }
        break;
        
        
    }
    
    
    //output of sorted list
    
    return 0;
}
