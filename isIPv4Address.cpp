//An IP address is a numerical label assigned to each device (e.g., computer, printer) participating 
//in a computer network that uses the Internet Protocol for communication. There are two versions of 
//the Internet protocol, and thus two versions of addresses. One of them is the IPv4 address.

//Given a string, find out if it satisfies the IPv4 address naming rules.
//For inputString = "172.16.254.1", the output should be
//isIPv4Address(inputString) = true;

//For inputString = "172.316.254.1", the output should be
//isIPv4Address(inputString) = false.

//316 is not in range [0, 255].

// For inputString = ".254.255.0", the output should be
// isIPv4Address(inputString) = false.

// There is no first number.

bool isIPv4Address(string inputString) {
    
    bool valid = true;
    
    //first we check the string whether:
    //1)starts with a dot, 2)contains less than 3 or more than 3 dots
    //3)any dots are next to each other, 4)the string ends with a dot
    
    int size = inputString.length();
    //check if the string starts with a dot
    if (inputString[0] == '.') {
        return false;
    }
    //check if the string ends with a dot
    if ((inputString[size-1]) == '.') {
        return false;
    } 
    //now we check if the number of dots is exactly 3, and any dots are
    //consecutive
    int num_dots = 0;
    for (int i = 0; i < size; i++) {
        if (inputString[i] == '.') {
            num_dots++;
            if (num_dots > 3) {
                return false;
            }
            //assuming no string starts with a dot at this point
            if (inputString[i-1] == '.') {
                return false;
            }
        }
    }
    if (num_dots < 3) { return false; }
    
    //we can assume that at this point, the string is correctly formatted
    //we can check for valid values of the integers
    //let's store the indeces at which there are dots in a vector
    vector<int>indeces_dots;
    //we will include 0 for utility puposes
    indeces_dots.push_back(0);
    for (int i = 0; i < size; i++) {
        if (inputString[i] == '.') {
              indeces_dots.push_back(i + 1);//we add 1 for utility purposes(we don't want to include dot itself)
        }
    }
    

    //now we go through the vector, and extract substrings and turn to integers
    //if the value of the integers is outside the valid amounts, we return false
    string buffer;
    int int_buffer;
    for (int i = 0; i < indeces_dots.size(); i++) {
        if (i == indeces_dots.size() - 1) {
            buffer = inputString.substr(indeces_dots[i], inputString.length() - 1);
        } else {
            buffer = inputString.substr(indeces_dots[i], indeces_dots[i+1] - indeces_dots[i] - 1);
        }
        //now we check if all the chars are digits
        for (int j = 0; j < buffer.length(); j++) {
            if (j == 0 && buffer[0] == '0' && buffer.length() != 1) {
                return false;
            }
            if (!isdigit(buffer[j])) {
                return false;
            }
        }
        try {
            int_buffer = stoi(buffer);
        } catch(std::invalid_argument error) {
            return false;
        } catch (std::out_of_range error1) {
            return false;
        }
        if (int_buffer < 0 || int_buffer > 255) {
            return false;
        }
    }
    
    return valid;
}
