// Check if the given string is a correct time representation of the 24-hour clock.

// Example

// For time = "13:58", the output should be
// solution(time) = true;
// For time = "25:51", the output should be
// solution(time) = false;
// For time = "02:76", the output should be
// solution(time) = false.

bool solution(string time) {
    string hour="";
    string minute="";
    for (int i=0; i<time.length();i++) {
        if (time[i]==':') {
            for (int j=i+1; i<time.length(); j++) {
                minute+=time[j];
                i++;
            }
        } else {
            hour+=time[i];
        }
    }
    if (stoi(hour)>23 || stoi(minute)>59) {
        return false;
    } else {
        return true;
    }
    return true;
}
