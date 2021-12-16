// We define the weakness of number x as the number of positive integers smaller than x that have more divisors than x.

// It follows that the weaker the number, the greater overall weakness it has. For the given integer n, you need to answer two questions:

// what is the weakness of the weakest numbers in the range [1, n]?
// how many numbers in the range [1, n] have this weakness?
// Return the answer as an array of two elements, where the first element is the answer to the first question, and the second element 
// is the answer to the second question.
// Example

// For n = 9, the output should be
// solution(n) = [2, 2].

// Here are the number of divisors and the specific weakness of each number in range [1, 9]:

// 1: d(1) = 1, weakness(1) = 0;
// 2: d(2) = 2, weakness(2) = 0;
// 3: d(3) = 2, weakness(3) = 0;
// 4: d(4) = 3, weakness(4) = 0;
// 5: d(5) = 2, weakness(5) = 1;
// 6: d(6) = 4, weakness(6) = 0;
// 7: d(7) = 2, weakness(7) = 2;
// 8: d(8) = 4, weakness(8) = 0;
// 9: d(9) = 3, weakness(9) = 2.

vector<int> solution(int n) {

    vector<int> answer;
    map<int, int> divMap;
    map<int, int> weaknessMap;

    int num_divs = 1;
    int divend;
    int weakness_count = 0;
    int largest_weakness = 0;
    for (unsigned int i = 1; i <= n; i++) {
        divend = 1;
        num_divs = 1;
        while (divend != i) {
            if (i%divend == 0) {
                num_divs++;
            }
            divend++;
        }
        divMap[num_divs]++;
        for (map<int, int>::iterator itr = divMap.begin(); itr != divMap.end(); itr++) {
            if (itr->first > num_divs) {
                weakness_count += itr->second;
            }
        }
        largest_weakness = max(largest_weakness, weakness_count);
        weaknessMap[weakness_count]++;
        weakness_count = 0;
    }
    answer.push_back(largest_weakness);
    answer.push_back(weaknessMap[largest_weakness]);
    return answer;
}
