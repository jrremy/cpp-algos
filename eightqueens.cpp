/* Name: Jeremy Davoodzadeh
* Assignment 1
*/

#include <iostream>

using namespace std;

int main() {
    // Creating the 8x8 board and placing a queen at top left position
    // An array element being 0 means no queen in that spot. 1 means there is a queen in that spot
    //We'll keep track of our position with r and c, and our completed solution arrangements with sol_num
    int b[8][8] = {};
    int sol_num = 0;
    int r = 0, c = 0;
    b[r][c] = 1;

nc: // Move over to next column
    c++;
    if(c == 8) goto print; // We've passed through column indexes 0 through 7, meaning we've placed a queen in every column and it's time to print our solution.
    r = -1; // We make it -1 here because incrementing r is part of the next section, nr. r will then become 0 and refer to the index of the first row.

nr: // Move over to next row
    r++;
    if(r == 8) goto backtrack; // We've gone through all rows 0 through 7 and still no queen placed, so we'll move back a column to see if we can move the previous queen 
    // to be able to place it in the next row.

    // Row test
    for(int i = 0; i < c; i++){
        if(b[r][i] == 1) goto nr;
    }

    // Lower diagonal test
    for(int i = 1; (r + i) < 8 && (c - i) >= 0; i++){
        if(b[r + i][c - i] == 1) goto nr;
    }

    // Upper diagonal test
    for(int i = 1; (r - i) >= 0 && (c - i) >= 0; i++){
        if(b[r - i][c - i] == 1) goto nr;
    } 

    b[r][c] = 1; // Tests passed, place queen
    goto nc;

backtrack: // Move back a column to try moving the previous queen to be able to place the next one
    c--;
    if(c < 0) return 0; // Once we can no longer backtrack any further, we've found all our solutions and the program terminates.
    // Find where the queen is in the previous row
    r = 0;
    while(b[r][c] != 1){
        r++;
    }
    // Remove that queen and see where the next place we can put it will be
    b[r][c] = 0;
    goto nr;

print:
    // At this point, a solution was found so we'll increment our counter and print out that solution
    sol_num++;
    cout << "Solution #: " << sol_num << endl;

    for(int ir = 0; ir < 8; ir++){
        for(int ic = 0; ic < 8; ic++){
            cout << b[ir][ic];
        }
        cout << endl;
    }

    cout << endl;

    // Continue to look for the next possible solution arrangement by backtracking
    goto backtrack;


}