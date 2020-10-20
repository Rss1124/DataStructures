/*��̬�����˳���*/ 
#include<bits/stdc++.h>
using namespace std;
#define InitSize 10 //��Ҫ��ǰ������ʼ��С 

typedef struct{
	int *data; //ָʾ��̬���������ָ�� 
	int MAXSIZE; //���������󳤶� 
	int length; //�����鵱ǰ�ĳ��� 
}SeqList;

void init_List(SeqList &L){
	L.data=(int *)malloc(InitSize*sizeof(int)); //��malloc����һƬ�����Ŀռ� 
	L.length=0;
	L.MAXSIZE=InitSize; 
}

void increase_List(SeqList &L,int len){
	int *p=L.data; //ָ��p����ָ����ǰ���ڴ�ռ� 
	L.data=(int *)malloc((L.MAXSIZE+len)*sizeof(int)); //ע���ʱ�Ѿ�������һ��MAXSIZE+len���ȵĿռ䣬����L.dataָ��ָ�����·���Ŀռ� 
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i]; //��ԭ���ڴ�ռ��е�����Ǩ�Ƶ��·���Ŀռ��� 
	} 
	L.MAXSIZE=L.MAXSIZE+len;
	free(p); //���ɵ��ڴ�ռ��ͷŵ� 
}

int find_List(SeqList &L,int i){ //���±���ҵ�i��Ԫ�� 
	return L.data[i-1];
} 

int find_List_ByValue(SeqList &L,int value){ //��ֵ���� 
	for(int i=0;i<L.length;i++){
		if(L.data[i]==value) return i+1;
		return 0;
	}
} 

int main(){
	SeqList L;
	init_List(L);
	increase_List(L,5);
	return 0; 
} 
