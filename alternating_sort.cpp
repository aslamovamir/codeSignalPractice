bool alternatingSort(vector<int> a) {
    vector<int> b;
    bool ascending = true;    
    //let's create the b array from the algo first
    int i = 0;
    int j = a.size() - 1;
    while (true){
        b.push_back(a[i]);
        b.push_back(a[j]);
        i++;
        j--;
        if (i -1  == j) {
            break;
        }
    }
    
    for (int u = 0; u < b.size(); u++) {
        cout<<b[u]<<" ";
    }


    for (int k = 0; k < b.size(); k++) {
        if (k == b.size() - 1) {
            break;
        }
        int y = b[k];
        int u = b[k+1];
        if (y > u) {
            ascending = false;
            break;
        }
    }
    
    return ascending;
}
