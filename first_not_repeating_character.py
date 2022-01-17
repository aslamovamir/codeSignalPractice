# Given a string s consisting of small English letters, find and return the first instance of a non-repeating character in it. If there is 
# no such character, return '_'.

# Example

# For s = "abacabad", the output should be
# solution(s) = 'c'.

# There are 2 non-repeating characters in the string: 'c' and 'd'. Return c since it appears in the string first.

# For s = "abacabaabacaba", the output should be
# solution(s) = '_'.

# There are no characters in this string that do not repeat.

def solution(s):
    # let's first store all the numbers in a dictionary, with
    # key as the number, and value its frequency in the list
    FreqMap = {}
    
    for char in s:
        if char not in FreqMap:
            FreqMap[char] = 1
        else:
            FreqMap[char] += 1
    
    # now loop again, and return the number with frequency 1
    for char in s:
        if FreqMap[char] == 1:
            return char
    
    return '_'

  
