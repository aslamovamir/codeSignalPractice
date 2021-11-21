// Given a string, return its encoding defined as follows:

// First, the string is divided into the least possible number of disjoint substrings consisting of identical characters
// for example, "aabbbc" is divided into ["aa", "bbb", "c"]
// Next, each substring with length greater than one is replaced with a concatenation of its length and the repeating character
// for example, substring "bbb" is replaced by "3b"
// Finally, all the new strings are concatenated together in the same order and a new string is returned.
// Example

// For s = "aabbbc", the output should be
// solution(s) = "2a3bc".

string solution(string s) {
    string result;
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i == s.length()-1) {
            result += s[i];
            break;
        }
        if (s[i+1] == s[i]) {
            counter += 2;
            i++;
            while(s[i+1] == s[i]) {
                counter++;
                i++;
            }
            result += to_string(counter);
            counter = 0;
        }
        result += s[i];
    }
    return result;
}
