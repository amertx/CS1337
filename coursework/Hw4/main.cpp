/*
 
 Assignment #4 - Pointers and Dynamic Arrays
 ----------------------
 Author: Amer Din
 Class Name: 1337 CS I
 Date: 3/22/2020
 Description: In this program, the user will be presented with a menu that allows them to the following:
 (Once each option is validated and chosen the result will be outputted to the user)
 A) Create and initilize a dynamic array
 -   This option will enable the user to dynamically allocate and initialize with random numbers [80,1001) an array of size N. The option will ultimately return a pointer to the dynamically allocated array.
 B) Display statistic on the aray
 -   This option will enable the user to find the statistics about the array by searching the minimum and maximum elements and by calculating the average of elements
 C) Search for an element
 -   This option will enable the user to find an element key within the array and will return a nullptr if it is not found
 D) Quit
 -   Exits the program
 */

//libraries and symbolic constants
#include <iostream>

using namespace std;

//function prototypes
int *createArray(int &N);
void findStats(int *arr, int N, int &min, int &max, double &average);
int *searchElement(int *arr, int N, int key);
void findSequence(int *, int);

int main() {
    //local variables
    char input;
    char inputPostLoop;
    int size;
    int *dynamicArray = nullptr;
    int minimum;
    int maximum;
    int searchKey;
    int *searchingOfElementValue;
    double average;
    bool firstPass = true;
    

    //menu options
    cout << "A. Create and initilize a dynamic array" << endl;
    cout << "B. Display statistics on the array" << endl;
    cout << "C. Search for an element" << endl;
    cout << "D. Quit" << endl;
    cout << "E. Bonus " << endl;
    cin >> input;
    inputPostLoop = input;
    
    if(input == 'd' || input == 'D'){
        cout << "Exiting" << endl;
        exit(EXIT_SUCCESS);
    }
    
    
    
    while(inputPostLoop != 'a'&& inputPostLoop != 'A'){
        cout << "You must enter option A before any of the rest" << endl;
        cin >> inputPostLoop;
    }
    
    //rest of the options
    while(input != 'd'||input != 'D'){
        if (!firstPass) {
            cout << "A. Create and initilize a dynamic array" << endl;
            cout << "B. Display statistics on the array" << endl;
            cout << "C. Search for an element" << endl;
            cout << "D. Quit" << endl;
            cout << "E. Bonus " << endl;
            cin >> inputPostLoop;
            cout << endl;
        }
        
        switch (inputPostLoop) {
                //lower case a
            case 'a':{
                //Once A is chosen the integer value is inputted
                cout << "Enter an integer for the size of the array: ";
                cin >> size;
                
                //If the array was already initialized then it must be deleted
                if(dynamicArray != nullptr){
                    delete [] dynamicArray;
                }
                
                //running of function
                dynamicArray = createArray(size);
                
                //output of contents
                cout << "The array contents are: " << endl;
                for(int i = 0; i < size; i++){
                    cout << dynamicArray[i] << " ";
                }
                cout << endl;
                
                firstPass = false;
                break;
            }
                //upper case A
            case 'A':{
                //Once A is chosen the integer value is inputted
                cout << "Enter an integer for the size of the array: ";
                cin >> size;
                
                //If the array was already initialized then it must be deleted
                if(dynamicArray != nullptr){
                    delete [] dynamicArray;
                }
                
                //running of function
                dynamicArray = createArray(size);
                
                //output of contents
                cout << "The array contents are: " << endl;
                for(int i = 0; i < size; i++){
                    cout << dynamicArray[i] << " ";
                }
                cout << endl;
                firstPass = false;
                break;
            }
                //lower case b
            case 'b': {
                //calling of findStats function; displaying these variables’ calculated values from inside the caller (main) function
                findStats(dynamicArray, size, minimum, maximum, average);
                cout << "Minimum: " << minimum << endl;
                cout << "Maximum: " << maximum << endl;
                cout << "Average: " << average << endl;
                cout << endl;
                break;
            }
                //upper case B
            case 'B':{
                //calling of findStats function; displaying these variables’ calculated values from inside the caller (main) function
                findStats(dynamicArray, size, minimum, maximum, average);
                cout << "Minimum: " << minimum << endl;
                cout << "Maximum: " << maximum << endl;
                cout << "Average: " << average << endl;
                cout << endl;
                break;
            }
                //lower case c
            case 'c':{
                cout << "Enter a number to search: " << endl;
                cin >> searchKey;
                searchingOfElementValue = searchElement(dynamicArray, size, searchKey);
                if(searchingOfElementValue != nullptr){
                    cout << searchKey << " was found at " << searchingOfElementValue << " at index " << searchingOfElementValue - dynamicArray << endl;
                }else{
                    cout << searchKey << " was not found within the array created" << endl;
                }
                cout << endl;
                break;
            }
                //upper case C
            case 'C':{
                cout << "Enter a number to search: " << endl;
                cin >> searchKey;
                searchingOfElementValue = searchElement(dynamicArray, size, searchKey);
                if(searchingOfElementValue != nullptr){
                    cout << searchKey << " was found at " << searchingOfElementValue << " at index " << searchingOfElementValue - dynamicArray << endl;
                }else{
                    cout << searchKey << " was not found within the array created" << endl;
                }
                cout << endl;
                break;
            }
                
                //deletion of pointers and exiting of program
                //lower case d
            case 'd':{
                //deletion of pointer if the array returns a nullptr
                if(dynamicArray != nullptr){
                    delete [] dynamicArray;
                }
                cout << "Exiting" << endl;
                exit(EXIT_SUCCESS);
            }
                //upper case D
            case 'D':{
                //deletion of pointer if the array returns a nullptr
                if(dynamicArray != nullptr){
                    delete [] dynamicArray;
                }
                cout << "Exiting" << endl;
                exit(EXIT_SUCCESS);
            }
                 //lower case e
            case 'e':{
             
                findSequence(dynamicArray, size);
                cout << endl;
                break;
            }
                //upper case E
            case 'E':{
                findSequence(dynamicArray, size);
                cout << endl;
                break;
            }
                break;
        }
        
        
        
        
    }
    
    return 0;
}


int *createArray(int &N){
    int *dynamicArray;
    //random function input values
    int minimum = 80;
    int maximum = 1001;
    int range = maximum - minimum + 1;
    //creation of dynamic array
    dynamicArray = new int[N];
    
    //iteration through each array value
    for(int i = 0; i < N; i++){
        dynamicArray[i] = minimum + rand()% range;
    }
    
    //returning of pointer to dynamic allocated array
    return dynamicArray;
}

void findStats(int *arr, int N, int &min, int &max, double &average){
    //initial minimums for each parameter
    min = arr[0];
    max = arr[0];
    average = 0;
    
    //iteration through array
    for (int i = 0;i < N; i++) {
        //checking for if minimum value is less than dynamic array at the iteration index
        if(arr[i] < min){
            min = arr[i];
        }
        //checking for if maximum value is less than dynamic array at the iteration index
        if(arr[i] > max){
            max = arr[i];
        }
        
        //summation for average
        average += arr[i];
    }
    
    //division of N number of elements
    average = average / N;
    
}

int *searchElement(int *arr, int N, int key){
    //iteration through loop
    for(int i = 0; i < N; i++){
        if(arr[i] == key){
            return &arr[i];
        }
    }
    //returning of null ptr if no element was found in the loop
    return nullptr;
    
}

void findSequence(int *arr, int N){
    int num1;
    int num2;
    int num3;
    int num4;
    int indexValue = 0;
    bool found = false;
    
    cout << endl;
    
    //ask user for 4 values
    cout << "Enter number 1: ";
    cin >> num1;
    
    cout << "Enter number 2: ";
    cin >> num2;
    
    cout << "Enter number 3: ";
    cin >> num3;

    cout << "Enter number 4: ";
    cin >> num4;
    
    //looping through each iteration and making sure each element inputted is equal to first four entered
    while(indexValue < N){
        if(arr[indexValue] == num1 && arr[indexValue+1]==num2 && arr[indexValue+2]==num3 && arr[indexValue+3] == num4){
            found = true;
            cout << "The numbers you entered are in order!" << endl;
        }
        indexValue++;
    }
    
    //not found
    if(!found){
        cout << "The numbers you entered are not in the sequence" << endl;
    }
    
}
