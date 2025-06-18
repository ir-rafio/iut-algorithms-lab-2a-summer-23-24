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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll noOfOutposts, noOfSignalLinks;

    cin >> noOfOutposts >> noOfSignalLinks;

    vector<vector<pair<ll, ll>>> connections(noOfOutposts);
    vector<ll> distance(noOfOutposts);
    multiset<pair<ll, ll>> st;

    for (ll i = 0; i < noOfOutposts; i++) {
        if (!i) {
            distance[i] = 0;
        } else {
            distance[i] = 1e15;
        }
    }

    st.insert({0, 0});

    for (ll i = 0; i < noOfSignalLinks; i++) {
        ll first, second, cost;

        cin >> first >> second >> cost;
        first--, second--;

        connections[first].push_back({second, cost});
    }

    while (st.size()) {
        pair<ll, ll> top = *(st.begin());
        ll nodeNo = top.second, nodeDistance = top.first;
        st.erase(st.begin());

        for (auto &neighbour : connections[nodeNo]) {
            ll adjNode = neighbour.first, edgeWeight = neighbour.second;

            if (nodeDistance + edgeWeight < distance[adjNode]) {
                auto record = st.find({distance[adjNode], adjNode});

                if (record != st.end()) {
                    st.erase(record);
                }
                distance[adjNode] = nodeDistance + edgeWeight;
                st.insert({distance[adjNode], adjNode});
            }
        }
    }

    printV(distance);

    return 0;
}