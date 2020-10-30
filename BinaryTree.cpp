/*二叉树的链式存储__by递归实现
前序遍历
中序遍历
后序遍历*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild; //lchild 左孩子指针,rchild 右孩子指针 
}BiTNode,*BiTree; //BiTNode 用于强调构建树的节点，BiTree 用于强调整个树 

void create_tree(BiTree &T); //二叉树的创建（通过递归实现） 
void pr_tra(BiTree &T); //前序遍历
void in_tra(BiTree &T); //中序遍历
void po_tra(BiTree &T); //后序遍历 

void create_tree(BiTree &T){ 
	char ch;
	cout<<"请输入字符(输入#则表示不输入，赋值为空)"<<endl;
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		cout<<"正在转向左孩子"<<endl;
		create_tree(T->lchild);
		cout<<"正在转向右孩子"<<endl;
		create_tree(T->rchild);
	}
}
void pr_tra(BiTree &T){
	if(T!=NULL){
		cout<<T->data;
		pr_tra(T->lchild);
		pr_tra(T->rchild);			
	} 
}
void in_tra(BiTree &T){
	if(T!=NULL){
		pr_tra(T->lchild);
		cout<<T->data;		
		pr_tra(T->rchild);			
	} 
}
void po_tra(BiTree &T){
	if(T!=NULL){
		pr_tra(T->lchild);
		pr_tra(T->rchild);
		cout<<T->data;					
	} 
}
int main(){
	BiTree T;
	create_tree(T); 
	cout<<"前序遍历(根左右):";
	pr_tra(T);
	cout<<endl;
	cout<<"中序遍历(左根右):";
	in_tra(T);
	cout<<endl;
	cout<<"后序遍历(左右根):"; 
	po_tra(T);
}
