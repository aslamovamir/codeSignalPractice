// Define a word as a sequence of consecutive English letters. Find the longest word from the given string.

// Example

// For text = "Ready, steady, go!", the output should be
// solution(text) = "steady".

string solution(string text) {
    string result="";
    string itr_str="";
    int size_counter = 0;
    int longest = 0;
    for (int i = 0; i < text.size(); i++) {
        if (isalpha(text[i])) {
            itr_str+=text[i];
            size_counter++;
        } else {
            if (size_counter > longest) {
              longest = size_counter; 
              result = itr_str;  
            }
            size_counter = 0;
            itr_str = "";
        }
        if (i == text.size()-1 && isalpha(text[i])) {
            if (size_counter > longest) {
              longest = size_counter; 
              result = itr_str;  
            }
        }
    }  
    return result;
}
