#include<bits/stdc++.h>
using namespace std;

bool init_DLinkList(DLinkList &L); //初始化双链表 
bool insert_nextNode(DNode *p,DNode *s); //在p结点之后插入s结点;注意:(如果通过位序来向后插入一个节点,那么可以先通过位序找到该节点,然后调用此函数直接进行后插操作,如果是前插的话,就先通过位序找到他的前一个节点,然后调用该函数) 
bool delete_nextNode(DNode *p); //删除p结点的后继结点 
bool destory_DLinkList(DLinkList &L); //摧毁双链表 

typedef struct DNode{
	int data;
	struct DNode *prior,*next; //注意：如果struct后面没有跟结构体变量(struct)的名字DNode，那么此行会报错;指针prior适用于指向前一个结点的 
}DNode,*DLinkList;

bool init_DLinkList(DLinkList &L){
	L=(DNode *)malloc(sizeof(DNode)); //分配头结点 
	if(L==NULL) return false; //头结点分配失败
	L->prior=NULL; //头结点的前驱指针永远指向NULL 
	L->next=NULL; //后继指针暂时没有东西可指
	return true; 
}

bool insert_nextNode(DNode *p,DNode *s){
	if(p==NULL||s==NULL) return false;
	s->next=p->next; //s的后继指向p的后继 
	if(p->next!=NULL) 	p->next->prior=s; //如果p的后继结点不为空，那么p的后继的前驱将指向s，否则直接让p的后继指向s，s的前驱指向p 
	s->prior=p; 
	p->next=s;
	return true;
} 

bool delete_nextNode(DNode *p){
	if(p==NULL) return false;
	DNode *s=p->next; //找到p的后继结点
	if(s==NULL) return false; //p没有后继 
	p->next=s->next;
	if(s->next!=NULL) s->next->prior=p;
	free(s) 
	return true;
}

bool destory_DLinkList(DLinkList &L){ //此处的L的可以表示为头结点 
	while(L->next!=NULL){
		delete_nextNode(L);
	}
	free(L);
	L=NULL;
	return true;	
}

int main(){
	DLinkList L;
	init_DLinkList(L);
} 
