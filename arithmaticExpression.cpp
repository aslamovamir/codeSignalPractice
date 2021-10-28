// Consider an arithmetic expression of the form a#b=c. Check whether it is possible to 
// replace # with one of the four signs: +, -, * or / to obtain a correct expression.

bool arithmeticExpression(int a, int b, int c) {
    if (a + b == c) {
        cout<<"+"<<endl;
        return true;
    } else if (a - b == c) {
        cout<<"-"<<endl;
        return true;
    } else if (a * b == c) {
        cout<<"*"<<endl;
        return true;
    } else if (a / b == c && a % b == 0) {
        cout<<"/"<<endl;
        return true;
    } else {
        return false;
    }
}
