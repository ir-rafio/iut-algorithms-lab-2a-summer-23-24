#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1005;

int money[MAX];
bool visited[MAX];
vector<int> friends[MAX];

int people_count, group_sum;

void dfs(int person, int& count, int& total) {
    visited[person] = true;
    count++;
    total += money[person];

    for (int friend_id : friends[person]) {
        if (!visited[friend_id]) {
            dfs(friend_id, count, total);
        }
    }
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int case_num = 1; case_num <= test_cases; case_num++) {
        int n, m;
        cin >> n >> m;

        int total_money = 0;

        for (int i = 0; i < n; i++) {
            cin >> money[i];
            total_money += money[i];
            friends[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            friends[a].push_back(b);
            friends[b].push_back(a);
        }

        cout << "Case " << case_num << ": ";

        if (total_money % n != 0) {
            cout << "No" << endl;
            continue;
        }

        group_sum = total_money / n;
        memset(visited, false, sizeof(visited));
        bool is_possible = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int group_size = 0, group_total = 0;
                dfs(i, group_size, group_total);

                if (group_total != group_size * group_sum) {
                    is_possible = false;
                    break;
                }
            }
        }

        cout << (is_possible ? "Yes" : "No") << endl;
    }

    return 0;
}

