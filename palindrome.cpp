bool checkPalindrome(string inputString) {
    //we will use a stack to push the characters from the orig string, and append one by one to      //another string
    bool palindrome = true;
    string reversed = "";
    vector<char> stack;
    for (int i = 0; i < inputString.length(); i++) {
        stack.insert(stack.begin(), inputString[i]);
    }
    for (int i = 0; i < stack.size(); i++) {
        reversed += stack[i];
    }
    for (int i = 0; i < reversed.length(); i++) {
        if (inputString[i] != reversed[i]) {
            palindrome = false;
            break;
        }
    }
 
    return palindrome;
}
