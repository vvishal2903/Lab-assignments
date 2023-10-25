#include<iostream>
using namespace std;

typedef struct Node
{
	int key;
	Node *left, *right, *parent;
};

Node *newNode(int item)
{
	Node *temp = new Node;
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->parent = NULL;
	return temp;
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

Node* insert_recur(Node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
	{
		Node *lchild = insert_recur(node->left, key);
		node->left = lchild;
		lchild->parent = node;
	}
	else if (key > node->key)
	{
		Node *rchild = insert_recur(node->right, key);
		node->right = rchild;
		rchild->parent = node;
	}

	return node;
};

Node* insert(Node* root, int key)
{

    Node* z = newNode(key);
    Node* x = root;
    Node* y = NULL;
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        y = z;

    else if (z->key < y->key)
        y->left = z;

    else
        y->right = z;
    return y;
};

int maxValue(Node* root) {
    if (root == NULL) {
        cerr << "Tree is empty" << endl;
        return -1; 
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->key;
}

Node *minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node* Delete(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = Delete(root->left, key);
    else if (key > root->key)
        root->right = Delete(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = Delete(root->right, temp->key);
    }
    return root;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	inorder(root);
	return 0;
}