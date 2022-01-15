# You have been watching a video for some time. Knowing the total video duration find out what portion of the video you have already watched.

# Example

# For part = "02:20:00" and total = "07:00:00", the output should be
# solution(part, total) = [1, 3].

# You have watched 1 / 3 of the whole video.

# Input/Output

# [execution time limit] 4 seconds (py3)

# [input] string part

# A string of the following format "hh:mm:ss" representing the time you have been watching the video.

# [input] string total

# A string of the following format "hh:mm:ss" representing the total video duration.

# [output] array.integer

# An array of the following format [a, b] (where a / b is a reduced fraction).

from fractions import Fraction
def solution(part, total):
    # idea is to divide the total duration in seconds by the total time of moview we have watched
    # let's first seperate the hours, minutes and seconds and store in a list
    time_duration = total.split(':')
    time_part = part.split(':')
    
    print(time_duration)
    print(time_part)
    # let's collect the total times in seconds
    duration_total = int(time_duration[0])*3600 + int(time_duration[1])*60 + int(time_duration[2])
    part_total = int(time_part[0])*3600 + int(time_part[1])*60 + int(time_part[2])
    
    print(duration_total)
    print(part_total)
    
    ratio = part_total/duration_total
    ratio = round(ratio, 1)

    # we will use python built-in method to get a reduced fraction
    fraction_obj = Fraction(part_total, duration_total)
    # split the fraction object into a list
    fract_list = str(fraction_obj).split('/')
    answer = []
    # if the two durations are the same, the fraction object is equal to 1,
    # meaning that there is only 1 value in the fract_list
    if len(fract_list) == 1:
        answer.append(1)
        answer.append(1)
        return answer
    answer.append(int(fract_list[0]))
    answer.append(int(fract_list[1]))
    
    return answer


