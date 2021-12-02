#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

/*
The program takes in a file of numbers in one function and based on user input in another will either sort the numbers in each 
row by highest to lowest or lowest to highest. Additionally the program will has a function to print it the terminal and the 
user will is able to edit integers in the array. Finally a function that writes the array to a file in the last function.
*/
//const varibles that can't be changed


/*

ALL CODE WRITTEN BY CARTER ROCK

*/

const int ARRAY_WIDTH = 4;
const int ARRAY_LENGTH = 10;
const string q = "Q";
const string e = "E";
const string l = "L";
const string h = "H";
const string sOutfilename = "Results.txt";
//Declares all function besides main
void GetData(string name, int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]);
void PrintResultsAndEdit(int (numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]);
void LowestToHighest(int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]);
void HighestToLowest(int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]);
void WriteToFile(int (numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]);

int main(int argc, char* argv[]){
    //grabs file name and declares varibles
    string input;
    string name;
    name = argv[1];
    //declares array
    int numberarray[ARRAY_LENGTH][ARRAY_WIDTH];
    //calls function
    GetData(name, numberarray);
    while(input != q){
        cout << endl <<"If you would not like sort or edit anything else press 'Q' and the array will write to a new txt file otherwise input anything else to continue:";
        cin >> input;
        //convert string to uppercase for checking if the while loop should continue
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input != q){
            cout << endl <<"if you would like to sort highest to lowest enter 'H', if you would like to sort lowest to highest enter 'L', and if you would like to see and edit the array press 'E':";
            cin >> input;
            //convert string to uppercase for checking the if else statements
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            //if else structure to call the correct function
            if (input == h){
                HighestToLowest(numberarray);
            } else if (input == l){
                LowestToHighest(numberarray);
            } else if (input == e){
                PrintResultsAndEdit(numberarray);
            } else {
                cout << endl << "That isn't a vaild input try again.";
            }
        } 
    }
    WriteToFile(numberarray);
}

// a function that reads and inputs the file into an array
void GetData(string name, int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]){
    //declares varibles
    ifstream fs;
    int first;
    int sec;
    int third;
    int four;
    int index2 = 0;
    //opens file and checks to make sure it was successful
    fs.open(name);
    if(!fs){
        cout << "Failure" << endl;
    } else {
        cout << "Success" << endl;
    }
    //runs till the end of the file and iterates through rows
    while (!fs.eof() && fs >> first >> sec >> third >> four){
        //loop interates through cols and fill array with numbers from file
        for (int index = 0;index < ARRAY_WIDTH; index++){
            if (index == 0){
                numberarray[index2][index] = first;
            } else if (index == 1){
                numberarray[index2][index] = sec;
            } else if (index == 2){
                numberarray[index2][index] = third;
            } else if (index == 3){
                numberarray[index2][index] = four;
            }
        }
        index2++;
    }
}


// a function that print the array from the file to a terminal and allows you to edit it
void PrintResultsAndEdit(int (numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]){
    //declare varibles
    string input;
    int temp1;
    int temp2;
    int tempinput;
    //
    cout << "The following information is the array of numbers:" << endl;
    //loop interates through cols
    for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
        //loop iterates through rows 
        for (int index = 0;index < ARRAY_WIDTH; index++){
            cout << numberarray[index2][index] << " ";
        }
        cout << endl;
    }
    while (input != q){
        cout << "If you would not like to edit any varibles in the array press 'Q' otherwise input anything else to edit:";
        //input
        cin >> input;
        //convert string to uppercase for checking if the while loop should continue
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        //check if user wants to edit
        if (input != q){
            cout << endl << "Enter a row to edit starting at 0 for the first row (don't go higher than " << ARRAY_LENGTH - 1 << "):";
            cin >> temp1;
            cout << endl << "Enter a column to edit starting at 0 for the first row (don't go higher than " << ARRAY_WIDTH - 1 << "):";
            cin >> temp2;
            cout << endl << "Enter a number to insert into that place (don't insert numbers with decimals):";
            cin >> tempinput;
            numberarray[temp1][temp2] = tempinput;
        }
    }
}

//a function that compare all number in a row to each other and sort them lowest to highest
void LowestToHighest(int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]){
    //loop interates through rows
    for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
        //loop interates through cols
        for (int index = 0;index < ARRAY_WIDTH; index++){
            for (int index3 = 0;index3 < ARRAY_WIDTH; index3++){
                //swaps number to put lowest one in front
                if (numberarray[index2][index] < numberarray[index2][index3]){
                    swap(numberarray[index2][index], numberarray[index2][index3]);
                }
            }
        }
    }
    cout << endl << "SORTED";
}

//a function that compare all number in a row to each other and sort them highest to lowest
void HighestToLowest(int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]){
    //loop interates through rows 
    for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
        //loop interates through cols 
        for (int index = 0;index < ARRAY_WIDTH; index++){
            for (int index3 = 0;index3 < ARRAY_WIDTH; index3++){
                //swaps numbers to put highest one in front
                if(numberarray[index2][index] > numberarray[index2][index3]){
                    swap(numberarray[index2][index], numberarray[index2][index3]);
                }
            }
        }
    }
    cout << endl << "SORTED";
}

// a function that prints the array to a filoe called results
void WriteToFile(int (numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]){
    //stream object
    ofstream foutstream;
    foutstream.open(sOutfilename);
    //loop interates through cols
    for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
        //loop iterates through rows 
        for (int index = 0;index < ARRAY_WIDTH; index++){
            foutstream <<  numberarray[index2][index] << " ";
        }
        foutstream <<  endl;
    }  
}