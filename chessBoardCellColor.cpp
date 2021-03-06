// Given two cells on the standard chess board, determine whether they have the same color or not.

// Example

// For cell1 = "A1" and cell2 = "C3", the output should be
// chessBoardCellColor(cell1, cell2) = true.
  
// For cell1 = "A1" and cell2 = "H3", the output should be
// chessBoardCellColor(cell1, cell2) = false.

bool chessBoardCellColor(string cell1, string cell2) {
    //65 - A
    //dark -> columnwise even numbers on even ASCII letters
    char col1 = cell1[0];
    char col2 = cell2[0];
    char row1 = cell1[1];
    char row2 = cell2[1];
    
    //cell 1 is on dark
    if (col1%2 == 0 && row1%2 == 0) {
        if (col2%2 == 0 && row2%2 == 0) {
            return true;
        } else if (col2%2 != 0 && row2%2 != 0) {
            return true;
        } else {
            return false;
        }
      // cell 1 on white
    } else if (col1%2 == 0 && row1%2 != 0) { 
        if (col2%2 != 0 && row2%2 == 0) {
            return true;
        } else if (col2%2 == 0 && row2%2 != 0) {
            return true;
        } else {
            return false;
        }
      // cell 1 on white 
    } else if (col1%2 != 0 && row1%2 == 0) {
        if (col2%2 != 0 && row2%2 == 0) {
            return true;
        } else if (col2%2 == 0 && row2%2 != 0) {
            return true;
        } else {
            return false;
        }
      //cell 1 on dark
    } else {
        if (col2%2 != 0 && row2%2 != 0) {
            return true;
        } else if (col2%2 == 0 && row2%2 == 0) {
            return true;
        } else {
            return false;
        }
    }
}
