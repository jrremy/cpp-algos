/* Name: Jeremy Davoodzadeh
* Assignment 2
*/

#include <iostream>

using namespace std;

int main() {
    // Creating a 1D array representing an 8x8 board and placing a queen at top left position
    // Each element (indexes 0-7) represents a column and its value (0-7) represents the row at which a queen is placed
    // We'll keep track of our column position with c and our row position will be represented by q[c] 
    // sol_num will keep track of our completed solution arrangements
    int q[8] = {};
    int c = 0, sol_num = 0;
    q[0] = 0;

nc: // Move over to next column
    c++;
    if(c == 8) goto print; // We've passed through column indexes 0 through 7, meaning we've placed a queen in every column and it's time to print our solution.
    q[c] = -1; // We make it -1 here because incrementing q[c] is part of the next section, nr. q[c] will then become 0 and refer to the first row.

nr: // Move over to next row
    q[c]++;
    if(q[c] == 8) goto backtrack; // We've gone through all rows 0 through 7 and still no queen placed, so we'll move back a column to see if we can move the previous queen 
    // to be able to place it in the next row.

    // Test
    for(int i = 0; i < c; i++) {
        if(q[i] == q[c] || (c - i) == abs(q[c] - q[i])) goto nr;
    } // Having the value of the queen's row position reduces all the tests from 2D solution down to 1 line of code
    // Having the same value as that at current index c in any other column means horizontal check failed
    // If the change in columns (c-i) is the same as the change in row position, measured with abs val to consider both upward and downward, then diag test failed
    goto nc; // Tests passed, place queen

backtrack: // Move back a column to try moving the previous queen to be able to place the next one
    c--;
    if(c < 0) return 0; // Once we can no longer backtrack any further, we've found all our solutions and the program terminates.
    // No longer need to locate row of queen in previous column since we already have the row value as the element's value
    goto nr;

print:
    // At this point, a solution was found so we'll increment our counter and print out that solution
    sol_num++;
    cout << "Solution #" << sol_num << ": " << endl;
    // Printing our 1D array
    cout << "1D Format: " << endl;
    for(int i = 0; i < 8; i++) {
        cout << q[i];
    }
    cout << endl;
    // Printing the board 8x8 style with 0 representing no queen and 1 representing queen
    cout << "2D Format: " << endl;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(q[i] == j) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }

    cout << endl;

    // Continue to look for the next possible solution arrangement by backtracking
    goto backtrack;
}