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


vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor) {
    int s=image.size();
    vector<vector<int>> visited(s,vector<int>(s,-1));
    queue<vector<int>> q;
    q.push({sr,sc});
    while(!q.empty()){
        vector<int> z=q.front();
        q.pop();
        int x=z[0],y=z[1];
        visited[x][y]=newColor;
        if(y+1<s) if(visited[x][y+1]!=newColor&&image[x][y+1]!=0) q.push({x,y+1});
        if(x-1>=0) if(visited[x-1][y]!=newColor&&image[x-1][y]!=0) q.push({x-1,y});
        if(y-1>=0) if(visited[x][y-1]!=newColor&&image[x][y-1]!=0) q.push({x,y-1});
        if(x+1<s) if(visited[x+1][y]!=newColor&&image[x+1][y]!=0) q.push({x+1,y});
    }

    for(int i =0;i<s;i++){
        for(int j=0;j<s;j++){
            if(visited[i][j]==newColor){
                image[i][j]=newColor;
            }
        }
    }
    return image;
}


vector<vector<int>> nearest(vector<vector<int>>& grid){
    int row=grid.size();
    int column=grid[0].size();
    vector<vector<int>> visited(row,vector<int>(column,0)),distance(row,vector<int>(column,INT16_MAX));
    queue<vector<int>> q;
    for(int i =0;i<row;i++){
        for(int j=0;j<column;j++){
            if(grid[i][j]==1){
                q.push({i,j,0});
                visited[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        vector<int> z=q.front();
        q.pop();
        int x=z[0],y=z[1],t=z[2];
        visited[x][y]=1;
        if(y+1<column) if(visited[x][y+1]!=1) q.push({x,y+1,t+1});
        if(x-1>=0) if(visited[x-1][y]!=1) q.push({x-1,y,t+1});
        if(y-1>=0) if(visited[x][y-1]!=1) q.push({x,y-1,t+1});
        if(x+1<row) if(visited[x+1][y]!=1) q.push({x+1,y,t+1});
        distance[x][y]=min(t,distance[x][y]);
    }
    return distance;
}

vector<vector<char>> fill(vector<vector<char>>& mat) {
    int row=mat.size();
    int column=mat[0].size();
    vector<vector<int>> visited(row,vector<int>(column,0));
    for(int i =0;i<row;i++){
        if(mat[i][0]=='O'){
                visited[i][0]=1;
            }
    }
    for(int i =0;i<row;i++){
        if(mat[i][column-1]=='O'){
                visited[i][column-1]=1;
            }
    }
    for(int j=0;j<column;j++){
        if(mat[0][j]=='O'){
                visited[0][j]=1;
            }
    }
    for(int j =0;j<column;j++){
        if(mat[row-1][j]=='O'){
                visited[row-1][j]=1;
            }
    }
    for(int i =0;i<row;i++){
        for(int j=0;j<column;j++){
            if(visited[i][j]!=1 && mat[i][j]=='O'){
                mat[i][j]='X';
                visited[i][j]=1;
            }
        }
    }
    return mat;
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    int row=grid.size();
    int column=grid[0].size();
    vector<vector<int>> visited(row,vector<int>(column,0));
    queue<vector<int>> q;
    for(int i =0;i<row;i++){
        for(int j=0;j<column;j++){
            if(grid[i][j]==1){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        vector<int> z=q.front();
        q.pop();
        int x=z[0],y=z[1];
        if((x==0||x==row-1)||(y==0||y==column-1)){
            visited[x][y]=1;
        }
    }
    int sol=0;
    for(int i =0;i<row;i++){
        for(int j=0;j<column;j++){
            if(grid[i][j]==1&&visited[i][j]!=1){
                sol++;
            }
        }
    }
    return sol;
}


void bfsNum(vector<vector<char>> &grid, int x,int y,int row,int column,vector<vector<int>>& visited){
    queue<vector<int>> q;
    q.push({x,y});
    while(!q.empty()){
        vector<int> z=q.front();
        q.pop();
        int x=z[0],y=z[1];
        visited[x][y]=1;
        if(y+1<column) if(visited[x][y+1]!=1&&grid[x][y+1]=='1') q.push({x,y+1});
        if(x-1>=0) if(visited[x-1][y]!=1&&grid[x-1][y]=='1') q.push({x-1,y});
        if(y-1>=0) if(visited[x][y-1]!=1&&grid[x][y-1]=='1') q.push({x,y-1});
        if(x+1<row) if(visited[x+1][y]!=1&&grid[x+1][y]=='1') q.push({x+1,y});
        if(y+1<column && x+1<row) if(visited[x+1][y+1]!=1&&grid[x+1][y+1]=='1') q.push({x+1,y+1});
        if(x-1>=0&&y-1>=0) if(visited[x-1][y-1]!=1&&grid[x-1][y-1]=='1') q.push({x-1,y-1});
        if(y-1>=0&&x+1<row) if(visited[x+1][y-1]!=1&&grid[x+1][y-1]=='1') q.push({x+1,y-1});
        if(x-1>=0&&y+1<column) if(visited[x-1][y+1]!=1&&grid[x-1][y+1]=='1') q.push({x-1,y+1});
    }
}

int numIslands(vector<vector<char>> &grid){
    int sol=0;
    int row=grid.size();
    int column=grid[0].size();
    vector<vector<int>> visited(row,vector<int>(column,0));
    for(int i =0;i<row;i++){
        for(int j=0;j<column;j++){
            if(visited[i][j]!=1&&grid[i][j]=='1'){
                bfsNum(grid,i,j,row,column,visited);
                sol++;
            }
        }
    }
    return sol;
}

void dfsTopo(vector<int>& visited,vector<vector<int>> adj,int v,stack<int>& st){
    visited[v]=1;
    for(auto x:adj[v]){
        if(!visited[x]) dfsTopo(visited,adj,x,st);
    }
    st.push(v);
}

vector<int> topoSort(int V, vector<vector<int>>& adj){
    vector<int> visited(V,0),sol;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(visited[i]!=1){
            dfsTopo(visited,adj,i,st);
        }
    }
    while(!st.empty()){
        sol.push_back(st.top());
        st.pop();
    }
    return sol;
}




bool isCyclicbfs(int N, vector<vector<int>> adj) {
    vector<int> visited(N,0);
    queue<pair<int,int>> q;
    q.push({0,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent= q.front().second;
        q.pop(); 
        
        for(auto x: adj[node]){
            if(!visited[x]){
                q.push({x,node});
                visited[node]=1;
            }else if(parent!=x){
                return true;
            }
        }
    }
    return false;
}


bool dfsCycleUn(vector<int>& visited,vector<vector<int>> adj,int node,int parent){
    visited[node]=1;
    for(auto x:adj[node]){
        if(!visited[x]){
           if( dfsCycleUn(visited,adj,x,node)==true) return true;
        }else if(parent!=x){
            return true;
        }
    }
    return false;
}

bool isCyclicUn(int N, vector<vector<int>> adj) {
    vector<int> visited(N,0);
    for(int i=0;i<N;i++){
        if(visited[i]!=1){
            if(dfsCycleUn(visited,adj,i,-1)==true) return true;
        }
    }
    return false;
}
bool dfsCycledir(vector<int>& visited,vector<vector<int>> adj,int node,vector<int>& vpath){
    visited[node]=1;
    vpath[node]=1;
    for(auto x:adj[node]){
        if(!visited[x]){
           if( dfsCycledir(visited,adj,x,vpath)==true) return true;
        }else if(vpath[x]){
            return true;
        }
    }
    vpath[node]=0;
    return false;
}

bool isCyclicdir(int N, vector<vector<int>> adj) {
    vector<int> visited(N,0);
    vector<int> vpath(N,0);
    for(int i=0;i<N;i++){
        if(visited[i]!=1){
            if(dfsCycledir(visited,adj,i,vpath)==true) return true;
        }
    }
    return false;
}


vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
    vector<vector<int>> adj(N);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> distance(N,INT16_MAX),sol;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        
        distance[node]=min(dist,distance[node]);
        for(auto x: adj[node]){
            if(dist<distance[x]) q.push({x,dist+1});
        }
    }
    return distance;
}

vector < int > shortestPathd(int N, int M, vector < vector < int >> & edges) {
    vector<vector<int>> adj(N);
    for(int i=0;i<M;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> distance(N,INT16_MAX);
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        distance[node]=min(dist,distance[node]);
        for(auto x: adj[node]){
            if(dist<distance[x]){
                for(int i=0;i<edges.size();i++){
                    if(edges[i][0]==node&& edges[i][1]==x){
                        q.push({x,edges[i][2]+dist});
                    }
                }
            };
        }
    }

    for(auto&x: distance){
        if(x==INT16_MAX){
            x=-1;
        }
    }
    return distance;
}

vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> distance(V,INT16_MAX);
    queue<pair<int,int>> q;
    q.push({S,0});
    while(!q.empty()){
        int node=q.front().first;
        int dist=q.front().second;
        q.pop();
        distance[node]=min(dist,distance[node]);
        for(auto x: adj[node]){
            if(dist<distance[x]){
                for(int i=0;i<edges.size();i++){
                    if(edges[i][0]==node&&edges[i][1]==x || edges[i][0]==x&&edges[i][1]==node){
                        q.push({x,edges[i][2]+dist});
                    }
                }
            };
        }
    }

    for(auto&x: distance){
        if(x==INT16_MAX){
            x=-1;
        }
    }
    return distance;
}

int main(){
    int n=3;
    vector<vector<int>> edges = {
    {{0, 1, 1}, {0, 2, 6}, {1, 2, 3}}
    };
    

    for(auto x:dijkstra(n,edges,2)){
        cout<<x<<" ";
    }

    return 0;
}