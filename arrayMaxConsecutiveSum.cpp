// Given array of integers, find the maximal possible sum of some of its k consecutive elements.

// Example

// For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
// arrayMaxConsecutiveSum(inputArray, k) = 8.
// All possible sums of 2 consecutive elements are:

// 2 + 3 = 5;
// 3 + 5 = 8;
// 5 + 1 = 6;
// 1 + 6 = 7.
// Thus, the answer is 8.

int arrayMaxConsecutiveSum(vector<int> inputArray, int k) {
    int max_sum = 0;
    int running_sum = 0;
    
    for (int i = 0; i < inputArray.size(); i++) {
        if (i + k > inputArray.size()) {
            break;
        }
        for (int j = i; j < i+k; j++) {
            running_sum += inputArray[j];
        }
        if (running_sum > max_sum) {
            max_sum = running_sum;
        }   
        running_sum = 0;
    }
    return max_sum;
}
