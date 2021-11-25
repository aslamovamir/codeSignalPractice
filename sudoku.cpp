// Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that each column, 
// each row, and each of the nine 3 × 3 sub-grids that compose the grid contains all of the digits from 1 to 9.

// This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

// Example

// For
// grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
//         [4, 6, 5, 8, 7, 9, 3, 2, 1],
//         [7, 9, 8, 2, 1, 3, 6, 5, 4],
//         [9, 2, 1, 4, 3, 5, 8, 7, 6],
//         [3, 5, 4, 7, 6, 8, 2, 1, 9],
//         [6, 8, 7, 1, 9, 2, 5, 4, 3],
//         [5, 7, 6, 9, 8, 1, 4, 3, 2],
//         [2, 4, 3, 6, 5, 7, 1, 9, 8],
//         [8, 1, 9, 3, 2, 4, 7, 6, 5]]
// the output should be
// solution(grid) = true;

// For
// grid = [[1, 3, 2, 5, 4, 6, 9, 2, 7],
//         [4, 6, 5, 8, 7, 9, 3, 8, 1],
//         [7, 9, 8, 2, 1, 3, 6, 5, 4],
//         [9, 2, 1, 4, 3, 5, 8, 7, 6],
//         [3, 5, 4, 7, 6, 8, 2, 1, 9],
//         [6, 8, 7, 1, 9, 2, 5, 4, 3],
//         [5, 7, 6, 9, 8, 1, 4, 3, 2],
//         [2, 4, 3, 6, 5, 7, 1, 9, 8],
//         [8, 1, 9, 3, 2, 4, 7, 6, 5]]
// the output should be
// solution(grid) = false.

// The output should be false: each of the nine 3 × 3 sub-grids should contain all of the digits from 1 to 9.

bool solution(vector<vector<int>> grid) {
    map<char, int> iterator;
    int regulator = 0;
    
    //check rows
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            iterator[grid[i][j]]++;
            if (iterator[grid[i][j]] > 1) {
                return false;
            }
        }
        iterator.clear();
    }
    //check columns
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            iterator[grid[j][i]]++;
            if (iterator[grid[j][i]] > 1) {
                return false;
            }
        }
        iterator.clear();
    } 
    //check 3X3 subgrids
    for (int i = 0; i < 9; i+=3) {
        for (int u = 0; u < 3; u++) {
            for (int j = i; j < i + 3; j++) {
                for (int y = regulator; y < regulator + 3; y++) {
                    iterator[grid[j][y]]++;
                    if (iterator[grid[j][y]] > 1) {
                        return false;
                    }
                }
            }
            regulator += 3;
            iterator.clear();
        }
        regulator = 0;
    }
    
    return true;
}
