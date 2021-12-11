// Remove a part of a given array between given 0-based indexes l and r (inclusive).

// Example

// For inputArray = [2, 3, 2, 3, 4, 5], l = 2, and r = 4, the output should be
// solution(inputArray, l, r) = [2, 3, 5].

vector<int> solution(vector<int> inputArray, int l, int r) {
    vector<int> answer;
    for (unsigned int i = 0; i < inputArray.size(); i++) {
        if (i == l) {
            i = r;
            continue;
        } 
        answer.push_back(inputArray[i]);
    }
    return answer;
}
