#include <iostream>
#include <queue>
#define max(a,b) (a>b)?a:b
using namespace std;

typedef struct bstnode
{
    int data;
    bstnode *left;
    bstnode *right;
}node;

node* getnode(int data)
{
    node* newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insert(node* root,int data)
{
    if(root==NULL)
    {
        root = getnode(data);
        return root;
    }
    else if(data<=root->data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}

bool Search(node* root,int data)
{
    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(root->data<=data)
        return Search(root->right,data);
    else
        return Search(root->left,data);
}

int findmin(node* root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty";
        return 0;
    }
    while(root->left!=NULL)
        root = root->left;
    return root->data;
}

int findmin_rec(node* root)
{
    node* temp = root;
    if(temp == NULL)
    {
        cout<<"Tree is empty";;
        return 0;
    }
    else if(root->left==NULL)
        return root->data;
    return findmin_rec(root->left);
}

int findmax(node* root)
{
    if(root == NULL)
        return 0;
    while(root->right!=NULL)
        findmax(root->right);
    return root->right;
}

int findmax_rec(node* root)
{
    node *temp = root;
    if(root==NULL)
        return 0;
    else if(root->right==NULL)
        return root->data;
    findmax_rec(root->right);
}
int find_height(node* root)
{
    if(root == NULL)
        return 0;
    return max(find_height(root->left),find_height(root->right))+1;
}

void level_order(node* root)
{
    if(root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
        q.pop();
    }
}

void in_order(node* root)
{
    if(root == NULL)
        return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

void post_order(node *root)
{
    if(root==NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    coout<<root->data<<" ";
}

void pre_order(node* root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}

bool is_bst(node* root,int minvalue,int maxvalue)
{
    if(root == NULL)
        return;
    if(root->data>minvalue && root->data<maxvalue && is_bst(root->left,minvalue,root->data) && is_bst(root->right,root->data,maxvalue))
        return true;
}

int main()
{
    node *root=NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    int num;
    cout<<"Enter a number to be searched:";
    cin>>num;
    if(Search(root,num))
        cout<<"Found";
    else
        cout<<"Not Found";
    cout<<endl;
    return 0;
}
