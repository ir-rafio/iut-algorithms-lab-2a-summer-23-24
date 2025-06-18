#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;


enum Color {WHITE, GRAY, BLACK};

struct vertex{
    int value = -1;
    int d=0;
    int f=0;
    int pi = -1;
    Color color = WHITE;
};


vector<vector<int>> adjList;
vector<vertex> vertices;

int t = 0;

void initialize(int v){
    adjList.resize(v+1);
    vertices.resize(v+1);
}

void add_edge(int v, int u){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void DFS_visit(int u){
    cout << vertices[u].value << endl;
    t++;
    vertices[u].d = t;
    vertices[u].color = GRAY;

    for(int i:adjList[u]){
        if(vertices[i].color==WHITE){
            vertices[i].pi = u;
            DFS_visit(i);
        }
    }
    vertices[u].color = BLACK;
    t++;
    vertices[u].f = t;

}


void DFS(int v){

    for(int i=0;i<v;i++){
        vertices[i].color = WHITE;
        vertices[i].pi = -1;
    }
    for(int i=0;i<v;i++){
        if(vertices[i].color == WHITE){
            DFS_visit(i);
        }
        
    }
}



void pre()
{
    fastio;

    
}

void solve(int tc)
{
    int n, m, avg=0;

        cin >> n >> m;
        vector<int> arr(n);

        initialize(n);

        for(int i=0;i<n; i++){
            cin >> arr[i];
            avg += arr[i];
            vertices[i].value = (arr[i]);
        }

        //for(int i=0;i<m; i++){
        //    cout << vertices[i].value;
        //}//

      /*  if(avg%n){
            cout << "Case " << i << ": No" << endl;
            continue;
        }*/


        for(int i=0;i<m; i++){
            int u,v;
            cin >> u >> v;
            add_edge(u,v);
        }

        DFS(n);

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
    }

    return 0;
}
