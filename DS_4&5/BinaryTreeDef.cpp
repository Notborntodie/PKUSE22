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
		if (p->isLeaf())			//ֱ���������в����ж�Ҷ���ĺ�������
			leaf++;
		IOT(p->Left);
		IOT(p->Right);
		return;
	}

	int getheight(BinaryTreeNode* p) {		//���ض������ĸ߶�
		if (!p)
			return 0;
		else
		{
			int L = getheight(p->Left);
			int R = getheight(p->Right);
			return(L > R ? L + 1 : R + 1);
		}
	}

	int getleaf() {	//����Ҷ������
		this->IOT(this->root);
		int L = this->leaf;
		this->leaf = 0;
		return L;
	}

	BinaryTreeNode* CreateTree() {			//ϰ��7�Ķ��������ɷ�ʽ��ABD###CE#G##FH##I##
		char c;								//PPT��72ҳ��0137##8##4##25##6##
		scanf("%c", &c);					//PPT��103ҳ���ṹ����AB#CD##E#F##HIJK###LM##N##O##
		if (((char)c == '#' || (char)c == '\n'))		//ABCD##E##F#GH#I###J#KL##MN#OPRS##T###QU#V###W#XY##Z# �Լ������õĶ�����
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

	void swap(BinaryTreeNode* root) {		//�ݹ齻�����ҽ��
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

	BinaryTreeNode* GetVal(BinaryTreeNode* p, BinaryTreeNode* Get,char c) { //����ĳ���ض�Ԫ�ؽ�㣬�粻�����򷵻� '#'
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
