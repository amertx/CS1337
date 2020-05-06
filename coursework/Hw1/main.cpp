/*
 Online Shopper Program
 ----------------------
 Author: Amer Din
 Class Name: 1337 CS I
 Date: 2/1/2020
 Description: In this program, the user will be prompted to enter a title of a movie, rent per day on each service. and the number of days to keep the movie. After all these components are inputted, the total cost will be calculated for each and decide which service the user should rent from. In addition, once the calculation is performed, the movie title, rent per day, the number of days, the name of the service, the total cost on each service and final recommendation on from which service the user should rent the movie will be outputted orderly.

 */

#include <iostream>
#include <iomanip>
using namespace std;

//Global Variables
//Monthly fees
double netflixFee = 8.99;
double vuduFee = 4.99;
double huluFee = 6.99;
double disneyFee = 9.99;
double amazonFee = 9.69;

int main() {
    // insert code here...
    //local variables
    string movieTitle;
    double rentPerDayNetflix;
    double rentPerDayVudu;
    double rentPerDayHulu;
    double rentPerDayDisney;
    double rentPerDayAmazon;

    //number of days veriable
    int numOfDays = 0;
    
    //totla cost variables
    double netflixTotalCost;
    double vuduTotalCost;
    double huluTotalCost;
    double disneyTotalCost;
    double amazonTotalCost;
    string minimum;
    
    // prompts for introduction
    cout << "What is the title of your movie?" << endl;
    getline(cin, movieTitle);
    

    //rent per day
    cout << "What is your rent per day for Netlix?" << endl;
    cin >> rentPerDayNetflix;
    
    cout << "What is your rent per day for Vudu?" << endl;
    cin >> rentPerDayVudu;
    
    cout << "What is your rent per day for Hulu?" << endl;
    cin >> rentPerDayHulu;
    
    cout << "What is your rent per day for Disney?" << endl;
    cin >> rentPerDayDisney;
    
    cout << "What is your rent per day for Amazon?" << endl;
    cin >> rentPerDayAmazon;
    
    cout << "What is the number of days you rented?" << endl;
    cin >> numOfDays;
    
    // Calcuation of total cost
    netflixTotalCost = (numOfDays * rentPerDayNetflix) + netflixFee;
    vuduTotalCost = (numOfDays * rentPerDayVudu) + vuduFee;
    huluTotalCost = (numOfDays * rentPerDayHulu) + huluFee;
    disneyTotalCost = (numOfDays * rentPerDayDisney) + disneyFee;
    amazonTotalCost = (numOfDays * rentPerDayAmazon) + amazonFee;
    
    //recommnedation logic for lowest price
    int minimumPrice = 0;
    minimumPrice = netflixTotalCost;
    minimum = "NETFLIX";
    if(minimumPrice > vuduTotalCost){
        minimumPrice = vuduTotalCost;
        minimum = "VUDU";
    }
    if(minimumPrice > huluTotalCost){
        minimumPrice = huluTotalCost;
        minimum = "HULU";
    }
    if(minimumPrice > disneyTotalCost){
        minimumPrice = disneyTotalCost;
        minimum = "DISNEY";
    }
    if(minimumPrice > amazonTotalCost){
        minimumPrice = amazonTotalCost;
        minimum = "AMAZON";
    }
    
    
    //recommnedation logic for calculating highest price
    int highestPrice = 0;
    highestPrice = netflixTotalCost;
    if(highestPrice < vuduTotalCost){
        highestPrice = vuduTotalCost;
        //minimum = "VUDU";
    }
    if(highestPrice < huluTotalCost){
        highestPrice = huluTotalCost;
        //minimum = "HULU";
    }
    if(highestPrice < disneyTotalCost){
        highestPrice = disneyTotalCost;
        //minimum = "DISNEY";
    }
    if(highestPrice < amazonTotalCost){
        highestPrice = amazonTotalCost;
        //minimum = "AMAZON";
    }
    cout << endl;
    
    
    
    //Display of all variables and literals
    cout << "RENT/DAY" << setw(19) << "# of DAYS" << setw(13) << "SERVICE" << setw(16) << "TOTAL" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << rentPerDayNetflix << setw(19) << numOfDays << setw(16) << "NETFLIX"  << setw(17) << netflixTotalCost << endl;
    cout << rentPerDayVudu << setw(19) << numOfDays << setw(16) << "VUDU" << setw(17) << vuduTotalCost << endl;
    cout << rentPerDayHulu << setw(19) << numOfDays << setw(16) << "HULU" << setw(17) << huluTotalCost << endl;
    cout << rentPerDayDisney << setw(19) << numOfDays << setw(16) << "DISNEY" << setw(17) << disneyTotalCost << endl;
    cout << rentPerDayAmazon << setw(19) << numOfDays << setw(16) << "AMAZON" << setw(17) << amazonTotalCost << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "|   Lowest price to rent \""<< movieTitle << "\"" << " is " << minimum << ", you may save $" << (highestPrice-minimumPrice)<< "    |" << endl;
    cout << endl;
    
    
    
    return 0;
}
