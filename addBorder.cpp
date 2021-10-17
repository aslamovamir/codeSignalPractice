//Given a rectangular matrix of characters, add a border of asterisks(*) to it.
//Example: picture = ["abc",
//           "ded"]
// addBorder(picture) = ["*****",
//                       "*abc*",
//                       "*ded*",
//                       "*****"]

vector<string> addBorder(vector<string> picture) {
    vector<string> bordered;
    
    int size = picture[0].length();
    string border = "";
    for (int i = 0; i < size + 2; i++) {
        border += '*';
    }
    bordered.push_back(border);
    
    for (int i = 0; i < picture.size(); i++) {
        bordered.push_back('*' + picture[i] + '*');
    }
    bordered.push_back(border);
    
    return bordered;
}
