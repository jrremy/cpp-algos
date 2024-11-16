/* Name: Jeremy Davoodzadeh
 * Assignment: n Queens using dynamic memory
 */

#include <iostream>
#include <cmath>
using namespace std;

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

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n)
{
    // Dynamically declare an array of size n and initialize the first element to 0.
    int *q;
    q = new int[n];
    q[0] = 0;

    // We'll keep track of our column position with c and our row position will be represented by q[c]
    int c = 0;

    // To keep track of the total number of solutions found with a nxn board and n queens to place
    int solutions = 0;

    // Here's the reused 1D 8 queens algorithm without goto
    while (c >= 0)
    { // The program runs until we can no longer backtrack any further
        c++;
        if (c == n)
        { // We've passed through column indexes 0 through 7, meaning we've placed a queen in every column and it's time to print our solution.
            solutions++;
            c--;
        }
        else
            q[c] = -1; // We make it -1 here because incrementing q[c] is part of the next section, nr. q[c] will then become 0 and refer to the first row.

        while (c >= 0)
        { // Where we check the column for a valid place to put a queen
            q[c]++;
            if (q[c] == n)
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

    // Delete the array.
    delete[] q;

    // Return the number of solutions.
    return solutions;
}

int main()
{
    int n = 12;
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}
