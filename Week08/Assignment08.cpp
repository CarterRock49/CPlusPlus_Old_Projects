#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
This program takes input from a file and finds the average and outputs that to the terminal through usage of arrays,
loops, a struct, and muliple functions inside a class.
*/
//const varibles that can't be changed
const int ARRAY_WIDTH = 4;
const int ARRAY_LENGTH = 10;

class bowling2{
    // private can't be accessed outside the class
    private:
        string name2;
        struct bowling{
            string name;
            int scores[ARRAY_WIDTH];
            double average;
        };
    // public can be accessed outside the class
    public:
        bowling2();
        //constructor
        bowling2(string name1){
            name2 = name1;
        }
        //declare struct
        bowling realbowling[ARRAY_LENGTH];
        // a public function that reads and inputs the file into arrays
        void GetBowlingData(){
            //declares varibles
            ifstream fs;
            string cha;
            int first;
            int sec;
            int third;
            int four;
            int index2 = 0;
            //opens file and checks to make sure it was successful
            fs.open(name2);
            if(!fs){
                cout << "Failure" << endl;
            } else {
                cout << "Success" << endl;
            }
            //runs till the end of the file and iterates through rows
            while (!fs.eof() && fs >> cha >> first >> sec >> third >> four){
                //fill name array from file
                realbowling[index2].name = cha;
                //loop interates through cols and fill array with numbers from file
                for (int index = 0;index < ARRAY_WIDTH; index++){
                    if (index == 0){
                        realbowling[index2].scores[index] = first;
                    } else if (index == 1){
                        realbowling[index2].scores[index] = sec;
                    } else if (index == 2){
                        realbowling[index2].scores[index] = third;
                    } else if (index == 3){
                        realbowling[index2].scores[index] = four;
                    }
                }
                index2++;
            }
        }

        // a public function that takes the previous inputed array and finds some averages and inputs it into the struct
        void GetAverageScore(){
            //declare varibles
            double average = 0;
            //loop iterates through rows
            for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
                //loop interates through cols
                for (int index = 0;index < ARRAY_WIDTH; index++){
                    //adds each colomn in a row
                    average = average + realbowling[index2].scores[index];
                }
                //gets average of each row and puts it into the struct
                realbowling[index2].average = average/(ARRAY_WIDTH);
                average = 0;
            }
        }

        // a public function that takes all the struct info acquired and prints them to the terminal
        void PrettyPrintResults(){
            cout << "The following information is the bowler names, scores, and averages respectively:" << endl;
            //loop iterates through rows
            for (int index2 = 0; index2 < ARRAY_LENGTH; index2++){
                cout << realbowling[index2].name << " ";
                //loop interates through cols
                for (int index = 0;index < ARRAY_WIDTH; index++){
                    //loop interates through rows 
                    cout << realbowling[index2].scores[index] << " ";
                }
                cout << realbowling[index2].average << endl;
            }
            //press any key to continue
            system("pause");
        }
};


int main(int argc, char* argv[]){
    //grabs file name
    string name;
    name = argv[1];
    // create object
    bowling2 object1(name);
    //calling member functions
    object1.GetBowlingData();
    object1.GetAverageScore();
    object1.PrettyPrintResults();

}

