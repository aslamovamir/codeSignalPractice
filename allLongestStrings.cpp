//Given an array of strings, return another array containing all of its longest strings.
vector<string> allLongestStrings(vector<string> inputArray) {
    //we will first the size of the longest string in the         //array
    vector<string> longest_array;
    int size_longest = inputArray[0].length();
    for (int i = 1; i < inputArray.size(); i++) {
        if (inputArray[i].length() > size_longest) {
            size_longest = inputArray[i].length();
        }
    }
    //now we will consider string with the same length as 
    //the value of the longest-string-size
    for (int i = 0; i < inputArray.size(); i++) {
        if (inputArray[i].length() == size_longest) {
            longest_array.push_back(inputArray[i]);
        }
    }
    
    return longest_array;
}
