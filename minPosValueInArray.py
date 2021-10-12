def solution(A):
    # we first consider all positive numbers
    pos_A = list()
    for i in range(0, len(A)):
        if A[i] < 0:
            continue
        else:
            pos_A.append(A[i])
    sortedA = sorted(pos_A)
    answer = 1
    min_val = 1
    for i in range(0, len(pos_A)):
        if min_val in pos_A:
            min_val += 1
            if i == (len(pos_A) - 1):
                min_val += 1
            continue
        else:
            answer = min_val
            return answer

    answer = min_val
    return answer
