// Some phone usage rate may be described as follows:

// first minute of a call costs min1 cents,
// each minute from the 2nd up to 10th (inclusive) costs min2_10 cents
// each minute after 10th costs min11 cents.
// You have s cents on your account before the call. What is the duration of 
// the longest call (in minutes rounded down to the nearest integer) you can have?

int phoneCall(int min1, int min2_10, int min11, int s) {
    if (s - min1 < 0) {
        return 0;
    } else if (s - min1 == 0) {
        return 1;
    } else {
        int duration_call = 1;
        s -= min1;
        int rate2 = s / min2_10;
        if (rate2 > 10) {
            s -= 9 * min2_10;
            duration_call += 9;
            duration_call += s/min11;
            return duration_call;
        } else {
            return 1 + rate2;
        }
    }
}
