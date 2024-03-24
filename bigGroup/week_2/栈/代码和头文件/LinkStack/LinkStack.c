#include"LinkStack.h"

//���˵�
void welcome(){
	printf("*-----------------------*\n");
	printf("|\t�ڶ��ܴ�����ҵ\t|\n");
	printf("*-----------------------*\n");
	printf("|\t1.��ʼ��ջ\t|\n");
	printf("|\t2.��ջ����\t|\n");
	printf("|\t3.��ջ����\t|\n");
	printf("|\t4.ջ�Ƿ��\t|\n"); 
	printf("|\t5.��ȡջ��Ԫ��\t|\n");
	printf("|\t6.���ջ�ĳ���\t|\n");
	printf("|\t7.���ջ     \t|\n"); 
	printf("|\t8.����ջ\t|\n");
	printf("|\t9.�˳�ϵͳ\t|\n");
	printf("*-----------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
} 

//��ʼ��ջ
Status initLStack(LinkStack **s){
	*s = (LinkStack *)malloc(sizeof(LinkStack));
	if( *s ==NULL){
		printf("failed\n");//���ٿռ�ʧ�� 
		return ERROR;
	}
	//���ջ������
	(*s)->top = NULL;
	(*s)->count = 0;
	//printf("��ʼ���ɹ�\n");
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if( s->count ==0 ){
		return SUCCESS;
	}else {
	  return ERROR;	
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s == NULL || s->top == NULL){
		//printf("��Ϊ��ջ\n");
		return ERROR;
	}
		*e = s->top->data;
		printf("��ջ������Ϊ��%d\n",*e);
		return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(isEmptyLStack(s) == SUCCESS){
		printf("��ǰջ�ѿ�\n");
		return ERROR;
	}else {
		//��ջ��һ��һ��ɾ��
		while(s->top != NULL){
			struct StackNode * temp = s->top;
		s->top = s->top->next;
		free(temp);
		} 
		//���������� 
		s->count = 0;
		return SUCCESS; 
	}
}

//����ջ
Status destroyLStack(LinkStack *s){
	if(isEmptyLStack(s) == ERROR){
		//����� 
		clearLStack(s);
	}
	free(s);
	//printf("11111\n");
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(isEmptyLStack(s) == SUCCESS){
		printf("��Ԫ��\n");
		return ERROR; 
	}
	*length = s->count;
	printf("ջ�ĳ���Ϊ��%d\n",*length); 
	return SUCCESS;
}

//��ջ 
Status pushLStack(LinkStack *s,ElemType data){
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if(temp == NULL){
		printf("failed\n");
		return ERROR;
	}
	temp->data = data;
	temp->next = s->top;
	s->top = temp;
	s->count++;
	return SUCCESS;
} 

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s)){
		printf("��ջ\n");
		return ERROR;
	} else {
		StackNode* temp = (StackNode*)malloc(sizeof(StackNode*));
		temp = s->top;
		*data = temp->data;
		s->top = s->top->next;
		free(temp);
		s->count--;
		return SUCCESS;
	}
}

int main(){
	ElemType *e = (ElemType *)malloc(sizeof(ElemType ));
	LinkStack *s ;
	ElemType *data =(ElemType *)malloc(sizeof(ElemType ));
	int *length = (int *)malloc(sizeof(int));
	int d;
	int flag = 0;
	while(1){
		welcome();
		char k = getch();
		switch(k){
			case '1': //��ʼ��ջ
				if(initLStack(&s)){
					printf("��ʼ���ɹ�\n");
					flag = 1; 
				}
				system("pause");
				system("cls");
				break;
			case '2' : //��ջ
				if(flag == 0){
					printf("��δ��ʼ��\n");
					system("pause");
					system("cls");
					break;
				}
				printf("���������ݣ�\n");
				scanf("%d",&d);
				if(pushLStack(s, d)){
					printf("��ջ�ɹ�\n");
				}
				system("pause");
				system("cls");
			  	break;
			case '3': //��ջ
				popLStack(s,data);
				int ret = *data;
				printf("������Ϊ��%d\n",ret);
				system("pause");
				system("cls");
			  	break;
			case '4': //�Ƿ��ջ
			if(isEmptyLStack(s)) {
				printf("ջΪ��\n");
			}else {
				printf("��Ϊ��ջ\n");
			}
			system("pause");
				system("cls");
			  	break;
			case '5': // ��ȡջ��Ԫ��
				getTopLStack(s,e); 
				system("pause");
				system("cls");
			  	break;
			case '6'://���ջ����
					LStackLength(s,length);
					system("pause");
				system("cls");
			  	break;
			case '7': //���ջ
			  		if(clearLStack(s)){
			  		printf("������\n");
				  	}else {
				  	printf("���ʧ��\n"); 
				  	} 
				  	system("pause");
					system("cls");
					break;
					case '8': //����ջ 
					if(destroyLStack(s)){
						printf("���ٳɹ�\n");
					}else {
						printf("����ʧ��\n");
					}
				   	system("pause");
					system("cls");
					break;
					case '9': //�˳�
					printf("�ɹ��˳�ϵͳ\n");
					return ;
					default: // �������
					printf("��������\n");
					system("pause");
					system("cls");
					break; 
		}
	}
	 
	
	return 0;
}
