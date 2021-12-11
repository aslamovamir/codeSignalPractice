// Given two arrays of integers a and b, obtain the array formed by the elements of a followed by the elements of b.

// Example

// For a = [2, 2, 1] and b = [10, 11], the output should be
// solution(a, b) = [2, 2, 1, 10, 11].

vector<int> solution(vector<int> a, vector<int> b) {
    for (auto itr: b) {
        a.push_back(itr);
    }
    return a;
}
