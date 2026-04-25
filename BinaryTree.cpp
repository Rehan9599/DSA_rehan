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


vector<int> preorder1(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> ans;
    if(root!=nullptr) st.push(root);
    while(!st.empty()){
        auto it =st.top();
        st.pop();
        ans.push_back(it->data);
        if(it->right!=nullptr) st.push(it->right);
        if(it->left!=nullptr) st.push(it->left);
    }
    return ans;
}
vector<int> inorder1(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node=root;
    vector<int> ans;
    if(root!=nullptr) st.push(root);
    while(true){
        if(node!=nullptr){
            st.push(node);
            node=node->left;
        }else{
            if(st.empty()){
                break;
            }
            node=st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return ans;
}

int maxDepth(TreeNode* root) {
    if(root==nullptr){
        return 0;
    }
    int ansl=maxDepth(root->left);
    int ansr=maxDepth(root->right);
    return 1+max(ansl,ansr);
}

bool isBalanced(TreeNode *root){
    if(root==nullptr) return true;
    int maxl=maxDepth(root->left);
    int maxr=maxDepth(root->right);
    if(abs(maxl-maxr)>1) return false;
    bool leftB=isBalanced(root->left);
    if(leftB==false) return false;
    bool rightB=isBalanced(root->right);
    if(rightB==false) return false;
    return true;
}

int main(){
    vector<int> roots = {1, 4, 5, 7,3,2, 6 };

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

    cout<<isBalanced(root[0]);

    return 0;
}