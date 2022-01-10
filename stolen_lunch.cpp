// When you recently visited your little nephew, he told you a sad story: there's a bully at school who steals his lunch every day, and locks it away in 
// his locker. He also leaves a note with a strange, coded message. Your nephew gave you one of the notes in hope that you can decipher it for him. And 
// you did: it looks like all the digits in it are replaced with letters and vice versa. Digit 0 is replaced with 'a', 1 is replaced with 'b' and so on,
// with digit 9 replaced by 'j'.

// The note is different every day, so you decide to write a function that will decipher it for your nephew on an ongoing basis.

// Example

// For note = "you'll n4v4r 6u4ss 8t: cdja", the output should be
// solution(note) = "you'll never guess it: 2390".


string solution(string note) {
    string answer = "";
    char run_letter;
    int run_digit;
    
    //we will loop through the string and if we find a digit, we change it to a letter
    //and if a letter corresponds to a value from 0 to 9, we change it to a digit char
    for (unsigned int i = 0; i < note.length(); i++) {
        if (isdigit(note[i])) {
            run_letter = 97 +(note[i] - '0');
            answer += run_letter;
            continue;
        }
        run_digit = note[i] - 97;
        if (run_digit >= 0 && run_digit <= 9) {
            run_letter = '0' + run_digit;
            answer += run_letter;
            continue;
        }
        answer += note[i];
    }
    
    return answer;
}
