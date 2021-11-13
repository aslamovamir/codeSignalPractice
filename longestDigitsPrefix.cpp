// Given a string, output its longest prefix which contains only digits.

// Example

// For inputString = "123aa1", the output should be
// longestDigitsPrefix(inputString) = "123".

string longestDigitsPrefix(string inputString) {
    string result = "";
    for (int i = 0; i < inputString.size(); i++) {
        if (isdigit(inputString[i]) && i == 0) {
            result+=inputString[i];
            while(isdigit(inputString[++i])) {
                result+=inputString[i];
            }
            return result;
        }
    }
    return result;
}

