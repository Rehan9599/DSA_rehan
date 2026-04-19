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

    

    stack<pair<TreeNode*, int>> trav;

    trav.push({root,1});

    if(root==nullptr) return res;

    while(!trav.empty()){
        auto it=trav.top();
        trav.pop();


        if(it.second==1){
            preOrder.push_back(it.first->data);
            it.second++;
            trav.push(it);

            if(it.first->left!=nullptr){
                trav.push({it.first->left, 1});
            }
        }

        else if(it.second==2){
            inOrder.push_back(it.first->data);
            it.second++;

            trav.push(it);

            if(it.first->right!=nullptr){
                trav.push({it.first->right, 1});
            }

        }

        else{
            posOrder.push_back(it.first->data);
        }
    }
    res.push_back(inOrder);
    res.push_back(preOrder);
    res.push_back(posOrder);

    return res;


}


vector<int> preorder(TreeNode* root,vector<int>& pre){
    if(root==nullptr) return pre;

    pre.push_back(root->data);

    preorder(root->left,pre);

    preorder(root->right,pre);

    return pre;
}


vector<int> inorder(TreeNode* root,vector<int>& in){
    if(root==nullptr) return in;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

    return in;
}

vector<int> postorder(TreeNode* root,vector<int>& pos){
   if(root==nullptr) return pos;

    postorder(root->left,pos);
    
    postorder(root->right,pos);
    pos.push_back(root->data);

    return pos;
}

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    deque<TreeNode*> queue;
    if(root!=nullptr) queue.push_back(root);
    while(!queue.empty()){
        vector<int> lev;
        int lsize=queue.size();
        for(int i=0; i<lsize;i++){
            lev.push_back(queue[i]->data);
            if(queue[i]->left!=nullptr){
                queue.push_back(queue[i]->left);
            }
            if(queue[i]->right!=nullptr){
                queue.push_back(queue[i]->right);
            }
        }
        int c=0;
        while(c<lsize){
            queue.pop_front();
            c++;
        }
        res.push_back(lev);
    }
    return res;
}


int main(){
    vector<int> roots = {1, 4, 5, 7,-1,-1, 6 };

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

    vector<int> pre;

    for(auto x: levelOrder(root[0])){
        for(auto y :x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    return 0;
}