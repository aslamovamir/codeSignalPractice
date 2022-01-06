# Given two strings a and b, both consisting only of lowercase English letters, your task is to calculate how many strings equal to a can 
# be constructed using only letters from the string b? Each letter can be used only once and in one string only.

# Example

# For a = "abc" and b = "abccba", the output should be solution(a, b) = 2.

# We can construct 2 strings a = "abc" using only letters from the string b.

# For a = "ab" and b = "abcbcb", the output should be solution(a, b) = 1.


def solution(a, b):
    MapFreq_a = {}
    MapFreq_b = {}
    
    Set = set()
    # collect from a
    for char in a:
        if char not in MapFreq_a:
            Set.add(char)
            MapFreq_a[char] = 1
        else:
            MapFreq_a[char] += 1
            
    # collect from b those that are in a
    for char in b:
        if char in MapFreq_a:
            if char not in MapFreq_b:
                MapFreq_b[char] = 1
            else:
                MapFreq_b[char] += 1
    
    map_b_complete = True
    for char in a:
        if char not in MapFreq_b:
            map_b_complete = False
            break
    
    if map_b_complete:
        counter = 0
        while True:
            terminate = False
            for char in Set:
                if MapFreq_b[char] - MapFreq_a[char] >= 0:
                    MapFreq_b[char] -= MapFreq_a[char]
                else:
                    terminate = True
                    break
            if terminate:
                break
            else:
                counter += 1
        return counter
    else:
        return 0

      
