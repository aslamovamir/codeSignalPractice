vector<int> isZigzag(vector<int> numbers) {
    int size_of_vector = numbers.size();
    int index = 0;
    vector<int> zigzag;
    for (int i = 0; i < size_of_vector; i++) {
        if (numbers[i] < numbers[i+1] && numbers[i+1] > numbers[i+2] || numbers[i] > numbers[i+1] && numbers[i+2] > numbers[i+1]) {
            zigzag.push_back(1);
        } else {
            zigzag.push_back(0);
        }
        index++;
        if (index == size_of_vector - 2) {
            break;
        }
    }
    return zigzag;
}
