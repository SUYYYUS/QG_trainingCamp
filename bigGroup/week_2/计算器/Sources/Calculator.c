#include"Calculator.h" 



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
		//printf("������Ϊ��%d\n",*e);
		return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack *s){
	if(isEmptyLStack(s) == SUCCESS){
		//printf("��ǰջ�ѿ�\n");
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


//�ж�����������ȼ�
int priority(char operator){
	if(operator == '+' || operator == '-'){
		return 1;
	}else if (operator == '*' || operator == '/'){
		return 2;
	}else {
		return 0;
	}
}

//��������
double ret (char operator, double number1, double number2){
	switch(operator){
		case '+':
			return number2 + number1;
		case '-':
			return number2 - number1;
		case '*':
			return number2 * number1;
		case '/':
			if(number1 == 0){
				printf("not\n");
				return ;
			}
			return number2 / number1;
		default: 
			return 0;	
	}
} 

// �������ջ
Status charpushLStack(LinkStack* s, char data){
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

// �������ջ
Status charpopLStack(LinkStack* s, char* data){
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

// ������õ�ջ��Ԫ��
Status chargetTopLStack(LinkStack* s, char* e){
	if(s == NULL || s->top == NULL){
		//printf("��Ϊ��ջ\n");
		return ERROR;
	}
		*e = s->top->data;
		//printf("������Ϊ��%d\n",*e);
		return SUCCESS;
}




double calculate(char* expression){
	//��ʼ��������ջ
	int i = 0;
	LinkStack *operator;
	LinkStack *number;
	initLStack(&operator);
	initLStack(&number);
	ElemType *e =(ElemType *)malloc(sizeof(ElemType));
	ElemType *data = (ElemType *)malloc(sizeof(ElemType));
	
	//===========================
	while(expression[i] != '\0'){
		//�жϿո�
		if(expression[i] == ' '){
			continue ;
		} else if(expression[i] >= '0' && expression[i] <= '9' ){
			double a = 0;
			
			while(expression[i] >= '0' && expression[i] <= '9' ){
				a = a*10 + (expression[i] - '0');
				i++;
			}
			//printf("a======%f\n",a);
			pushLStack(number, a);//�������� 
		} else {
			if(expression[i] == '('){
			charpushLStack(operator, expression[i]);//ѹ�������� 
		} else if(expression[i] == ')'){
			//��ȡջ��Ԫ�� 
			chargetTopLStack(operator,e);
			while(*e != '('){
				charpopLStack(operator,data);
				char s = *data;
				popLStack(number,data);
				double num1 = *data;
				popLStack(number,data);
				double num2 = *data;
				pushLStack(number,ret(s,num1,num2));
				chargetTopLStack(operator,e);
			}
			//���������� 
			charpopLStack(operator,data);
		} else{
			chargetTopLStack(operator,e);
			while(isEmptyLStack(operator) == ERROR && priority(*e) >= priority(expression[i])){
				charpopLStack(operator,data);
				char s =  *data;
				popLStack(number,data);
				double num1 =  *data;
				popLStack(number,data);
				double num2 =  *data;
				pushLStack(number,ret(s,num1,num2));
				chargetTopLStack(operator,e);
			}
			charpushLStack(operator,expression[i]);
		}
			i++;
		}
	}
	
	while(isEmptyLStack(operator) == ERROR){
				charpopLStack(operator,data);
				char s =  *data;
				popLStack(number,data);
				double num1 =  *data;
				popLStack(number,data);
				double num2 =  *data;
				pushLStack(number,ret(s,num1,num2));
				}
	popLStack(number,data);
	double result = *data;
    destroyLStack(operator);
    destroyLStack(number);
	return result;
}


int main(){
	int n ;
	Status status;
	char expression[100];
	while(1){
		printf("=========ע��========\n");
		printf("��������Ӣ�����뷨!!!\n");
		printf("�����Է��ſ�ͷ!!!\n");
		printf("��֧�ָ���������!!!\n");
		printf("����������ĸ�˳�~~~\n"); 
		printf("=====================\n");
	printf("��������ȷ�ı��ʽ��\n");
	scanf("%s",expression);
	for(n=0;expression[n]!='\0';n++){
		if((expression[n]<'0' || expression[n]>'9') 
		&& expression[n] !='+' && expression[n] !='-' 
		&& expression[n] !='/' && expression[n] !='*' 
		&& expression[n] !='(' && expression[n] !=')'){
			printf("����\n");
			
			return;
		}
	}
	double need = calculate(expression);
	printf("������Ϊ��\n%f\n",need);
	system("pause");
	system("cls");
	}

	return 0;
}
