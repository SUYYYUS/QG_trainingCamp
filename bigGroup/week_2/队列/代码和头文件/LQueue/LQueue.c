#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

//主菜单
void welcome(){
	printf("*-------------------------------*\n");
	printf("|\t第二周大组作业队列\t|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.初始化队列\t\t|\n");
	printf("|\t2.入队操作\t\t|\n");
	printf("|\t3.出队操作\t\t|\n");
	printf("|\t4.队列长度\t\t|\n"); 
	printf("|\t5.遍历队列\t\t|\n");
	printf("|\t6.清空队列\t\t|\n");
	printf("|\t7.销毁队列      \t|\n");
	printf("|\t8.判断是否空\t\t|\n");  
	printf("|\t9.获得头元素\t\t|\n"); 
	printf("|\t0.推出\t\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n");
} 


//初始化队列
void InitLQueue(LQueue *Q){
	Q->front = Q->rear = (Node *)malloc(sizeof(Node));
	Q->front->next = Q->rear->next = NULL;
	Q->front->data = Q->rear->data = NULL;
	Q->length = 0;
	printf("初始化成功\n");
}

//判断是否为空
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		return TRUE;
	}else{
		return FALSE;
	}
}

//求队列长度 
int LengthLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		printf("队列为空\n");
		return 0;
	}
	return Q->length; 
}

//入队操作 
Status EnLQueue(LQueue *Q, void *data){
	//开辟空间 
	Node *temp = (Node *)malloc(sizeof(Node));
	if( temp == NULL){
		return FALSE;
	}
	temp->data = (void*)malloc(datasize);
	memcpy(temp->data, data, datasize);
	temp->next = NULL;
	Q->rear->next = temp;
	Q->rear = temp;
	Q->length++;
	return TRUE;
}

//出队操作 
Status DeLQueue(LQueue *Q){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	Node* temp = (Node *)malloc(sizeof(Node));
	temp = Q->front;
	Q->front = temp->next;
	if(Q->rear == temp){
		Q->front = Q->rear;
	}
	Q->length--;
	free(temp);
	temp = NULL;
	return TRUE;
}

//获取首元素 
Status GetHeadLQueue(LQueue *Q, void *e){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		printf("空\n");
		return FALSE;
	}
	memcpy(e, Q->front->next->data, datasize);
	if (e == NULL) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

//清空队列 
void ClearLQueue(LQueue *Q){
	while(DeLQueue(Q));
}

//销毁队列 
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
	Q = NULL;
}

//操作函数
void LPrint(void *q){
	if(q == NULL){
		return ;
	}
	if(datasize == sizeof(int)){ 
		printf("--%d\n",*(int*)q);
	}else if(datasize == sizeof(double)){
		printf("--%lf\n",*(double*)q); 
	}else if(datasize == sizeof(char)){
		printf("--%c\n",*(char*)q);
	}
	return ;
} 

//遍历队列 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	
	Node * p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	while(p != NULL){
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}

//确定类型
int gettype(){
	int select = 0;
	while(select == 0){
		printf("请选择您的队列数据类型： 1.int , 2.double , 3.char\n");
		scanf("%d",&select);
		if(select == 1){
			return sizeof(int);
		}else if (select == 2){
			return sizeof(double);
		}else if (select == 3){
			return sizeof(char);
		}else{
			select = 0;
			printf("请重新输入\n");
			system("pause");
			system("cls");
		}
	}
} 


int main(){
	Status status;
	LQueue *Q = (LQueue *)malloc(sizeof(LQueue));
	int f = 0;
	while(1){
		welcome();
		char s = getch();
		switch(s){
			case '1': //初始化队列 
			if(f == 1){
				printf("已有队列，请先销毁旧队列\n");
				system("pause");
				system("cls");
				break;
			} 
			InitLQueue(Q);
			datasize = gettype();
			printf("选择完毕\n");
			f = 1;
			system("pause");
			system("cls");
			break;						 
			case '2': //入队
			//判断是否初始化 
			if(f == 0){
				printf("还未初始化，没有队列\n");
				system("pause");
				system("cls");
				break;
			}	
				void *data = (void*)malloc(sizeof(datasize));
				if(datasize == sizeof(int)){
					printf("输入整形入队的数据：\n");
					scanf("%d",data);
				}else if(datasize == sizeof(double)){
					printf("输入浮点数型入队的数据：\n");
					scanf("%f",data);
				} else if(datasize == sizeof(char)){
					printf("输入字符入队的数据：\n");
					scanf_s("%c",data);
				} 
				if(EnLQueue(Q, data)){
					printf("入队成功\n");
				}else if(!EnLQueue(Q, &data)){
					printf("入队失败\n");
				}
			system("pause");
			system("cls");
			break;
			case '3': //出队操作 
			if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			status = DeLQueue(Q);
			if(status == TRUE){
				printf("出队成功\n");
			}
			system("pause");
			system("cls");
			break;
			
			case '4': {
				if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			//队列长度
			int leng = LengthLQueue(Q);
			printf("队列长度为%d\n",leng); 
			system("pause");
			system("cls");
			break;
			}
			
			case '5': //遍历队列
			if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			TraverseLQueue(Q, LPrint);
			system("pause");
			system("cls");
			break;
			case '6': //清空队列
			if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			ClearLQueue(Q);
			printf("清空完成\n");
			system("pause");
			system("cls"); 
			break;
			case '7': //销毁队列
			if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			DestoryLQueue(Q);
			printf("销毁完成\n");
			f = 0;
			system("pause");
			system("cls"); 
			break;
			case '8': //判断队列是否为空
			if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			if(IsEmptyLQueue(Q)){
				printf("为空\n");
			}else {
				printf("不为空\n");
			}
			system("pause");
			system("cls");
			break; 
			case '9': {//获得头元素
			if(f == 0){
				printf("还未初始化队列，没有队列\n");
				system("pause");
				system("cls");
				break;
			}
			void *e=(void*)malloc(sizeof(datasize));
			GetHeadLQueue(Q, e);
			printf("首元素的：\n"); 
			LPrint(e);
			system("pause");
			system("cls");
			break;
			}
			case '0': //退出系统
			printf("欢迎下次再见\n");
			return;
			default : 
			printf("请重新输入\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
} 
