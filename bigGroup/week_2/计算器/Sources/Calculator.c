#include"Calculator.h" 



//初始化栈
Status initLStack(LinkStack **s){
	*s = (LinkStack *)malloc(sizeof(LinkStack));
	if( *s ==NULL){
		printf("failed\n");//开辟空间失败 
		return ERROR;
	}
	//清空栈的数据
	(*s)->top = NULL;
	(*s)->count = 0;
	//printf("初始化成功\n");
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if( s->count ==0 ){
		return SUCCESS;
	}else {
	  return ERROR;	
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s == NULL || s->top == NULL){
		//printf("此为空栈\n");
		return ERROR;
	}
		*e = s->top->data;
		//printf("该数据为：%d\n",*e);
		return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	if(isEmptyLStack(s) == SUCCESS){
		//printf("当前栈已空\n");
		return ERROR;
	}else {
		//从栈顶一个一个删除
		while(s->top != NULL){
			struct StackNode * temp = s->top;
		s->top = s->top->next;
		free(temp);
		} 
		//计数器归零 
		s->count = 0;
		return SUCCESS; 
	}
}

//销毁栈
Status destroyLStack(LinkStack *s){
	if(isEmptyLStack(s) == ERROR){
		//先清空 
		clearLStack(s);
	}
	free(s);
	//printf("11111\n");
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(isEmptyLStack(s) == SUCCESS){
		printf("无元素\n");
		return ERROR; 
	}
	*length = s->count;
	printf("栈的长度为：%d\n",*length); 
	return SUCCESS;
}

//入栈 
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

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(isEmptyLStack(s)){
		printf("空栈\n");
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


//判断运算符的优先级
int priority(char operator){
	if(operator == '+' || operator == '-'){
		return 1;
	}else if (operator == '*' || operator == '/'){
		return 2;
	}else {
		return 0;
	}
}

//进行运算
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

// 运算符入栈
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

// 运算符出栈
Status charpopLStack(LinkStack* s, char* data){
	if(isEmptyLStack(s)){
		printf("空栈\n");
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

// 运算符得到栈顶元素
Status chargetTopLStack(LinkStack* s, char* e){
	if(s == NULL || s->top == NULL){
		//printf("此为空栈\n");
		return ERROR;
	}
		*e = s->top->data;
		//printf("该数据为：%d\n",*e);
		return SUCCESS;
}




double calculate(char* expression){
	//初始化两个链栈
	int i = 0;
	LinkStack *operator;
	LinkStack *number;
	initLStack(&operator);
	initLStack(&number);
	ElemType *e =(ElemType *)malloc(sizeof(ElemType));
	ElemType *data = (ElemType *)malloc(sizeof(ElemType));
	
	//===========================
	while(expression[i] != '\0'){
		//判断空格
		if(expression[i] == ' '){
			continue ;
		} else if(expression[i] >= '0' && expression[i] <= '9' ){
			double a = 0;
			
			while(expression[i] >= '0' && expression[i] <= '9' ){
				a = a*10 + (expression[i] - '0');
				i++;
			}
			//printf("a======%f\n",a);
			pushLStack(number, a);//存入数字 
		} else {
			if(expression[i] == '('){
			charpushLStack(operator, expression[i]);//压入左括号 
		} else if(expression[i] == ')'){
			//获取栈顶元素 
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
			//弹出左括号 
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
		printf("=========注意========\n");
		printf("括号须用英文输入法!!!\n");
		printf("不能以符号开头!!!\n");
		printf("不支持浮点数运算!!!\n");
		printf("输入任意字母退出~~~\n"); 
		printf("=====================\n");
	printf("请输入正确的表达式：\n");
	scanf("%s",expression);
	for(n=0;expression[n]!='\0';n++){
		if((expression[n]<'0' || expression[n]>'9') 
		&& expression[n] !='+' && expression[n] !='-' 
		&& expression[n] !='/' && expression[n] !='*' 
		&& expression[n] !='(' && expression[n] !=')'){
			printf("有误\n");
			
			return;
		}
	}
	double need = calculate(expression);
	printf("计算结果为：\n%f\n",need);
	system("pause");
	system("cls");
	}

	return 0;
}
