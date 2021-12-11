// Given an integer size, return array of length size filled with 1s.

// Example

// For size = 4, the output should be
// solution(size) = [1, 1, 1, 1].

vector<int> solution(int size) {
    vector<int> answer;
    for (int i = 0; i < size; i++) {
        answer.push_back(1);
    }
    return answer;
}
