// Correct variable names consist only of English letters, digits and underscores and they can't start with a digit.

// Check if the given string is a correct variable name.

// Example

// For name = "var_1__Int", the output should be
// variableName(name) = true;
// For name = "qq-q", the output should be
// variableName(name) = false;
// For name = "2w2", the output should be
// variableName(name) = false.

bool variableName(string name) {
    if (isdigit(name[0])) { return false ;}
    for (auto i: name) {
        cout<<i<<"  ";
        if (!(i > 47 && i < 58 || i > 64 && i < 91 || i > 96 && i < 123 || i == 95)) {
            return false;
        }
    } 
    return true;
}
