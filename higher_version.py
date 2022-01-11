# Given two version strings composed of several non-negative decimal fields separated by periods ("."), both strings contain equal number of numeric fields.
# Return true if the first version is higher than the second version and false otherwise.

# The syntax follows the regular semver ordering rules:

# 1.0.5 < 1.1.0 < 1.1.5 < 1.1.10 < 1.2.0 < 1.2.2
# < 1.2.10 < 1.10.2 < 2.0.0 < 10.0.0
# There are no leading zeros in any of the numeric fields, i.e. you do not have to handle inputs like 100.020.003 (it would instead be given as 100.20.3).

# Example

# For ver1 = "1.2.2" and ver2 = "1.2.0", the output should be
# solution(ver1, ver2) = true;
# For ver1 = "1.0.5" and ver2 = "1.1.0", the output should be
# solution(ver1, ver2) = false.

def solution(ver1, ver2):
    # let's fisrt seperate the digits into a seperate list
    digits1 = ver1.split('.')
    digits2 = ver2.split('.')
    print(digits1)
    print(digits2)
    
    # now we loop through the two lists and see which are greater
    zip_list = zip(digits1, digits2)
    for d1, d2 in zip_list:
        if int(d1) > int(d2):
            return True
        elif int(d1) < int(d2):
            return False
    
    return False
  
