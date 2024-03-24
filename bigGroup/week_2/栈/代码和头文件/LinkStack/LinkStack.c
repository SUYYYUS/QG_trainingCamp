#include"LinkStack.h"

//主菜单
void welcome(){
	printf("*-----------------------*\n");
	printf("|\t第二周大组作业\t|\n");
	printf("*-----------------------*\n");
	printf("|\t1.初始化栈\t|\n");
	printf("|\t2.入栈操作\t|\n");
	printf("|\t3.出栈操作\t|\n");
	printf("|\t4.栈是否空\t|\n"); 
	printf("|\t5.获取栈顶元素\t|\n");
	printf("|\t6.检测栈的长度\t|\n");
	printf("|\t7.清空栈     \t|\n"); 
	printf("|\t8.销毁栈\t|\n");
	printf("|\t9.退出系统\t|\n");
	printf("*-----------------------*\n");
	printf("请选择想要执行的功能：\t\n");
} 

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
		printf("该栈顶数据为：%d\n",*e);
		return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	if(isEmptyLStack(s) == SUCCESS){
		printf("当前栈已空\n");
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
			case '1': //初始化栈
				if(initLStack(&s)){
					printf("初始化成功\n");
					flag = 1; 
				}
				system("pause");
				system("cls");
				break;
			case '2' : //入栈
				if(flag == 0){
					printf("还未初始化\n");
					system("pause");
					system("cls");
					break;
				}
				printf("请输入数据：\n");
				scanf("%d",&d);
				if(pushLStack(s, d)){
					printf("入栈成功\n");
				}
				system("pause");
				system("cls");
			  	break;
			case '3': //出栈
				popLStack(s,data);
				int ret = *data;
				printf("该数据为：%d\n",ret);
				system("pause");
				system("cls");
			  	break;
			case '4': //是否空栈
			if(isEmptyLStack(s)) {
				printf("栈为空\n");
			}else {
				printf("不为空栈\n");
			}
			system("pause");
				system("cls");
			  	break;
			case '5': // 获取栈顶元素
				getTopLStack(s,e); 
				system("pause");
				system("cls");
			  	break;
			case '6'://检测栈长度
					LStackLength(s,length);
					system("pause");
				system("cls");
			  	break;
			case '7': //清空栈
			  		if(clearLStack(s)){
			  		printf("清空完成\n");
				  	}else {
				  	printf("清空失败\n"); 
				  	} 
				  	system("pause");
					system("cls");
					break;
					case '8': //销毁栈 
					if(destroyLStack(s)){
						printf("销毁成功\n");
					}else {
						printf("销毁失败\n");
					}
				   	system("pause");
					system("cls");
					break;
					case '9': //退出
					printf("成功退出系统\n");
					return ;
					default: // 输入错误
					printf("输入有误\n");
					system("pause");
					system("cls");
					break; 
		}
	}
	 
	
	return 0;
}
