// Given an array of strings, sort them in the order of increasing lengths. If two strings have the same length, their relative order must be the 
// same as in the initial array.

// Example

// For

// inputArray = ["abc",
//               "",
//               "aaa",
//               "a",
//               "zz"]
// the output should be

// solution(inputArray) = ["",
//                             "a",
//                             "zz",
//                             "abc",
//                             "aaa"]

//Insertion Sort Algorithm: O(n^2) complexity
vector<string> solution(vector<string> inputArray) {
    vector<string> sorted;
    
    int indexing;
    for (int i = 0; i < inputArray.size(); i++) {
        indexing = sorted.size();
        while (indexing != 0) {
            if (sorted[indexing-1].length() <= inputArray[i].length()) {
                break;
            }
            indexing--;
        }
        sorted.insert(sorted.begin() + indexing, inputArray[i]);
    }
    
    return sorted;
}

