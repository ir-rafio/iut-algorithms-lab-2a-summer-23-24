#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define result cout << answer << endl
#define all(v) v.begin(), v.end()
#define full(a) a, a + (sizeof(a) / sizeof(a[0]))
#define printV(v) for (const auto &x : v) cout << x << " "; cout << endl

using namespace std;
using ll = long long;

ll noOfPeople, noOfRelations, value = -1;
bool possible = true;
vector<ll> money;
vector<bool> visited;
vector<vector<ll>> relations;

void bfs(const ll &node) {
    if (!possible) {
        return;
    }

    ll sum = 0, size = 1;
    queue<ll> Q;
    Q.push(node);
    visited[node] = true;
    while (!Q.empty()) {
        ll temp = Q.front();
        sum += money[temp];
        Q.pop();
        for (ll i = 0; i < relations[temp].size(); i++) {
            ll nextNode = relations[temp][i];
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                Q.push(nextNode);
                size++;
            }
        }
    }

    if (sum % size) {
        possible = false;
    } else if (value == -1) {
        value = sum / size;
    } else if (value != (sum / size)) {
            possible = false;
    }
}

void solve(const ll &testcase) {
    cin >> noOfPeople >> noOfRelations;

    value = -1;
    possible = true;
    money = vector<ll>(noOfPeople);
    relations = vector<vector<ll>>(noOfPeople);
    visited = vector<bool>(noOfPeople, false);

    for (ll &x : money) {
        cin >> x;
    }
    
    for (ll i = 0; i < noOfRelations; i++) {
        ll first, second;

        cin >> first >> second;
        first--, second--;

        relations[first].push_back(second);
        relations[second].push_back(first);
    }

    for (ll i = 0; i < noOfPeople; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }

    cout << "Case " << testcase << ": ";
    if (possible) {
        yes;
    } else {
        no;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll testcases;
    
    cin >> testcases;
    
    for (ll i = 0; i < testcases; i++) {
        solve(i + 1);
    }

    return 0;
}