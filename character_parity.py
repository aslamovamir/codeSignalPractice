# Given a character, check if it represents an odd digit, an even digit or not a digit at all.

# Example

# For symbol = '5', the output should be
# solution(symbol) = "odd";
# For symbol = '8', the output should be
# solution(symbol) = "even";
# For symbol = 'q', the output should be
# solution(symbol) = "not a digit".


def solution(symbol):
    if symbol.isdigit():
        if int(symbol)%2 == 0:
            return "even"
        else:
            return "odd"
    else:
        return "not a digit"
      
      
