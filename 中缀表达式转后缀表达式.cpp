#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 20
string str1,str2;

typedef struct{
	char c[MAXSIZE]; //�����
	int top; //ջ��ָ�� 
}SqStack;

bool init_SqStack(SqStack &S){
	S.top=-1;
}
bool empty(SqStack S){
	if(S.top==-1) return true;
	else return false;
}
bool push(SqStack &S,char ch){
	if(S.top==MAXSIZE-1) return false; //ջ�������޷���ջ
	S.top=S.top+1;
	S.c[S.top]=ch;
	return true; 
}
char pop(SqStack &S){
	char ch;
	if(S.top==-1) return false; //ջ�ѿգ��޷���ջ
	ch=S.c[S.top];
	S.top=S.top-1;
	return ch; 
}
void change(SqStack &S){
	init_SqStack(S);
	cin>>str1;
	for(int i=0;i<str1.length();i++){
		if(str1[i]>=48&&str1[i]<=57) str2+=str1[i]; //��������ǲ�����0-9,ֱ����� 
//		else if(str1[i]=='(') push(S.c);//������������ţ�ֱ����ջ 
		else if(str1[i]=='+'||str1[i]=='-'||str1[i]=='*'||str1[i]=='/'){ //�������������� 
			if(empty(S)==true) push(S,str1[i]); //�����ʱջ�ǿյģ���ֱ����ջ
			else{ //���ջ��Ϊ�� 
				if(str1[i]=='*'||str1[i]=='/') push(S,str1[i]); //�����ʱ����߼��Ĳ�����'*'����'/',��ֱ����ջ 
				else{ //���������Ԫ�س�ջ,��ջ���ٽ��µĲ�������ջ 
					str2+=pop(S);
					push(S,str1[i]); 
				}
			} 
		}
		else if(str1[i]=='(') push(S,str1[i]); //��������������ţ�ֱ����ջ 
		else if(str1[i]==')'){
			while(S.c[S.top+1]=='('){
				str2+=pop(S);
			}
		} 
		
	}
	for(int i=S.top;i>=0;i--){
		str2+=pop(S);
	}		
	cout<<str2; 	
}


int main(){
	SqStack S;
	change(S);
}


