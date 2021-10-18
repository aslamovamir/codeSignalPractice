// You are given an array of integers representing coordinates of obstacles situated on a straight line.

// Assume that you are jumping from the point with coordinate 0 to the right. You are allowed only to make jumps of the same length represented by some integer.

// Find the minimal length of the jump enough to avoid all the obstacles.

#include <algorithm>

int avoidObstacles(vector<int> inputArray) {
    
    //first we sort the array
    sort(inputArray.begin(), inputArray.end());
    //we need to jump thrugh the entire array, therefore
    //we need to determine the lenght of the path
    int largest_val = inputArray[0];
    for (int i = 0; i < inputArray.size(); i++) {
        if (largest_val < inputArray[i]) {
            largest_val = inputArray[i];
        }
    }
    //now we go through the path
    //and keep a couter variable as current
    //point in the path and add the min jump
    //value to it each time, if we collide with
    //one of the obstacles, we increment the jump value
    //and restart the loop
    bool collided = false;
    int curr_point = 0;
    int min_jumps = 1; //smallest default
    for (int i = 0; i <= largest_val; i++) {
        collided = false;
        curr_point += min_jumps;
        for (int j = 0; j < inputArray.size(); j++) {
            if (curr_point == inputArray[j]) {
                collided = true;
                break;
            }
        }
        if (collided) {
            min_jumps++;
            curr_point = 0;
            i = -1;
        }
    }
    
