#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// using std::cout;
// using std::ifstream;
// using std::istringstream;
// using std::sort;
// using std::string;
// using std::vector;
// using std::abs;

enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
};

// directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

std::vector<State> ParseLine(std::string line)
{
    std::istringstream sLine(line);
    int n;
    char c;
    std::vector<State> row;

    while (sLine >> n >> c && c == ',')
    {
        if (n == 0)
        {
            row.push_back(State::kEmpty);
        }
        else
        {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

std::vector<std::vector<State>> ReadBoardFile(std::string path)
{
    std::ifstream myfile(path);
    std::vector<std::vector<State>> board{};

    if (myfile)
    {
        std::string line;
        while (std::getline(myfile, line))
        {
            std::vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

bool Compare(std::vector<int> node1, std::vector<int> node2)
{
    float f1 = node1[2] + node1[3];
    float f2 = node2[2] + node2[3];

    return f1 > f2;
}

bool CheckValidCell(int x, int y, std::vector<std::vector<State>> &grid)
{
    bool limit_x = (x >= 0 && x < grid.size());
    bool limit_y = (y >= 0 && x < grid[0].size());

    if (limit_x && limit_y)
    {
        return grid[x][y] == State::kEmpty;
    }
    else
    {
        return false;
    }
}

int Heuristic(int x1, int y1, int x2, int y2)
{
    return std::abs(x2 - x1) + std::abs(y2 - y1);
}

void CellSort(std::vector<std::vector<int>> *v)
{
    std::sort(v->begin(), v->end(), Compare);
}

void AddToOpen(int x, int y, int g, int h, std::vector<std::vector<int>> &openNodes, std::vector<std::vector<State>> &grid)
{
    std::vector<int> params{x, y, g, h};
    openNodes.push_back(params);
    grid[x][y] = State::kClosed;
}

void ExpandNeighbors(const std::vector<int> &current, int goal[2], std::vector<std::vector<int>>& openList, std::vector<std::vector<State>>& grid)
{
    int x = current[0];
    int y = current[1];
    int g = current[2];

    for (std::size_t i = 0; i < 4; i++)
    {
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        if (CheckValidCell(x2, y2, grid))
        {
            int g2 = g + 1;
            int h2 = Heuristic(x2, y2, goal[0], goal[1]);
            AddToOpen(x2, y2, g2, h2, openList, grid);
        }
    }
}

std::vector<std::vector<State>> Search(std::vector<std::vector<State>> board, int init[2], int goal[2])
{
    std::vector<std::vector<int>> open{};

    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = Heuristic(x, y, goal[0], goal[1]);

    AddToOpen(x, y, g, h, open, board);

    while (open.size() > 0)
    {
        CellSort(&open);

        auto current = open.back();
        open.pop_back();
        int x = current[0];
        int y = current[1];
        board[x][y] = State::kPath;

        if (x == goal[0] && y == goal[1])
        {
            board[init[0]][init[1]] = State::kStart;
            board[goal[0]][goal[1]] = State::kFinish;
            return board;
        }

        ExpandNeighbors(current, goal, open, board);
    }

    std::vector<std::vector<State>> solution{};
    std::cout << "No path found"
              << "\n";
    return solution;
}

std::string CellString(State cell)
{
    switch (cell)
    {
    case State::kObstacle:
        return "⛰️   ";
    
    case State::kPath:
        return "🚗   ";
    
    case State::kStart: 
    return "🚦   ";
    
    case State::kFinish: 
    return "🏁   ";
    
    default:
        return "0   ";
    }
}

void PrintBoard(const std::vector<std::vector<State>> board)
{
    for (std::size_t i = 0; i < board.size(); i++)
    {
        for (std::size_t j = 0; j < board[i].size(); j++)
        {
            std::cout << CellString(board[i][j]);
        }
        std::cout << "\n";
    }
}

int main()
{
    int init[2]{0, 0};
    int goal[2]{4, 5};

    auto board = ReadBoardFile("/home/chandradeep_p/!!!!!!!!!!!!!!!!!!!!!!!!!/cpp-nanodegree/C++ Foundations/files/1.board");
    auto solution = Search(board, init, goal);
    PrintBoard(solution);

    return 0;
}