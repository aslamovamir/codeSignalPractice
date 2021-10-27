//Given an integer n, return the largest number that contains exactly n digits.

int largestNumber(int n) {
    int largest = 0;
    int tens = 1;
    for (int i = 0; i < n; i++) {
        largest += 9 * tens;
        tens *= 10;
    }
    
    return largest;
}
