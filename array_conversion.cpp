// Given an array of 2k integers (for some integer k), perform the following operations until the array contains only one element:

// On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
// On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.
// After the algorithm has finished, there will be a single element left in the array. Return that element.

// Example

// For inputArray = [1, 2, 3, 4, 5, 6, 7, 8], the output should be
// solution(inputArray) = 186.

// We have [1, 2, 3, 4, 5, 6, 7, 8] -> [3, 7, 11, 15] -> [21, 165] -> [186], so the answer is 186.

//helper function to sum each pair of the array
vector<int> sum(vector<int> inputArray) {
    vector<int> sum_arr;
    for (int i = 1; i < inputArray.size(); i+=2) {
        sum_arr.push_back(inputArray[i] + inputArray[i-1]);    
    }
    return sum_arr;
}

//helper function to multiply each pair of the array
vector<int> product(vector<int> inputArray) {
    vector<int> product_arr;
    for (int i = 1; i < inputArray.size(); i+=2) {
        product_arr.push_back(inputArray[i] * inputArray[i-1]);
    }
    return product_arr;
}

//main function
int solution(vector<int> inputArray) {
    if(inputArray.size() == 1) {
        return inputArray[0];
    }
    int answer;
    int iterator = 1;
    while(true) {
        //if even, product pair
        if (iterator%2 == 0) {
            inputArray = product(inputArray);
            //check if the lenght of the array is 1
            if(inputArray.size() == 1) {
                return inputArray[0];
            }
        } else { //else if odd, sum pair
            inputArray = sum(inputArray);
            //check if the lenght of the array is 1
            if(inputArray.size() == 1) {
                return inputArray[0];
            }
        }
        iterator++;
    }
}
