#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
struct node {
	int val;
	node* next;
};
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
	node* nums;
	BinaryTreeNode* root;
	BST() {
		this->root = new BinaryTreeNode();
		nums = (node*)malloc(sizeof(node));
	}
	void getnums() {
		printf("input numbers\n");
		int  p,j;
		scanf("%d", &p);
		setbuf(stdin, NULL);
		node* temp = nums;
		for (int i = 0; i < p; i++)
		{
			scanf("%d", &j);
			node* l = (node*)malloc(sizeof(node));
			l->val = j;
			temp->next = l;
			temp = temp->next;
		}
		temp->next = NULL;
		nums = nums->next;
		this->root->val = nums->val;
		nums = nums->next;
	}
	void Create(BinaryTreeNode* root) {
		if (nums->val <= root->val)
		{
			if (root->Left)
			{
				Create(root->Left);
				return;
			}
			else
			{
				BinaryTreeNode* temp = new BinaryTreeNode(nums->val);
				nums = nums->next;
				root->Left = temp;
				return ;
			}
		}
		else
		{
			if (root->Right)
			{
				Create(root->Right);
				return;
			}
			else
			{
				BinaryTreeNode* temp = new BinaryTreeNode(nums->val);
				nums = nums->next;
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
