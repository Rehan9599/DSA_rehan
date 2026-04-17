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


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<vector<int>> treeTraversal(TreeNode* root){
    vector<int> preOrder;
    vector<int> posOrder;
    vector<int> inOrder;
    vector<vector<int>> res;

    


}

int main(){
    vector<int> roots = {1, 3, 4, 5, 2, 7, 6 };

    vector<TreeNode*> root(roots.size(),nullptr);

    for(int i=0;i<roots.size();i++){
        root[i]=new TreeNode(roots[i]);
    }

    for(int i=0;i<roots.size();i++){
        int l=2*i+1;
        int r= 2*i+2;

        if(r<roots.size()) root[i]->right=root[r];
        if(l<roots.size()) root[i]->left=root[l];
    }

    for(auto x: treeTraversal(root[0])){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    return 0;
}