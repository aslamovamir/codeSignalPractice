// Given a string, find out if its characters can be rearranged to form a palindrome.
// For inputString = "aabb", the output should be
// palindromeRearranging(inputString) = true.

// We can rearrange "aabb" to make "abba", which is a palindrome.

bool palindromeRearranging(string inputString) {
    
    bool can_be_pal = true;
    //any string can have its letters rearranged to form a palindrome 
    //if the number of each of the letters is some even number or/and only of 
    //of the letters' number is odd
    
    //to check for that we make a vector of numbers of unique letters
    vector<char>unique_chars;
    bool repeated = false;
    unique_chars.push_back(inputString[0]);
    for (int i = 1; i < inputString.length(); i++) {
        repeated = false;
        for (int j = 0; j < unique_chars.size(); j++) {
            if (inputString[i] == unique_chars[j]) {
                repeated = true;
                break;
            }
        }
        if (repeated) {
            continue;
        }
        unique_chars.push_back(inputString[i]);
    }

    //now we create a vector to store the number of each letter in the string
    vector<int> size_unique (unique_chars.size());
    for (int i = 0; i < unique_chars.size(); i++) {
        for (int j = 0; j < inputString.length(); j++) {
            if (unique_chars[i] == inputString[j]) {
                size_unique[i]++;
            }
        }
    }

    //now we check for even numbers, and only one number of odd numbers
    bool met_odd = false;
    for (int i = 0; i < size_unique.size(); i++) {
        if (size_unique[i]%2 != 0 && met_odd) {
            can_be_pal = false;
            break;
        }
        if (size_unique[i]%2 != 0) {
            if (met_odd) {
                can_be_pal = false;
                break;
            } else {
                met_odd = true;
            }
        }
    }
    
    return can_be_pal;
}
