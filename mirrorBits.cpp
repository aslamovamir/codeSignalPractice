// For a = 97, the output should be
// solution(a) = 67.

// 97 equals to 1100001 in binary, which is 1000011 after mirroring, and that is 67 in base 10.

// For a = 8, the output should be
// solution(a) = 1.

int solution(int a) {
    int itr = a;
    int answer = 0;
    vector<char> bi_stack;
    while (itr != 0) {
        if (itr % 2 == 1) {
            bi_stack.insert(bi_stack.begin(),'1');
        } else {
            bi_stack.insert(bi_stack.begin(),'0');;
        }
        itr /= 2;
    }
    int regulator = 0;
    for (auto itr: bi_stack) {
        cout<<itr<<" ";
        if (itr == '1') {
            answer += pow(2, regulator);
        }
        regulator++;
    }
    return answer;
}
