// Given an integer n, find the minimal k such that

// k = m! (where m! = 1 * 2 * ... * m) for some integer m;
// k >= n.
// In other words, find the smallest factorial which is not less than n.

// Example

// For n = 17, the output should be
// solution(n) = 24.

// 17 < 24 = 4! = 1 * 2 * 3 * 4, while 3! = 1 * 2 * 3 = 6 < 17).

int solution(int n) {
    int answer = 1;
    int regulator;
    for (int i = 1; i < n; i++) {
        regulator = i;
        if (regulator == 1) {
            answer += 1;
        } else if (regulator == 2) {
            answer += 2;
        } else {
            while(regulator >= 1) {
            answer *= regulator;
            regulator--;
            }    
        }
        if (answer >= n) {
            break;
        }
        answer = 1;
    }
    return answer;
}
