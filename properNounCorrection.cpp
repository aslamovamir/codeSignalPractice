// Proper nouns always begin with a capital letter, followed by small letters.

// Correct a given proper noun so that it fits this statement.

// Example

// For noun = "pARiS", the output should be
// solution(noun) = "Paris";
// For noun = "John", the output should be
// solution(noun) = "John".

string solution(string noun) {
    for (unsigned int i = 0; i < noun.length(); i++) {
        if (i == 0) {
            noun[i] = toupper(noun[i]);
            continue;
        }
        noun[i] = tolower(noun[i]);
    }
    return noun;
}
