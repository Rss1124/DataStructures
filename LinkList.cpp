/*带有头结点的单链表
特性：指针只能一个方向往后进行查找，所以在对前一个节点进行操作时需要从头结点开始遍历
这样时间复杂度就会很高O(n)，当然也可以开辟一个临时的结点，用"偷梁换柱"的方法来进行操作，从而使时间复杂度降为O(1) 
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef struct LNode{ //定义单链表结点类型 
	int data; //结点存放的数据 
	struct LNode *next; //指针指向下一个结点 	
}LNode, *LinkList; //两种表示结点的方法,本质上是一样的,但是具体写代码的时候想要表示的含义不一样,LNode*(强调结点),LinkList(强调单链表)

bool init_List(LinkList &L); //初始化一个带头节点的单链表
bool empty(LinkList L); //通过判断头结点的next是否为空来确定单链表是否为空 
bool insert_before_Node(LinkList &L,int i,int e); //【前插法】只给你结点的位序，让你在该结点的前面插入一个新结点,平均时间复杂度:O(n) 
bool insert_front_Node(LNode *p,int e); //【前插法】给你一个完整的结点，让你在该结点的前面插入一个新结点,平均时间复杂度:O(1)
bool insert_after_Node(LNode *p,int e); //【后插法】只给你一个完整的结点，让你在该结点的后面插入一个新结点,平均时间复杂度:O(1)
bool delete_before_Node(LinkList &L,int i,int e); //【前删法】只给你结点的位序，让你在该结点的前面删除一个结点,平均时间复杂度:O(n)
bool delete_after_Node(LNode *p); //【后删法】只给你一个完整的结点，让你删除该结点的后面一个结点,平均时间复杂度:O(1)
LNode * get_Elem(LinkList L,int i); //按位序来查找链表对应的结点,平均时间复杂度O(n) 
LNode * find_Elem(LinkList L,int e); // 按照给定的数值，来查找结点内是否含有该数值，从而找到结点 ,平均时间复杂度:O(n) 
int get_ListLen(LinkList L); //获取链表的长度,平均时间复杂度:O(n) 
LinkList init_tail_List(LinkList &L); //【尾插法】 逆序初始化一个单链表 
LinkList init_head_List(LinkList &L); //【头插法】 顺序初始化一个单链表 ,poi：最终链表得到的顺序是输入元素的逆序 【链表的逆置】 

bool init_List(LinkList &L){ 
	L=(LNode *)malloc(sizeof(LNode)); //给头节点开辟一个空间
	if(L==NULL) return false; //内存不足，分配失败
	L->next=NULL;
	return true;
}

bool empty(LinkList L){ 
	if(L->next==NULL) return true;
	else return false;
}

bool insert_before_Node(LinkList &L,int i,int e){ 
	if(i<1) return false; //插入的位置不符合规定 
	LNode *p; //指针P指向当前扫描的点 
	int j=0; //指针P从头结点（0结点）开始找要插入的位置
	p=L;
	while(p!=NULL&&j<i-1){ //找到第i-1个结点 
		p=p->next;
		j++;
	} 
	if(p==NULL) return false; //i值不合法
	LNode *s=(LNode *)malloc(sizeof(LNode)); //开辟新的结点s用来存放要插入的元素e 
	s->data=e;
	s->next=p->next; //注意此处的指针间的逻辑关系 
	p->next=s;
	return true;
}

bool insert_front_Node(LNode *p,int e){
	if(p==NULL) return false; //内存不够，分配失败 
	LNode *s=(LNode *)malloc(sizeof(LNode));
	if(s==NULL) return false; //内存不够，分配失败
	s->next=p->next;
	p->next=s;
	s->data=p->data; //将结点的数据进行交换 
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
	if(i<1) return false; //删除的位置不符合规定 
	LNode *p; //指针P指向当前扫描的点 
	int j=0; //指针P从头结点（0结点）开始找要插入的位置
	p=L;
	while(p!=NULL&&j<i-1){ //找到第i-1个结点 
		p=p->next;
		j++;
	} 	
	if(p==NULL) return false; //i值不合法
	if(p->next==NULL) return false; //说明该结点后面已经没有结点了
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

LNode * get_Elem(LinkList L,int i){ //注意此处的返回类型：是一个结点 
	if(i<1) return false; //插入的位置不符合规定 
	LNode *p; //指针P指向当前扫描的点 
	int j=0; //指针P从头结点（0结点）开始找要插入的位置
	p=L;
	while(p!=NULL&&j<i){ //找到第i个结点 
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
	L=(LinkList)malloc(sizeof(LNode)); //生成头结点 
	LNode *s,*r=L; //r为尾结点
	scanf("%d",&x);
	while(x!=9999){ //如果用户输入9999,那么就结束初始化
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s; //让指针r指向s结点 
		scanf("%d",&x); 
	} 
	r->next=NULL;
	return L; 
}

LinkList init_head_List(LinkList &L){
	int x;
	L=(LinkList)malloc(sizeof(LNode)); //生成头结点 
	L->next=NULL;
	LNode *s; //r为头结点 
	scanf("%d",&x);
	while(x!=9999){ //如果用户输入9999,那么就结束初始化
		s=(LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next; //此步骤为后插操作 
		L->next=s;
		scanf("%d",&x); 
	}
	return L;
} 

int main(){
	LinkList L; //L指针指向头结点（其实也可以说指向了整个单链表） 
	init_List(L);
	return 0;
}
