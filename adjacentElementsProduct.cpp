int adjacentElementsProduct(vector<int> inputArray) {
    //initialization if the variable, largest product
    int largest = inputArray[0] * inputArray[1];
    int product;
    //we start comparing inside a for loop
    for (int i = 1; i < inputArray.size(); i++) {
        //if the index is next to the last index, we break the loop
        if (i == inputArray.size() - 1) {
            break;
        }
        product = inputArray[i] * inputArray[i+1];
        if (largest < product) {
            largest = product;
        }
    }
    return largest;
}
