/*��̬�����˳���*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10

typedef struct{
	int data[MAXSIZE];
	int length;
}SeqList;
 
void init_List(SeqList &L){ //˳����ʼ����ע��˴�ʹ����&�� 
	for(int i=0;i<MAXSIZE;i++){
		L.data[i]=0; 
	}
	L.length=0;
}

void insert_List(SeqList &L,int i,int e){ //˳���Ĳ��� 
	for(int j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
}

void delete_List(SeqList &L,int i,int &e){ //˳����ɾ�� ��ע�⣺��������&��Ϊ���ǰ�e����ȥ�� 
	e=L.data[i-1];
	for(int j=i-1;j<=L.length;j++){
		L.data[j]=L.data[j+1];
	}
	L.length--;
}

int find_List(SeqList &L,int i){ //���ҵ�i��Ԫ�� 
	return L.data[i-1];
} 

int main(){
	SeqList L;
	init_List(L);
	insert_List(L,3,3);
	int e=0; //e:��¼��ɾ����Ԫ�� 
	delete_List(L,3,e); 
	return 0;
}
