//Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, each statue having an 
//non-negative integer size. Since he likes to make things perfect, he wants to arrange them from smallest to 
//largest so that each statue will be bigger than the previous one exactly by 1. He may need some additional 
//statues to be able to accomplish that. Help him figure out the minimum number of additional statues needed.

int makeArrayConsecutive2(vector<int> statues) {
    int num_add = 0;
    //we will first sort the array contents from smallest to largest
    //for that, we will use the smallest-from-left algorithm using a stack
    vector<int> stack;
    int to_push, smallest, index;
    int size_orig = statues.size();
    for (int i = 0; i < size_orig; i++) {
        smallest = statues[0];
        index = 0;
        for (int j = 0; j < statues.size(); j++) {
            if (smallest > statues[j]) {
                smallest = statues[j];
                index = j;
            }
        }
        stack.push_back(smallest);
        //we now remove the smallest value from the original vector
        statues.erase(statues.begin() + index);
    }

    cout<<"\nSTACK: ";
    for (int i = 0; i < stack.size(); i++) {
        cout<<stack[i];
    }

    int difference;
    for (int i = 0; i < stack.size(); i++) {
        if (i == stack.size() - 1) {
            break;
        }
        cout<<"\ni: "<<i<<endl;
        difference = stack[i+1] - stack[i];
        if (difference != 1) {
            while(difference != 1) {
                stack[i]++;
                difference = stack[i+1] - stack[i];
                num_add++;
            }
        }
    }
    
    return num_add;
}

