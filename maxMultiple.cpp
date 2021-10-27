// Given a divisor and a bound, find the largest integer N such that:

// N is divisible by divisor.
// N is less than or equal to bound.
// N is greater than 0.
// For divisor = 3 and bound = 10, the output should be
// maxMultiple(divisor, bound) = 9.

int maxMultiple(int divisor, int bound) {
    int N = bound;
    if (N%divisor == 0) {
        return N;
    } else {
        while (N%divisor != 0) {
            N--;
        }
    }
    
    return N;
}
