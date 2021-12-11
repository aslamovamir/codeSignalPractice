// Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, each statue having an non-negative
// integer size. Since he likes to make things perfect, he wants to arrange them from smallest to largest so that each statue
// will be bigger than the previous one exactly by 1. He may need some additional statues to be able to accomplish that. Help 
// him figure out the minimum number of additional statues needed.
  
// For statues = [6, 2, 3, 8], the output should be
// solution(statues) = 3.

// Ratiorg needs statues of sizes 4, 5 and 7.

int solution(vector<int> statues) {
    int answer = 0;
    if (statues.size() <= 1) {
        return answer;
    }
    stack<int> Stack;
    sort(statues.begin(), statues.end());
    for (unsigned int i = 1; i < statues.size(); i++) {
        cout<<statues[i];
        Stack.push(statues[i] - statues[i-1]);
    }
    while (!Stack.empty()) {
        if (Stack.top() != 1) {
            answer += Stack.top()-1;
        }
        Stack.pop();
    }
    return answer;
}
