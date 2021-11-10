// Given a string, your task is to replace each of its characters by the next one in the English alphabet; i.e. 
// replace a with b, replace b with c, etc (z would be replaced by a).

// Example

// For inputString = "crazy", the output should be alphabeticShift(inputString) = "dsbaz".

std::string alphabeticShift(std::string inputString) {
    for (int i = 0; i < inputString.size(); ++i) {
        inputString[i] = (inputString[i] + 1 - 'a') % 26 + 'a';
    }
    return inputString;
}
