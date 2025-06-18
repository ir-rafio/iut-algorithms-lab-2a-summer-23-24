#include<iostream>
#include<vector>
#include<numeric>

 using namespace std;
 
 
 class DSU{
 
 
 public: vector<int>parent,size;
 
DSU(int n){
parent.resize(n);
size.assign(n,1);
iota(parent.begin(),parent.end(),0);
}

int find(int a){
if(parent[a]==a) return a;
return parent[a]=find(parent[a]);

}

void unite(int a, int b){
int ra=find(a);
int rb=find(b);
if(ra!=rb){

if(size[ra]<size[rb] swap(ra, rb);
parent[rb]=ra;
size[ra]+=size[rb];
}
  }
  
 };
 

int main(){

int T;
cin >> T;
for(int casenum=1; casenum<=T; ++casenum){
int n,m;
cin >> n >> m;
vector<int> money(n);
 for (int i = 0; i < n; ++i) {
      cin >> money[i];
        }
        
      DSU dsu(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u - 1, v - 1);
        }
        
    
    
     unordered_map<int, pair<long long, int>> components;
        for (int i = 0; i < n; ++i) {
            int root = dsu.find(i);
            components[root].first += money[i];
            components[root].second += 1;
        }  
        
      bool possible = true;
        for (const auto& [root, data] : components) {
            if (data.first % data.second != 0) {
                possible = false;
                break;
            }
        }

        cout << "Case " << caseNum << ": " << (possible ? "Yes" : "No") << "\n";
    }
             
return 0;}
    
}



  
        
   
