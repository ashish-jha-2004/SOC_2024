#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;

    double a = sqrt(B * C / A);
    double b = sqrt(A * C / B);
    double c = sqrt(A * B / C);

    int sum_of_edges = 4 * (a + b + c);

    cout << sum_of_edges << endl;

    return 0;
}

