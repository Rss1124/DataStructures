/*˳��ջ��ʵ��
ȱ�㣺ջ�Ĵ�С���ɱ� 
*/ 
#include<bits/stdc++.h>
using namespace std; 
#define MAXSIZE 10
typedef struct{
	int data[MAXSIZE];
	int top; //��ʾջ��ָ�룬һ���ʾ������±� 
}SqStack;

void init_sqstack(SqStack &S); //��ʼ��ջ 
bool empty_sqstack(SqStack S); //�ж�ջ�Ƿ�Ϊ��
bool push(SqStack &S,int e); //��Ԫ��e��ջ 
bool pop(SqStack &S,int &e); //��ջ��Ԫ�س�ջ,��ͨ������e���� 
bool get_top(SqStack &S,int &e); //��ȡջ��Ԫ��,��ͨ������e���� 

void init_sqstack(SqStack &S){
	S.top=-1;
} 
bool empty_sqstack(SqStack S){
	if(S.top==-1) return true;
	else return false;
}
bool push(SqStack &S,int e){
	if(S.top==MAXSIZE-1) return false; //��ʱջ�������޷�����
	S.top=S.top+1;
	S.data[S.top]=e; //S.top��ֵ����������±� 
	return true; 
}
bool pop(SqStack &S,int &e){
	if(S.top==-1) return false; //��ʱ�Ѿ��ǿ�ջ��û��Ԫ�ؿ��Գ�ջ��
	e=S.data[S.top]; //S.top��ֵ����������±� 
	S.top=S.top-1;
	return true; 
} 
bool get_top(SqStack &S,int &e){
	if(S.top==-1) return false; ////��ʱ�Ѿ��ǿ�ջ��û��ջ��Ԫ����
	e=S.data[S.top];
	return true; 
} 

int main(){
	SqStack S;
	init_sqstack(S);
}
