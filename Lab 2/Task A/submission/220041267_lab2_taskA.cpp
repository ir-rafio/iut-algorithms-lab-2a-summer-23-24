#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> bottles(n);
        for (int i = 0; i < n; ++i) {
            cin >> bottles[i];
        }

      
        sort(bottles.begin(), bottles.end());

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (x >= bottles[i]) {
                x -= bottles[i];
                count++;
            } else {
                break;
            }
        }

        cout << count << endl;
    }

    return 0;
}

