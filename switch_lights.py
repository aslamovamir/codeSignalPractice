# N candles are placed in a row, some of them are initially lit. For each candle from the 1st to the Nth the following algorithm is applied: 
# if the observed candle is lit then states of this candle and all candles before it are changed to the opposite. Which candles will remain
# lit after applying the algorithm to all candles in the order they are placed in the line?

# Example

# For a = [1, 1, 1, 1, 1], the output should be
# solution(a) = [0, 1, 0, 1, 0].

# Check out the image below for better understanding:



# For a = [0, 0], the output should be
# solution(a) = [0, 0].

# The candles are not initially lit, so their states are not altered by the algorithm.


def solution(a):
    # idea is to keep all the changes up to a certain candle in a dictionary, 
    # with the key as a candle in a certain position and the values as the number
    # of total opposites met; if the number of oposites is even, then the candle is
    # in the same state as before, but if it is odd, the oposite state is obtained
    
    CandleOppMap = {}
    
    # candles will be identified with thier index in the list
    for i in range(0, len(a)):
        # at default the initial value of each candle is 0
        CandleOppMap[i] = 0
        # print('CYCLE: ', i)
        # now we check if the candle is 1
        # if so, we increment the values of all the keys of the map ontained so far
        if a[i] == 1:
            # print('MET ON')
            for j in range(0, i + 1):
                CandleOppMap[j] += 1
        
    # now we loop through the list and see if the value in the Map is odd or even
    answer = []
    for i in range(0, len(a)):
        if CandleOppMap[i]%2 == 0:
            # if even, we take the same candle state
            answer.append(a[i])
        else:
            answer.append(0 if a[i] == 1 else 1)
        
    return answer   

  
