// You are taking part in an Escape Room challenge designed specifically for programmers. In your efforts to find a clue, you've found a binary code 
//   written on the wall behind a vase, and realized that it must be an encrypted message. After some thought, your first guess is that each 
//   consecutive 8 bits of the code stand for the character with the corresponding extended ASCII code.

// Assuming that your hunch is correct, decode the message.

// Example

// For code = "010010000110010101101100011011000110111100100001", the output should be
// solution(code) = "Hello!".

// The first 8 characters of the code are 01001000, which is 72 in the binary numeral system. 72 stands for H in the ASCII-table, so the first letter is H.
// Other letters can be obtained in the same manner.

string solution(string code) {
    int iter = 0;
    int count = 0;
    char iterC;
    vector<char> chars;
    string solution = "";
    for (int i = code.length()-1; i >= 0; i--) {
        if (count == 7) {
            count = 0;
            iterC = NULL + iter;
            chars.push_back(iterC);
            iter = 0;
            continue;
        }
        if (code[i] == '1') {
            iter += (int)pow(2, count);
        }
        count++;
    }
    for (int i = chars.size()-1; i >= 0; i--) {
        solution += chars[i];
    }
    chars.clear();
    
    return solution;
}
