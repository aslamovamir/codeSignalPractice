// Given a string, check if it can become a palindrome through a case change of some (possibly, none) letters.

// Example

// For inputString = "AaBaa", the output should be
// solution(inputString) = true.

// "aabaa" is a palindrome as well as "AABAA", "aaBaa", etc.

// For inputString = "abac", the output should be
// solution(inputString) = false.

// All the strings which can be obtained via changing case of some group of letters, i.e. "abac", "Abac", "aBAc" and 13 more, are not palindromes.

bool solution(string inputString) {
    stack<char> Stack;
    for (unsigned int i = 0; i < inputString.length(); i++) {
        cout<<inputString[i]<<endl;
        Stack.push(tolower(inputString[i]));
        if (inputString.length()%2 != 0 && i == inputString.length()/2) {
            for (unsigned int j = i; j < inputString.length(); j++) {
                if (Stack.top() == tolower(inputString[j])) {
                    Stack.pop();
                } else {
                    return false;
                }
            }
            break;
        } else if (inputString.length()%2 == 0 && i == inputString.length()/2 - 1) {
            for (unsigned int j = i + 1; j < inputString.length(); j++) {
                if (Stack.top() == tolower(inputString[j])) {
                    Stack.pop();
                } else {
                    return false;
                }
            }
            break;
        }
    }
    return true;
}
