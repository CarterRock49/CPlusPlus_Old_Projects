#include <iostream>

using namespace std;

int main()
{
    //intro print
    cout << "*******************************************************************" << endl;
    cout << "*************** Welcome to my first program ***********************"  << endl;
    cout << "Convert a large number of seconds into hours, minutes, and seconds."  << endl;
    cout << "*******************************************************************" << endl << endl;
    cout << "Please enter a large number of seconds:";
    //declare varibles
    int input_secs;
    float minute;
    float hour;
    //input and maths
    cin >> input_secs;
    minute = input_secs / 60;
    hour = minute / 60;
    //prints varibles
    cout << "\nThe number of hours in the number is:" << hour;
    cout << "\nThe number of minutes in the number is:" << minute;
    cout << "\nThe number of seconds in the number is:" << input_secs << endl;
    //press any key to continue
    system("pause");
    return 0;
}