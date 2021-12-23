// Given an array of strings, return another array containing all of its longest strings.

// Example

// For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
// solution(inputArray) = ["aba", "vcd", "aba"].

vector<string> solution(vector<string> inputArray) {
    map<int, vector<string>> Map;
    int largest = 0;
    for (unsigned int i=0; i<inputArray.size(); i++) {
        Map[inputArray[i].length()].push_back(inputArray[i]);
        if (inputArray[i].length() > largest) {
            largest = inputArray[i].length();
        }
    }
    return Map[largest];
}
