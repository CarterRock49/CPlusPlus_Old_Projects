#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

/*
given a file in same folder and ran via command prompt the program
determines how many of specfic letters are in the file and 
the total count of letters through the use of a loop and 
a decision structure.
*/

int main(int argc, char* argv[]){

    ifstream fs;
    //grabs file name and opens it
    string name;
    name = argv[1];
    fs.open(name);
    //declare varibles
    char ch;
    string cha;
    int Acount = 0;
    int Ecount = 0;
    int Icount = 0;
    int Ocount = 0;
    int Ucount = 0;
    int Xcount = 0;
    int Ycount = 0;
    int Zcount = 0;
    int lettercount = 0;
    //intro print
    cout << setfill('*') << setw(67) << '*' << endl;
    cout << setw(15) << '*' << " Welcome to my Letter Count Program " << setw(16) << '*' << endl;
    cout << setw(67) << '*' << endl << endl;
    // prints file name
    cout << "Analyzing file '" << name << "'..."  << endl;
    //loop that repeats the code inside until the end of the file
    while (!fs.eof() && fs >> ch){
        //converts all letters to upper case so that all desired letters are counted
        cha = ch;
        transform(cha.begin(), cha.end(), cha.begin(), ::toupper);
        //decision structure to count desired letters by adding one each time a letter is found
        if (cha == "A"){
            lettercount++;
            Acount++;
        } else if (cha == "E"){
            lettercount++;
            Ecount++;
        } else if (cha == "I"){
            lettercount++;
            Icount++;
        } else if (cha == "O"){
            lettercount++;
            Ocount++;
        } else if (cha == "U"){
            lettercount++;
            Ucount++;
        } else if (cha == "X"){
            lettercount++;
            Ucount++;
        } else if (cha == "Y"){
            lettercount++;
            Ucount++;
        } else if (cha == "Z"){
            lettercount++;
            Ucount++;
        }  
    }
    //prints the end results
    cout << endl << "The number of A's: " << setfill('.') << setw(52) << Acount << endl;
    cout << "The number of E's: " << setfill('.') << setw(52) << Ecount << endl;
    cout << "The number of I's: " << setfill('.') << setw(52) << Icount << endl;
    cout << "The number of O's: " << setfill('.') << setw(52) << Ocount << endl;
    cout << "The number of U's: " << setfill('.') << setw(51) << Ucount << endl;
    cout << "The number of X's: " << setfill('.') << setw(51) << Xcount << endl;
    cout << "The number of Y's: " << setfill('.') << setw(51) << Ycount << endl;
    cout << "The number of Z's: " << setfill('.') << setw(51) << Zcount << endl;
    cout << "The letterd count is: " << setfill('.') << setw(51) << lettercount << endl;
    //press any key to continue
    system("pause");
    return 0;
}