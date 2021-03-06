// Your Informatics teacher at school likes coming up with new ways to help you understand the material. When you started studying numeral systems, 
// he introduced his own numeral system, which he's convinced will help clarify things. His numeral system has base 26, and its digits are represented
// by English capital letters - A for 0, B for 1, and so on.

// The teacher assigned you the following numeral system exercise: given a one-digit number, you should find all unordered pairs of one-digit numbers
// whose values add up to the number.

// Example

// For number = 'G', the output should be
// solution(number) = ["A + G", "B + F", "C + E", "D + D"].

// Translating this into the decimal numeral system we get: number = 6, so it is ["0 + 6", "1 + 5", "2 + 4", "3 + 3"].

vector<string> solution(char number) {
    vector<string> answer;
    int code = number - 65;
    
    int half = code/2;
    string iterator;
    char first, second;
    for (int i = 0; i <= half; i++) {
        first = 'A' + i;
        second = 'A' + code-i;
        iterator += first;
        iterator += " + ";
        iterator += second;
        answer.push_back(iterator);
        iterator = "";
    }
    
    return answer; 
}

