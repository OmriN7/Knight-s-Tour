//Function Commenting Format
/*/////////////////////////////////////////////////////////////////////
* Name:
*
* Inputs:
*       // Parameters //
*
*       // Variables //
*
*
* Outputs:
*       // Return Value //
*
* Description:
*
*/

///HEADER FILES
///////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring> //memset
#include <cstdio> //printf


///DEFINES
//////////////////////////////////////////////////////////////////////
using namespace std;

#define DEBUG 1



typedef struct
{
    int StepX;
    int StepY;
} KNIGHT_STEP_T, *KNIGHT_STEP_P;


const KNIGHT_STEP_T KnightStepTbl [8] =
{
    {2,1}, //0
    {1,2}, //1
    {-1,2}, //2
    {-2,1}, //3
    {-2,-1}, //4
    {-1,-2}, //5
    {1,-2}, //6
    {2,-1} //7

};

///PROTOTYPES
//////////////////////////////////////////////////////////////////////
int KnightsTour(int boardSize);
bool MoveLegal(int moveType, int boardSize, int* board, int currentX, int currentY);
void PrintBoard(int boardSize, int* board);
bool PushSequence(int * possibleMove, int boardSize);


int main(void)
{
    int boardSize = 8;

    KnightsTour(boardSize);
    return 0;
}

int KnightsTour(int boardSize)
{

    ///Variables
    int board[8][8];
    memset(board, -1, (boardSize*boardSize*sizeof(int)));

    //int * permutationSequence = (int *) malloc(sizeof(int) * boardSize * boardSize);


    int successfulPermutations = 0;

    int currentX = 0;
    int currentY = 0;

    int possibleMove = 0;

    bool everythingScanned = false;

    int knightsPlacedDown = 0;


    board[0][0] = possibleMove;
    knightsPlacedDown++;


    PrintBoard(boardSize, &board[0][0]);

    //Place down the first Knight
    ///Functionality
    while(!everythingScanned)
    {
        ///Evaluate next place place down queen
        for(;possibleMove < 8; possibleMove++)
        {
            if(MoveLegal(possibleMove, boardSize, &board[0][0], currentX, currentY))
            {
                break;
            }
        }

        if(possibleMove == 8)
        {
            //RemoveKnight()
            do
            {
                knightsPlacedDown--;

                int tempX = currentX + KnightStepTbl[board[currentX][currentY]].StepX;
                int tempY = currentY + KnightStepTbl[board[currentX][currentY]].StepY;

                board[currentX][currentY] = -1;

                currentX = tempX;
                currentY = tempY;

                possibleMove = board[currentX][currentY];

            } while(PushSequence(&possibleMove, boardSize));


        }
        else
        {
            //Add Knight
            ///!Put this all inside a function.
            knightsPlacedDown++;

            currentX = currentX + KnightStepTbl[possibleMove].StepX;
            currentY = currentY + KnightStepTbl[possibleMove].StepY;

            int revertedMove = ((possibleMove+4)%(boardSize-1));

            board[currentX][currentY] = revertedMove;



            PrintBoard(boardSize, &board[0][0]);

            possibleMove = 0;

            if(knightsPlacedDown == ((boardSize*boardSize)-1))
            {
                //Successful permutation found! :D
                successfulPermutations++;

                //RemoveKnight()
                do
                {
                knightsPlacedDown--;

                int tempX = currentX + KnightStepTbl[board[currentX][currentY]].StepX;
                int tempY = currentY + KnightStepTbl[board[currentX][currentY]].StepY;

                currentX = tempX;
                currentY = tempY;

                possibleMove = board[currentX][currentY];

                board[currentX+KnightStepTbl[possibleMove].StepX][currentY+KnightStepTbl[possibleMove].StepY] = -1;
            } while(PushSequence(&possibleMove, boardSize));
            }
        }
    }

    return successfulPermutations;
}

/*
void addKnight()
{
}
*/

void PrintBoard(int boardSize, int* board)
{
    for(int rowScanner = 0; rowScanner < boardSize; rowScanner++)
    {
        for(int columnScanner = 0; columnScanner < boardSize; columnScanner++)
        {
            if(1)
            {
                if((*(board+(columnScanner*boardSize)+(rowScanner))) == -1)
                {
                    cout << "x ";
                }
                else
                {
                    cout << "o ";
                }
            }
            else
            {
                printf("%3d ", (*(board+(rowScanner*boardSize)+(columnScanner))));
            }


        }
        cout << "\n";
    }
    cout << "\n";
}

void removeKnight()
{

}

//Function Comments
/*/////////////////////////////////////////////////////////////////////
* Name: bool PushSequence(int * possibleMove, int boardSize)
*
* Inputs:
*       // Parameters //
*               int * possibleMove          Address to the next possible move
*                                           to scan for
*
*               int boardSize               The size of the board.
*
*
*       // Variables //
*               N/A
*
*
* Outputs:
*       // Return Value //
*               Whether or not the latest knight needs to be removed.
*
* Description:
*       Pushes the variable that determines the next move the program should
*       scan from the latest knight that's placed down. If the variable is too
*       large then the variable would return "true", else, "false".
*
*/
bool PushSequence(int * possibleMove, int boardSize)
{
    (*(possibleMove))++;
    if((*(possibleMove)) >= boardSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MoveLegal(int moveType, int boardSize, int* board, int currentX, int currentY)
{
    int moveXOffset = KnightStepTbl[moveType].StepX;
    int moveYOffset = KnightStepTbl[moveType].StepY;

    if(((*(board+((currentX+moveXOffset)*boardSize)+((currentY+moveYOffset)))) != (-1)) ||
        (currentX+moveXOffset >= boardSize) ||
        (currentY+moveYOffset >= boardSize))
    {
        return false;
    }
    else
    {
        return true;
    }
}
