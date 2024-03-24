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
	printf("|\t9.���ͷԪ��\t\t|\n"); 
	printf("|\t0.�Ƴ�\t\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
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
	temp->data = (void*)malloc(datasize);
	memcpy(temp->data, data, datasize);
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

//��ȡ��Ԫ�� 
Status GetHeadLQueue(LQueue *Q, void *e){
	//�ж��Ƿ�Ϊ��
	if(IsEmptyLQueue(Q)){
		printf("��\n");
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

//��ն��� 
void ClearLQueue(LQueue *Q){
	while(DeLQueue(Q));
}

//���ٶ��� 
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q->front);
	Q->front = Q->rear = NULL;
	Q = NULL;
}

//��������
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

//�������� 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	//�ж��Ƿ�Ϊ��
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

//ȷ������
int gettype(){
	int select = 0;
	while(select == 0){
		printf("��ѡ�����Ķ����������ͣ� 1.int , 2.double , 3.char\n");
		scanf("%d",&select);
		if(select == 1){
			return sizeof(int);
		}else if (select == 2){
			return sizeof(double);
		}else if (select == 3){
			return sizeof(char);
		}else{
			select = 0;
			printf("����������\n");
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
			case '1': //��ʼ������ 
			if(f == 1){
				printf("���ж��У��������پɶ���\n");
				system("pause");
				system("cls");
				break;
			} 
			InitLQueue(Q);
			datasize = gettype();
			printf("ѡ�����\n");
			f = 1;
			system("pause");
			system("cls");
			break;						 
			case '2': //���
			//�ж��Ƿ��ʼ�� 
			if(f == 0){
				printf("��δ��ʼ����û�ж���\n");
				system("pause");
				system("cls");
				break;
			}	
				void *data = (void*)malloc(sizeof(datasize));
				if(datasize == sizeof(int)){
					printf("����������ӵ����ݣ�\n");
					scanf("%d",data);
				}else if(datasize == sizeof(double)){
					printf("���븡��������ӵ����ݣ�\n");
					scanf("%f",data);
				} else if(datasize == sizeof(char)){
					printf("�����ַ���ӵ����ݣ�\n");
					scanf_s("%c",data);
				} 
				if(EnLQueue(Q, data)){
					printf("��ӳɹ�\n");
				}else if(!EnLQueue(Q, &data)){
					printf("���ʧ��\n");
				}
			system("pause");
			system("cls");
			break;
			case '3': //���Ӳ��� 
			if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			status = DeLQueue(Q);
			if(status == TRUE){
				printf("���ӳɹ�\n");
			}
			system("pause");
			system("cls");
			break;
			
			case '4': {
				if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			//���г���
			int leng = LengthLQueue(Q);
			printf("���г���Ϊ%d\n",leng); 
			system("pause");
			system("cls");
			break;
			}
			
			case '5': //��������
			if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			TraverseLQueue(Q, LPrint);
			system("pause");
			system("cls");
			break;
			case '6': //��ն���
			if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			ClearLQueue(Q);
			printf("������\n");
			system("pause");
			system("cls"); 
			break;
			case '7': //���ٶ���
			if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			DestoryLQueue(Q);
			printf("�������\n");
			f = 0;
			system("pause");
			system("cls"); 
			break;
			case '8': //�ж϶����Ƿ�Ϊ��
			if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			if(IsEmptyLQueue(Q)){
				printf("Ϊ��\n");
			}else {
				printf("��Ϊ��\n");
			}
			system("pause");
			system("cls");
			break; 
			case '9': {//���ͷԪ��
			if(f == 0){
				printf("��δ��ʼ�����У�û�ж���\n");
				system("pause");
				system("cls");
				break;
			}
			void *e=(void*)malloc(sizeof(datasize));
			GetHeadLQueue(Q, e);
			printf("��Ԫ�صģ�\n"); 
			LPrint(e);
			system("pause");
			system("cls");
			break;
			}
			case '0': //�˳�ϵͳ
			printf("��ӭ�´��ټ�\n");
			return;
			default : 
			printf("����������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
} 
