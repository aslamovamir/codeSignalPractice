//Ticket numbers usually consist of an even number of digits. A ticket number is considered 
//lucky if the sum of the first half of the digits is equal to the sum of the second half.
//Given a ticket number n, determine if it's lucky or not

bool isLucky(int n) {
    
    bool lucky = false;
    //first we need to determine what how many digits number is n
    int num_digits = 0;
    int copy_n = n;
    while (copy_n != 0) {
        copy_n /= 10;
        num_digits++;
    }
    
    //now we determine the number of digits in each half
    //we can assume the total number of digits is always even
    int digs_half = num_digits / 2;

    //now we will seperate the n into two seperate numbers
    //one will be the divident of some power of 10, while
    //the other the remainder of that
    int half1, half2;
    int power_ten = pow(10, digs_half);
    half1 = n / power_ten;
    half2 = n % power_ten;

    //now we calculate 2 totals of each digits in the 2 halves
    int total1 = 0;
    int total2 = 0;
    while (half1 != 0) {
        total1 += half1 % 10;
        half1 /= 10;
    }

    while (half2 != 0) {
        total2 += half2 % 10;
        half2 /= 10;
    }

    //now we return truu if the two totals are equal, otherwise we return false
    return (total1 == total2) ? true: false;
}
