// You found two items in a treasure chest! The first item weighs weight1 and is worth value1, and the second 
// item weighs weight2 and is worth value2. What is the total maximum value of the items you can take with you,
// assuming that your max weight capacity is maxW and you can't come back for the items later?

// Note that there are only two items and you can't bring more than one item of each type, i.e. you can't take two 
// first items or two second items.

// For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 8, the output should be
// knapsackLight(value1, weight1, value2, weight2, maxW) = 10.

// You can only carry the first item.

// For value1 = 10, weight1 = 5, value2 = 6, weight2 = 4, and maxW = 9, the output should be
// knapsackLight(value1, weight1, value2, weight2, maxW) = 16.

// You're strong enough to take both of the items with you.

// For value1 = 5, weight1 = 3, value2 = 7, weight2 = 4, and maxW = 6, the output should be
// knapsackLight(value1, weight1, value2, weight2, maxW) = 7.

// You can't take both items, but you can take any of them.


int knapsackLight(int value1, int weight1, int value2, int weight2, int maxW) {
    int higher_v = value1 > value2 ? value1: value2;
    int greater_w = higher_v == value1 ? weight1: weight2;
    int lesser_v = higher_v == value1 ? value2: value1;
    int lesser_w = higher_v == value1 ? weight2: weight1;
    int total = 0;
    if (maxW - greater_w >= 0) {
        total += higher_v;
        maxW -=greater_w;
        if (maxW > 0 && maxW - lesser_w >= 0) {
            total += lesser_v;
            return total;
        } else {
            return total;
        }
    } else if (maxW - higher_v < 0 && maxW - lesser_w < 0) {
        return total;
    } else if (maxW - lesser_w >= 0) {
        return total += lesser_v;
    } else {
        return total;
    }
}
