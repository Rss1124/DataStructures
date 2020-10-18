/*静态分配的顺序表*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10

typedef struct{
	int data[MAXSIZE];
	int length;
}SeqList;
 
void init_List(SeqList &L){ //顺序表初始化【注意此处使用了&】 
	for(int i=0;i<MAXSIZE;i++){
		L.data[i]=0; 
	}
	L.length=0;
}

void insert_List(SeqList &L,int i,int e){ //顺序表的插入 
	for(int j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
}

void delete_List(SeqList &L,int i,int &e){ //顺序表的删除 【注意：这里用了&，为的是把e带回去】 
	e=L.data[i-1];
	for(int j=i-1;j<=L.length;j++){
		L.data[j]=L.data[j+1];
	}
	L.length--;
}

int find_List(SeqList &L,int i){ //查找第i个元素 
	return L.data[i-1];
} 

int main(){
	SeqList L;
	init_List(L);
	insert_List(L,3,3);
	int e=0; //e:记录被删除的元素 
	delete_List(L,3,e); 
	return 0;
}
