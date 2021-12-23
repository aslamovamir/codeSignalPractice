// Given a rectangular matrix of characters, add a border of asterisks(*) to it.

// Example

// For

// picture = ["abc",
//            "ded"]
// the output should be

// solution(picture) = ["*****",
//                       "*abc*",
//                       "*ded*",
//                       "*****"]
                      
  
vector<string> solution(vector<string> picture) {
    vector<string> answer;
    string iterator = "";
    for (unsigned int i = 0; i < picture[0].length()+2; i++) {
        iterator += '*';
    }
    answer.push_back(iterator);
    iterator = "";
    for (unsigned int i=0; i<picture.size(); i++) {
        iterator += '*';
        iterator += picture[i];
        iterator += '*';
        answer.push_back(iterator);
        iterator = "";
    }
    for (unsigned int i = 0; i < picture[0].length()+2; i++) {
        iterator += '*';
    }
    answer.push_back(iterator);
    iterator = "";
    return answer;
}
