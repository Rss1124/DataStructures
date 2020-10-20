#include<bits/stdc++.h>
using namespace std;

bool init_DLinkList(DLinkList &L); //��ʼ��˫���� 
bool insert_nextNode(DNode *p,DNode *s); //��p���֮�����s���;ע��:(���ͨ��λ����������һ���ڵ�,��ô������ͨ��λ���ҵ��ýڵ�,Ȼ����ô˺���ֱ�ӽ��к�����,�����ǰ��Ļ�,����ͨ��λ���ҵ�����ǰһ���ڵ�,Ȼ����øú���) 
bool delete_nextNode(DNode *p); //ɾ��p���ĺ�̽�� 
bool destory_DLinkList(DLinkList &L); //�ݻ�˫���� 

typedef struct DNode{
	int data;
	struct DNode *prior,*next; //ע�⣺���struct����û�и��ṹ�����(struct)������DNode����ô���лᱨ��;ָ��prior������ָ��ǰһ������ 
}DNode,*DLinkList;

bool init_DLinkList(DLinkList &L){
	L=(DNode *)malloc(sizeof(DNode)); //����ͷ��� 
	if(L==NULL) return false; //ͷ������ʧ��
	L->prior=NULL; //ͷ����ǰ��ָ����Զָ��NULL 
	L->next=NULL; //���ָ����ʱû�ж�����ָ
	return true; 
}

bool insert_nextNode(DNode *p,DNode *s){
	if(p==NULL||s==NULL) return false;
	s->next=p->next; //s�ĺ��ָ��p�ĺ�� 
	if(p->next!=NULL) 	p->next->prior=s; //���p�ĺ�̽�㲻Ϊ�գ���ôp�ĺ�̵�ǰ����ָ��s������ֱ����p�ĺ��ָ��s��s��ǰ��ָ��p 
	s->prior=p; 
	p->next=s;
	return true;
} 

bool delete_nextNode(DNode *p){
	if(p==NULL) return false;
	DNode *s=p->next; //�ҵ�p�ĺ�̽��
	if(s==NULL) return false; //pû�к�� 
	p->next=s->next;
	if(s->next!=NULL) s->next->prior=p;
	free(s) 
	return true;
}

bool destory_DLinkList(DLinkList &L){ //�˴���L�Ŀ��Ա�ʾΪͷ��� 
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
