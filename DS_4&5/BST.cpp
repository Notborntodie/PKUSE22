#include"BSTDef.cpp"
int main()
{
	BST* T = new BST();
	int nums;
	printf("input numbers\n");
	scanf("%d", &nums);
	setbuf(stdin, NULL);
	int j;
	for (int i = 0; i < nums; i++)
	{
		scanf("%d", &j);
		T->Add(T->root, j);
	}
	T->InOrderTraverse(T->root);
}
