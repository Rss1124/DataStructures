/*动态分配的顺序表*/ 
#include<bits/stdc++.h>
using namespace std;
#define InitSize 10 //需要提前给出初始大小 

typedef struct{
	int *data; //指示动态分配数组的指针 
	int MAXSIZE; //该数组的最大长度 
	int length; //该数组当前的长度 
}SeqList;

void init_List(SeqList &L){
	L.data=(int *)malloc(InitSize*sizeof(int)); //用malloc申请一片连续的空间 
	L.length=0;
	L.MAXSIZE=InitSize; 
}

void increase_List(SeqList &L,int len){
	int *p=L.data; //指针p用来指向以前的内存空间 
	L.data=(int *)malloc((L.MAXSIZE+len)*sizeof(int)); //注意此时已经开辟了一个MAXSIZE+len长度的空间，所以L.data指针指向了新分配的空间 
	for(int i=0;i<L.length;i++){
		L.data[i]=p[i]; //将原来内存空间中的数据迁移到新分配的空间中 
	} 
	L.MAXSIZE=L.MAXSIZE+len;
	free(p); //将旧的内存空间释放掉 
}

int find_List(SeqList &L,int i){ //按下标查找第i个元素 
	return L.data[i-1];
} 

int find_List_ByValue(SeqList &L,int value){ //按值查找 
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
