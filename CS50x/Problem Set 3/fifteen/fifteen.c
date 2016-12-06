/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// blank tile coordinates
int blanktile_i;
int blanktile_j;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void print_space(int value);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    blanktile_i = d - 1;
    blanktile_j = d - 1;
    

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // Counts through array
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // Formula starts from d - 1 and counts downward
            board[i][j] = (d * d) - ((i * d) + (j + 1));
        }
    }
    
    // Swaps 1 and 2
    if (d % 2 == 0)
    {
        int swap = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = swap;
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // 0 is treated as blank tile and printed
            if (board[i][j] == 0)
            {
                printf("_   ");
            }
            else 
            {
                printf("%i", board[i][j]);
                print_space(board[i][j]);
            }
        }
        
        printf("\n");
    }
    // TODO
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    if (tile >= d*d)
    {
        return false;
    }
    
    //Evaluates position of tile
    int ipos, jpos;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                ipos = i;
                jpos = j;
            }
        }
    }
    
    // Evaluates if tile is next to blank tile for j position
    if ((blanktile_i == ipos) && (abs(blanktile_j - jpos) == 1))
    {
        int swap = board[ipos][jpos];
        board[ipos][jpos] = 0;
        board[blanktile_i][blanktile_j] = swap;
        blanktile_i = ipos;
        blanktile_j = jpos;
        return true;
    }
    
    // Evaluates if tile is next to blank tile for i position
    else if ((blanktile_j == jpos) && (abs(blanktile_i - ipos) == 1))
    {
        int swap = board[ipos][jpos];
        board[ipos][jpos] = 0;
        board[blanktile_i][blanktile_j] = swap;
        blanktile_i = ipos;
        blanktile_j = jpos;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int count = 0;
    
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // This "jumps" to the next column
            if ((j + 1 > d - 1) && (i < d - 1))
            {
                if ((board[i][j] > board[i + 1][0]) && (board[i + 1][0] != 0))
                {
                    count++;
                }
            }
            
            // If no jump needed, simply evaluates next space
            else if ((board[i][j] > board[i][j + 1]) && (board[i][j + 1] != 0))
            {
                count++;
            }
            
        }
    }
    
    if (count > 0)
    {
        return false;
    }
    
    // Makes sure blank space is in correct spot
    else if (count == 0 && board[d - 1][d - 1] == 0)
    {
        return true;
    }
    
    return false;
}

void print_space(int value)
{
    // Prints appropriate number of spaces if number is 10 or greater
    if (value > 9)
    {
        printf("  ");
    }
    else
    {
        printf("   ");
    }
}