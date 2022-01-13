# Given array of integers, for each position i, search among the previous positions for the last (from the left) position that contains a smaller value.
# Store this value at position i in the answer. If no such value can be found, store -1 instead.

# Example

# For items = [3, 5, 2, 4, 5], the output should be
# solution(items) = [-1, 3, -1, 2, 4].

def solution(items):
    
    # helper function to return the last smaller value
    def smaller_last(item, items):
        for i in reversed(range(len(items))):
            if items[i] < item:
                return items[i]
        return -1
    
    answer = []
    stack = []
    for i in range(len(items)):
        answer.append(smaller_last(items[i], stack));
        stack.append(items[i])

    return answer
