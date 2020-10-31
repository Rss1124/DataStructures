/*二叉树的链式存储*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild; //lchild:左孩子指针；rchild:右孩子指针 
	int ltag,rtag; //ltag:前驱线索；rtag:后继线索 
}BiTNode,*BiTree; //BiTNode 用于强调构建树的节点，BiTree 用于强调整个树 

BiTNode *pre=NULL; //用于前驱指针

void create_tree(BiTree &T); //二叉树的创建（通过递归实现） 
void pr_tra(BiTree &T); //前序遍历
void in_tra(BiTree &T); //中序遍历
void po_tra(BiTree &T); //后序遍历 
void vist(BiTNode *q); //具体的线索化操作 
void pr_thread(BiTree &T); //前序线索化 
void in_thread(BiTree &T); //中序线索化 
void po_thread(BiTree &T); //后序线索化 

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
void vist(BiTNode *q){
	if(q->lchild==NULL){ //如果该结点左子树为空,就让该节点的左孩子指向pre指针 
		q->lchild=pre;
		q->ltag=1; //如果ltag=1则表示该节点没有左孩子是一个前驱指针，否则表示该节点存在左孩子 
	}
	if(pre!=NULL&&pre->rchild==NULL){
		pre->rchild=q;
		pre->rtag=1; 
	} 
	pre=q; //让pre指针指向q结点 
}
void pr_thread(BiTree &T){
	if(T!=NULL){
		vist(T);
		if(T->ltag==0) pr_thread(T->lchild);
		pr_thread(T->rchild); 
	}
} 
void in_thread(BiTree &T){
	if(T!=NULL){
		in_thread(T->lchild);
		vist(T);
		in_thread(T->rchild;)	
	}
} 
void po_thread(BiTree &T){
	if(T!=NULL){
		in_thread(T->lchild);
		in_thread(T->rchild);
		vist(T);
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
	
//	if(pre->rchild==NULL) pre->rtag=1;	//已经到了最后一个节点 
}
