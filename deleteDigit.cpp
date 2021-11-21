// Given some integer, find the maximal number you can obtain by deleting exactly one digit of the given number.

// Example

// For n = 152, the output should be
// solution(n) = 52;
// For n = 1001, the output should be
// solution(n) = 101.


int solution(int n) {
    
    vector<int> digs;
    while(n/10 != 0) {
        digs.insert(digs.begin(), n%10);
        n /= 10;
        if (n/10 == 0) {
            digs.insert(digs.begin(), n);
        }
    }
    for (int i = 0; i < digs.size(); i++) {
        if (i == digs.size()-1) {
            digs.erase((digs.begin() + i));
            break;
        }
        if (digs[i] < digs[i+1]) {
            digs.erase(digs.begin() + i);
            break;
        }
    }
    int result = 0;
    int index = digs.size()-1;
    for (int i = 0; i < digs.size(); i++) {
        result += digs[index] * pow(10, i);
        index--;
    }
    return result;
}
