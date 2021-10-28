// Given integers a and b, determine whether the following pseudocode results in an infinite loop

// while a is not equal to b do
//   increase a by 1
//   decrease b by 1
// Assume that the program is executed on a virtual machine which can store arbitrary long numbers and execute forever.

bool isInfiniteProcess(int a, int b) {
    if (a == b) {
        return false;
    } else if ((a - b) % 2 != 0) {
        return true;
    } else if (a+1 == b) {
        return true;
    } else if (a >= b) {
        return true;
    } else if (b < 0) {
        return true;
    } else {
        return false;
    }
}
