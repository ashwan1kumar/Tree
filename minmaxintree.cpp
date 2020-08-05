#include<bits/stdc++.h>
using namespace std;

struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};

BSTNode* GetNode(int data)
{
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
BSTNode* push(BSTNode* root, int data)
{
	if (root == nullptr)
	{
		root = GetNode(data);
	}
	else if (data < root->data)
	{
		root->left = push(root->left, data);
	}
	else
	{
		root->right = push(root->right, data);
	}
	return root;
}
bool Search(BSTNode* root, int data)
{
	if (root == nullptr)
		return false;
	else if (root->data == data)
		return true;
	else if (data < root->data)
	{
		return Search(root->left, data);
	}
	else
		return Search(root->right, data);
}
void FindMaxandMin(BSTNode* root)
{
	int max = -1;
	int min = INT_MAX;
	BSTNode* current = root;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	min = current->data;
	current = root;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	max = current->data;
	cout << "Min and Max are respectively: " << min << " " << max << endl;
}
int height(BSTNode* root)
{
	if (root == nullptr)
		return -1;
	return max(height(root->left), height(root->right)) + 1;
}
int main()
{
	BSTNode* root = nullptr;
	root = push(root, 10);
	root = push(root, 5);
	root = push(root, 6);
	root = push(root, 2);
	root = push(root, 9);
	root = push(root, 23);
	root = push(root, 22);
	root = push(root, 100);
	FindMaxandMin(root);
	cout << height(root) << endl;;
}