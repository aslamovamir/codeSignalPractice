// Consider the following ciphering algorithm:

// For each character replace it with its code.
// Concatenate all of the obtained numbers.
// Given a ciphered string, return the initial one if it is known that it consists only of lowercase letters.

// Note: here the character's code means its decimal ASCII code, the numerical representation of a character used by most modern programming languages.

// Example

// For cipher = "10197115121", the output should be
// solution(cipher) = "easy".

// Explanation: charCode('e') = 101, charCode('a') = 97, charCode('s') = 115 and charCode('y') = 121.

string solution(string cipher) {
    string answer = "";
    
    string run_string = "";
    int run_code;
    char run_char;
    
    for (unsigned int i = 0; i < cipher.length(); i++) {
        run_string += cipher[i];
        if (stoi(run_string) >= 97 && stoi(run_string) <= 122) {
            run_char = stoi(run_string);
            answer += run_char;
            run_string = "";
        }
    }
    
    return answer;
}
