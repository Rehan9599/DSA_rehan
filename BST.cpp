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

void display(TreeNode* root){
    if(root==nullptr){
        return;
    }
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* in=root;
    while(in != nullptr){
        if(in->data<val){
            if(in->right==nullptr){
                break;
            }else{
                in=in->right;
            }
        }else if(in->data>val){
            if(in->left==nullptr){
                break;
            }else{
                in=in->left;
            }
        }
        if(in->left==nullptr&& in->right==nullptr) break;
    }
    TreeNode* d=new TreeNode(val);
    if(in->data>val){
        in->left=d;
    }else if(in->data<val){
        in->right=d;
    }

    return root;
}
void knum(TreeNode* root, int k,vector<int>&arr){
    if(root==nullptr){
        return;
    }
    knum(root->left,k,arr);
    arr.push_back(root->data);
    knum(root->right,k,arr);
}

vector<int> kLargesSmall(TreeNode* root,int k){
    vector<int> arr;
    knum(root,3,arr);
    vector<int> sol ={arr[k-1],arr[arr.size()-k]};
    return sol;
}

vector<int> inorder(TreeNode* root,vector<int>& in){
    if(root==nullptr) return in;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);

    return in;
}

bool isBST(TreeNode* root){
    vector<int> in;
    inorder(root,in);
    for(int i=0;i<in.size()-1;i++){
        if(in[i]>in[i+1]){
            return false;
        }
    }
    return true;
}

TreeNode* lca(TreeNode* root, int p, int q){
    vector<int> in;
    TreeNode* lr=root;
    inorder(root,in);
    int k,l;
    for(int i=0;i<in.size();i++){
        if(in[i]==p) k=i;
        if(in[i]==q) l=i;
    }
    int z=in[(k+l)%2==0?(k+l)/2:((k+l)/2)+1];
    while(lr!=nullptr){
        if(z<lr->data){
            lr=lr->left;
        }else if(z>lr->data){
            lr=lr->right;
        }else{
            break;
        }
    }
    return lr;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> inor=preorder;
    sort(inor.begin(),inor.end());
    
}

int main(){
    vector<int> roots = {5, 3, 6, 4, 2, -1, 7};
    TreeNode* root=buildTree(roots);
    cout<<lca(root,3,6)->data;
    return 0;
}