#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define all(v) v.begin(), v.end()
#define full(a) a, a + (sizeof(a) / sizeof(a[0]))
#define printV(v) for (const auto &x : v) cout << x << " "; cout << endl

using namespace std;
using ll = long long;

vector<bool> visited;
vector<vector<ll>> sameCountry;

ll bfs(const ll &node) {
    ll size = 1;
    queue<ll> Q;
    Q.push(node);
    visited[node] = true;

    while (!Q.empty()) {
        ll temp = Q.front();
        Q.pop();
        for (ll i = 0; i < sameCountry[temp].size(); i++) {
            ll nextNode = sameCountry[temp][i];
            if (!visited[nextNode]) {
                visited[nextNode] = true;
                Q.push(nextNode);
                size++;
            }
        }
    }

    return size;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll noOfAstronauts, noOfPairs, answer = 0, sum = 0, prefixSum = 0;

    cin >> noOfAstronauts >> noOfPairs;

    vector<ll> groupSizes;
    visited = vector<bool>(noOfAstronauts, false);
    sameCountry = vector<vector<ll>>(noOfAstronauts);

    for (ll i = 0; i < noOfPairs; i++) {
        ll first, second;

        cin >> first >> second;

        sameCountry[first].push_back(second);
        sameCountry[second].push_back(first);
    }

    for (ll i = 0; i < noOfAstronauts; i++) {
        if (!visited[i]) {
            ll groupSize = bfs(i);
            groupSizes.push_back(groupSize);
        }
    }

    for (const ll &grpSz : groupSizes) {
        sum += grpSz;
    }
    for (const ll &grpSz : groupSizes) {
        answer += grpSz * (sum - prefixSum - grpSz);
        prefixSum += grpSz;
    }

    result;

    return 0;
}