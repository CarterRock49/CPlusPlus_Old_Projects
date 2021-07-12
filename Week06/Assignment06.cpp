#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
This program takes input from a file and finds the average and outputs that to the terminal through usage of arrays,
loop, and muliple functions.
*/
//const varibles that can't be changed
const int ARRAY_WIDTH = 4;
const int ARRAY_LENGTH = 10;
//Declares all function besides main
void GetBowlingData(string name, string (&namearray)[ARRAY_LENGTH], int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]);
void GetAverageScore(int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH], double (&averagearray)[ARRAY_LENGTH]);
void PrettyPrintResults(string (namearray)[ARRAY_LENGTH], int (numberarray)[ARRAY_LENGTH][ARRAY_WIDTH], double (averagearray)[ARRAY_LENGTH]);

int main(int argc, char* argv[]){
    //grabs file name
    string name;
    name = argv[1];
    //declares arrays
    string namearray[ARRAY_LENGTH];
    int numberarray[ARRAY_LENGTH][ARRAY_WIDTH];
    double averagearray[ARRAY_LENGTH];
    //calls functions
    GetBowlingData(name, namearray, numberarray);
    GetAverageScore(numberarray, averagearray);
    PrettyPrintResults(namearray, numberarray, averagearray);

}

// a function that reads and inputs the file into arrays
void GetBowlingData(string name, string (&namearray)[ARRAY_LENGTH], int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH]){
    //declares varibles
    ifstream fs;
    string cha;
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
    while (!fs.eof() && fs >> cha >> first >> sec >> third >> four){
        //fill name array from file
        namearray[index2] = cha;
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

// a functions that takes the previous inputed array and finds some averages and inputs it into a new array
void GetAverageScore(int (&numberarray)[ARRAY_LENGTH][ARRAY_WIDTH], double (&averagearray)[ARRAY_LENGTH]){
    //declare varibles
    double average;
    //loop iterates through rows
    for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
        //loop interates through cols
        for (int index = 0;index < ARRAY_WIDTH; index++){
            //adds each colomn in a row
            average =+ numberarray[index2][index];
        }
    //gets average of each row and puts it into another array
    averagearray[index2] = average/(ARRAY_WIDTH);
    }
}

// a function that takes all the arrays acquired and prints them to the terminal
void PrettyPrintResults(string (namearray)[ARRAY_LENGTH], int (numberarray)[ARRAY_LENGTH][ARRAY_WIDTH], double (averagearray)[ARRAY_LENGTH]){
    cout << "The following information is the bowler names, scores, and averages respectively:" << endl;
    //loop iterates through rows
    for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
        cout << namearray[index2] << " ";
        //loop interates through cols
        for (int index = 0;index < ARRAY_WIDTH; index++){
            //loop interates through rows 
            cout << numberarray[index2][index] << " ";
        }
        cout << averagearray[index2] << endl;
    }
    //press any key to continue
    system("pause");
}


