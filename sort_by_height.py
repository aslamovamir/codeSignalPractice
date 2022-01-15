# Some people are standing in a row in a park. There are trees between them which cannot be moved. Your task is to rearrange the people by their 
# heights in a non-descending order without moving the trees. People can be very tall!

# Example

# For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
# solution(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

def solution(a):
    # let's first store the height into a seperate list
    heights = []
    
    for item in a:
        if item != -1:
            heights.append(item)
        
    # let's now sort the heights
    heights.sort()
    
    # now we loop again, and if we encounter a height, we take a value 
    # from the sorted heights list
    indexing = 0
    for i in range(len(a)):
        if a[i] != -1:
            a[i] = heights[indexing]
            indexing += 1
            
    return a
  
