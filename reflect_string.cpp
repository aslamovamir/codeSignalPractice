// Define an alphabet reflection as follows: a turns into z, b turns into y, c turns into x, ..., n turns into m, m turns into n, ..., z turns into a.

// Define a string reflection as the result of applying the alphabet reflection to each of its characters.

// Reflect the given string.

// Example

// For inputString = "name", the output should be
// solution(inputString) = "mznv".

string solution(string inputString) {
     
    string answer = "";
    
    for (unsigned int i = 0; i < inputString.length(); i++) {
        answer += 97 + (122 - inputString[i]);
    }
     
    return answer;
}
