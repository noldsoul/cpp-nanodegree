#include <iostream>
#include <fstream>
#include <vector>

void PrintBoard(std::vector<std::vector<int>> board){
    for (int i=0; i< board.size(); i++){
        for (int j=0; j < board.size(); j++){
            std::cout<<board[i][j];
        }
        std::cout<< "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> board{{0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 1, 0}};
    PrintBoard(board);
    return 0;
}