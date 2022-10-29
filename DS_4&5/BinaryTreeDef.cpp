#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
class BinaryTreeNode {
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
		if (!(this->Left || this->Right))
			return true;
		else
			return false;
	}
};


class BTree {
private:
	int leaf = 0;
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
		if (p->isLeaf())			//直接在周游中插入判断叶结点的函数即可
			leaf++;
		IOT(p->Left);
		IOT(p->Right);
		return;
	}

	int getheight(BinaryTreeNode* p) {		//返回二叉树的高度
		if (!p)
			return 0;
		else
		{
			int L = getheight(p->Left);
			int R = getheight(p->Right);
			return(L > R ? L + 1 : R + 1);
		}
	}

	int getleaf() {	//返回叶结点个数
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

	void swap(BinaryTreeNode* root) {		//递归交换左右结点
		if (root == NULL)
			return;
		BinaryTreeNode* temp;
		temp = root->Left;
		root->Left = root->Right;
		root->Right= temp;
		swap(root->Left);
		swap(root->Right);
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
};
