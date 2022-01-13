// Some file managers sort filenames taking into account case of the letters, others compare strings as if all of the letters are of the same case.
// That may lead to different ways of filename ordering.

// Call two filenames an unstable pair if their ordering depends on the case.

// To compare two filenames a and b, find the first position i at which a[i] ≠ b[i]. If a[i] < b[i], then a < b. Otherwise a > b. If such position
// doesn't exist, the shorter string goes first.

// Given two filenames, check whether they form an unstable pair.

// Example

// For filename1 = "aa" and filename2 = "AAB", the output should be
// solution(filename1, filename2) = true.

// Because "AAB" < "aa", but "AAB" > "AA".

// For filename1 = "A" and filename2 = "z", the output should be
// solution(filename1, filename2) = false.

// Both "A" < "z" and "a" < "z".


bool solution(string filename1, string filename2) {
    bool file1_greater;
    bool too_short = true;
    bool too_short1 = true;
    int shorter = filename1.length() > filename2.length()? filename2.length(): filename1.length();
    
    for (int i = 0; i < shorter; i++) {
        if (filename1[i] != filename2[i]) {
            too_short = false;
            if (filename1[i] > filename2[i]) {
                file1_greater = true;
            } else {
                file1_greater = false;
            }
            if (isupper(filename2[i]) && !isupper(filename1[i])) {
                for (int j = 0; j < shorter; j++) {
                    if (toupper(filename1[j]) > filename2[j]) {
                        if (file1_greater) {
                            return false;
                        } else {
                            return true;
                        }
                    } else if (toupper(filename1[j]) < filename2[j]) {
                        if (file1_greater) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
                if (file1_greater) {
                    if (shorter == filename1.length()) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (shorter == filename1.length()) {
                        return false;
                    } else {
                        return true;
                    }
                }
            } else if (islower(filename2[i]) && !islower(filename1[i])) {
                for (int j = 0; j < shorter; j++) {
                    if (tolower(filename1[j]) > filename2[j]) {
                        if (file1_greater) {
                            return false;
                        } else {
                            return true;
                        }
                    } else if (tolower(filename1[j]) < filename2[j]) {
                        if (file1_greater) {
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
                if (file1_greater) {
                    if (shorter == filename1.length()) {
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (shorter == filename1.length()) {
                        return false;
                    } else {
                        return true;
                    }
                }
            } else {
                return false;
            }
        }
    }
    
    return false;
}
