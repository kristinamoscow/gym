/*
	Given a binary tree,
	determine if it is a valid binary search tree (BST).

*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), 
	left(nullptr), right(nullptr){}
};

TreeNode* create_tree(TreeNode* root,
 const vector<int>& gr, int i, int n){
	if(i < n) {
		TreeNode* p = new TreeNode(gr[i]);
		root = p;
		root->left = create_tree(
			root->left, gr, 2 * i + 1, n);
		root->right = create_tree(
			root->right, gr, 2 * i + 2, n);
	}
	
	return root;
}

void print_tree(TreeNode* root){ 
    if (root != NULL){ 
		cout << root->val <<" "; 
        print_tree(root->left); 
        print_tree(root->right); 
    } 
} 

void delete_tree(TreeNode* node){
	if(node == nullptr) return;
	
	delete_tree(node->left);
	delete_tree(node->right);
	
	delete(node);
}

bool isValidBST(TreeNode* root){
	if(root == nullptr){
		 return true;
	}
	if(root->left != nullptr){
		if(root->left->val != 0 &&
			root->left->val > root->val){
			return false;
		}
	}
	if(root->right != nullptr){
	 if(root->right->val != 0 && 
		root->right->val < root->val){
			return false;
		}
	}
	return isValidBST(root->left) &&
		isValidBST(root->right);
}

int main(){
	vector<int> grv = {8, 5, 10, 4, 6, 9, 0};
	vector<int> grn = {5, 1, 4, 0, 0, 6, 9};

	TreeNode* tree;
	
	tree = create_tree(tree, grv, 0, grv.size());
	print_tree(tree);
	cout << boolalpha << isValidBST(tree) << endl;
	delete_tree(tree);

	tree = create_tree(tree, grn, 0, grn.size());
	print_tree(tree);
	cout << boolalpha << isValidBST(tree) << endl;
	delete_tree(tree);
	tree = nullptr;

	return 0;
}