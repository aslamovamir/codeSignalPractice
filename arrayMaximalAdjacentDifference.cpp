// Given an array of integers, find the maximal absolute difference between any two of its adjacent elements.
// For inputArray = [2, 4, 1, 0], the output should be
// arrayMaximalAdjacentDifference(inputArray) = 3.

int arrayMaximalAdjacentDifference(vector<int> inputArray) {
    //we assume the length of the array is at least 3
    
    int maxDiff = abs(inputArray[1] - inputArray[0]);
    for (int i = 1; i < inputArray.size(); i++) {
        if (i == inputArray.size() - 1) { break; }
        if (abs((inputArray[i+1] - inputArray[i])) > maxDiff) {
            maxDiff = abs(inputArray[i+1] - inputArray[i]);
        }
    }
    
    return maxDiff;
}
