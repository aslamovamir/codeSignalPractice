// Check if all digits of the given integer are even.

// Example

// For n = 248622, the output should be
// evenDigitsOnly(n) = true;
// For n = 642386, the output should be
// evenDigitsOnly(n) = false.

bool evenDigitsOnly(int n) {
    int digit;
    do {
        cout<<"n: "<<n<<endl;
        digit = n%10;
        cout<<"digit: "<<digit<<endl;
        if (n%2 != 0) { return false; }
        n /= 10;
    } while (n != 0);
    return true;
}
