//Given a sequence of integers as an array, determine whether it is possible to obtain a strictly 
//increasing sequence by removing no more than one element from the array.

bool almostIncreasingSequence(vector<int> sequence) {
    bool strictly_increasing = false;
    int size = sequence.size();
    
    
    bool sorted = true;
    int compare1, compare2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sorted = true;
            if (j == size - 1) {
                break;
            }
            if (i == j) {
                j++;
            }
            compare1 = sequence[j];
            if (i == size - 1 && j + 1 == size - 1) {
                break;
            }
            if (j+1 == i) {
                j++;
            }
            compare2 = sequence[j+1];
            if (compare1 >= compare2) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            strictly_increasing = true;
            break;
        }
    }
    
    return strictly_increasing;
}
