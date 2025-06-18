#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, x;
    vector<int> outputs;

    while (t--)
    {
        cin >> n >> x;
        vector<int> inputs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> inputs[i];
        }
        sort(inputs.begin(), inputs.end());

        int sum = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            sum += inputs[i];
            if (sum > x)
            {
                break;
            }
            else
                count++;
        }
        outputs.push_back(count);
    }

    for (int z : outputs)
    {
        cout << z << endl;
    }

    return 0;
}