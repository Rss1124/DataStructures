/*ѭ������__by����ʵ��
���䣺
Q:���֪����ǰ�������ж��ٸ�Ԫ�� 	A:(rear+MAXSZIE-front)%MAXSIZE: 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10
 
typedef struct{
	int data[MAXSIZE]; //����Ԫ�� 
	int front,rear; //front:��ͷָ��; rear:��βָ�� 
}SqQueue; 

bool init_queue(SqQueue &Q); //���г�ʼ��
bool empty(SqQueue &Q); //�����п�
bool insert_queue(SqQueue &Q,int e); //���
bool delete_queue(SqQueue &Q,int &e); //���ӣ���������Ԫ�ط��ظ�e 
int get_elem(SqQueue &Q,int &e); //��ȡ��ǰ��ͷԪ�� 

bool init_queue(SqQueue &Q){
	Q.front=Q.rear=0; //�ö�ͷָ�����βָ��ָ���һ��λ�� 
	return true;
}
bool empty(SqQueue &Q){
	if(Q.front==Q.rear) return true; //˵����ͷָ�����βָ��ָ����ͬһ���ط���˵������Ϊ�� 
	else return false;
} 
bool insert_queue(SqQueue &Q,int e){
	if((Q.rear+1)%MAXSIZE==(Q.front)) return false; //��ʱ��������  
	else{
		Q.data[Q.rear]=e;
		Q.rear=(Q.rear+1)%MAXSIZE; //�ö��г�Ϊһ����״ 
	}
	return true; 
}
bool delete_queue(SqQueue &Q,int &e){
	if(Q.rear==Q.front) return false; //��ʱ����Ϊ�գ��޷����� 
	else{
		e=Q.data[Q.front];
		Q.front=(Q.front+1)%MAXSIZE;
	}
	return true;
}
int get_elem(SqQueue &Q,int &e){
	if(Q.rear==Q.front) return false; //��ʱ����Ϊ�գ��޷���ȡԪ��
	else{
		e=Q.data[Q.front];
	} 
	return e;
} 

int main(){
	SqQueue Q;
}


