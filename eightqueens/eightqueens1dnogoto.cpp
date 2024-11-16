#include <iostream>

using namespace std;

// The function that returns true if no queen is present in the same row, oolumn, or diagonal up/down
bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++)
    {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i]))
            return false;
    } // Having the value of the queen's row position reduces all the tests from 2D solution down to 1 line of code
    // Having the same value as that at current index c in any other column means horizontal check failed
    // If the change in columns (c-i) is the same as the change in row position, measured with abs val to consider both upward and downward, then diag test failed
    return true; // The test has passed and has not returned false, therefore true is returned
}

// The function that prints a solution
void print(int q[])
{
    static int numSolutions = 0;                            // Keeps track of the number of solutions found so far
    cout << "Solution #" << ++numSolutions << ": " << endl; // Increment solution counter
    // Printing our 1D array
    cout << "1D Format: " << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << q[i];
    }
    cout << endl;
    // Printing the board 8x8 style with 0 representing no queen and 1 representing queen
    cout << "2D Format: " << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (q[i] == j)
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
        }
        cout << endl;
    }

    cout << endl;
}

int main()
{
    // Creating a 1D array representing an 8x8 board and placing a queen at top left position
    // Each element (indexes 0-7) represents a column and its value (0-7) represents the row at which a queen is placed
    // We'll keep track of our column position with c and our row position will be represented by q[c]
    int q[8] = {};
    int c = 0;
    q[0] = 0;

    while (c >= 0)
    { // The program runs until we can no longer backtrack any further
        c++;
        if (c == 8)
        { // We've passed through column indexes 0 through 7, meaning we've placed a queen in every column and it's time to print our solution.
            print(q);
            c--;
        }
        else
            q[c] = -1; // We make it -1 here because incrementing q[c] is part of the next section, nr. q[c] will then become 0 and refer to the first row.

        while (c >= 0)
        { // Where we check the column for a valid place to put a queen
            q[c]++;
            if (q[c] == 8)
            {
                c--;
                // We've gone through all rows 0 through 7 and still no queen placed, so we'll move back a column to see if we can move the previous queen
                // to be able to place it in the next row.
            }
            else if (ok(q, c))
            {
                break; // Move back up to our outer while loop to continue to next column
            }
        }
    }
    return 0; // We've found all our solutions and the program terminates
}