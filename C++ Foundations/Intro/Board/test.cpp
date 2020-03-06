#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using std::cout;
using std::istringstream;
using std::string;
using std::vector;

void PrintVector(vector<int> v)
{
    cout << "{ ";

    for (auto item : v)
    {
        cout << item << " ";
    }
    cout << "}"
         << "\n";
}
vector<int> ParseLine(string line)
{
    istringstream my_stream(line);
    int n;
    char c;
    vector<int> row;
    while(my_stream >> n >> c && c == ',')
    {
        row.push_back(n);
    }
    return row;
}

void TestParseLine()
{
    cout << "----------------------------------------------------------"
         << "\n";
    cout << "TestParseLine: ";
    string line = "0,1,0,0,0,0,";
    vector<int> solution_vect{0, 1, 0, 0, 0, 0};
    vector<int> test_vect;
    test_vect = ParseLine(line);
    if (test_vect != solution_vect)
    {
        cout << "failed"
             << "\n";
        cout << "\n"
             << "Test input string: " << line << "\n";
        cout << "Your parsed line: ";
        PrintVector(test_vect);
        cout << "\n";
    }
    else
    {
        cout << "passed"
             << "\n";
    }
    cout << "----------------------------------------------------------"
         << "\n";
    return;
}