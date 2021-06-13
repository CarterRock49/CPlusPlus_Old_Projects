#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

/*
This program is an item shipping calculator that takes user input and outputs that info plus a shipping cost and
*/
//declares const varibles that can't be changed
const int shippingone = 50;
const int shippingtwo = 100;
const int shippingthree = 150;
const int fragilecost = 2;
const string sOutfilename = "order.txt";

int main(){
    //stream object
    ofstream foutstream;
    foutstream.open(sOutfilename);
    //declare varibles
    string name;
    string fragile;
    bool frag;
    float order;
    string des;
    float cost = 0;
    //intro print, setfill replaces the default space with the desired
    cout << setfill('.') << setw(53) << '.' << endl;
    cout <<  "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(53) << '.' << endl << endl;
    // writes intro print the the txt file
    foutstream <<  setfill('.') << setw(53) << '.' << endl <<  "ITCS 2530 - Programming Assignment for week #3" << endl << setw(53) << '.' << endl << endl;
    //requests info form user then inputs that into varibles
    cout << "Please enter the item name (no spaces)" << setw(16) << ':';
    cin >> name;
    //writes first input to txt file
    foutstream <<  "Please enter the item name (no spaces)" << setw(16) << ':' << name;
    //convert string varible into all uppercase
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    cout << "Is the item fragile? (y=yes/n=no)" << setw(21) << ':';
    cin >> fragile;
    foutstream << endl <<"Is the item fragile? (y=yes/n=no)" << setw(21) << ':' << fragile;
    //convert string varible into all uppercase
    transform(fragile.begin(), fragile.end(), fragile.begin(), ::toupper);
    //checks to make sure that the input waS vaild and if not it displays a message and ends
    if (!(fragile == "Y" ||  fragile == "N")){ 
        cout <<"Invaild entry, exiting";
        system("pause");
        return 0;
    }
    //requests info form user then inputs that into varibles
    cout << "Please enter your order total" << setw(25) << ':';
    cin >> order;
    cout << "Please enter destination. (usa/can/aus/mars)" << setw(15) << ':';
    cin >> des;
    foutstream << endl << "Please enter your order total" << setw(25) << ':' << order << endl << "Please enter destination. (usa/can/aus)" << setw(15) << ':' << des;
    //convert string varible into all uppercase
    transform(des.begin(), des.end(), des.begin(), ::toupper);
    //checks to make sure that the input waS vaild and if not it displays a message and ends
    if (!(des == "CAN" || des == "USA" || des == "AUS")){ 
        cout << "Invaild entry, exiting" << endl;
        system("pause");
        return 0;
    }
    //if else to add the proper shipping cost
    // under 50
    if (order <= shippingone){
        // if  else statement for location
        if (des == "USA"){
            cost = cost + 6;
        } else if(des == "CAN"){
            cost = cost + 8;
        } else if(des == "AUS"){
            cost = cost + 10;
        } else {
            
        }
    // 50.01 to 100
    } else if(order > shippingone && order <= shippingtwo){ 
        // if  else statement for location
        if (des == "USA"){
            cost = cost + 9;
        } else if(des == "CAN"){
            cost = cost + 12;
        } else if(des == "AUS"){
            cost = cost + 14;
        } else {
            cost = cost + 11000;
        }
    // 100.01 to 150
    } else if(order > shippingtwo && order <= shippingthree){
        // if  else statement for location
        if (des == "USA"){
            cost = cost + 12;
        } else if(des == "CAN"){
            cost = cost + 15;
        } else if(des == "AUS"){
            cost = cost + 17;
        } else {
            cost = cost + 17000;
        }
    //over 150 doesn't add shipping
    }
    //add fragile shipping cost if shipping is not free and the item is fragile
    if (order > shippingthree && fragile == "Y"){
        cost = cost + fragilecost;
    }
    //finds final cost
    order = order + cost;

    //prints end reults
    cout << endl << "Your item is" << setw(30) << ":" << name << endl;
    cout << "Your shipping cost is" << setw(21) << "$" << setprecision(2) << fixed << cost << endl;
    cout << "You are shipping to" << setw(23) << ":" << des << endl;
    cout << "Your total shipping costs are" << setw(13) << "$" << order << endl << endl;

    //writes end result to txt file
    foutstream << endl << endl << "Your item is" << setw(30) << ":" << name << endl << "Your shipping cost is" << setw(21) << "$" << setprecision(2) << fixed << cost << endl<< "You are shipping to" << setw(23) << ":" << des << endl<< "Your total shipping costs are" << setw(13) << "$" << order << endl << endl;

    cout << setfill('-') << setw(51) << "Thank You!" << endl << endl;

    //press any key to continue
    system("pause");
    return 0;
}