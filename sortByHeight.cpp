//Some people are standing in a row in a park. There are trees between them which cannot be moved. 
//Your task is to rearrange the people by their heights in a non-descending order without moving 
//the trees. People can be very tall!
//For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
//sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

vector<int> sortByHeight(vector<int> a) {

    //we will get the sorted list of heights first without the trees
    //utility variables
    vector <int> heights;
    vector<int> sorted_heights;
    int size = a.size();
    int smallest;
    int smallest_index;
    
    for (int i = 0; i < size; i++) {
        if (a[i] >= 0) {
            heights.push_back(a[i]);
        }
    }
    //now we will go through the elements of a, 
    //if element is not -1, we will push the element
    //into the sorted_heights stack
    
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            sorted_heights.push_back(a[i]);
        } else {
            smallest = heights[0];
            smallest_index = 0;
            for (int j = 1; j < heights.size(); j++){
                if (smallest > heights[j]) {
                    smallest = heights[j];
                    smallest_index = j;
                }
            }
            //we push the smallest value of the current vector
            //into the sorted heights stack
            sorted_heights.push_back(smallest);
            //we delete the value at smallest index
            heights.erase(heights.begin() + smallest_index);
        }
    }
    
    return sorted_heights;
}
