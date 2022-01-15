# You are watching a volleyball tournament, but you missed the beginning of the very first game of your favorite team. Now you're curious about how the 
# coach arranged the players on the field at the start of the game.

# The team you favor plays in the following formation:

# 0 3 0
# 4 0 2
# 0 6 0
# 5 0 1
# where positive numbers represent positions occupied by players. After the team gains the serve, its members rotate one position in a clockwise direction, 
# so the player in position 2 moves to position 1, the player in position 3 moves to position 2, and so on, with the player in position 1 moving to position
# 6.

# Here's how the players change their positions:



# Given the current formation of the team and the number of times k it gained the serve, find the initial position of each player in it.

# Example

# For

# formation = [["empty",   "Player5", "empty"],
#              ["Player4", "empty",   "Player2"],
#              ["empty",   "Player3", "empty"],
#              ["Player6", "empty",   "Player1"]]
# and k = 2, the output should be

# solution(formation, k) = [
#     ["empty",   "Player1", "empty"],
#     ["Player2", "empty",   "Player3"],
#     ["empty",   "Player4", "empty"],
#     ["Player5", "empty",   "Player6"]
# ]
# For

# formation = [["empty", "Alice", "empty"],
#              ["Bob",   "empty", "Charlie"],
#              ["empty", "Dave",  "empty"],
#              ["Eve",   "empty", "Frank"]]
# and k = 6, the output should be

# solution(formation, k) = [
#     ["empty", "Alice", "empty"],
#     ["Bob",   "empty", "Charlie"],
#     ["empty", "Dave",  "empty"],
#     ["Eve",   "empty", "Frank"]
# ]


def solution(formation, k):
    # first let's store the players in a list in a clockwise fashion
    players_roll = []
    
    # get the first row
    for player in formation[0]:
        if player != 'empty':
            players_roll.append(player)
    # get the last column except for the last of row 1   
    for i in range(1, len(formation)):
        if formation[i][2] != 'empty':
            players_roll.append(formation[i][2])
    # get the second column except for the second of row 1
    for i in range(1, len(formation)):
        if formation[i][1] != 'empty':
            players_roll.append(formation[i][1])
    # get the first column except for the first of row 1
    # get them from bottom to top
    for i in reversed(range(len(formation))):
        if i == 0:
            break
        if formation[i][0] != 'empty':
            players_roll.append(formation[i][0])    
        
    # let's find out the number of swaps we need
    # because 6 gains means the formation returns to the initial state,
    # we are interested in the gains modulo the number of players
    swaps = k % len(players_roll)
    # if the swaps is 0, we return the original formation
    if not swaps:
        return formation
    else:
        # let's store which player each player at the given formation at the start in a seperate list
        # then we will loop through the formation in a circular faishion once again and replace the 
        # player with the player from the swap list - we will take advantage of positional indexing
        swap_list = []
        for i in range(len(players_roll)):
            swap_index = (i + swaps)%len(players_roll)
            # make a pair
            swap_list.append(players_roll[swap_index])
         
        # rotationally loop through the formation and swap    
        # positional indexing
        index = 0
        # get the first row
        for i in range(len(formation[0])):
            if formation[0][i] != 'empty':
                formation[0][i] = swap_list[index]
                index += 1
        # get the last column except for the last of row 1   
        for i in range(1, len(formation)):
            if formation[i][2] != 'empty':
                formation[i][2] = swap_list[index]
                index += 1
        # get the second column except for the second of row 1
        for i in range(1, len(formation)):
            if formation[i][1] != 'empty':
                formation[i][1] = swap_list[index]
                index += 1
        # get the first column except for the first of row 1
        # get them from bottom to top
        for i in reversed(range(len(formation))):
            if i == 0:
                break
            if formation[i][0] != 'empty':
                formation[i][0] = swap_list[index]
                index += 1
        
        return formation
      
      
