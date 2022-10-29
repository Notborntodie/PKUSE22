#include"BinaryTreeDef.cpp"
void Homework_4() {
	printf("第四题：\n前序：tLR  中序：LtR  后序：LRt\n");
	printf("（1）对于该二叉树的每一个结点，其左子树不存在。\n");
	printf("（2）该二叉树只有根结点。\n（3）对于该二叉树的每一个结点，其右子树不存在。");
}

BTree* Homework_5() {
	BTree* T = new BTree();
	printf("\n\n输入字符以创建二叉树，输入#生成空结点。Example：ABD###CE#G##FH##I##\n");
	T->root = T->CreateTree();
	setbuf(stdin, NULL);
	printf("\n该二叉树一共有%d片叶子。\n", T->GetLeaf());
	return T;
}
void Homework_6(BTree* T) {
	printf("\n该二叉树一共有%d层。\n",T->GetHeight(T->root));
}
void Homework_7(BTree* T) {
	printf("\n镜面影射变换算法操作前（中序遍历）：\n");
	T->InOrderTraverse(T->root);
	T->Swap(T->root);
	printf("\n镜面影射变换算法操作后（中序遍历）：\n");
	T->InOrderTraverse(T->root);
}
void Homework_8(BTree* T) {
	char c1, c2;
	printf("\n\n请输入任意两个结点的值：\n");
	c1 = getchar();
	c2 = getchar();
	setbuf(stdin, NULL);
	BinaryTreeNode* p = new BinaryTreeNode('#');
	p = T->GetVal(T->root, p, c1);
	BinaryTreeNode* q = new BinaryTreeNode('#');
	q = T->GetVal(T->root, q, c2);
	BinaryTreeNode* ans = T->LowestAncestor(p, q, T->root);
	if (!ans)
		printf("无公共祖先结点！");
	else
		printf("\n两个结点的公共祖先结点的值为%c",ans->val);
}
bool Homework_14_Recursion(BTree* T,char c) {
	BinaryTreeNode* p = new BinaryTreeNode('#');
	p = T->GetVal(T->root, p, c);
	return(!p->val == '#');
}

int main()
{
	Homework_4();
	BTree* T;
	T = Homework_5();
	Homework_6(T);
	Homework_7(T);
	Homework_8(T);
}

