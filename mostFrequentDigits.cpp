// Given an array of integers a,your task is to calculate the digits that occur the most 
// number of times in the array. Return the array of these digits in ascending order.
// For a = [25, 2, 3, 57, 38, 41], the output should be mostFrequentDigits(a) = [2, 3, 5].


vector<int> mostFrequentDigits(vector<int> a) {
    vector<int> most_freq;
    
    vector<int> digit_list;

    
    int number;
    int digit;
    int tens = 10;
    bool cycled = false;
    for (int i = 0; i < a.size(); i++) {
        number = a[i];
        while (true) {
            digit = number%tens;
            digit_list.push_back(digit);
            if (number/tens == 0) {
                break;
            } else {
                number = number/tens;
            }
        }
    }
    // for (int i = 0; i < digit_list.size(); i++) {
    //     cout<<digit_list[i]<<" ";
    // }
    //get unique
    bool met_already = false;
    vector<int> unique;
    for (int i = 0; i < digit_list.size(); i++) {
        for (int j = 0; j < unique.size(); j++) {
            if (digit_list[i] == unique[j]) {
                met_already = true;
                break;
            }
        }
        if (met_already) {
            met_already = false;
            continue;
        } else {
            unique.push_back(digit_list[i]);
            met_already = false;
        }
    }
    std::cout<<"\nUNIQUE: ";
    for (int i = 0; i < unique.size(); i++) {
        cout<<unique[i]<<" ";
    }
    vector<int> freq_list(unique.size());
    for (int i = 0; i < unique.size(); i++) {
        for (int j = 0; j < digit_list.size(); j++) {
            if (unique[i] == digit_list[j]) {
                freq_list[i]++;
            }
        }
    }
    cout<<"\nFREQUENCIES:";
    for (int i = 0; i < freq_list.size(); i++) {
        std::cout<<freq_list[i]<<" "; 
    }
    int biggest = freq_list[0];
    for (int i = 0 ; i < freq_list.size(); i++) {
        if (biggest < freq_list[i]) {
            biggest = freq_list[i];
        }
    }
    
    for (int i = 0; i < freq_list.size(); i++) {
        if (freq_list[i] == biggest) {
            most_freq.push_back(unique[i]);
        }
    }
    sort(most_freq.begin(), most_freq.end());
    std::cout<<"\nMOST FREQUENT: ";
    for (int i = 0; i < most_freq.size(); i++) {
        cout<<most_freq[i]<<" ";
    }
    
    
    return most_freq;
}


