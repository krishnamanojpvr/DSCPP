#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BinaryTree
{
private:
    void printLevel(Node *root, int level);
public:
    Node *root;
    BinaryTree()
    {
        root = NULL;
    }
    Node *Create();
    void PreOrderDisplay(Node *root);
    void PostOrderDisplay(Node *root);
    void InOrderDisplay(Node *root);
    void LevelOrderDisplay(Node *root);
    void DisplayRoot();
    int Height(Node *root);
};
Node *BinaryTree::Create()
{
    int data;
    cout << "Enter data (-1 for no data) : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *newnode = new Node(data);
    cout << "Enter LEFT Child of " << data << " :" << endl;
    newnode->left = Create();
    cout << "Enter RIGHT child of " << data << " :" << endl;
    newnode->right = Create();
    return newnode;
}
void BinaryTree::DisplayRoot()
{
    if (root != NULL)
    {
        cout << "**************************" << endl;
        cout << "The root of the tree is : " << root->data << endl;
        cout << "**************************" << endl;
        return;
    }
    cout << "No Tree created, Root node is NULL";
}
int BinaryTree::Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = Height(root->left);
    int rh = Height(root->right);
    if (lh > rh)
    {
        return (lh + 1);
    }
    else
    {
        return (rh + 1);
    }
}
void BinaryTree::PreOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderDisplay(root->left);
    PreOrderDisplay(root->right);
}
void BinaryTree::PostOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderDisplay(root->left);
    PostOrderDisplay(root->right);
    cout << root->data << " ";
}
void BinaryTree::InOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderDisplay(root->left);
    cout << root->data << " ";
    InOrderDisplay(root->right);
}
void BinaryTree::printLevel(Node *root, int level){
    if(root==NULL){
        return;
    }
    else if(level==0){
        cout<<root->data<<" ";
    }
    else if(level>0){
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);
    }
    else{
        return;
    }
}
void BinaryTree::LevelOrderDisplay(Node *root)
{
    int height = Height(root);
    for (int i = 0; i < height; i++)
    {
        printLevel(root,i);
    }
}
int main()
{
    BinaryTree bt;
    bt.root = bt.Create();
    bt.DisplayRoot();

    cout << "PreOrderDisplay: ";
    bt.PreOrderDisplay(bt.root);
    cout << endl;

    cout << "PostOrderDisplay: ";
    bt.PostOrderDisplay(bt.root);
    cout << endl;

    cout << "InOrderDisplay: ";
    bt.InOrderDisplay(bt.root);
    cout << endl;

    cout << "LevelOrderDisplay: ";
    bt.LevelOrderDisplay(bt.root);
    cout << endl;

    return 0;
}