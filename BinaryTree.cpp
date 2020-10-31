/*����������ʽ�洢*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild; //lchild:����ָ�룻rchild:�Һ���ָ�� 
	int ltag,rtag; //ltag:ǰ��������rtag:������� 
}BiTNode,*BiTree; //BiTNode ����ǿ���������Ľڵ㣬BiTree ����ǿ�������� 

BiTNode *pre=NULL; //����ǰ��ָ��

void create_tree(BiTree &T); //�������Ĵ�����ͨ���ݹ�ʵ�֣� 
void pr_tra(BiTree &T); //ǰ�����
void in_tra(BiTree &T); //�������
void po_tra(BiTree &T); //������� 
void vist(BiTNode *q); //��������������� 
void pr_thread(BiTree &T); //ǰ�������� 
void in_thread(BiTree &T); //���������� 
void po_thread(BiTree &T); //���������� 

void create_tree(BiTree &T){ 
	char ch;
	cout<<"�������ַ�(����#���ʾ�����룬��ֵΪ��)"<<endl;
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		cout<<"����ת������"<<endl;
		create_tree(T->lchild);
		cout<<"����ת���Һ���"<<endl;
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
	if(q->lchild==NULL){ //����ý��������Ϊ��,���øýڵ������ָ��preָ�� 
		q->lchild=pre;
		q->ltag=1; //���ltag=1���ʾ�ýڵ�û��������һ��ǰ��ָ�룬�����ʾ�ýڵ�������� 
	}
	if(pre!=NULL&&pre->rchild==NULL){
		pre->rchild=q;
		pre->rtag=1; 
	} 
	pre=q; //��preָ��ָ��q��� 
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
	cout<<"ǰ�����(������):";
	pr_tra(T);
	cout<<endl;
	cout<<"�������(�����):";
	in_tra(T);
	cout<<endl;
	cout<<"�������(���Ҹ�):"; 
	po_tra(T);
	
//	if(pre->rchild==NULL) pre->rtag=1;	//�Ѿ��������һ���ڵ� 
}
