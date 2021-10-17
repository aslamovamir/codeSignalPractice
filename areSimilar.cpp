//Two arrays are called similar if one can be obtained from another by swapping at most one pair of elements in one of the arrays.

//Given two arrays a and b, check whether they are similar.

bool areSimilar(vector<int> a, vector<int> b) {
    
    bool similar = false;
    //utility variables
    int temp;
    bool terminate = false;
    
    
    if (a == b) {
        similar = true;
    } else {
        for (int i = 0; i < a.size(); i++) {
            if (i == a.size() - 1) {
                break;
            }
            for (int j = i + 1; j < a.size(); j++) {
                //we do the swap
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                //we check if the a is equal to be after the swap
                //if equal we break out of all loops
                //if not, we do the swap back
                if (a == b) {
                    terminate = true;
                    similar = true;
                    break;
                } else {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
            if (terminate) {
                break;
            }
        }
    }
    
    return similar;
}



//BETTER SOLUTION WITH SMALLER RUN_TIME
//CREDIT TO RicheyHans: https://github.com/RicheyHans/-JAVA-algorithm/blob/master/codefights/areSimilar.java
bool areSimilar(vector<int> a, vector<int> b) {
    
    bool similar = false;
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b) {
        if (count <= 2) {
            similar = true;
        }
    }

    
    return similar;
}
