bool solution(string inputString) {
    if (inputString.length()%2 != 0) {
        return false;
    } else {
        map<char, int> Map;
        for (unsigned int i = 0; i < inputString.length(); i++) {
            Map[inputString[i]]++;
        }
        for (map<char, int>::iterator itr = Map.begin(); itr != Map.end(); itr++) {
            if (itr->second%2 != 0) {
                return false;
            }
        }
        return true;
    }
}
