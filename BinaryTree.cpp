/*����������ʽ�洢__by�ݹ�ʵ��
ǰ�����
�������
�������*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild; //lchild ����ָ��,rchild �Һ���ָ�� 
}BiTNode,*BiTree; //BiTNode ����ǿ���������Ľڵ㣬BiTree ����ǿ�������� 

void create_tree(BiTree &T); //�������Ĵ�����ͨ���ݹ�ʵ�֣� 
void pr_tra(BiTree &T); //ǰ�����
void in_tra(BiTree &T); //�������
void po_tra(BiTree &T); //������� 

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
}
