#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<int> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<int> row;
    while (sline >> n >> c && c == ',') {
      row.push_back(n);
    }
    return row;
}

vector<vector<int>> ReadBoardFile(string path) {
  ifstream myfile(path);
  vector<vector<int>> board;
  int count = 0;
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<int> int_line = ParseLine(line);
      board.push_back(int_line);
      for (int i =0; i< int_line.size();i++)
      {
        cout<<int_line[i];
      }
      cout<<"\n"<<count<<"\n";
      count+=1;
    }
  }
  cout<<count<<std::endl;
  return board;
}

void PrintBoard(const vector<vector<int>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j];
    }
    cout << "\n";
  }
}

int main() {
  // Store the output of ReadBoardFile in the "board" variable.
  vector<vector<int>> board = ReadBoardFile("/home/chandradeep_p/!!!!!!!!!!!!!!!!!!!!!!!!!/cpp-nanodegree/C++ Foundations/files/1.board");
  // PrintBoard(board);
  cout<< board.size();
}