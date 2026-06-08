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

int diameterOfBinaryTree(TreeNode* root) {
    if(root==nullptr) return true;
    int maxl=maxDepth(root->left);
    int maxr=maxDepth(root->right);
    return maxl+maxr;
}



int maxPath(TreeNode* root,int& maxi) {
     if(root==nullptr){
        return 0;
    }
    int ansl=maxPath(root->left,maxi);
    int ansr=maxPath(root->right,maxi);
    maxi=max(maxi,root->data+ansl+ansr);

    return root->data+max(ansl,ansr);
}

int maxPathSum(TreeNode* root){
    int maxi=INT16_MIN;
    maxPath(root,maxi);
    return maxi;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr||q==nullptr) return true;
    if(p->data!=q->data) return false;
    cout<<p->data<<" "<<q->data<<"\n";
    bool l=isSameTree(p->left,q->left);
    bool r=isSameTree(p->right,q->right);
    return l&&r;
}


vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    deque<TreeNode*> queue;
    if(root!=nullptr) queue.push_back(root);
    int z=0;
    while(!queue.empty()){
        vector<int> lev;
        int lsize=queue.size();
        z++;
        for(int i=0; i<lsize;i++){
            if (z%2==0 ) lev.push_back(queue[i]->data);
            if(z%2!=0)   lev.push_back(queue[lsize-i-1]->data);
            if(queue[i]->right!=nullptr){
                queue.push_back(queue[i]->right);
            }
            if(queue[i]->left!=nullptr){
                queue.push_back(queue[i]->left);
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

vector<int> leafnodes(TreeNode* root,vector<int>& ln){
    if(root==nullptr){
        return ln;
    }
    if(root->left==nullptr&&root->right==nullptr) ln.push_back(root->data);
    leafnodes(root->left,ln);
    leafnodes(root->right,ln);
    return ln;
}

vector <int> boundary(TreeNode* root){
    vector<int>lb,mb,rb;
    vector<int> sol;
    TreeNode* l=root,*r=root,*m=root;
    while(l!=nullptr){
        lb.push_back(l->data);
        l=l->left;
    }
    while(r!=nullptr){
        rb.push_back(r->data);
        r=r->right;
    }
    leafnodes(m,mb);

    for(int i=0;i<lb.size()-1;i++){
        sol.push_back(lb[i]);
    }
    for(int i=0;i<mb.size();i++){
        sol.push_back(mb[i]);
    }
    for(int i=rb.size()-2;i>0;i--){
        sol.push_back(rb[i]);
    }
    return sol;
}

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

int main(){
    vector<int> roots = {1, 2, -1, 4, 9, 6, 5, 3, -1,-1,-1,-1,-1, 7, 8};

    TreeNode* root=buildTree(roots);

    for(auto x : boundary(root)){
        cout<<x<<" ";
    }
    return 0;
}