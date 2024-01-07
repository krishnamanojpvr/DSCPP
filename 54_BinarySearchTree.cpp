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
class BinarySearchTree
{
    void printLevel(Node *curr, int level);

public:
    Node *root;
    BinarySearchTree()
    {
        root = NULL;
    }
    Node *CreateRoot();
    Node *Insert(Node *curr, int val);
    Node *Delete(Node *root, int val);
    void InOrderDisplay(Node *root);
    void PreOrderDisplay(Node *root);
    void PostOrderDisplay(Node *root);
    void LevelOrderDisplay(Node *root);
    int Height(Node *root);
};
void BinarySearchTree::PreOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrderDisplay(root->left);
    PreOrderDisplay(root->right);
}
void BinarySearchTree::PostOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderDisplay(root->left);
    PostOrderDisplay(root->right);
    cout << root->data << " ";
}
void BinarySearchTree::InOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderDisplay(root->left);
    cout << root->data << " ";
    InOrderDisplay(root->right);
}
Node *BinarySearchTree::CreateRoot()
{
    if (this->root == NULL)
    {
        int data;
        cout << "Enter root : ";
        cin >> data;
        Node *newnode = new Node(data);
        this->root = newnode;
        cout << "Root Created Successfully" << endl;
        return this->root;
    }
    cout << "Root already created" << endl;
    return this->root;
}
int BinarySearchTree::Height(Node *curr)
{
    if (curr == NULL)
    {
        return 0;
    }
    int lh = Height(curr->left);
    int rh = Height(curr->right);
    if (lh > rh)
    {
        return lh + 1;
    }
    else
    {
        return rh + 1;
    }
}
void BinarySearchTree::LevelOrderDisplay(Node *root)
{
    int height = Height(root);
    for (int i = 0; i < height; i++)
    {
        printLevel(root, i);
        cout << endl;
    }
}
Node *BinarySearchTree::Insert(Node *curr, int val)
{
    if (curr == NULL)
    {
        Node *newnode = new Node(val);
        return newnode;
    }

    else if (val < curr->data)
    {
        curr->left = Insert(curr->left, val);
    }
    else if (val > curr->data)
    {
        curr->right = Insert(curr->right, val);
    }
    return curr;
}
void BinarySearchTree::printLevel(Node *curr, int level)
{
    if (curr == NULL)
    {
        return;
    }

    else if (level == 0)
    {
        cout << curr->data << " ";
        return;
    }
    else if (level > 0)
    {
        printLevel(curr->left, level - 1);
        printLevel(curr->right, level - 1);
    }
    else
    {
        return;
    }
}
Node *BinarySearchTree::Delete(Node *curr, int val)
{
    // The base case
    if (curr == NULL)
    {
        return curr;
    }
    // Left Child
    if (val < curr->data)
    {
        curr->left = Delete(curr->left, val);
        return curr;
    }
    // Right Child
    else if (val > curr->data)
    {
        curr->right = Delete(curr->right, val);
        return curr;
    }

    // Now, we've reached to the node which we want to delete.
    // Our task is to check whether it has 0 or 1 or 2 children.

    // If it has 0 or 1 child :

    if (curr->left == NULL)
    {
        Node *temp = curr->right;
        delete curr;
        return temp;
    }
    else if (curr->right == NULL)
    {
        Node *temp = curr->left;
        delete curr;
        return temp;
    }

    // Inorder Predecessor : Largest element in Left Subtree of the Current Node
    // Inorder Successor   : Smallest element in Right Subtree of the current Node
    // Or else if the node has 2 children :
    // Find its Inorder Successor
    // Copy the data of inorder successor and delete it
    // Replace the curr node's data with Inorder successor's data (that you've copied earlier)
    else
    {
        Node *tempParent = curr;
        Node *temp = curr->right;
        while (temp->left != NULL)
        {
            tempParent = temp;
            temp = temp->left;
        }
        int data = temp->data;
        delete temp;
        tempParent->left = NULL;
        curr->data = data;
        return curr;
    }
}
int main()
{
    BinarySearchTree bst;
    bst.root = bst.CreateRoot();
    int insertData;
    cout << "Enter the data you want to insert (-1 to not insert) : ";
    cin >> insertData;
    while (insertData != -1)
    {
        bst.Insert(bst.root, insertData);
        cout << "Enter the data you want to insert (-1 to cancel) : ";
        cin >> insertData;
    }

    cout << "Height : " << bst.Height(bst.root) << endl;

    cout << "PreOrderDisplay: ";
    bst.PreOrderDisplay(bst.root);
    cout << endl;

    cout << "PostOrderDisplay: ";
    bst.PostOrderDisplay(bst.root);
    cout << endl;

    cout << "InOrderDisplay: ";
    bst.InOrderDisplay(bst.root);
    cout << endl;

    cout << "LevelOrderDisplay: " << endl;
    bst.LevelOrderDisplay(bst.root);
    cout << endl;

    int deleteData;
    cout << "Enter the data you want to delete (-1 to cancel) : ";
    cin >> deleteData;
    while (deleteData != -1)
    {
        bst.Delete(bst.root, deleteData);
        cout << endl;

        cout << "LevelOrderDisplay: " << endl;
        bst.LevelOrderDisplay(bst.root);
        cout << endl;

        cout << "Enter the data you want to delete (-1 to cancel) : ";
        cin >> deleteData;
    }

    return 0;
}