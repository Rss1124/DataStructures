/*��ͷ�ڵ�Ķ���__by����ʵ��*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct LinkNode{ //�������������еĽ�� 
	int data;
	struct LinkQueue *next;
}LinkNode; 
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

bool init_linkqueue(LinkQueue &Q); //�����еĳ�ʼ��
bool isempty(LinkQueue &Q); //�������п�
bool insert_linknode(LinkQueue &Q,int e); //��� 
bool delete_linknode(LinkQueue &Q,int &e); //���� 

bool init_linkqueue(LinkQueue &Q){
	Q.rear=Q.front=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
	return true;
}
bool isempty(LinkQueue &Q){
	if(Q.front==Q.rear) return true; //����Ϊ��
	else return false; 
} 
bool insert_linknode(LinkQueue &Q,int e){
	LinkNode node = (LinkNode*)malloc(sizeof(LinkNode)); //�����½��node���ڴ������e
	node->data=e;
	node->next=NULL;
	Q.rear->next=node;
	Q.rear=node; 
}
bool delete_linknode(LinkQueue &Q,int &e){
	if(Q.front==Q.rear) return false; //��ʱ����Ϊ�գ��޷�����
	LinkNode *node = Q.front->next; //��ָ��ָ����һ����ɾ����Ԫ��
	e = node->data;
	Q.front->next = node->next;
	if(Q.rear==node){ //ɾ�����Ƕ�βԪ��
		Q.rear=Q.front; //�ö�βָ��ָ���ͷָ�� 
	}
	free(p);
	return true;
}

int main(){
	LinkQueue Q; //����һ����ʽ���� 
	init_linkqueue(Q); //��ʼ������ 
} 
 
