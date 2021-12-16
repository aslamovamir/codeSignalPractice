// Determine whether the given string can be obtained by one concatenation of some string to itself.

// Example

// For inputString = "tandemtandem", the output should be
// solution(inputString) = true;
// For inputString = "qqq", the output should be
// solution(inputString) = false;
// For inputString = "2w2ww", the output should be
// solution(inputString) = false.

bool solution(string inputString) {
    if (inputString.length()%2 != 0) {
        return false;
    } else {
        string part1 = inputString.substr(0, inputString.length()/2);
        string part2 = inputString.substr(inputString.length()/2, inputString.length()/2);
        if (part1 == part2) {
            return true;
        } else {
            return false;
        }
    }
}
