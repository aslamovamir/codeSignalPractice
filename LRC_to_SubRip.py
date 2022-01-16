# During your most recent trip to Codelandia you decided to buy a brand new CodePlayer, a music player that (allegedly) can work with any possible 
# media format. As it turns out, this isn't true: the player can't read lyrics written in the LRC format. It can, however, read the SubRip format,
# so now you want to translate all the lyrics you have from LRC to SubRip.

# Since you are a pro programmer (no noob would ever get to Codelandia!), you're happy to implement a function that, given lrcLyrics and songLength,
# returns the lyrics in SubRip format.

# Example

# For

# lrcLyrics = ["[00:12.00] Happy birthday dear coder,",
#              "[00:17.20] Happy birthday to you!"]
# and songLength = "00:00:20", the output should be

# solution(lrcLyrics, songLength) = [
#   "1",
#   "00:00:12,000 --> 00:00:17,200",
#   "Happy birthday dear coder,",
#   "",
#   "2",
#   "00:00:17,200 --> 00:00:20,000",
#   "Happy birthday to you!"
# ]

def solution(lrcLyrics, songLength):
    
    
     # let's create a helper function to process the duration
    def durationLRC(duration):
        
        split = duration.split(":")
        hours = str(int(split[0])//60).zfill(2)
        minutes = str(int(split[0])%60).zfill(2)
        seconds_split = split[1].split(".")
        seconds_1 = seconds_split[0].zfill(2)
        seconds_2 = seconds_split[1].ljust(3, "0")
        duration = f"{hours}:{minutes}:{seconds_1},{seconds_2}"
        
        return duration
    
    
    # let's create another helper function to format the song lenght provided
    def durationLRC_length(duration):
        split = duration.split(":")
        duration = f"{split[0]}:{split[1]}:{split[2]},000"
    
        return duration
        
    
    # let's store the songs and thier durations in a 2-d arrray
    # array inside will store the length and the song name
    lyrics = []
    duration = ""
    song_name = ""
    for song in lrcLyrics:
        song_l = []
        # let's first get the duration
        for i in range(1, len(song)):
            if song[i] == ']':
                song_l.append(duration)
                song_name = song[i+2:]
                song_l.append(song_name)
                lyrics.append(song_l)
                break
            duration += song[i]
        song_name = ""
        duration = ""
    
    # let's define a counter
    counter = len(lyrics)
    # answer as a list of strings
    LRC = []
        
    for i in range(len(lyrics)):
        if i == len(lyrics)-1:
            LRC.append(str(i+1))
            duration = f"{durationLRC(lyrics[i][0])} --> {durationLRC_length(songLength)}"
            LRC.append(duration)
            LRC.append(lyrics[i][1])
            break
        LRC.append(str(i+1))
        duration = f"{durationLRC(lyrics[i][0])} --> {durationLRC(lyrics[i+1][0])}"
        LRC.append(duration)
        LRC.append(lyrics[i][1])
        LRC.append('')
    
    return LRC

