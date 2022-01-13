# Yesterday you found some shoes in the back of your closet. Each shoe is described by two values:

# type indicates if it's a left or a right shoe;
# size is the size of the shoe.
# Your task is to check whether it is possible to pair the shoes you found in such a way that each pair consists of a right and a left shoe of an equal size.

# Example

# For

# shoes = [[0, 21], 
#          [1, 23], 
#          [1, 21], 
#          [0, 23]]
# the output should be
# solution(shoes) = true;

# For

# shoes = [[0, 21], 
#          [1, 23], 
#          [1, 21], 
#          [1, 23]]
# the output should be
# solution(shoes) = false.

def solution(shoes):
    if len(shoes) == 1 or len(shoes) == 0:
        return False
    
    # we will store the 2 types of shoes and their frequencies 
    # in 2 different dictionaries
    Map0 = {}
    Map1 = {}
    
    for pair in shoes:
        # if the type is 0
        if pair[0] == 0:
            if pair[1] not in Map0:
                Map0[pair[1]] = 1
            else:
                Map0[pair[1]] += 1
        # if the type is 1
        else:
            if pair[1] not in Map1:
                Map1[pair[1]] = 1
            else:
                Map1[pair[1]] += 1
    
    # we will check both of the maps
    for key, value in Map0.items():
        if key in Map1:
            # if the number of these shoes is not equal to each other
            # we return false
            if value != Map1[key]:
                return False
        else:
            return False
    
    for key, value in Map1.items():
        if key in Map0:
            # if the number of these shoes is not equal to each other
            # we return false
            if value != Map0[key]:
                return False
        else:
            return False
    
    return True
  
