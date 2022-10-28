#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class BinaryTreeNode {
public:
	int val;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode() {
		this->val = NULL;
		this->Left = NULL;
		this->Right = NULL;
	}
	BinaryTreeNode(int i) {
		this->val = i;
		this->Left = NULL;
		this->Right = NULL;
	}
	~BinaryTreeNode() {

	}
	/*以上为析构函数*/
	bool isLeaf() {
		if (!(this->Left || this->Right))
			return true;
		else
			return false;
	}
};
class BST {
private:
	
public:
	BinaryTreeNode* root;
	BST() {
		this->root = new BinaryTreeNode();
	}
	void Add(BinaryTreeNode* root,int nums) {
		if (root->val == NULL)
		{
			root->val = nums;
			return;
		}
		if (nums <= root->val)
		{
			if (root->Left)
			{
				Add(root->Left,nums);
				return;
			}
			else
			{
				BinaryTreeNode* temp = new BinaryTreeNode(nums);
				root->Left = temp;
				return;
			}
		}
		else
		{
			if (root->Right)
			{
				Add(root->Right,nums);
				return;
			}
			else
			{
				BinaryTreeNode* temp = new BinaryTreeNode(nums);
				root->Right = temp;
				return;
			}
		}
	}

	void InOrderTraverse(BinaryTreeNode* p) {
		if (p == NULL)
			return;
		InOrderTraverse(p->Left);
		printf("%d ", p->val);
		InOrderTraverse(p->Right);
		return;
	}
};
