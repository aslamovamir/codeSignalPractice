# Given a rectangular matrix and integers a and b, consider the union of the ath row and the bth (both 0-based) column of the matrix (i.e. all cells that 
# belong either to the ath row or to the bth column, or to both). Return sum of all elements of that union.

# Example

# For

# matrix = [[1, 1, 1, 1], 
#           [2, 2, 2, 2], 
#           [3, 3, 3, 3]]
# a = 1, and b = 3, the output should be
# solution(matrix, a, b) = 12.

# Here (2 + 2 + 2 + 2) + (1 + 3) = 12.

def solution(matrix, a, b):
    answer = 0
    
    # let's first sum up the elements from the row "a"
    for i in range(len(matrix[a])):
        answer += matrix[a][i]
    
    # now let's add up the elements from the column "b"
    # we will skip the row "a" in the calculation to simulate a union
    for i in range(len(matrix)):
        if i == a:
            continue
        answer += matrix[i][b] 
    
    return answer
  
