#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//declares const varibles that can't be changed.
const float contain = 2.76;
const float cost = 4.12;
const float profit = 1.45;

int main(){
    //intro print, setfill replaces the default space with the desired *
    cout << setfill('*') << setw(67) << '*' << endl;
    cout << setw(17) << '*' << " Welcome to my Second Program " << setw(19) << '*' << endl;
    cout << setw(67) << '*' << endl << endl;
    cout << "Please enter the total number of kilograms of cheese produced: ";
    //declare varibles
    int input_kilo;
    float con;
    float final_cost;
    float final_profit;
    //input and maths
    cin >> input_kilo;
    con = input_kilo / contain;
    //rounds to nearest integer
    con = round(con);
    // final math
    final_cost = con * cost;
    final_profit = con * profit;
    //outputs varibles in a coloumn with the final two varibles being rounded to the second decimal place
    cout << setfill(' ') << "The number of containers to hold the cheese is: "<< setw(23) << setprecision(0) << fixed << con << endl;
    cout << "The cost of producing " << con << " container(s) of cheese is: $" << setw(17) << setprecision(2) << final_cost << endl;
    cout << "The profits from producing "<< setprecision(0) << con << " container(s) of cheese is: $"<< setw(12) << setprecision(2) << final_profit << endl;
    //press any key to continue
    system("pause");
    return 0;
}