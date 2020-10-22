/*循环队列__by数组实现
补充：
Q:如何知道当前队列里有多少个元素 	A:(rear+MAXSZIE-front)%MAXSIZE: 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10
 
typedef struct{
	int data[MAXSIZE]; //数组元素 
	int front,rear; //front:队头指针; rear:队尾指针 
}SqQueue; 

bool init_queue(SqQueue &Q); //队列初始化
bool empty(SqQueue &Q); //队列判空
bool insert_queue(SqQueue &Q,int e); //入队
bool delete_queue(SqQueue &Q,int &e); //出队，并将出队元素返回给e 
int get_elem(SqQueue &Q,int &e); //获取当前队头元素 

bool init_queue(SqQueue &Q){
	Q.front=Q.rear=0; //让队头指针与队尾指针指向第一个位置 
	return true;
}
bool empty(SqQueue &Q){
	if(Q.front==Q.rear) return true; //说明队头指针与队尾指针指向了同一个地方，说明队列为空 
	else return false;
} 
bool insert_queue(SqQueue &Q,int e){
	if((Q.rear+1)%MAXSIZE==(Q.front)) return false; //此时队列已满  
	else{
		Q.data[Q.rear]=e;
		Q.rear=(Q.rear+1)%MAXSIZE; //让队列成为一个环状 
	}
	return true; 
}
bool delete_queue(SqQueue &Q,int &e){
	if(Q.rear==Q.front) return false; //此时队列为空，无法出队 
	else{
		e=Q.data[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
	}
	return true;
}
int get_elem(SqQueue &Q,int &e){
	if(Q.rear==Q.front) return false; //此时队列为空，无法获取元素
	else{
		e=Q.data[Q.front];
	} 
	return e;
} 

int main(){
	SqQueue Q;
}


