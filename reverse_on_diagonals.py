# The longest diagonals of a square matrix are defined as follows:

# the first longest diagonal goes from the top left corner to the bottom right one;
# the second longest diagonal goes from the top right corner to the bottom left one.
# Given a square matrix, your task is to reverse the order of elements on both of its longest diagonals.

# Example

# For

# matrix = [[1, 2, 3],
#           [4, 5, 6],
#           [7, 8, 9]]
# the output should be

# solution(matrix) = [[9, 2, 7],
#                               [4, 5, 6],
#                               [3, 8, 1]]

def solution(matrix):
    
    # diagonal variable to determine number of swaps
    diagonal = len(matrix)
    
    # let's first swap the first diagonal
    # at this swap process both top and bottom will manage the rows and columns
    top = 0
    bottom = diagonal-1
    while top < bottom:
        temp = matrix[bottom][bottom]
        matrix[bottom][bottom] = matrix[top][top]
        matrix[top][top] = temp
        top += 1
        bottom -= 1
    
    # now we swap the second diagonal
    # this time, top will manage the rows and bottom will manage the columns
    top = 0
    bottom = diagonal - 1 
    while top < bottom:
        temp = matrix[bottom][top]
        matrix[bottom][top] = matrix[top][bottom]
        matrix[top][bottom] = temp
        top += 1
        bottom -= 1
    
    return matrix

