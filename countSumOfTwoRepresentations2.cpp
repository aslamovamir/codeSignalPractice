// Given integers n, l and r, find the number of ways to represent n as a sum of two integers A and B such that l ≤ A ≤ B ≤ r.

// Example

// For n = 6, l = 2, and r = 4, the output should be
// solution(n, l, r) = 2.

// There are just two ways to write 6 as A + B, where 2 ≤ A ≤ B ≤ 4: 6 = 2 + 4 and 6 = 3 + 3.

int solution(int n, int l, int r) {
    map<int, int> hash;
    int answer = 0;
    int L = l;
    while(L<=r) {
        hash[n-L]++;
        L++;
    }
    int R = r;
    vector<int> stack;
    bool in_stack = false;
    for (; R>=l; R--) {
        if (hash[R] != 0) {
            for (unsigned int i = 0; i < stack.size(); i++) {
                if (stack[i] == R) {
                    in_stack = true;
                    break;
                }
            }
            if (in_stack) { in_stack = false; continue; }
            stack.push_back(n-R);
            answer++;
        }
    }
    
    return answer;
}
