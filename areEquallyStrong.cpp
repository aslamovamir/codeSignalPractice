// Call two arms equally strong if the heaviest weights they each are able to lift are equal.

// Call two people equally strong if their strongest arms are equally strong (the strongest arm can be both the right and the left), and so are their weakest arms.

// Given your and your friend's arms' lifting capabilities find out if you two are equally strong.

bool areEquallyStrong(int yourLeft, int yourRight, int friendsLeft, int friendsRight) {

    int yourStrongest = (yourLeft > yourRight) ? yourLeft: yourRight;
    int yourWeakest = (yourStrongest == yourLeft) ? yourRight: yourLeft;
    int friendsStrongest = (friendsLeft > friendsRight) ? friendsLeft: friendsRight;
    int friendsWeakest = (friendsStrongest == friendsLeft) ? friendsRight: friendsLeft;
    
    return (yourStrongest == friendsStrongest && yourWeakest == friendsWeakest);
}
