#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;

    
}

int sum = 0;
int counter = 0;

void dfsVisit(vector<vector<int>>& adjList, vector<string>& colors, vector<int>& money, int node) {
    colors[node] = "gray";
    cout << "\n";
    sum += money[node];
    counter++;
    for (int vertex: adjList[node]) {
        if (colors[vertex] == "white") {
            dfsVisit(adjList, colors, money, vertex);
        }
    }
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    vector<int> money(n + 1);
    vector<vector<int>> adjList(vector<vector<int>>(n + 1));
    vector<string> colors(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> money[i];
        colors[i] = "white";
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int prevAvg = 0;

    for (int i = 1; i <= n; i++) {
        if (colors[i] == "white") {
            dfsVisit(adjList, colors, money, i);
            int avg = sum / counter;
            if (i > 1) {
                if (avg != prevAvg) {
                    cout << "Case " << tc << ": No";
                    return;
                }
            }
            if (sum % counter != 0) {
                cout << "Case " << tc << ": No";
                return;
            }
            prevAvg = avg;
            sum = 0;
            counter = 0;
        }
    }
    
    cout << "Case " << tc << ": Yes";

}

signed main()
{
    pre();

    int tc, tt = 1;
    cin >> tt;
    
    for(tc = 1; tc <= tt; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve(tc);
        cout << '\n';
        sum = 0;
        counter = 0;
    }

    return 0;
}