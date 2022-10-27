#include"BSTDef.cpp"
int main()
{
	BST* T = new BST();
	BinaryTreeNode* M;
	T->getnums();
	while (T->nums)
		T->Create(T->root);
	T->InOrderTraverse(T->root);
}
