// We want to turn the given integer into a number that has only one non-zero digit using a tail rounding approach. 
// This means that at each step we take the last non 0 digit of the number and round it to 0 or to 10. If it's 
// less than 5 we round it to 0 if it's larger than or equal to 5 we round it to 10 (rounding to 10 means 
// increasing the next significant digit by 1). The process stops immediately once there is only one non-zero
// digit left.

// Example

// For n = 15, the output should be
// solution(n) = 20;

// For n = 1234, the output should be
// solution(n) = 1000.

// 1234 -> 1230 -> 1200 -> 1000.

// For n = 1445, the output should be
// solution(n) = 2000.

// 1445 -> 1450 -> 1500 -> 2000.

int solution(int n) {
    int answer = 0;
    bool carry = false;
    int regulator = 1;
    while (n!=0) {
        if (n%10 < 5) {
            if (carry) {
                if (n%10 + 1 < 5 && n/10 != 0) {
                    carry = false;    
                }
            }
        } else {
            if(carry) {
                if (n%10 + 1 < 5) {
                    carry = false;
                }
            } else {
                if (n/10 != 0) {
                    carry = true;
                }
            }
        }
        if (n/10 == 0) {
            if (carry) {
                answer += (regulator * (n + 1));
            } else {
                answer += (regulator * n);
            }
        }
        regulator *= 10;
        n/=10;
    }
    return answer;
}
