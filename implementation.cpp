#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MOD 1e9+7
using namespace std;
struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetnewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BstNode* push(BstNode* root, int data)
{
	if (root == NULL)
	{
		root = GetnewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = push(root->left, data);
	}
	else
		root->right = push(root->right, data);
	return root;
}
bool search(BstNode* root, int data)
{
	if (root->data == data)
		return true;
	else if (root == NULL)
		return false;
	else if (root->data < data)
	{
		return	search(root->right, data);
	}
	else
		return	search(root->left, data);

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	BstNode* root = NULL;
	root = push(root, 15);
	root = push(root, 10);
	root = push(root, 20);
	root = push(root, 5);
	root = push(root, 7);
	root = push(root, 22);
	root = push(root, 19);
	root = push(root, 55);
	int x;
	cin >> x;
	if (search(root, 55))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	cout << "yes" << endl;

	return 0;

}
