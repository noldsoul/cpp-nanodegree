/*
   Write a function calledReadBoardFile which reads 
   lines from a file. Write each line to cout, followed by 
   a newline character "\n". The function should accept 
   a string argument, which represents the path to the file. 
   For now, ReadBoardFile does not need to return anything, 
   so use a void return type.
   Call ReadBoardFile from main using the argument "1.board".
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void ReadBoardFile(std::string file)
{
    ifstream my_file;
    my_file.open(file);
    if (my_file)
    {
        string line;
        while(getline(my_file, line))
        {
            cout << line << "\n";
        }
    }
}


int main()
{

    ReadBoardFile("/home/chandradeep_p/!!!!!!!!!!!!!!!!!!!!!!!!!/cpp-nanodegree/Board/files/1.board");
    return 0;
}
