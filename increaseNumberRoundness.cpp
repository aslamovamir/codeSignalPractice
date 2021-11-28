// Define an integer's roundness as the number of trailing zeroes in it.

// Given an integer n, check if it's possible to increase n's roundness by swapping some pair of its digits.

// Example

// For n = 902200100, the output should be
// solution(n) = true.

// One of the possible ways to increase roundness of n is to swap digit 1 with digit 0 preceding it: 
// roundness of 902201000 is 3, and roundness of n is 2.

// For instance, one may swap the leftmost 0 with 1.

// For n = 11000, the output should be
// solution(n) = false.

// Roundness of n is 3, and there is no way to increase it.

bool solution(int n) {
    bool met_nonzero = false;
    bool met_zero = false;
    while(n!=0) {
        if (!met_zero) {
            if (n%10 == 0) {
                met_zero = true;
                continue;
            }    
        }
        if (!met_nonzero) {
            if (n%10 != 0) {
                met_nonzero = true;
                continue;
            }
        }
        if (met_nonzero) {
            if (n%10 == 0) {
                return true;
            }
        }
        if (met_zero && !met_nonzero) {
            if (n%10 != 0) {
                met_nonzero = true;
                continue;
            }
        }
        if (met_zero && met_nonzero) {
            if (n%10 == 0) {
                return true;
            }
        }
        n /= 10;
    }
    return false;
}
