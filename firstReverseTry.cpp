// Reversing an array can be a tough task, especially for a novice programmer. Mary just started coding, 
// so she would like to start with something basic at first. Instead of reversing the array entirely, 
// she wants to swap just its first and last elements.

// Given an array arr, swap its first and last elements and return the resulting array.

// Example

// For arr = [1, 2, 3, 4, 5], the output should be
// solution(arr) = [5, 2, 3, 4, 1].

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int temp;
    if (arr.size() == 1) {
        return arr;
    }
    for (unsigned int i = 0; i < arr.size(); i++) {
        if (i == arr.size()-1) {
            answer.push_back(temp);
            break;
        }
        if (i == 0) {
            temp = arr[0];
            answer.push_back(arr[arr.size()-1]);
            continue;
        }
        answer.push_back(arr[i]);
    }
    return answer;
}
