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


int numProvinces(vector<vector<int>> adj) {
    vector<vector<int>> edges;
    for(int i=0;i<adj.size();i++){
        for(int j=i+1;j<adj.size();j++){
            if(adj[i][j]) edges.push_back({i,j});
        }
    }
    return findNumberOfComponent(adj.size(),edges);
}


int orangesRotting(vector<vector<int>> &grid) {
    int s=grid.size(),sol=0;
    vector<vector<int>> visited(s,vector<int>(s,-1));
    queue<vector<int>> q;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(grid[i][j]==2) q.push({i,j,0});
        }
    }
    while(!q.empty()){
        vector<int> z=q.front();
        q.pop();
        int x=z[0],y=z[1],t=z[2];
        visited[x][y]=2;
        if(y+1<s) if(visited[x][y+1]!=2&&grid[x][y+1]!=0) q.push({x,y+1,t+1});
        if(x-1>=0) if(visited[x-1][y]!=2&&grid[x-1][y]!=0) q.push({x-1,y,t+1});
        if(y-1>=0) if(visited[x][y-1]!=2&&grid[x][y-1]!=0) q.push({x,y-1,t+1});
        if(x+1<s) if(visited[x+1][y]!=2&&grid[x+1][y]!=0) q.push({x+1,y,t+1});
        sol=max(sol,t);
    }

    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(grid[i][j]==1&&visited[i][j]!=2) return -1;
        }
    }
    return sol;
}

int main(){
    int v=5;
    vector<vector<int>> adj={{2,1,1},{0,1,0},{1,0,1}};
    cout<<orangesRotting(adj);

    return 0;
}