#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

//Declares all function besides main
void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& xxxsboard);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int xxxsboard);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int xxxsboard);
//const varibles that can't be changed
const int smallboard = 175;
const int medboard = 190;
const int largeboard = 200;
const int xxxsboards = 100;

/*
The program gives the user a mulitude of options to go about purchasing 
surf boards via the use of loops, decision structures, and muliple functions.
*/
int main(){
    //Intro print
    cout << setfill('*') << setw(67) << '*' << endl;
    cout << setw(5) << '*' << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << '*' << endl;
    cout << setw(67) << '*' << endl << endl;
    //declare varibles
    char select;
    string select2;
    int small = 0;
    int med = 0;
    int large = 0;
    int xxxs = 0;
    //print user options
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit program press 'Q'" << endl << endl;
    //infinite loop so that the user can make as many selections as need
    while(true){
    //input for discision structure
    cout << "Please enter selection: ";
    cin >> select;
    cout << endl;
    //converts all letters to upper case so that all desired letters checked
    select2 = select;
    transform(select2.begin(), select2.end(), select2.begin(), ::toupper);
    //discision structure based on previous user input that calls different functions
    if (select2 == "S"){
        ShowUsage();
    } else if (select2 == "P"){
        MakePurchase(small ,med ,large , xxxs);
    } else if (select2 == "C"){
        DisplayPurchase(small ,med ,large ,xxxs);
    } else if (select2 == "T"){
        DisplayTotal(small ,med ,large ,xxxs);
    } else if (select2 == "Q"){
        cout << "Thank you" << endl;
        //press any key to continue
        system("pause");
        return 0;
    } else {
        cout << "That was a bad input try again";
    }
}}

// a function to show the user how to use the program
void ShowUsage(){
    //clears the console
    system("clear");
    //Intro print
    cout << setfill('*') << setw(67) << '*' << endl;
    cout << setw(5) << '*' << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << '*' << endl;
    cout << setw(67) << '*' << endl << endl;
    //print user options
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit program press 'Q'" << endl << endl;
}

//varible passed in by reference to change the values and a function to sell surfboards
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& xxxsboard){
    //selection print
    cout << "Please enter the quanity and type (S=small, M=medium, L=Large, X=XXXSmall) of surfboards you would like to purchase: ";
    //declare varibles and take user input
    int quantity;
    char select;
    string select2;
    cin >> quantity >> select;
    //converts all letters to upper case so that all desired letters checked
    select2 = select;
    transform(select2.begin(), select2.end(), select2.begin(), ::toupper);
    //if else statement to add the right amount to the right varible
    if (select2 == "S"){
        iTotalSmall = iTotalSmall + quantity;
    } else if (select2 == "M"){
        iTotalMedium = iTotalMedium + quantity;
    } else if (select2 == "L"){
        iTotalLarge = iTotalLarge + quantity;
    } else if (select2 == "X"){
        xxxsboard = xxxsboard + quantity;
    } else {
        cout << "That was a bad input try again";
    }
}

//varible passed in as const and function to show the number of surfboards of each size sold
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int xxxsboard){
    //series of if statements to print total number only if a minimum of one has been picked out
    if (iTotalSmall > 0){
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    }
    if (iTotalMedium > 0){
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;
    }
    if (iTotalLarge > 0){
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    }
    if (xxxsboard > 0){
        cout << "The total number of xxxsmall surfboards is " << xxxsboard << endl;
    }
}

//varible passed in as const and a function to show the total amount of money made
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int xxxsboard){
    //declare varibles and find total
    int smalltotal = smallboard * iTotalSmall;
    int medtotal = medboard * iTotalMedium;
    int largetotal = largeboard * iTotalLarge;
    int xxxstotal = xxxsboards * xxxsboard;
    int totalcost = largetotal + medtotal + smalltotal + xxxstotal;
    //series of if statements to print total number and costs only if a minimum of one has been picked out
    if (iTotalSmall > 0){
        cout << "The total number of small surfboards is " << iTotalSmall << "at a total of $" << smalltotal << endl;
    }
    if (iTotalMedium > 0){
        cout << "The total number of medium surfboards is " << iTotalMedium << "at a total of $" << medtotal << endl;
    }
    if (iTotalLarge > 0){
        cout << "The total number of large surfboards is " << iTotalLarge << "at a total of $" << largetotal << endl;
    }
    if (xxxsboard > 0){
        cout << "The total number of large surfboards is " << xxxsboard << "at a total of $" << xxxstotal << endl;
    }
    //print final amount due
    cout << "Amount due: " << totalcost << endl;
}   
