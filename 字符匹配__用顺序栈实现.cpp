/*�ַ�ƥ��__��˳��ջʵ��
�����㷨������ɨ�������ַ�����������������������ջ��������������������ջ��������ƥ�� 
ƥ��ɹ�����1,ƥ��ʧ�ܷ���0
ƥ��ʧ�ܵ�����������ŵ��������ŵ����������Ų�ƥ�� 
*/ 
#include<bits/stdc++.h>
using namespace std; 
#define MAXSIZE 10

typedef struct{
	char data[MAXSIZE];
	int top; //ջ��ָ�� 
}SqStack;

bool char_match(string str,int length); //���ص㣺�ַ�ƥ���㷨�����ϸƷ 
void init_stack(SqStack &S); //˳��ջ�ĳ�ʼ��
bool empty(SqStack S); //˳��ջ�п�
bool push(SqStack &S,char c); //��ջ
bool pop(SqStack &S,char &c); //��ջ 

void init_stack(SqStack &S){
	S.top=-1;
}
bool empty(SqStack S){
	if(S.top==-1) return true; //��ջ 
	else return false;
}
bool push(SqStack &S,char c){
	if(S.top==MAXSIZE-1) return false; //ջ���� 
	S.top=S.top+1;
	S.data[S.top]=c;
	return true;
}
bool pop(SqStack &S,char &c){
	if(S.top==-1) return false; //ջ���� 
	c=S.data[S.top];
	S.top=S.top-1;
	return true; 
}
bool char_match(string str,int length){
	SqStack S;
	init_stack(S);
	for(int i=0;i<length;i++){
		if(str[i]=='('||str[i]=='['||str[i]=='{'){ //����˳��ջ 
			push(S,str[i]); //ɨ�赽�����ţ���ջ 
		}
		else{
			if(empty(S)==true) return false; //�����ʱɨ�赽�����ţ���ջΪ�գ�ֱ�ӷ��� 
			char topElem;
			pop(S,topElem); //ɨ�赽�����ţ���ջ����ƥ�� 
			if(str[i]==')' && topElem!='(') return false;
			if(str[i]==']' && topElem!='[') return false;
			if(str[i]=='}' && topElem!='{') return false;
		}
	}
	return empty(S);
}

int main(){
	string str;
	cin>>str;
	int l=str.length();
	cout<<char_match(str,l);
}


