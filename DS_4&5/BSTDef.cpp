#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<stack>
using namespace std;

class BinaryTreeNode {
public:
	string val;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode() {
		this->val = "";
		this->Left = NULL;
		this->Right = NULL;
	}
	BinaryTreeNode(string i) {
		this->val = i;
		this->Left = NULL;
		this->Right = NULL;
	}
	bool isLeaf() {
		return !(this->Left || this->Right);
	}
};
class BST {
private:
	int leaf = 0;
public:
	int num = 0;
	BinaryTreeNode* root;
	BST() {
		this->root = new BinaryTreeNode();
	}
	void Add(BinaryTreeNode* root,string input) {		//������������������µĽ�㣬������13��
		if (root->val == "")
		{
			root->val = input;
			return;
		}
		if (input <= root->val)
		{
			if (root->Left)
			{
				Add(root->Left, input);
				return;
			}
			else
			{
				BinaryTreeNode* temp = new BinaryTreeNode(input);
				root->Left = temp;
				return;
			}
		}
		else
		{
			if (root->Right)
			{
				Add(root->Right, input);
				return;
			}
			else
			{
				BinaryTreeNode* temp = new BinaryTreeNode(input);
				root->Right = temp;
				return;
			}
		}
	}

	void InOrderTraverse(BinaryTreeNode* p) {
		if (p == NULL)
			return;
		InOrderTraverse(p->Left);
		if (p->isLeaf())
			leaf++;
		num++;
		cout << p->val+' ';
		InOrderTraverse(p->Right);
		return;
	}

	void DelNode(BinaryTreeNode* p,string token) {			//12��ɾ��BST���
		if (p->val == token) {
			p == NULL;
			return;
		}
		if (p->val > token){
			if (p->Left->val == token)
			{
				BinaryTreeNode* Del = p->Left;
				p->Left = Del->Left;
				p->Right = Del->Right;
				Del = NULL;
			}
			else
				DelNode(p->Left, token);
		}
		else {
			if (p->Right->val == token)
			{
				BinaryTreeNode* Del = p->Right;
				p->Left = Del->Left;
				p->Right = Del->Right;
				Del = NULL;
			}
			else
				DelNode(p->Right, token);
		}
	}
	void smallcount(BinaryTreeNode* p,string k) {		//����һ���жϱȽϹؼ����С����
		if (p == NULL)
			return;
		if (k <= p->val)
			num++;
		smallcount(p->Left, k);
		smallcount(p->Right, k);
		return;
	}

	int smallcount_NonRecursion(BinaryTreeNode* p, string k) {		//��15��ǵݹ�ⷨ������ppt�ᵽ�ı���ģʽȻ���Լ��޸�
		int count = 0;
		using std::stack;
		stack<BinaryTreeNode*> st;
		BinaryTreeNode* t = p;
		while (!st.empty() || t) 
		{
			if (t) 
			{
				st.push(t);
				t = t->Left;
			}
			else 
			{
				t = st.top();
				if (t->val >= k)
					count++;
				else
					break;
				t = t->Right;
				st.pop();
			}	
		}
		return count;
	}
};