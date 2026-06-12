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





TreeNode* buildTree(const vector<int>& roots){
    if(roots.empty() || roots[0]==-1) return nullptr;

    TreeNode* root=new TreeNode(roots[0]);
    queue<TreeNode*> q;
    q.push(root);

    size_t i=1;
    while(i<roots.size() && !q.empty()){
        TreeNode* node=q.front();
        q.pop();

        if(i<roots.size() && roots[i]!=-1){
            node->left=new TreeNode(roots[i]);
            q.push(node->left);
        }
        i++;

        if(i<roots.size() && roots[i]!=-1){
            node->right=new TreeNode(roots[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}


TreeNode* searchBST(TreeNode* root, int val,TreeNode* sol) {
    if(root==nullptr) return nullptr;
    if(val==root->data) return root;
    if(val<root->data){
        sol=searchBST(root->left,val,sol);
    }
    if(val>root->data){
        sol=searchBST(root->right,val,sol);
    }
    return sol;
}


vector<int> floorCeilOfBST(TreeNode* root,int key){
    vector<int> sol={-1,999};
    TreeNode* l=root,*r=root;
    while(l!=nullptr){
        if(key>l->data){
            sol[0]=max(sol[0],l->data);
            l=l->right;
        }
        else if(key<l->data){
            sol[1]=min(sol[1],l->data);
            l=l->left;
        }
    }
    if(sol[1]==999) sol[1]=-1;
    return sol;
}

int main(){
    vector<int> roots = {8, 4, 12, 2, 6, 10, 14};
    TreeNode* root=buildTree(roots);
    for(auto x : floorCeilOfBST(root,15)){
        cout<<x<<" ";
    }
    return 0;
}