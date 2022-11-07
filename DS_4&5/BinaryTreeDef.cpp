#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<malloc.h>
#include<stack>
using namespace::std;

class BinaryTreeNode {
	friend class BTree;
public:
	char val;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode() {
	}
	BinaryTreeNode(char i) {
		this->val = i;
	}
	bool isLeaf() {
		return(!(this->Left || this->Right));
	}
};


class BTree {
private:
	int leaf = 0;
	char cmp=(char)0;
public:
	BinaryTreeNode* root;
	BTree() {
		this->root = new BinaryTreeNode();
	}
	void InOrderTraverse(BinaryTreeNode* p) {
		if (p == NULL)
			return;
		InOrderTraverse(p->Left);
		printf("%c ", p->val);
		InOrderTraverse(p->Right);
		return;
	}

	void IOT(BinaryTreeNode* p) {
		if (p == NULL)
			return;
		IOT(p->Left);
		if (this->leaf)
			leaf++;
		IOT(p->Right);
		return;
	}

	int GetHeight(BinaryTreeNode* p) {		//返回二叉树的高度
		if (!p)
			return 0;
		else
		{
			int L = GetHeight(p->Left);
			int R = GetHeight(p->Right);
			return(L > R ? L + 1 : R + 1);
		}
	}

	int GetLeaf() {	//返回叶结点个数
		this->IOT(this->root);
		int L = this->leaf;
		this->leaf = 0;
		return L;
	}

	BinaryTreeNode* CreateTree() {			//习题7的二叉树生成方式：ABD###CE#G##FH##I##
		char c;								//PPT第72页：0137##8##4##25##6##
		scanf("%c", &c);					//PPT第103页（结构）：AB#CD##E#F##HIJK###LM##N##O##
		if (((char)c == '#' || (char)c == '\n'))		//ABCD##E##F#GH#I###J#KL##MN#OPRS##T###QU#V###W#XY##Z# 自己测试用的二叉树
			return NULL;
		else 
		{
			BinaryTreeNode* T = new BinaryTreeNode(c);
			T->val = c;
			T->Left=CreateTree();
			T->Right=CreateTree();
			return T;
		}
	}

	void Swap(BinaryTreeNode* root) {		//递归交换左右结点
		if (root == NULL)
			return;
		BinaryTreeNode* temp;
		temp = root->Left;
		root->Left = root->Right;
		root->Right= temp;
		Swap(root->Left);
		Swap(root->Right);
		return;
	}

	BinaryTreeNode* GetVal(BinaryTreeNode* p, BinaryTreeNode* Get,char c) { //返回某个特定元素结点，如不存在则返回 '#'
		if (p == NULL||Get->val==c)
			return Get;
		if (p->val == c)
			Get->val = c;
		GetVal(p->Left,Get,c);
		GetVal(p->Right,Get,c);
		return Get;
	}
	BinaryTreeNode* LowestAncestor(BinaryTreeNode* p, BinaryTreeNode* q, BinaryTreeNode* root) {
		if (p->val == '#' || q->val == '#')
			return NULL;
		if (!root || p->val == root->val|| q->val == root->val)
			return root;
		BinaryTreeNode* Left = LowestAncestor(p, q, root->Left);
		BinaryTreeNode* Right = LowestAncestor(p, q, root->Right);
		if (Left && Right)
			return root;
		return(!Right ? Left : Right);
	}
	bool isBST(BinaryTreeNode* p) {//判断其是否为BST
		if (!p)
			return true;
		if (p->Left && p->Left->val > p->val)
			return false;
		if (p->Right && p->Right->val < p->val)
			return false;
		return isBST(p->Left) && isBST(p->Right);
	}
	bool Search_NonRecursion(BinaryTreeNode* root, char c) {		//14题非递归解法
		using std::stack;
		stack<BinaryTreeNode*> st;
		BinaryTreeNode* p = root;
		while (!st.empty() || p) {
			if (p)
			{
				st.push(p);
				p = p->Left;
			}
			else {
				p = st.top();
				if (p->val == c)
					return true;
				p = p->Right;
				st.pop();
			}
		}
		return false;
	}
};
