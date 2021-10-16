//Given two strings, find the number of common characters between them.

int commonCharacterCount(string s1, string s2) {
    int num_common_ch = 0;
    char iter_char;
    
    //first we will create two stacks for the two strings fro unique letters from each string
    //we will then create two more stacks that will correspondingly store number of these letters in the strings
    
    vector<char> stack_unique1;
    vector<char> stack_unique2;
    vector<int> num_stack_1;
    vector<int> num_stack_2;

    bool continue_condition = false;
    //making the unique list of letters of the string 1
    for (int i = 0; i < s1.length(); i++) {
        continue_condition = false;
        iter_char = s1[i];
        //we also check if we already have the letter in the stack_unique_1
        for (int j = 0; j < stack_unique1.size(); j++) {
            if (iter_char == stack_unique1[j]) {
                continue_condition = true;
                break;
            }
        }
        if (continue_condition) {
            continue;
        }
        stack_unique1.push_back(iter_char);
    }
    for (int i = 0; i < stack_unique1.size(); i++) {
        num_stack_1.push_back(0);
    }
    for (int i = 0; i < stack_unique1.size(); i++) {
        for (int j = 0; j < s1.length(); j++) {
            if (stack_unique1[i] == s1[j]) {
                num_stack_1[i]++;
            }
        }
    }

    //making the unique list of the letters of the string 2
    for (int i = 0; i < s2.length(); i++) {
        continue_condition = false;
        iter_char = s2[i];
        //we also check if we already have the letter in the stack_unique_1
        for (int j = 0; j < stack_unique2.size(); j++) {
            if (iter_char == stack_unique2[j]) {
                continue_condition = true;
                break;
            }
        }
        if (continue_condition) {
            continue;
        }
        stack_unique2.push_back(iter_char);
    }
    for (int i = 0; i < stack_unique2.size(); i++) {
        num_stack_2.push_back(0);
    }
    for (int i = 0; i < stack_unique2.size(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (stack_unique2[i] == s2[j]) {
                num_stack_2[i]++;
            }
        }
    }

    //now we compare the unique stacks of letters of each of the strings
    //if we see a match of the letters, we caompare the corresponding 
    //numbering of these letters in the two stacks of letter numberings
    //the smaller value of the numbering is the common number of the 
    //same letters from the two stacks
    int total_letter_count = 0;
    for (int i = 0; i < stack_unique1.size(); i++) {
        for (int j = 0; j < stack_unique2.size(); j++) {
            if (stack_unique1[i] == stack_unique2[j]) {
                if (num_stack_1[i] - num_stack_2[j] < 0) {
                    total_letter_count += num_stack_1[i];
                } else {
                    total_letter_count += num_stack_2[j];
                }
            }
        }
    }

    return num_common_ch;
}
