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
	printf("|\t9.推出\t\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n");
} 

//入队类型菜单
void welcome1(){
	printf("|\t1.整数\t\t|\n");
	printf("|\t2.浮点数\t|\n");
	printf("|\t3.字符\t\t|\n");
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
	//判断输入哪种类型 
	if( datatype[d] == '1'){
		temp->data = (void*)malloc(sizeof(int));
		//data = (void*)malloc(sizeof(int));
	}else if(datatype[d] == '2'){
		temp->data = (void*)malloc(sizeof(double));
		//data = (void*)malloc(sizeof(double));
	}else if(datatype[d] == '3'){
		temp->data = (void*)malloc(sizeof(char));
		//data = (void*)malloc(sizeof(char));
	}
	temp->data = data;
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
	temp = Q->front->next;
	Q->front->next = temp->next;
	if(Q->rear == temp){
		Q->front = Q->rear;
	}
	free(temp);
	Q->length--;
	return TRUE;
}
 
//获取首元素 
Status GetHeadLQueue(LQueue *Q, void *e){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	if (datatype[0] == '1'){
		e = malloc(sizeof(int));
		e = Q->front->next->data;
	}else if (datatype[0] == '2'){
		e = malloc(sizeof(double));
		e = Q->front->next->data;
	}else if (datatype[0] == '3'){
		e = malloc(sizeof(char));
		e = Q->front->next->data;
	}
	
	return TRUE;
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
}

//操作函数
void LPrint(void *q){
	int *value = (int*)q;
    printf("%d ", *value);

} 

//遍历队列 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	d = 0;
	Node * p = (Node*)malloc(sizeof(Node));
	p = Q->front->next;
	while(p != NULL){
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}


// 初始化检验
Status haveNotInitLQueue(LQueue* Q)
{
	if (Q == NULL || Q->front == NULL || Q->rear == NULL)
	{
		printf("尚未初始化队列\n");
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


int main(){
	Status status;
	LQueue *Q = (LQueue *)malloc(sizeof(LQueue));
	IsEmptyLQueue(Q);
	int f = 0;
	while(1){
		welcome();
		char s = getch();
		switch(s){
			case '1': //初始化队列 
			InitLQueue(Q);
			f = 1;
			system("pause");
			system("cls");
			break;						 
			case '2': //入队
			//判断是否初始化 
			if(f == 0){
				printf("还未初始化\n");
				system("pause");
				system("cls");
				break;
			} 
			d = LengthLQueue(Q);
			welcome1();
			printf("输入想要入队的数据类型：\n");
			char s1 = getch();
			
			switch(s1){
				case '1': //int
				type = '1';
				datatype[d] = '1';
				int *data = (void*)malloc(sizeof(int));
				printf("输入入队的数据：\n");
				scanf("%d",&data);
				if(EnLQueue(Q, &data)){
					printf("good\n");
				}
				break;
				
				case '2': //double
				type = '2';
				datatype[d] = '2';
				double *data2 = (void*)malloc(sizeof(double));
				printf("输入入队的数据：\n");
				scanf("%f",&data2);
				if(EnLQueue(Q, &data2)){
					printf("good\n");
				}
				break;
				
				case '3': //char
				type = '3';
				datatype[d] = '3';
				char *data3= (void*)malloc(sizeof(char));
				printf("输入入队的数据：\n");
				scanf("%c",&data3);
				if(EnLQueue(Q, &data3)){
					printf("good\n");
				}
				break;
			}
			system("pause");
			system("cls");
			break;
			
			case '3': {
			//出队操作 
			void *e=malloc(8);
			GetHeadLQueue(Q, &e);
			//if (datatype[0] == '1')
//			{
//				printf("%d\n", (int*)e);
//			}
//			else if (datatype[0] == '2')
//			{
//				printf("%.2f", e);
//			}
//			else if (datatype[0] == '3')
//			{
//				printf("%c", *(char*)e);
//			}
			printf("首元素的地址：%d\n",e); 
			status = DeLQueue(Q);
			if(status == TRUE){
				printf("出队成功\n");
			}
			system("pause");
			system("cls");
			break;
			}
			case '4': {
			//队列长度
			int leng = LengthLQueue(Q);
			printf("changdu==%d\n",leng); 
			system("pause");
			system("cls");
			break;
			}
			
			case '5': //遍历队列
			TraverseLQueue(Q, LPrint);
			system("pause");
			system("cls");
			break;
			case '6': //清空队列
			ClearLQueue(Q);
			printf("清空完成\n");
			system("pause");
			system("cls"); 
			break;
			case '7': //销毁队列
			DestoryLQueue(Q);
			printf("销毁完成\n");
			system("pause");
			system("cls"); 
			break;
			case '8': //判断队列是否为空
			if(IsEmptyLQueue(Q)){
				printf("为空\n");
			}else {
				printf("不为空\n");
			}
			system("pause");
			system("cls");
			break; 
			case '9': //退出系统
			printf("欢迎下次再见\n");
			return;
			default : //
			printf("请重新输入\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
} 
