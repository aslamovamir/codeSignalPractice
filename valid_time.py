# Check if the given string is a correct time representation of the 24-hour clock.

# Example

# For time = "13:58", the output should be
# solution(time) = true;
# For time = "25:51", the output should be
# solution(time) = false;
# For time = "02:76", the output should be
# solution(time) = false.

def solution(time):
    # first let's seperate the hours and minutes and store in a list
    time_list = time.split(":")
    # now we check if the hours and minutes is valid in their respective ranges
    if int(time_list[0]) >= 0 and int(time_list[0]) <= 23:
        if int(time_list[1]) >= 0 and int(time_list[1]) <= 59:
            return True
        else:
            return False
    else:
        return False
