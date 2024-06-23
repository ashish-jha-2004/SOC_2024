#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int c = 2;
    int mx = 2;

    for (int i = 2; i < n; i++) {
        if (a[i] == a[i - 1] + a[i - 2]) {
            c++;
            mx = max(mx, c);
        } else {
            mx = max(mx, 2);
            c = 2;
        }
    }

    if (n == 1)
        cout << 1;
    else
        cout << mx;

    return 0;
}

