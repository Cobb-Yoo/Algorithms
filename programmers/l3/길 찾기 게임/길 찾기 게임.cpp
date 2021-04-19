#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a,b;

typedef struct Node{
    int idx, x,y;
    struct Node* left;
    struct Node* right;
}Node;

bool cmp(Node a, Node b){
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void insertNode(Node *parent, Node *child){
    if(parent->x > child->x){
        if(parent->left == NULL) parent->left = child;
        else insertNode(parent->left, child);
    }else{
        if(parent->right == NULL) parent->right = child;
        else insertNode(parent->right, child);
    }
}

void preorder(Node *root){
    if(root){
        a.push_back(root->idx);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        b.push_back(root->idx);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int len = nodeinfo.size();
    vector<Node> nodes;
    
    for(int i=0;i<len;i++) nodes.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1]});
    sort(nodes.begin(),nodes.end(),cmp);
    
    Node *root = &nodes[0];
    for(int i=1;i<len;i++) insertNode(root, &nodes[i]);
    
    preorder(root);
    postorder(root);
   
    answer.push_back(a);
    answer.push_back(b);
    
    return answer;
}
