#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// output format to use IDENTICALLY:
//BSH:Saru> ./filesize input.3lines input.1line 
//program: ./filesize
// input.3lines: 3
// input.1line: 1
//

//I decided to use a function since you said in class that if a function can't fit on the screen,
//then it is too large. It was a little unnecessary for this assignment but I figured it would be a good practice
//for the rest of the class
// Input:
// String passed by reference that takes the name of the file
// No Output.
// Opens the file passed in the form of a string and outputs how many lines are in the string.
void linesoffile(string& filename);

int main(int argc, char* argv[])
{
    // just to get you started, this is how to refer to the arguments that were passed
    // for (int arg = 0; arg < argc; ++arg)
    // {
    //     std::cout << "argv[" << arg << "]: " << argv[arg] << '\n' ;
    // }

    //this is here to make sure that the "program: ./filesize" is always outputted.
    cout << "program: " << argv[0] << endl;

    //goes through each argument in the command input and sends them in the form of strings to the linesoffile function.
    for(int arg = 1; arg < argc; arg++)
    {
        string filename = argv[arg];
        linesoffile(filename);
    }

    exit(0); // this means that the program executed correctly!
}

void linesoffile(string& filename)
{
    int count = 0;
    ifstream ifs;
    ifs.open(filename);
    string garbage;
    if(ifs.is_open())
    {
        while(getline(ifs, garbage))
        {
            count++;
        }
    }
    else
    {
        count = -1;
    }
    cout << " " << filename << ": " << count << endl;
}