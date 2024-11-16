#include <iostream>

using namespace std;

// The function that returns true if the value in array q at index c:
// 1) has not already been used
// 2) the neighboring boxes, as shown in helper array h, do not contain consecutive values 
bool ok(int q[], int c) {
    static int h[8][7] = {
        {-1}, // 0
        {0, -1}, // 1
        {0, 1, -1}, // 2
        {0, 2, -1}, // 3
        {2, 3, -1}, // 4
        {1, 2, 3, 4, -1}, // 5
        {1, 2, 5, -1}, // 6
        {4, 5, 6, -1} // 7
    };
    
    // Checks if number in the position has already been used
    for(int i = 0; i < c; i++) {
        if(q[i] == q[c]) {
            return false;
        }
    }
    
    // Checks for any consecutive neighboring numbers
    int i = 0;
    while(h[c][i] != -1) {
        if(abs(q[h[c][i]] - q[c]) == 1) {
            return false;
        }
        i++;
    }

    // All tests have passed, therefore true is returned
    return true;
}

// The function that prints a solution
void print(int q[]) {
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": " << endl;
    // The following print sequence will vary based on the arrangement of the boxes and labels
    cout << " " << q[1] << q[6] << endl;
    cout << q[0] << q[2] << q[5] << q[7] << endl;
    cout << " " << q[3] << q[4] << endl;
    cout << endl;
}

int main() {
    int q[8]; // Array representing the eight boxes
    int c = 0; // The index of the box
    q[c] = 1; // Box 1's value is set to 1

    while(c >= 0) { // The program runs until we can no longer backtrack any further
        c++;
        if(c == 8) { // We've passed through column indexes 0 through 7, meaning we've placed a number in every box and it's time to print our solution
            print(q);
            c--;
        } else q[c] = 0; // We set the number to 0 here because incrementing q[c] is part of the inner while loop.

        while(c >= 0) { // Looks for number to place in box c that satisfies the conditions
            q[c]++;
            if(q[c] == 9) { 
                c--; // We've gone through all numbers 1 through 8 and still none can be placed, so we'll move back a box (backtrack) to see if we 
                // could increment the previous box's value to be able to then place a number in the next box
            } else if(ok(q, c)) {
                break; // The value in box c works out, so we leave it there and move back up to our outer while loop to continue to next box
            }
        }
    }
    return 0; // We've found all our solutions and the program terminates
}