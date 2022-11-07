#include"BSTDef.cpp"
int main()
{
	BST* T = new BST();
	int nodes;
	cout << "请输入希望生成的结点数目："<<endl;
	cin >> nodes;
	setbuf(stdin, NULL);
	string j;
	for (int i = 0; i < nodes; i++)
	{
		cout << "现在输入第"<<i+1<< "个结点内容："<<endl;
		getline(cin, j);
		T->Add(T->root, j);
	}
	T->InOrderTraverse(T->root);
	BST* p=new BST();
	T->smallcount(T->root, "y");
	cout << endl << T->num << endl;
	//if (p->root)
		
	
}
