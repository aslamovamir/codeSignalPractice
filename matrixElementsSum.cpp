//Given matrix, a rectangular matrix of integers, where each value represents the cost of the room,
//your task is to return the total sum of all rooms that are suitable for the CodeBots (ie: add up
//all the values that don't appear below a 0).

int matrixElementsSum(vector<vector<int> > matrix) {
    int sum = 0;
    //we will use a stack to store indeces that we will ignore in calculations
    //these indeces will in dicate 0 was met at those indeces in previous iterations
    vector <int>stack;
    bool under_zero = false;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            under_zero = false;
            for (int k = 0; k < stack.size(); k++) {
                if (j == stack[k]) {
                    under_zero = true;
                    break;
                }
            }
            if (under_zero) {
                continue;
            }
            if (matrix[i][j] == 0) {
                stack.push_back(j);
                continue;
            }
            sum += matrix[i][j];
        }
    }

    for (int i = 0; i < stack.size(); i++) {
        cout<<stack[i]<<" ";
    }
    return sum;
}
