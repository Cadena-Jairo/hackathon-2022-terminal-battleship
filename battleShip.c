#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10

void player1gameBoard(int cols, int game_board[][cols]) 
{
    printf("***PLAYER 1 BOARD***\n");
    printf("  ");
    for(int num = 0; num < 10; num++)
    {
        printf("%d ", num + 1);
    }
    printf("\n");
  for (int row = 0; row < ROWS; row++) 
  {
    printf("%d ", row+1);
    for (int eCols = 0; eCols < cols; eCols++) {
      printf("%d ", game_board[row][eCols]);
    }
    printf("\n");
  }
  printf("\n");
}

void player2gameBoard(int cols, int game_board[][cols]) 
{
    printf("***PLAYER 2 BOARD***\n");
    printf("  ");
    for(int num = 0; num < 10; num++)
    {
        printf("%d ", num + 1);
    }
    printf("\n");
  for (int row = 0; row < ROWS; row++) 
  {
    printf("%d ", row+1);
    for (int eCols = 0; eCols < cols; eCols++) {
      printf("%d ", game_board[row][eCols]);
    }
    printf("\n");
  }
  printf("\n");
}


  int shipMenu() {
    int userNum;
    printf("\n");
    printf("1. Big Ship (Uses 5 spaces)\n");
    printf("2. Semi Ship (uses 3 spaces)\n");
    printf("3. Small Ship (uses 2 spaces)\n");
    printf("Enter ship you want to use: ");

    scanf("%d", &userNum);

    return userNum;
  }

  // this function will add the ship to the array/board game
  void theShip(int ship, int cols, int player[]) {
    int newCols;
    switch (ship) {
    case 1:
        if(cols > 6)
        {
            printf("Colum out of bounds, try again: ");
            scanf("%d", &newCols);
            for (int eCols = newCols - 1; eCols < newCols + 4; eCols++) 
            {
                player[eCols] = 1;
            } 
            
        }    
        else 
        {
            for (int eCols = cols - 1; eCols < cols + 4; eCols++) 
            {
                player[eCols] = 1;
            }            
        }
   
      break;
    case 2:
      if(cols > 8)
        {
            printf("Colum out of bounds, try again: ");
            scanf("%d", &newCols);
            for (int eCols = newCols - 1; eCols < newCols + 2; eCols++) 
            {
                player[eCols] = 1;
            } 
            
        }    
        else 
        {
            for (int eCols = cols - 1; eCols < cols + 2; eCols++) 
            {
                player[eCols] = 1;
            }            
        }
      break;
    case 3:
    
      if(cols > 9)
        {
            printf("Colum out of bounds, try again: ");
            scanf("%d", &newCols);
            for (int eCols = newCols - 1; eCols < newCols + 1; eCols++) 
            {
                player[eCols] = 1;
            } 
            
        }    
        else 
        {
            for (int eCols = cols - 1; eCols < cols + 1; eCols++) 
            {
                player[eCols] = 1;
            }            
        }
      break;
    default:
      printf("Not an option\n");
      break;
    }
  }
  
  void theCPUShip(int ship, int cols, int player[]) {
    int newCols;
    switch (ship) {
    case 1:
        if(cols > 6)
        {
            srand(time(NULL));
            
            newCols = (rand() % (5 - 1+1)) + 1;
            
            for (int eCols = newCols - 1; eCols < newCols + 4; eCols++) 
            {
                player[eCols] = 1;
            } 
            
        }    
        else 
        {
            for (int eCols = cols - 1; eCols < cols + 4; eCols++) 
            {
                player[eCols] = 1;
            }            
        }
   
      break;
    case 2:
      if(cols > 8)
        {
            srand(time(NULL));
            
            newCols = (rand() % (7 - 1+1)) + 1;
            
            for (int eCols = newCols - 1; eCols < newCols + 2; eCols++) 
            {
                player[eCols] = 1;
            } 
            
        }    
        else 
        {
            for (int eCols = cols - 1; eCols < cols + 2; eCols++) 
            {
                player[eCols] = 1;
            }            
        }
      break;
    case 3:
    
      if(cols > 9)
        {
            srand(time(NULL));
            
            newCols = (rand() % (8 - 1+1)) + 1;
            
            for (int eCols = newCols - 1; eCols < newCols + 1; eCols++) 
            {
                player[eCols] = 1;
            } 
            
        }    
        else 
        {
            for (int eCols = cols - 1; eCols < cols + 1; eCols++) 
            {
                player[eCols] = 1;
            }            
        }
      break;
    default:
      printf("Not an option\n");
      break;
    }
  }
  
  
_Bool target_shot(int col, int player[])
{

    if(player[col - 1] == 1)
    {
        player[col - 1] = 0;
        printf("You got a hit!\n");
        printf("\n");
        return 1;
    }
    else
    {
        printf("Miss\n");
        printf("\n");
        return 0;
    }
    return 0;

}
  
_Bool theWinner(int cols, int boardGame[][cols])
{
    //will check to see if counter is = to game board total (10X10 = 100)
    int counter = 0;
      for(int row = 0; row < ROWS; row++)
      {
          for(int daCols = 0; daCols < cols; daCols++)
            {
              if(boardGame[row][daCols] == 0)
              {
                    counter++;
              }
            }
      }
      if(counter == (ROWS * COLS))
      {
        return 1;
      }
    return 0;
}

  int main() {
    // 1 big ship 5 spaces
    // 3 small ship 2 spaces
    // 1 medial ship 3 spaces
    // 10x10 board
    int shotRow, shotCol, daShotRow, daShotCol;
    int player1one[ROWS][COLS];
    int player2two[ROWS][COLS];
    int cpu1one[ROWS][COLS];
    int daRows, daCols, ship, gameChoice, daRowTime, daColTime, daShipTime;
    _Bool targetP1, targetP2, winnerP1, winnerP2;
    
    printf("***SELECT GAMEMODE***\n");
    printf("1. Player 1v1 with friend\n");
    printf("2. Player 1v1 with CPU\n");
    scanf("%d", &gameChoice);
    
    switch(gameChoice)
    {
        case 1: 
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                player1one[r][c] = 0;
                player2two[r][c] = 0;
            }
        }
    
        printf("\n PLayer 1: Enter 3 boat places \n");
    
        //player1gameBoard(COLS, player1one);
        
        for(int times = 0; times < 3; times++)
        {
            player1gameBoard(COLS, player1one);

            printf("Enter row you want to place: ");
            scanf("%d", &daRows);
  
            printf("Enter colum you want to place: ");
            scanf("%d", &daCols);


            ship = shipMenu();
    
            theShip(ship, daCols, player1one[daRows - 1]);
    
        }

        printf("\n PLayer 2: Enter 3 boat places \n");

        //player2gameBoard(COLS, player2two);
    
        for(int times = 0; times < 3; times++)
        {
            player2gameBoard(COLS, player2two);

            printf("Enter row you want to place: ");
            scanf("%d", &daRows);
  
            printf("Enter colum you want to place: ");
            scanf("%d", &daCols);

            ship = shipMenu();
    
            theShip(ship, daCols, player2two[daRows - 1]);
    
        } 
    
        do
        {
            printf("Player 1's turn\n");
            printf("Pick a row and colmn you want to shoot (Format: rows x cols): ");
            scanf("%d x %d", &shotRow, &shotCol);
            printf("\n");
      
            targetP1 = target_shot(shotCol, player2two[shotRow - 1]);
        
            if(targetP1 == 1)
            {
                printf("Player 1's turn again\n");
                printf("Pick a row and colmn you want to shoot (Format: rows x cols): ");
                scanf("%d x %d", &shotRow, &shotCol);
                printf("\n");

      
                targetP1= target_shot(shotCol, player2two[shotRow - 1]);
            }
        
            winnerP1 = theWinner(COLS, player2two);
            winnerP2 = theWinner(COLS, player1one);
        
        
            if(winnerP1 == 1)
            {
                printf("Player 1 Wins!!!!\n");
                return 0;
            }
            else if(winnerP2 == 1)
            {
                printf("Player 2 Wins!!!!\n");
                return 0;
            }
        
            printf("Player 2's turn\n");
            printf("Pick a row and colmn you want to shoot (Format: rows x cols): ");
            scanf("%d x %d", &shotRow, &shotCol);
            printf("\n");
            
            targetP2 = target_shot(shotCol, player1one[shotRow - 1]);


            if(targetP2 == 1)
            {
                printf("Player 2's turn again\n");
                printf("Pick a row and colmn you want to shoot (Format: rows x cols): ");
                scanf("%d x %d", &shotRow, &shotCol);
                printf("\n");

      
                targetP2 = target_shot(shotCol, player1one[shotRow - 1]);
            }
       
            winnerP1 = theWinner(COLS, player2two);
            winnerP2 = theWinner(COLS, player1one);
        
        
            if(winnerP1 == 1)
            {
                printf("Player 1 Wins!!!!\n");
                return 0;
            }
            else if(winnerP2 == 1)
            {
                printf("Player 2 Wins!!!!\n");
                return 0;
            }
        
        } while(1);
    
        case 2:
        
            for(int r = 0; r < ROWS; r++)
            {
                for(int c = 0; c < COLS; c++)
                {
                    player1one[r][c] = 0;
                    cpu1one[r][c] = 0;
                }
            }
    
            printf("\n PLayer 1: Enter 3 boat places \n");
    
          //  player1gameBoard(COLS, player1one);
        
            for(int times = 0; times < 3; times++)
            {
                player1gameBoard(COLS, player1one);

                printf("Enter row you want to place: ");
                scanf("%d", &daRows);
  
                printf("Enter colum you want to place: ");
                scanf("%d", &daCols);
                
                ship = shipMenu();
    
                theShip(ship, daCols, player1one[daRows - 1]);
            }
            
            
            printf("\n PLAYER CPU: CREATING BOARD\n");
            printf("LOADING...\n");
            
            for(int times = 0; times < 3; times++)
            {
                srand(time(NULL));
                daRowTime = rand() % 10;
                
                daColTime = rand() % 10;

                daShipTime = (rand() % (3 -1+1)) + 1;
    
                theCPUShip(daShipTime, daColTime, cpu1one[daRowTime - 1]);
    
                //player1gameBoard(COLS, cpu1one);
            }
            
            do
            {
                printf("Player 1's turn\n");
                printf("Pick a row and colmn you want to shoot (Format: rows x cols): ");
                scanf("%d x %d", &shotRow, &shotCol);
                printf("\n");
      
                targetP1 = target_shot(shotCol, cpu1one[shotRow - 1]);
        
                if(targetP1 == 1)
                {
                    printf("Player 1's turn again\n");
                    printf("Pick a row and colmn you want to shoot (Format: rows x cols): ");
                    scanf("%d x %d", &shotRow, &shotCol);
                    
                    printf("\n");

      
                    targetP1= target_shot(shotCol, cpu1one[shotRow - 1]);
                }
            
                winnerP1 = theWinner(COLS, cpu1one);
                winnerP2 = theWinner(COLS, player1one);
        
        
                if(winnerP1 == 1)
                {
                    printf("Player 1 Wins!!!!\n");
                    return 0;
                }
                else if(winnerP2 == 1)
                {
                    printf("Player CPU Wins!!!!\n");
                    return 0;
                }
        
                printf("Player CPU's turn\n");
                printf("LOADING...");
                
                srand(time(NULL));
                
                daShotRow = (rand() % (10 - 1+1)) + 1;
                daShotCol = (rand() % (10 - 1+1)) + 1;

                printf("\n");
                
                targetP2 = target_shot(daShotCol, player1one[daShotRow - 1]);


                if(targetP2 == 1)
                {
                    printf("Player 2's turn again\n");
                    printf("LOADING... ");
                    
                    srand(time(NULL));
                
                    daShotRow = (rand() % (10 - 1+1)) + 1;
                    daShotCol = (rand() % (10 - 1+1)) + 1;
                    printf("\n");

      
                    targetP2 = target_shot(daShotCol, player1one[daShotRow - 1]);
                }
        
                winnerP1 = theWinner(COLS, cpu1one);
                winnerP2 = theWinner(COLS, player1one);
        
        
                if(winnerP1 == 1)
                {
                    printf("Player 1 Wins!!!!\n");
                    return 0;
                }
                else if(winnerP2 == 1)
                {
                    printf("Player CPU Wins!!!!\n");
                    return 0;
                }
        
            } while(1);
    }

    return 0;
  }
