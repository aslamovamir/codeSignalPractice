// You've intercepted an encrypted message, and you are really curious about its contents. You were able to find out that the message initially contained only
// lowercase English letters, and was encrypted with the following cipher:

// Let all letters from 'a' to 'z' correspond to the numbers from 0 to 25, respectively.
// The number corresponding to the ith letter of the encrypted message is then equal to the sum of numbers corresponding to the first i letters of the initial
// unencrypted message modulo 26.
// Now that you know how the message was encrypted, implement the algorithm to decipher it.

// Example

// For message = "taiaiaertkixquxjnfxxdh", the output should be
// solution(message) = "thisisencryptedmessage".

// The initial message "thisisencryptedmessage" was encrypted as follows:

// letter 0: t -> 19 -> t;
// letter 1: th -> (19 + 7) % 26 -> 0 -> a;
// letter 2: thi -> (19 + 7 + 8) % 26 -> 8 -> i;
// etc.


string solution(string message) {
    string answer = "";
    int runner = 0;
    char encoded;
    int code, encode;
    for (unsigned int i = 0; i < message.length(); i++) {
        cout<<"\n\n\nCYCLE: "<<message[i]<<endl;
        cout<<"RUNNER: "<<runner<<endl;
        code = message[i] - 97;
        cout<<"CODE: "<<code<<endl;
        if (i == 0) {
            cout<<"i is 0!!!"<<endl;
            runner += code;
            encode = runner;
        } else {
            encode = (code + 26 - (runner)%26)%26;
            cout<<"ENCODE: "<<encode<<endl;
            runner += encode;
            cout<<"ENCODE: "<<encode<<endl;
        }
        encoded = 97 + encode;
        cout<<"THE ENCODED CHAR: "<<encoded<<endl;
        answer += encoded;
    }
    
    return answer;
}

