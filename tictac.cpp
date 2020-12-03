#include <iostream>
#include <cstdlib>
#include <ctime>

class GameBoard
{
private:
    const int size = 3;
    int array[3][3];
    int row;
    int column;
    int move = 1;
    int winner;
public:
    void FillArray();
    void ShowArray();
    int Move();
    void MakeMove();
    void CheckMove();
    int OptimalMove();
    void RandomMove();
    int CheckWinner();
    void ChooseWinnner();
};

int main()
{
    GameBoard gameBoard;
    gameBoard.FillArray();
    gameBoard.ShowArray();
    while (gameBoard.CheckWinner() != 0)
    {
        if (gameBoard.Move() == 1)
        {
            gameBoard.MakeMove();
        }
        gameBoard.CheckWinner();
        if (gameBoard.Move() == 2)
        {
            if (gameBoard.OptimalMove() != 1)
            {
                gameBoard.RandomMove();
            }
        }
        gameBoard.CheckWinner();
        gameBoard.ShowArray();
    }
    gameBoard.ChooseWinnner();
}

void GameBoard::FillArray()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            array[i][j] = 0;
        }
    }
}
void GameBoard::ShowArray()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] == 0) std::cout << "-";
            if (array[i][j] == 1) std::cout << "X";
            if (array[i][j] == 2) std::cout << "O";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
int GameBoard::Move()
{
    return move;
}
void GameBoard::CheckMove()
{
    if (array[row][column] != 0)
    {
        MakeMove();
    }
}
void GameBoard::MakeMove()
{
    std::cout << "Make a move (write the number of the row and column) " << std::endl;
    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Column: ";
    std::cin >> column;
    /*CheckMove();*/
    array[row - 1][column - 1] = 1;
    move = 2;
}

void GameBoard::RandomMove()
{
    srand(time(NULL));
    row = rand() % 3;
    column = rand() % 3;
    if (array[row][column] == 0)
    {
        array[row][column] = 2;
        move = 1;
    }
    else RandomMove();
}
int GameBoard::CheckWinner()
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (((array[i][0] == 2) || (array[i][0] == 1)) && ((array[i][0] == array[i][1]) && (array[i][0] == array[i][2])))
        {
            if (array[i][0] == 2) winner = 2;
            else winner = 1;
            move = 0;
            result = 0;
            break;
        }
        if (((array[0][i] == 2) || (array[0][i] == 1)) && ((array[0][i] == array[1][i]) && (array[0][i] == array[2][i])))
        {
            if (array[0][i] == 2) winner = 2;
            else winner = 1;
            move = 0;
            result = 0;
            break;
        }
        if (((array[0][0] == 2) || (array[0][0] == 1)) && ((array[0][0] == array[1][1]) && (array[0][0] == array[2][2])))
        {
            if (array[0][0] == 2) winner = 2;
            else winner = 1;
            move = 0;
            result = 0;
            break;
        }
        if (((array[0][2] == 2) || (array[0][2] == 1)) && ((array[0][2] == array[1][1]) && (array[0][2] == array[2][0])))
        {
            if (array[0][2] == 2) winner = 2;
            else winner = 1;
            move = 0;
            result = 0;
            break;
        }
    }
    if (move != 0) return 1; else return result;
}
int GameBoard::OptimalMove()
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if ((array[i][0] == array[i][1]) && (array[i][0] != 0) && (array[i][2] == 0))
        {
            array[i][2] = 2;
            result = 1;
            break;
        }
        if ((array[i][1] == array[i][2]) && (array[i][1] != 0) && (array[i][0] == 0))
        {
            array[i][0] = 2;
            result = 1;
            break;
        }
        if ((array[i][0] == array[i][2]) && (array[i][0] != 0) && (array[i][1] == 0))
        {
            array[i][1] = 2;
            result = 1;
            break;
        }
        if ((array[0][i] == array[1][i]) && (array[0][i] != 0) && (array[2][i] == 0))
        {
            array[2][i] = 2;
            result = 1;
            break;
        }
        if ((array[1][i] == array[2][i]) && (array[1][i] != 0) && (array[0][i] == 0))
        {
            array[0][i] = 2;
            result = 1;
            break;
        }
        if ((array[0][i] == array[2][i]) && (array[0][i] != 0) && (array[1][i] == 0))
        {
            array[1][i] = 2;
            result = 1;
            break;
        }
        if ((array[0][0] == array[1][1]) && (array[0][0] != 0) && (array[2][2] == 0))
        {
            array[2][2] = 2;
            result = 1;
            break;
        }
        if ((array[1][1] == array[2][2]) && (array[1][1] != 0) && (array[0][0] == 0))
        {
            array[0][0] = 2;
            result = 1;
            break;
        }
        if ((array[0][0] == array[2][2]) && (array[0][0] != 0) && (array[1][1] == 0))
        {
            array[1][1] = 2;
            result = 1;
            break;
        }
        if ((array[0][2] == array[1][1]) && (array[0][2] != 0) && (array[2][0] == 0))
        {
            array[2][0] = 2;
            result = 1;
            break;
        }
        if ((array[1][1] == array[2][0]) && (array[1][1] != 0) && (array[0][2] == 0))
        {
            array[0][2] = 2;
            result = 1;
            break;
        }
        if ((array[0][2] == array[2][0]) && (array[0][2] != 0) && (array[1][1] == 0))
        {
            array[1][1] = 2;
            result = 1;
            break;
        }
    }
    move = 1;
    if (result == 1) return 1; else return 0;  
}
void GameBoard::ChooseWinnner()
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i][j] != 0) counter++;
        }
    }
    if (counter == 9)
    {
        std::cout << "NOBODY WINS!";
    }
    if (winner == 1)
    {
        std::cout << "YOU WON!";
    }
    if (winner == 2)
    {
        std::cout << "YOU LOSE!";
    }

}