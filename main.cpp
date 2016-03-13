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

///DEFINES
//////////////////////////////////////////////////////////////////////
using namespace std;

#define DEBUG 1


///PROTOTYPES
//////////////////////////////////////////////////////////////////////
int KnightsTour(int boardSize);
bool MoveLegal(int moveType, int boardSize, int* board, currentX, currentY);



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
    memset(board, 0, (boardSize*boardSize*sizeof(int)));

    //int * permutationSequence = (int *) malloc(sizeof(int) * boardSize * boardSize);


    int successfulPermutations = 0;

    int currentX = 0;
    int currentY = 0;
    int possibleMove = 0;

    bool everythingScanned = false;

    int knightsPlacedDown = 0;


    board[0][0] = 1;
    knightsPlacedDown++;

    ///Functionality
    while(!everythingScanned)
    {
        ///Evaluate next place place down queen
        for(possibleMove = 0; possibleMove < 8; possibleMove++)
        {
            if(MoveLegal(possibleMove, boardSize, &board[0][0]), currentX, currentY)
            {
                break;
            }
        }
        cout << possibleMove;


        if(possibleMove == 8)
        {
            //RemoveKnight
        }
        else
        {
            //Add Knight
            if(knightsPlacedDown == (boardSize*boardSize))
            {
                //Successful permutation found! :D
                successfulPermutations++;

                //removeKnight
            }
        }
    }

    return successfulPermutations;
}

bool MoveLegal(int moveType, int boardSize, int* board, currentX, currentY)
{
    int moveXOffset = 0;
    int moveYoffset = 0;

    switch(moveType)
    {
        case 0:
            break;

    }

    if(*(board+(currentX*boardSize*sizeof(int))+((currentY)*sizeof(int))) == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
