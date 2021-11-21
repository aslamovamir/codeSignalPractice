string solution(string s) {
    std::map<char, int> CFMap;
    for (int i = 0; i < s.size(); i++) {
        CFMap[s[i]]++;
    }
    char temp;
    bool met = false;
    vector<char> stack_unique;
    for (int i = 0; i < s.length(); i++) {
        temp = s[i];
        for (int j = 0; j < stack_unique.size(); j++) {
            if (temp == stack_unique[j]) {
                met = true;
                break;
            }
        }
        if (!met) {
            stack_unique.push_back(temp);
        }
        met = false;
    }
    
    string result = "";
    for (int i = 0; i < stack_unique.size(); i++) {
        if (CFMap[stack_unique[i]] != 1) {
            result += to_string(CFMap[stack_unique[i]]);
        }
        result += stack_unique[i];
    } 
    
    return result;
}
