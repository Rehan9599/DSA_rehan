#include <iostream>
#include <utility>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <climits>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// vector<vector<int>> createAdjL(int v,vector<vector<int>> edges){

// }

void traverse(vector<int>& visited, vector<vector<int>>& adj, int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) traverse(visited, adj, v);
    }
}

int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    int ans=0;
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(V,0);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            ans++;
            traverse(visited,adj,i);
        }
    }
    return ans;
}

vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
    vector<int> sol;
    vector<int> visited(V,0);
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            traverse(visited,adj,i);
        }
    }
}
    
vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
    
}

int main(){
    int v=7;
    vector<vector<int>> edges={{0,1},{1,2},{2,3},{4,5}};
    cout<<findNumberOfComponent(v,edges);

    return 0;
}