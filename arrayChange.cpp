// You are given an array of integers. On each move you are allowed to 
// increase exactly one of its element by one. Find the minimal number 
// of moves required to obtain a strictly increasing sequence from the input.


int arrayChange(vector<int> inputArray) {
    
    int minChange = 0;
    
    //we keep the difference between consecutive integers in a seperate array
    vector<int> differences;
    int diff;
    for (int i = 1; i < inputArray.size(); i++) {
        diff = inputArray[i] - inputArray[i-1];
        differences.push_back(diff);
    }

    //now we go through the differences array
    //if we encounter a 0, we know two integers are 
    //equal, so we add 1 to one of them, and thus decrease
    //by 1, the difference of between one of these integers
    //and the one next to it, and we keepm checking for 0's
    for (int i = 0; i < differences.size(); i++) {
        if (i == differences.size() - 1) {
            if (differences[i] == 0) {
                minChange++;
            } else if (differences[i] < 0) {
                while (differences[i] != 1) {
                    differences[i]++;
                    minChange++;
                }
            } else {
                break;
            }
        }
        if (differences[i] == 0) {
            //we add 1, so we increment the minChange
            minChange++;
            differences[i+1]--;
        } else if (differences[i] < 0) {
            while (differences[i] != 1) {
                differences[i]++;
                minChange++;
                differences[i+1]--;
            }
        }
    }   

    return minChange;
}
