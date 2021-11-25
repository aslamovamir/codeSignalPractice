// You are given an array of up to four non-negative integers, each less than 256.

// Your task is to pack these integers into one number M in the following way:

// The first element of the array occupies the first 8 bits of M;
// The second element occupies next 8 bits, and so on.
// Return the obtained integer M.

// Note: the phrase "first bits of M" refers to the least significant bits of M - the right-most bits of an 
// integer. For further clarification see the following example.

// Example

// For a = [24, 85, 0], the output should be
// solution(a) = 21784.

// An array [24, 85, 0] looks like [00011000, 01010101, 00000000] in binary.
// After packing these into one number we get 00000000 01010101 00011000 (spaces are placed for convenience),
// which equals to 21784.

int solution(vector<int> a) {
    int solution = 0;
    vector<char> stack;
    vector<char> bank;
    int iter;
    int remaind;
    
    for (int i = 0; i < a.size(); i++) {
        iter = a[i];
        while(iter != 0) {
            remaind = iter%2;
            if (remaind == 0) {
                stack.insert(stack.begin(),'0');
            } else {
                stack.insert(stack.begin(),'1');
            }
            iter /= 2;
        }
        for (int i = stack.size()-1; i >=0; i--) {
            bank.insert(bank.begin(), stack[i]);
        }
        while(stack.size() != 8) {
            bank.insert(bank.begin(), '0');
            stack.insert(stack.begin(), '0');
        }
        stack.clear();
    }
    int regulator = 0;
    for (int i = bank.size()-1; i >= 0; i--) {
        cout<<bank[i]<<"  ";
        solution += (bank[i] == '0')? 0: (int)pow(2, regulator);
        regulator++; 
    }
    return solution;
}
