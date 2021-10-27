// You're given three integers, a, b and c. It is guaranteed that two of these integers are equal to each other. What is the value of the third integer?

int extraNumber(int a, int b, int c) {
    if (a == b) {
        return c;
    } else if (a == c) {
        return b;
    } else if (b == c) {
        return a;
    }
}
