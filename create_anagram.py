# You are given two strings s and t of the same length, consisting of uppercase English letters. Your task is to find the minimum number of 
# "replacement operations" needed to get some anagram of the string t from the string s. A replacement operation is performed by picking exactly 
# one character from the string s and replacing it by some other character.

# Example

# For s = "AABAA" and t = "BBAAA", the output should be
# solution(s, t) = 1;
# For s = "OVGHK" and t = "RPGUC", the output should be
# solution(s, t) = 4.

def solution(s, t):
    Map_t = {}
    Map_s = {}
    answer = 0
    
    for letter in s:
        if letter not in Map_s:
            Map_s[letter] = 1
        else:
            Map_s[letter] += 1
    
    for letter in t:
        if letter not in Map_t:
            Map_t[letter] = 1
        else:
            Map_t[letter] += 1
    
    Set = set()
    
    for letter in t:
        if letter not in Set:
            Set.add(letter)
            if letter not in Map_s:
                answer += Map_t[letter]
            else:
                if Map_t[letter] > Map_s[letter]:
                    answer += (Map_t[letter] - Map_s[letter])
    
    return answer

