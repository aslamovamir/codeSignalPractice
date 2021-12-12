// Determine if the given number is a square of some non-negative integer.

// Example

// For n = 25, the output should be
// solution(n) = true;
// For n = 72, the output should be
// solution(n) = false.

bool solution(int n) {
    if (n < 100) {
        int indexing = 1;
        while (pow(indexing, 2) < 100) {
            if (n == pow(indexing, 2)) {
                return true;
            }
            indexing++;
            if (pow(indexing, 2) > n) {
                return false;
            }
        }
        return false;
    } else if (n >= 100 && n < 1000) {
        int indexing = 10;
        while (pow(indexing, 2) < 1000) {
            if (n == pow(indexing, 2)) {
                return true;
            }
            indexing++;
            if (pow(indexing, 2) > n) {
                return false;
            }
        }
        return false;
    } else {
        int indexing = 1000;
        while(pow(indexing, 2) != n) {
            if (pow(indexing, 2) > n) {
                return false;
            }
            indexing++;
        }
        return true;
    }
}
