#include <iostream>
#include <vector>
#include <algorithm>

// source: https://medium.com/@interviewprep/ugly-number-dynamic-programming-94520110a084

using namespace std;
using uInt = unsigned int;


uInt findUglyNumber(uInt position)
{
    const uInt NUMBER_TWO = 2;
    const uInt NUMBER_THREE = 3;
    const uInt NUMBER_FIVE = 5;

    
    vector<uInt> numbers;
    numbers.reserve(position);
    // to track last multiplier

    uInt pointerTraker2 = 0, pointerTraker3 = 0, pointerTraker5 = 0;
    uInt next = 0;
    
    numbers.push_back(1);
    for (uInt i = 1; i < position; i++)
    {
        next = std::min({ numbers[pointerTraker2] * NUMBER_TWO, numbers[pointerTraker3] * NUMBER_THREE, numbers[pointerTraker5] * NUMBER_FIVE });
        numbers.push_back(next);
        if (next == numbers[pointerTraker2] * NUMBER_TWO)
            pointerTraker2++;
        if (next == numbers[pointerTraker3] * NUMBER_THREE)
            pointerTraker3++;
        if (next == numbers[pointerTraker5] * NUMBER_FIVE)
            pointerTraker5++;
    }
    return next;

}

int main()
{
    uInt n = 1500;
    cout << "The number in position " << n  << " would be: " << findUglyNumber(n);
    return 0;

}
