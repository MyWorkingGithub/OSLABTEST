#include <iostream>
#include <vector>
using namespace std;

bool isWinningMove(vector<vector<bool>> board, int x, int y)
{

    int count = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j])
            {
                count++;
            }
        }
    }
    if (count == 1)
    {
        return true;
    }
    for (int i = x; i < board.size(); i++)
    {
        for (int j = y; j < board[0].size(); j++)
        {
            board[i][j] = false;
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] && isWinningMove(board, i, j))
            {
                return false;
            }
        }
    }

    return true;
}

vector<pair<int, int>> getWinningMoves(vector<vector<bool>> &board)
{
    vector<pair<int, int>> moves;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] && isWinningMove(board, i, j))
            {
                moves.push_back({i, j});
            }
        }
    }

    return moves;
}

int main()
{

    std::vector<std::vector<bool>> grid;
    int input = 0;
    std::cout << "Enter the number of Rows: ";
    std::cin >> input;
    int array[input];

    std::cout << "Now enter the number of columns in each row:\n";
    for (int i = 0; i < input; ++i)
    {
        std::cin >> array[i];
    }

    for (int i = 0; i < input; i++)
    {
        int j = 0;
        std::vector<bool> temp;
        for (; j < array[i]; ++j)
        {
            temp.push_back(true);
        }
        for (int k = j; k < array[0]; k++)
        {
            temp.push_back(false);
        }
        grid.push_back(temp);
    }

    grid[0][0] = false;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    vector<pair<int, int>> winningMoves = getWinningMoves(grid);

    cout << "Winning moves:" << endl;
    if (winningMoves.empty())
    {
        std::cout << "There is no winning move\n";
    }
    else
    {

        for (auto move : winningMoves)
        {
            cout << "(" << move.first << ", " << move.second << ")" << endl;
        }
    }

    return 0;
}
