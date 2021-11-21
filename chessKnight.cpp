// Given a position of a knight on the standard chessboard, find the number of different moves the knight can perform.

// The knight can move to a square that is two squares horizontally and one square vertically, or two squares vertically 
// and one square horizontally away from it. The complete move therefore looks like the letter L. Check out the image 
// below to see all valid moves for a knight piece that is placed on one of the central squares.

// Example

// For cell = "a1", the output should be
// solution(cell) = 2.
// For cell = "c2", the output should be
// solution(cell) = 6.

int solution(string cell) {
    if (cell[0] >= 'c' && cell[0] <= 'f') {
        if (cell[1] >= '3' && cell[1] <= '6') {
            return 8;
        } else  {
            return 6;
        }
    } else if (cell[0] == 'b' || cell[0] == 'g') {
        if (cell[1] >= '3' && cell[1] <= '6') {
            return 6;
        } else if (cell[1] == '7' || cell[1] == '2') {
            return 4;
        } else  {
            return 3;
        }
    } else  {
        if (cell[1] >= '3' && cell[1] <= '6') {
            return 4;
        } else if (cell[1] == '7' || cell[1] == '2') {
            return 3;
        } else  {
            return 2;
        }
    }
}
