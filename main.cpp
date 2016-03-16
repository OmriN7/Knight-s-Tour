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


void printBoard(int * board)
{
    for(int y = 0; y < 8; y++)
    {
        for(int x = 0; x < 8; x++)
        {
            if((*(board+(y*8)+x)) == -1)
            {
                printf("x ");
            }
            else
            {
                printf("o ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool MoveLegal(int moveType, int* board, int currentX, int currentY)
{
    int offsetX = KnightStepTbl[moveType].StepX;
    int offsetY = KnightStepTbl[moveType].StepY;

    if(((*(board+((currentY+offsetY)*8)+(currentX+offsetX))) == -1) &&
       ((currentX+offsetX) < 8) && ((currentX+offsetX) >= 0) &&
       ((currentY+offsetY) < 8) && ((currentY+offsetY) >= 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int KnightsTour(int boardSize)
{
    int board[8][8];
    memset(board, -1, (boardSize*boardSize*sizeof(int)));

    int successfulPermutations = 0;

    int currentX = 0;
    int currentY = 0;
    int possibleMove = 0;

    bool everythingScanned = false;

    int knightsPlacedDown = 0;



    board[currentX][currentY] = 8;
    knightsPlacedDown++;

    while(!everythingScanned)
    {
        //printBoard(&board[0][0]);


        ///Evaluate next place place down queen
        for(;possibleMove < 8; possibleMove++)
        {
            if(MoveLegal(possibleMove, &board[0][0], currentX, currentY))
            {
                break;
            }
        }

        if(possibleMove == 8)
        {
            ///Remove Knight
            int offsetX = KnightStepTbl[(board[currentY][currentX])].StepX;
            int offsetY = KnightStepTbl[(board[currentY][currentX])].StepY;


            int previousKnightX = currentX + offsetX;
            int previousKnightY = currentY + offsetY;

            if(previousKnightX == 0 && previousKnightY == 0)
            {
                printf("?");
            }
            possibleMove =  ((board[currentY][currentX]+4)%(boardSize));
            possibleMove++;

            board[currentY][currentX] = -1;

            currentX = previousKnightX;
            currentY = previousKnightY;


            knightsPlacedDown--;

        }
        else
        {
            ///Add Knight
            currentX = currentX + KnightStepTbl[possibleMove].StepX;
            currentY = currentY + KnightStepTbl[possibleMove].StepY;

            int revertedMove = ((possibleMove+4)%(boardSize));

            board[currentY][currentX] = revertedMove;

            possibleMove = 0;

            knightsPlacedDown++;
            if(knightsPlacedDown == 64)
            {

                successfulPermutations++;
                printBoard(&board[0][0]);
            }
        }
    }

    return successfulPermutations;
}

int main(void)
{
    int boardSize = 8;

    KnightsTour(boardSize);
    return 0;
}

