#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
enum class State
{
    Empty,
    Obstacle
};

vector<State> ParseLine(string line)
{
    istringstream my_stream(line);
    int n;
    char c;
    vector<State> row;
    while (my_stream >> n >> c && c == ',')
    {
        switch(n)
        {
        case 0:
            row.push_back(State::Empty);
            break;
        case 1:
            row.push_back(State::Obstacle);
            break;
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    if (myfile)
    {
        string line;
        while (getline(myfile, line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

string CellString(State cell)
{
    switch(cell)
    {
        case State::Obstacle: return "⛰️   ";
        case State::Empty : return "0   ";
    }
}

void PrintBoard(const vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

int main()
{
    auto board = ReadBoardFile("/home/chandradeep_p/!!!!!!!!!!!!!!!!!!!!!!!!!/cpp-nanodegree/Board/files/1.board");
    PrintBoard(board);
}