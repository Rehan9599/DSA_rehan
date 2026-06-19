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

void dfs(vector<int>& visited,vector<vector<int>> adj, vector<int>&sol,int v){
    visited[v]=1;
    sol.push_back(v);
    for(auto x:adj[v]){
        if(!visited[x]) dfs(visited,adj,sol,x);
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(V,0),sol;
    for(int i=0;i<V;i++){
       if(!visited[i]) dfs(visited,adj,sol,i); 
    }
    return sol;
}
    
vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(V,0),sol;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int z=q.front();
        q.pop();
        sol.push_back(z);
        visited[z]=1;
        for(auto x: adj[z]){
            if(!visited[x]) q.push(x);
        }
    }
    return sol;
}

int main(){
    int v=5;
    vector<vector<int>> edges={{0,2},{0,3},{0,1},{2,4}};
    for(auto x:dfsOfGraph(v,edges)){
        cout<<x<<" ";
    }

    return 0;
}