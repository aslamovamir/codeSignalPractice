//Below we will define an n-interesting polygon. Your task is to find the area of a polygon for a given n
int shapeArea(int n) {
    //assuming n ranges from 1
    int area = 1;
    
    for (int i = 1; i < n; i++) {
        area = area + 4*i;
    }
    
    return area;
}
