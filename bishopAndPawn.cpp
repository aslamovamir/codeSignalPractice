// Given the positions of a white bishop and a black pawn on the standard chess board, determine whether the bishop can capture the pawn in one move.

// The bishop has no restrictions in distance for each move, but is limited to diagonal movement

bool bishopAndPawn(string bishop, string pawn) {
    char biship_col = bishop[0];
    char bishop_row = bishop[1];
    char pawn_col = pawn[0];
    char pawn_row = pawn[1];
    if (pawn_row == bishop_row + (biship_col - pawn_col) || pawn_row == bishop_row + (pawn_col - biship_col) 
        || pawn_row == bishop_row - (biship_col - pawn_col) || pawn_row == biship_col - (pawn_col - biship_col)) {
        return true;
    } else {
        return false;
    }
}
