# You are implementing a command-line version of the Paint app. Since the command line doesn't support colors, you are using different characters to represent 
# pixels. Your current goal is to support rectangle x1 y1 x2 y2 operation, which draws a rectangle that has an upper left corner at (x1, y1) and a lower right
# corner at (x2, y2). Here the x-axis points from left to right, and the y-axis points from top to bottom.

# Given the initial canvas state and the array that represents the coordinates of the two corners, return the canvas state after the operation is applied. For 
# the details about how rectangles are painted, see the example.

# Example

# For

# canvas = [['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
#           ['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
#           ['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
#           ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
#           ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']]
# and rectangle = [1, 1, 4, 3], the output should be

# solution(canvas, rectangle) = [['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
#                   					['a', '*', '-', '-', '*', 'a', 'a', 'a'],
#                   					['a', '|', 'a', 'a', '|', 'a', 'a', 'a'],
#                   					['b', '*', '-', '-', '*', 'b', 'b', 'b'],
#                   					['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']]
# Here is the rectangle, colored for illustration:


# [['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
# ['a', '*', '-', '-', '*', 'a', 'a', 'a'],
# ['a', '|', 'a', 'a', '|', 'a', 'a', 'a'],
# ['b', '*', '-', '-', '*', 'b', 'b', 'b'],
# ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']]
# Note that rectangle sides are depicted as -s and |s, asterisks (*) stand for its corners and all of the other "pixels" remain the same.


def solution(canvas, rectangle):
    # let's get the corners provided
    top_left_x = rectangle[1]
    top_left_y = rectangle[0]
    bottom_right_x = rectangle[3]
    bottom_right_y = rectangle[2]
    
    # let's now get the corners not provided
    top_right_x = top_left_x
    top_right_y = bottom_right_y
    bottom_left_x = bottom_right_x
    bottom_left_y = top_left_y
    
    # let's label the corners first now
    # top left corner
    canvas[top_left_x][top_left_y] = '*'
    # top right corner
    canvas[top_right_x][top_right_y] = '*'
    # bottom left corner
    canvas[bottom_left_x][bottom_left_y] = '*'
    # bttom right corner
    canvas[bottom_right_x][bottom_right_y] = '*'
    
    # now let's get the borders
    # first, let's get horizontal borders
    left_y = top_left_y
    right_y = bottom_right_y
    while top_left_y < top_right_y - 1:
        top_left_y += 1
        canvas[top_left_x][top_left_y] = '-'
    
    while bottom_left_y < bottom_right_y - 1:
        bottom_left_y += 1
        canvas[bottom_left_x][bottom_left_y] = '-'
    
    # now, let's get the vertical borders
    while top_left_x < bottom_left_x - 1:
        print('X: ', top_left_x, 'Y: ', left_y)
        top_left_x += 1
        canvas[top_left_x][left_y] = '|'
    
    while top_right_x < bottom_right_x - 1:
        top_right_x += 1
        canvas[top_right_x][right_y] = '|'
    
    
    return canvas
    
