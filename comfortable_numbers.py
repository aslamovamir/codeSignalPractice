# Let's say that number a feels comfortable with number b if a ≠ b and b lies in the segment [a - s(a), a + s(a)], where s(x) is the sum of x's digits.

# How many pairs (a, b) are there, such that a < b, both a and b lie on the segment [l, r], and each number feels comfortable with the other (so a 
# feels comfortable with b and b feels comfortable with a)?

# Example

# For l = 10 and r = 12, the output should be
# solution(l, r) = 2.

# Here are all values of s(x) to consider:

# s(10) = 1, so 10 is comfortable with 9 and 11;
# s(11) = 2, so 11 is comfortable with 9, 10, 12 and 13;
# s(12) = 3, so 12 is comfortable with 9, 10, 11, 13, 14 and 15.
# Thus, there are 2 pairs of numbers comfortable with each other within the segment [10; 12]: (10, 11) and (11, 12).




def solution(l, r):
    # idea is to loop through all the numbers in the range from l to r
    # and to keep record of the numbers each of the number within the range
    # is comfortable with. We will keep this record in a dictionary -
    # - the keys will be the numbers from the range, and the values will be
    # a list of numbers they are comfartble with;
    # to help with the identification of the list of comfortable numbers
    # we will create a helper function
    
    # helper function
    def list_comfortable(number):
        list_comf = []
        # let's define the sum of digits
        digits = [int(digit) for digit in str(number)]
        sum_digs = sum(digits)
        # now we have a range of numbers to check
        for num in range(number - sum_digs, number + sum_digs + 1):
            if num != number:
                list_comf.append(num)
        
        #print("List of comfortable number of the number: ", list_comf)
        
        return list_comf
        
    
    # a dictionary to store the numbers in the range and thier list of comfortable numbers
    MapComf = {}
    
    # let's loop in the range
    for i in range(l, r + 1):
        MapComf[i] = list_comfortable(i)
        
    # now we loop through the map and see if any number in the list of comfortable numbers
    # is comfortable with any other number, if so we increment our variable counter
    counter = 0
    for i in range(l, r + 1):
        for j in range (i + 1, r + 1):
            # if both of the number are in each other's list, we increment the counter
            if j in MapComf[i] and i in MapComf[j]:
                counter += 1
    
    
    return counter
  
  
