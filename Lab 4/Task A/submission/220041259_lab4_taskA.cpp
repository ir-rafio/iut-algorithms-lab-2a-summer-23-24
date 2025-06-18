#include<bits/stdc++.h>
using namespace std;

const long long INF=1e18;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int outposts,links;
    cin>>outposts>>links;
    vector<vector<pair<int,int>>> network(outposts+1);
    vector<long long> dist(outposts+1,INF);

    for(int i=0;i<links;i++){
        int u,v,w;
        cin>>u>>v>>w;
        network[u].push_back({v,w});
    }

    int source=1;
    dist[source]=0;

    set<pair<long long,int>> st;
    st.insert({0,source});

    while(!st.empty()){
        auto outpost_pair=*st.begin();
        long long d=outpost_pair.first;
        int v=outpost_pair.second;
        st.erase(st.begin());

        if(d>dist[v]){
            continue;
        }

        for(auto child_link:network[v]){
            int child_outpost=child_link.first;
            int weight=child_link.second;

            if(dist[v]+weight<dist[child_outpost]){
                st.erase({dist[child_outpost],child_outpost});
                dist[child_outpost]=dist[v]+weight;
                st.insert({dist[child_outpost],child_outpost});
            }

        }
    }

    for(int i=1;i<=outposts;i++){
        cout<<dist[i]<<(i==outposts?"":" ");
    }

    cout<<endl;
    
    return 0;
}