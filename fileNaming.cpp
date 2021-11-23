// You are given an array of desired filenames in the order of their creation. Since two files cannot have equal names, 
// the one which comes later will have an addition to its name in a form of (k), where k is the smallest positive 
// integersuch that the obtained name is not used yet.

// Return an array of names that will be given to the files.

// Example

// For names = ["doc", "doc", "image", "doc(1)", "doc"], the output should be
// solution(names) = ["doc", "doc(1)", "image", "doc(1)(1)", "doc(2)"].

vector<string> solution(vector<string> names) {
    vector<string> solution;
    map<string, int> stack;
    string iterator="";
    int helper_count;
    for (int i=0; i<names.size(); i++) {
        if (stack[names[i]] == 0) {
            stack[names[i]]++;
            solution.push_back(names[i]);
        } else {
            iterator += names[i]+"("+to_string(stack[names[i]])+")";
            helper_count = stack[names[i]];
            while(stack[iterator] != 0) {
                helper_count++;
                iterator = names[i]+"("+to_string(helper_count)+")";
            }
            solution.push_back(iterator);
            stack[iterator]++;
            stack[names[i]]++;
            iterator="";
        }
    }
    return solution;
}
