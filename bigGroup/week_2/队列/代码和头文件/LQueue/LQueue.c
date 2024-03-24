#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"

//���˵�
void welcome(){
	printf("*-------------------------------*\n");
	printf("|\t�ڶ��ܴ�����ҵ����\t|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.��ʼ������\t\t|\n");
	printf("|\t2.��Ӳ���\t\t|\n");
	printf("|\t3.���Ӳ���\t\t|\n");
	printf("|\t4.���г���\t\t|\n"); 
	printf("|\t5.��������\t\t|\n");
	printf("|\t6.��ն���\t\t|\n");
	printf("|\t7.���ٶ���      \t|\n");
	printf("|\t8.�ж��Ƿ��\t\t|\n");  
	printf("|\t9.�Ƴ�\t\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
} 

//������Ͳ˵�
void welcome1(){
	printf("|\t1.����\t\t|\n");
	printf("|\t2.������\t|\n");
	printf("|\t3.�ַ�\t\t|\n");
} 

//��ʼ������
void InitLQueue(LQueue *Q){
	Q->front = Q->rear = (Node *)malloc(sizeof(Node));
	Q->front->next = Q->rear->next = NULL;
	Q->front->data = Q->rear->data = NULL;
	Q->length = 0;
	printf("��ʼ���ɹ�\n");
}

//�ж��Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		return TRUE;
	}else{
		return FALSE;
	}
}

//����г��� 
int LengthLQueue(LQueue *Q){
	if(IsEmptyLQueue(Q)){
		printf("����Ϊ��\n");
		return 0;
	}
	return Q->length; 
}

//��Ӳ��� 
Status EnLQueue(LQueue *Q, void *data){
	//���ٿռ� 
	Node *temp = (Node *)malloc(sizeof(Node));
	if( temp == NULL){
		return FALSE;
	}
	//�ж������������� 
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

//���Ӳ��� 
Status DeLQueue(LQueue *Q){
	//�ж��Ƿ�Ϊ��
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
 
//��ȡ��Ԫ�� 
Status GetHeadLQueue(LQueue *Q, void *e){
	//�ж��Ƿ�Ϊ��
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

//��ն��� 
void ClearLQueue(LQueue *Q){
	while(DeLQueue(Q));
}

//���ٶ��� 
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
}

//��������
void LPrint(void *q){
	int *value = (int*)q;
    printf("%d ", *value);

} 

//�������� 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	//�ж��Ƿ�Ϊ��
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


// ��ʼ������
Status haveNotInitLQueue(LQueue* Q)
{
	if (Q == NULL || Q->front == NULL || Q->rear == NULL)
	{
		printf("��δ��ʼ������\n");
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
			case '1': //��ʼ������ 
			InitLQueue(Q);
			f = 1;
			system("pause");
			system("cls");
			break;						 
			case '2': //���
			//�ж��Ƿ��ʼ�� 
			if(f == 0){
				printf("��δ��ʼ��\n");
				system("pause");
				system("cls");
				break;
			} 
			d = LengthLQueue(Q);
			welcome1();
			printf("������Ҫ��ӵ��������ͣ�\n");
			char s1 = getch();
			
			switch(s1){
				case '1': //int
				type = '1';
				datatype[d] = '1';
				int *data = (void*)malloc(sizeof(int));
				printf("������ӵ����ݣ�\n");
				scanf("%d",&data);
				if(EnLQueue(Q, &data)){
					printf("good\n");
				}
				break;
				
				case '2': //double
				type = '2';
				datatype[d] = '2';
				double *data2 = (void*)malloc(sizeof(double));
				printf("������ӵ����ݣ�\n");
				scanf("%f",&data2);
				if(EnLQueue(Q, &data2)){
					printf("good\n");
				}
				break;
				
				case '3': //char
				type = '3';
				datatype[d] = '3';
				char *data3= (void*)malloc(sizeof(char));
				printf("������ӵ����ݣ�\n");
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
			//���Ӳ��� 
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
			printf("��Ԫ�صĵ�ַ��%d\n",e); 
			status = DeLQueue(Q);
			if(status == TRUE){
				printf("���ӳɹ�\n");
			}
			system("pause");
			system("cls");
			break;
			}
			case '4': {
			//���г���
			int leng = LengthLQueue(Q);
			printf("changdu==%d\n",leng); 
			system("pause");
			system("cls");
			break;
			}
			
			case '5': //��������
			TraverseLQueue(Q, LPrint);
			system("pause");
			system("cls");
			break;
			case '6': //��ն���
			ClearLQueue(Q);
			printf("������\n");
			system("pause");
			system("cls"); 
			break;
			case '7': //���ٶ���
			DestoryLQueue(Q);
			printf("�������\n");
			system("pause");
			system("cls"); 
			break;
			case '8': //�ж϶����Ƿ�Ϊ��
			if(IsEmptyLQueue(Q)){
				printf("Ϊ��\n");
			}else {
				printf("��Ϊ��\n");
			}
			system("pause");
			system("cls");
			break; 
			case '9': //�˳�ϵͳ
			printf("��ӭ�´��ټ�\n");
			return;
			default : //
			printf("����������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
} 
