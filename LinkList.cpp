/*����ͷ���ĵ�����
���ԣ�ָ��ֻ��һ������������в��ң������ڶ�ǰһ���ڵ���в���ʱ��Ҫ��ͷ��㿪ʼ����
����ʱ�临�ӶȾͻ�ܸ�O(n)����ȻҲ���Կ���һ����ʱ�Ľ�㣬��"͵������"�ķ��������в������Ӷ�ʹʱ�临�ӶȽ�ΪO(1) 
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct LNode{ //���嵥���������� 
	int data; //����ŵ����� 
	struct LNode *next; //ָ��ָ����һ����� 	
}LNode, *LinkList; //���ֱ�ʾ���ķ���,��������һ����,���Ǿ���д�����ʱ����Ҫ��ʾ�ĺ��岻һ��,LNode*(ǿ�����),LinkList(ǿ��������)

bool init_List(LinkList &L); //��ʼ��һ����ͷ�ڵ�ĵ�����
bool empty(LinkList L); //ͨ���ж�ͷ����next�Ƿ�Ϊ����ȷ���������Ƿ�Ϊ�� 
bool insert_before_Node(LinkList &L,int i,int e); //��ǰ�巨��ֻ�������λ�������ڸý���ǰ�����һ���½��,ƽ��ʱ�临�Ӷ�:O(n) 
bool insert_front_Node(LNode *p,int e); //��ǰ�巨������һ�������Ľ�㣬�����ڸý���ǰ�����һ���½��,ƽ��ʱ�临�Ӷ�:O(1)
bool insert_after_Node(LNode *p,int e); //����巨��ֻ����һ�������Ľ�㣬�����ڸý��ĺ������һ���½��,ƽ��ʱ�临�Ӷ�:O(1)
bool delete_before_Node(LinkList &L,int i,int e); //��ǰɾ����ֻ�������λ�������ڸý���ǰ��ɾ��һ�����,ƽ��ʱ�临�Ӷ�:O(n)
bool delete_after_Node(LNode *p); //����ɾ����ֻ����һ�������Ľ�㣬����ɾ���ý��ĺ���һ�����,ƽ��ʱ�临�Ӷ�:O(1)
LNode * get_Elem(LinkList L,int i); //��λ�������������Ӧ�Ľ��,ƽ��ʱ�临�Ӷ�O(n) 
LNode * find_Elem(LinkList L,int e); // ���ո�������ֵ�������ҽ�����Ƿ��и���ֵ���Ӷ��ҵ���� ,ƽ��ʱ�临�Ӷ�:O(n) 
int get_ListLen(LinkList L); //��ȡ����ĳ���,ƽ��ʱ�临�Ӷ�:O(n) 
LinkList init_tail_List(LinkList &L); //��β�巨�� �����ʼ��һ�������� 
LinkList init_head_List(LinkList &L); //��ͷ�巨�� ˳���ʼ��һ�������� ,poi����������õ���˳��������Ԫ�ص����� ����������á� 

bool init_List(LinkList &L){ 
	L=(LNode *)malloc(sizeof(LNode)); //��ͷ�ڵ㿪��һ���ռ�
	if(L==NULL) return false; //�ڴ治�㣬����ʧ��
	L->next=NULL;
	return true;
}

bool empty(LinkList L){ 
	if(L->next==NULL) return true;
	else return false;
}

bool insert_before_Node(LinkList &L,int i,int e){ 
	if(i<1) return false; //�����λ�ò����Ϲ涨 
	LNode *p; //ָ��Pָ��ǰɨ��ĵ� 
	int j=0; //ָ��P��ͷ��㣨0��㣩��ʼ��Ҫ�����λ��
	p=L;
	while(p!=NULL&&j<i-1){ //�ҵ���i-1����� 
		p=p->next;
		j++;
	} 
	if(p==NULL) return false; //iֵ���Ϸ�
	LNode *s=(LNode *)malloc(sizeof(LNode)); //�����µĽ��s�������Ҫ�����Ԫ��e 
	s->data=e;
	s->next=p->next; //ע��˴���ָ�����߼���ϵ 
	p->next=s;
	return true;
}

bool insert_front_Node(LNode *p,int e){
	if(p==NULL) return false; //�ڴ治��������ʧ�� 
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL) return false; //�ڴ治��������ʧ��
	s->next=p->next;
	p->next=s;
	s->data=p->data; //���������ݽ��н��� 
	p->data=e;
	return true; 
}

bool insert_after_Node(LNode *p,int e){
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL) return false;
	s->data=e;
	s->next=p->next;
	p->next=s; 
} 

bool delete_before_Node(LinkList &L,int i,int e){ 
	if(i<1) return false; //ɾ����λ�ò����Ϲ涨 
	LNode *p; //ָ��Pָ��ǰɨ��ĵ� 
	int j=0; //ָ��P��ͷ��㣨0��㣩��ʼ��Ҫ�����λ��
	p=L;
	while(p!=NULL&&j<i-1){ //�ҵ���i-1����� 
		p=p->next;
		j++;
	} 	
	if(p==NULL) return false; //iֵ���Ϸ�
	if(p->next==NULL) return false; //˵���ý������Ѿ�û�н����
	LNode *q=p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;  
}

bool delete_after_Node(LNode *p){ 
	if(p==NULL) return false;
	LNode *q=p->next;
	p->data=p->next->data; 
	p->next=q->next;
	free(q);
	return true;
}

LNode * get_Elem(LinkList L,int i){ //ע��˴��ķ������ͣ���һ����� 
	if(i<1) return false; //�����λ�ò����Ϲ涨 
	LNode *p; //ָ��Pָ��ǰɨ��ĵ� 
	int j=0; //ָ��P��ͷ��㣨0��㣩��ʼ��Ҫ�����λ��
	p=L;
	while(p!=NULL&&j<i){ //�ҵ���i����� 
		p=p->next;
		j++;
	}
	return p; 
} 

LNode * find_Elem(LinkList L,int e){
	LNode *p=L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
	}
	return p;
} 

int get_ListLen(LinkList L){
	int len=0;
	LNode *p=L;
	while(p->next!=NULL){
		p=p->next;
		len++;
	}
	return len;
}

LinkList init_tail_List(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode)); //����ͷ��� 
	LNode *s,*r=L; //rΪβ���
	scanf("%d",&x);
	while(x!=9999){ //����û�����9999,��ô�ͽ�����ʼ��
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s; //��ָ��rָ��s��� 
		scanf("%d",&x); 
	} 
	r->next=NULL;
	return L; 
}

LinkList init_head_List(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode)); //����ͷ��� 
	L->next=NULL;
	LNode *s; //rΪͷ��� 
	scanf("%d",&x);
	while(x!=9999){ //����û�����9999,��ô�ͽ�����ʼ��
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next; //�˲���Ϊ������ 
		L->next=s;
		scanf("%d",&x); 
	}
	return L;
} 

int main(){
	LinkList L; //Lָ��ָ��ͷ��㣨��ʵҲ����˵ָ�������������� 
	init_List(L);
	return 0;
}
