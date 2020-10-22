/*带头节点的队列__by链表实现*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct LinkNode{ //用于声明队列中的结点 
	int data;
	struct LinkQueue *next;
}LinkNode; 
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

bool init_linkqueue(LinkQueue &Q); //链队列的初始化
bool isempty(LinkQueue &Q); //莲队列判空
bool insert_linknode(LinkQueue &Q,int e); //入队 
bool delete_linknode(LinkQueue &Q,int &e); //出队 

bool init_linkqueue(LinkQueue &Q){
	Q.rear=Q.front=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
	return true;
}
bool isempty(LinkQueue &Q){
	if(Q.front==Q.rear) return true; //队列为空
	else return false; 
} 
bool insert_linknode(LinkQueue &Q,int e){
	LinkNode node = (LinkNode*)malloc(sizeof(LinkNode)); //开辟新结点node用于存放数据e
	node->data=e;
	node->next=NULL;
	Q.rear->next=node;
	Q.rear=node; 
}
bool delete_linknode(LinkQueue &Q,int &e){
	if(Q.front==Q.rear) return false; //此时队列为空，无法出队
	LinkNode *node = Q.front->next; //让指针指向下一个待删除的元素
	e = node->data;
	Q.front->next = node->next;
	if(Q.rear==node){ //删除的是队尾元素
		Q.rear=Q.front; //让队尾指针指向队头指针 
	}
	free(p);
	return true;
}

int main(){
	LinkQueue Q; //声明一个链式队列 
	init_linkqueue(Q); //初始化队列 
} 
 
