// CodeMaster has just returned from shopping. He scanned the check of the items he bought and gave the 
// resulting string to Ratiorg to figure out the total number of purchased items. Since Ratiorg is a bot 
// he is definitely going to automate it, so he needs a program that sums up all the numbers which appear
// in the given input.

// Help Ratiorg by writing a function that returns the sum of numbers that appear in the given inputString.

// Example

// For inputString = "2 apples, 12 oranges", the output should be
// solution(inputString) = 14.

int solution(string inputString) {
    int result=0;
    int digit;
    string num="";
    for (int i=0; i<inputString.size(); i++) {
        if (isdigit(inputString[i])) {
            num+=inputString[i]; 
        } else {
            if (num=="") { continue; }
            else {
                result += stoi(num);
                num="";
            }
        }
        if (i==inputString.length()-1) {
            if (num=="") { continue; }
            else {
                result += stoi(num);
                num="";
            }
        }
    }
    return result;
}
