#include <iostream>
using namespace std;

// Function to compute the sum of digits of a number
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int findKthPerfectNumber(int k) {
    int count = 0;
    int number = 1;
    
    // Loop until we find the k-th number with digit sum 10
    while (true) {
        if (digitSum(number) == 10) {
            count++;
            if (count == k) {
                return number;
            }
        }
        number++;
    }
}

int main() {
    int k;
    cin >> k;
    
    int result = findKthPerfectNumber(k);
    cout << result;
    
    return 0;
}

