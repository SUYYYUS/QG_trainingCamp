#include <stdio.h>
#include <stdlib.h>
#include"binary_sort_tree.h"
//07/04/24 15:37
//主菜单
void welcome(){
	printf("*-------------------------------*\n");
	printf("|\t第四周大组作业\t\t|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.创建一个二叉树\t|\n");
	printf("|\t2.插入数据\t\t|\n");
	printf("|\t3.查找数据\t\t|\n");
	printf("|\t4.删除数据\t\t|\n"); 
	printf("|\t5.三序遍历（递归）\t|\n");
	printf("|\t6.三序遍历（非递归）\t|\n");
	printf("|\t7.层次遍历      \t|\n");
	printf("|\t8.退出系统\t\t|\n");  
	//printf("|\t9.退出系统\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n");
} 

//6菜单
void welcome6(){
	printf("*-------------------------------*\n");
	printf("|\t1.先序遍历\t\t|\n");
	printf("|\t2.中序遍历\t\t|\n");
	printf("|\t3.后序遍历\t\t|\n");
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n");
}


//初始化一个跟根节点 
Status BST_init(BinarySortTreePtr head){
	head->root = NULL;
	printf("success\n"); 
	return true;	 
}

//找到当前叶节点的符合要插入的位置
Node* findlast(Node *temp, ElemType e){
	if(temp->value > e && temp->left != NULL){
		return findlast(temp->left, e);
	}else if(temp->value > e && temp->left == NULL){
		return temp;
	}else if(temp->value < e && temp->right != NULL){
		return findlast(temp->right, e);
	}else if(temp->value < e && temp->right == NULL){
		return temp;
	}else if(temp->value == e){
		return NULL;
	}
}

//二叉排序树的插入 
Status BST_insert(BinarySortTreePtr head, ElemType e){
	//判断是否初始化
	if(head == NULL){
		printf("还没有一颗树\n");
		return false;
	}
	//若是为头节点 
	if(head->root == NULL){
		head->root = (Node *)malloc(sizeof(Node));
		
		head->root->value = e;
		head->root->left = NULL;
		head->root->right = NULL;
		return true;
	}
	//寻找当前数的最底层叶节点 
	Node *temp = (Node *)malloc(sizeof(Node));
	temp = findlast(head->root,e);
	//插入新的叶子节点
	if(temp == NULL){
		printf("该数已存在\n");
		return false;
	}
	if(temp->value > e){
		temp->left = (Node *)malloc(sizeof(Node));
		if(temp->left == NULL){
			printf("失败\n");
			return false; 
		}
		temp->left->value = e;
		temp->left->left = NULL;
		temp->left->right = NULL;
		return true;
	}else if(temp->value < e){
		//Node *rchild = (Node *)malloc(sizeof(Node));
		//创建该新的叶节点 
		temp->right= (Node *)malloc(sizeof(Node));
		if(temp->right == NULL){
			printf("失败\n");
			return false; 
		}
		//完善新的叶节点 
		temp->right->value = e;
		temp->right->right = NULL;
		temp->right->left = NULL;
		return true;
	} 

	
}

//查询是否有该节点 
Node* search(Node *temp, ElemType e){
	while(temp!=NULL && e!= temp->value){
		if(e < temp->value){
			temp=temp->left;
		}
		else if (e > temp->value){
			temp = temp->right;
		}
	}
	if(temp == NULL){
		printf("没有该数字\n");
	} 
	else {
		printf("查找到了\n");
	}
	return temp;
}

//二叉排序数的查询 
Status BST_search(BinarySortTreePtr head, ElemType e){
	//判断是否初始化
	if(head == NULL){
		printf("还没有一颗树\n");
		return false;
	}
	//判断是否能找到该节点 
	Node *temp = (Node *)malloc(sizeof(Node));
	temp = search(head->root,e);
	
	if(temp == NULL){
		return false;
	}
	else{
		printf("you\n");
		return true;
	}
	
}

//打印数据
void visit(NodePtr temp){
	if(temp == NULL){
		return;
	}
	printf("%d\t",temp->value);
}

//先序遍历（递归）
Status BST_preorderR(NodePtr temp, void (*visit)(NodePtr)){
	if(temp == NULL){
		return true;
	}	
	visit(temp);
	BST_preorderR(temp->left, visit);
	BST_preorderR(temp->right, visit);
} 

//中序遍历（递归） 
Status BST_inorderR(NodePtr temp, void (*visit)(NodePtr)){
	if(temp == NULL){
		return true;
	}
	BST_preorderR(temp->left, visit);
	visit(temp);
	BST_preorderR(temp->right, visit);
}

//后序遍历（递归） 
Status BST_postorderR(NodePtr temp, void (*visit)(NodePtr)){
	if(temp == NULL){
		return true;
	}
	BST_preorderR(temp->left, visit);
	BST_preorderR(temp->right, visit);
	visit(temp);
}

//找到直接后继
Node * findson(NodePtr temp) {
	Node *son = (Node *)malloc(sizeof(Node));
	son = temp->right;
	while(son->left != NULL){
		son = son->left;
	}
	return son;
}

//二叉排序树的删除 
Status BST_delete(BinarySortTreePtr head, ElemType e){
	//判断是否初始化
	if(head == NULL){
		printf("还没有一颗树\n");
		return false;
	}
	
	Node *temp = head->root;
	Node *dad =  NULL;
	
	while(1){
		dad = temp;
		if(temp->value > e){
			temp = temp->left;
		}
		else if(temp->value < e){
			temp = temp->right;
		}
		else if(temp->value == e){
			break;
		}
	}
	
		if(temp == NULL){
		printf("没有该数字\n");
		return false;
	}
	
	//情况一：左右节点都有
	if(temp->left != NULL && temp->right != NULL){
		Node *q = temp;
	dad = temp;
	temp = temp->right;
	while(temp->left != NULL){
		dad = temp;
		temp = temp->left;
	} 
	q->value = temp->value;
	if(dad->left == temp){
		dad->left = temp->right;
		free(temp);
	}
	else if(dad->right == temp){
		dad->right = temp->right;
		free(temp);
	}
	return true;
	}
	
	//情况二：左右节点都没有
	if(temp->left == NULL && temp->right == NULL){
		if(temp == head->root){
			free(head->root);
		}
		if(dad->left == temp){
			dad->left = NULL;
			free(temp);
		} 
		else if(dad->right == temp){
			dad->right = NULL;
			free(temp);
		}
		return true;
	}
	
	//情况三要么有左节点，要么有右节点
	 //左
	 if(temp->left != NULL && temp->right == NULL){
	 	
		 if(head->root == temp){
	 		head->root = temp->left;
	 		temp->left = NULL;
	 		free(temp);
		 }
		 if(dad->left == temp){
		 	dad->left = temp->left;
		 	temp->left = NULL;
		 	free(temp);
		 }
		 else if(dad->right == temp){
		 	dad->right = temp->right;
		 	temp->left = NULL;
		 	free(temp);
		 }
		 return true;
	 }
	if(temp->left == NULL && temp->right !=NULL){
		
		if(head->root == temp){
			head->root = temp->right;
			temp->right = NULL;
			free(temp); 
		}
		if(dad->left == temp){
			dad->left = temp->right;
			temp->right = NULL;
			free(temp);
		} 
		else if(dad->right == temp){
			dad->right = temp->right;
			temp->right = NULL;
			free(temp);
		}
		return true;
	}
	
	
	
	
	
	
//	while(temp != NULL && e != temp->value){
//		//保存当前节点的父节点 
//		dad = temp;
//		if(e > temp->value){
//			temp = temp->right;
//		}else if(e < temp->value){
//			temp = temp->left;
//		}
//	}
//	//判断是否有符合删除的数字 
//	if(temp == NULL){
//		printf("没有该数字\n");
//		return false;
//	}
//	//1.情况一 ：要删除的节点为叶节点，没有子节点
//	if(temp->left == NULL && temp->right == NULL){
//		//为跟节点的时候 
//		if(dad == NULL){
//			temp = NULL;
//		}
//		//通过该节点的父节点来对该节点进行删除 
//		else if (dad->left == temp){
//			dad->left = NULL;
//		}else if(dad->right == temp){
//			dad->right = NULL;
//		}
//		free(temp);
//	}
//	//情况二：要么有左节点，要么有右节点
//	if(temp->left == NULL && temp->right != NULL){
//		if(dad == NULL){
//			head->root = temp->right;
//		}else if(dad->left == temp){
//			dad->left = temp->right;
//		}else if(dad->right == temp){
//			dad->right = temp->right;
//		}
//		free(temp);
//	}
//	if(temp->left != NULL && temp->right == NULL){
//		if(dad == NULL){
//			head->root = temp->left;
//		}else if(dad->left == temp){
//			dad->left = temp->left;
//		}else if(dad->right == temp){
//			dad->right = temp->left;
//		}
//		free(temp);
//	}
//	//情况三：要删除的节点既有左节点也有右节点
//	if(temp->left != NULL && temp->right != NULL){
//		//先找出直接后继
//		Node *son = findson(temp);
//		//把直接后继的值赋给要删除的那个地方 
//		temp->value = son->value;
//		if(son == temp->right){
//			temp->right = son->right;
//		}
//		else{
//            Node* dad = temp;
//            while(dad->left != son){
//                dad = dad->left;
//            }
//            dad->left = son->right; 
//        }
//        
//		free(son); 
//	}
	
	return true;
	
}

//初始化栈
Status initLStack(LinkStack *s){
	s = (LinkStack *)malloc(sizeof(LinkStack));
	if( s ==NULL){
		printf("failed\n");//开辟空间失败 
		return false;
	}
	//清空栈的数据
	s->top = NULL;
	s->count = 0;
	//printf("初始化成功\n");
	return true;
}

//入栈 
Status pushLStack(LinkStack *s,ElemType1 data){
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if(temp == NULL){
		printf("failed\n");
		return false;
	}
	temp->data = data;
	temp->next = s->top;
	s->top = temp;
	s->count++;
	return true;
} 

//出栈
Status popLStack(LinkStack *s,ElemType1 *data){
	if(isEmptyLStack(s)){
		printf("空栈\n");
		return false;
	} else {
		StackNode* temp = (StackNode*)malloc(sizeof(StackNode*));
		temp = s->top;
		*data = temp->data;
		s->top = s->top->next;
		s->count--;
		free(temp);
		return true;
	}
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if( s->count ==0 )
	{
		return true;
	}else {
	  return false;	
	}
}

//清空栈
Status clearLStack(LinkStack *s){
	
	if(isEmptyLStack(s) == true){
		printf("当前栈已空\n");
		return false;
	}else {
		//从栈顶一个一个删除
		while(s->top != NULL){
		struct StackNode * temp = s->top;
		s->top = s->top->next;
		free(temp);
		} 
		//计数器归零 
		s->count = 0;
		return true; 
	}
}


//销毁栈
Status destroyLStack(LinkStack *s){
	if(isEmptyLStack(s) == false){
		//先清空 
		clearLStack(s);
	}
	LinkStackPtr temp = s->top;
	free(temp);
	s->top = NULL;
	//printf("11111\n");
	return true;
}

//先序遍历（非递归） 
Status BST_preorderI(BinarySortTreePtr head, void (*visit)(NodePtr)){
	Node *temp = head->root;
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	//初始化栈 
	initLStack(s);
	
	while(temp != NULL || !isEmptyLStack(s)){

		while (temp != NULL)
		{
			//先把根打印出来 
			visit(temp);
			//一直沿着左边入栈 
			pushLStack(s, temp);
			temp = temp->left;
		}
		// 左节点遍历完成 取栈顶 找右节点 
		if (!isEmptyLStack(s))
		{
			popLStack(s, &temp);
			temp = temp->right;
			//再把右节点中的偏左节点来遍历 
		}
	}
	//销毁栈 
	destroyLStack(s);
	return true;
	
}

//中序遍历（非递归）
Status BST_inorderI(BinarySortTreePtr head, void (*visit)(NodePtr)){
	Node *temp = head->root;
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));

	initLStack(s);
	while(temp != NULL && !isEmptyLStack(s)){
		while(temp != NULL){
			pushLStack(s, temp);
			temp = temp->left;
		}
		if(!isEmptyLStack(s)){
			//打印根值
			 popLStack(s, &temp);
			visit(temp);
			
			temp = temp->right;
		}
	}
	destroyLStack(s);
	return true; 
} 

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType1 *e){
	if(s == NULL || s->top == NULL){
		//printf("此为空栈\n");
		return false;
	}
		*e = s->top->data;
		//printf("该栈顶数据为：%d\n",*e);
		return true;
}



//后序遍历（非递归） 
Status BST_postorderI(BinarySortTreePtr head, void (*visit)(NodePtr)){
	Node *temp = head->root;
	Node *p = temp;
	int i = -1;
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	
	//ElemType1 *data = (ElemType1 *)malloc(sizeof(ElemType1));
	initLStack(s);
	
	//根节点入栈 
	pushLStack(s, temp);
//	while(i > -1){
//		popLStack(s, &temp);
//		i--;
//		pushLStack(s, temp);
//		
//		if(temp->left != NULL){
//			pushLStack(s, temp->left);
//			i++;
//		}else if (temp->right != NULL){
//			pushLStack(s, temp->right);
//			i++;
//		}	
//		
//	}
	
	while(!isEmptyLStack(s)){
		getTopLStack(s, &temp);
		if((temp->left == NULL && temp->right == NULL) || (p == temp->left || p ==temp->right)){
			visit(temp);
			popLStack(s, &temp);
			p = temp;
		}
		else{
			if(temp->left != NULL){
				pushLStack(s, temp->left);
			}
			if(temp->right != NULL){
				pushLStack(s, temp->right);
			} 
		}
	}
	
	destroyLStack(s);
	return true;
}


//初始化队列
void InitLQueue(LQueue *Q){
//	LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode));
//	Q->front = Q->rear = head;
//	Q->front->next = Q->rear->next = NULL;
//	Q->front->data = Q->rear->data = NULL;
//	Q->length = 0;
//	printf("初始化成功\n");
LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	head->next = NULL;
	head->data = NULL;
	Q->front = Q->rear = head;
}

//判断是否为空
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		return true;
	}else{
		return false;
	}
}

//入队操作 
Status EnLQueue(LQueue *Q, ElemType1 data){
	//开辟空间 
	LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));
	if( temp == NULL){
		return false;
	}
	//temp->data = (void*)malloc(datasize);
	//memcpy(temp->data, data, datasize);
	temp->data = data;
	temp->next = NULL;
	Q->rear->next = temp;
	Q->rear = temp;
	Q->length++;
	return true;
}

//出队操作 
Status DeLQueue(LQueue *Q){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		return false;
	}
	//LinkNode* temp = (LinkNode *)malloc(sizeof(LinkNode));
	LinkNode* temp = Q->front->next;
	//temp = Q->front->next;
	Q->front->next = temp->next;
	if(Q->rear == temp){
		Q->front = Q->rear;
	}
	Q->length--;
	free(temp);
	//temp = NULL;
	return true;
}

//获取首元素 
Status GetHeadLQueue(LQueue *Q, ElemType1 *e){
	//判断是否为空
	if(IsEmptyLQueue(Q)){
		printf("空\n");
		return false;
	}
	*e = Q->front->next->data;

		return true;

}

//// 销毁队列
//void DestoryLQueue(LQueue* Q) {
//	ClearLQueue(Q);
//	free(Q->front);
//	Q->front = Q->rear = NULL;
//}
//
//// 清空队列
//void ClearLQueue(LQueue* Q) {
//	while (DeLQueue(Q));
//}

//层次遍历
Status BST_levelOrder(BinarySortTreePtr head, void (*visit)(NodePtr)){
	LQueue *Q = (LQueue *)malloc(sizeof(LQueue));
	InitLQueue(Q);
	
	Node *temp = head->root;
	if(head->root == NULL){
		return false;
	}
	//入队
	 EnLQueue(Q, temp);
	 while(!IsEmptyLQueue(Q))
	 {
	 	GetHeadLQueue(Q, &temp);
	 	DeLQueue(Q);
	 	visit(temp);
	 	if(temp->left != NULL){
	 		EnLQueue(Q, temp->left);
		 }
		 if(temp->right != NULL){
		 	EnLQueue(Q, temp->right);
		 }
	 }
	 // DestoryLQueue(Q);
	 return true;
} 


int main() {
	int num;
	int i;
	int n;
	Status status;
	BinarySortTree* head = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	int flag = 0;
	//初始化根节点
	
	while(1){
		welcome();
		char s = getch();
		switch(s){
			case '1': //初始化树
			if(flag == 1){
				printf("已经有树了\n");
			}else{
			status = BST_init(head);
   			if(status == true){
   			printf("初始化成功\n");
   			flag = 1;
   			}else{
   			printf("初始化失败\n");
	   		}
			}			 
	   		system("pause");
	   		system("cls");
	   		break;
	   		case '2': //插入数据
	   		if(flag == 0){
	   			printf("还没有树，请先种一头树\n");
			   }else{
			   	printf("您想插入几个数据：\n");
			 scanf("%d",&n);
			 for(i = 0; i<n ;i++){
			 	printf("输入想要插入的数字：\n");
				scanf("%d",&num);
				status = BST_insert(head,num);
				if(status == true){
   				printf("插入成功\n");
   				}else{
   				printf("插入失败\n");
				i--;
	   			}
			 }
			 }
			system("pause");
	   		system("cls");
	   		break; 
			 case '3': //查询数据
			 if(flag == 0){
	   			printf("还没有树，请先种一头树\n");
			   }else{
			   	printf("输入你想要查找的数据：\n");
			 scanf("%d",&num);
			 BST_search(head, num);
			} 
			system("pause");
	   		system("cls");
			break;  
			case '4'://删除数据
			if(flag == 0){
	   			printf("还没有树，请先种一头树\n");
			   }else{
			   	printf("输入想删除的数字:\n");
				scanf("%d",&num);
				status = BST_delete(head, num);
				if(status == true){
					printf("删除成功\n");
				} 
			   }
			system("pause");
	   		system("cls");
			break;
			case '5': //三序遍历递归
			if(flag == 0){
	   			printf("还没有树，请先种一头树\n");
			   }else{
			   	printf("先序遍历:\n");
	BST_preorderR(head->root, visit);
	printf("\n"); 
	printf("=================================\n");
	printf("中序遍历:\n");
	BST_inorderR(head->root, visit);
	printf("\n");
	printf("=================================\n");
	printf("后序遍历:\n");
	BST_postorderR(head->root, visit);
	printf("\n");
	printf("=================================\n");
			   }
			 system("pause");
	   		system("cls");
			break;
			case '6' : //三序遍历非递归
			 if(flag == 0){
	   			printf("还没有树，请先种一头树\n");
			   }else{
			   	system("cls");
			   	welcome6();
				   char s6 = getch();
				   switch(s6){
				   	case '1':
				   		printf("先序遍历:\n");
							BST_preorderI(head, visit); 
							printf("\n");
							printf("=================================\n");
							break;
							case '2':
							 printf("中序遍历:\n");
							BST_inorderI(head, visit);
							printf("\n");
							printf("=================================\n");
							break;
							case '3':
							printf("后序遍历:\n");
							BST_postorderI(head, visit);
							printf("\n");
							printf("=================================\n");
							break;	
				   } 
			   	printf("还没完成，有漏洞\n");
			   }
			 system("pause");
	   		system("cls");
			break;
			case '7' ://层次遍历
			if(flag == 0){
				printf("还没有树，请先种一头树\n");
			}else {
				printf("若遍历的数不完全，请多执行几次即可\n"); 
				printf("层次遍历\n");
				BST_levelOrder(head, visit);
				//printf("进入死循环了\n");
				printf("\n");
			}
			 
			 system("pause");
	   		system("cls");
			break;
			 
			case '8': //退出系统
			printf("欢迎下次再见\n");
			return ;
			default ://输入错误
			printf("请重新输入\n");
			system("pause");
	   		system("cls");
			break; 
		} 
	}
	
	
	
	


	
//	
//   	status = BST_init(head);
//   	if(status == true){
//   		printf("初始化成功\n");
//   	}else{
//   		printf("初始化失败\n");
//	   }
//	for(i = 0;i<5;i++){
//	printf("输入想要插入的数字：\n");
//	scanf("%d",&num);
//	status = BST_insert(head,num);
//	if(status == true){
//   		printf("插入成功\n");
//   	}else{
//   		printf("插入失败\n");
//		i--;
//	   }
//	}
//	printf("=================================\n");
//	printf("输入想查询的数字:\n");
//	scanf("%d",&num);
//	BST_search(head, num);
//	printf("=================================\n");
	//printf("先序遍历:\n");
	//BST_preorderR(head->root, visit);
	//printf("\n"); 
	//printf("=================================\n");
	//printf("中序遍历:\n");
	//BST_inorderR(head->root, visit);
	//printf("\n");
	//printf("=================================\n");
	//printf("后序遍历:\n");
	//BST_postorderR(head->root, visit);
	//printf("\n");
	//printf("=================================\n");
	//printf("=================================\n");
//	printf("=================================\n");//
	//printf("输入想删除的数字:\n");
	//scanf("%d",&num);
	///BST_delete(head, num);
	//BST_postorderR(head->root, visit);
	//printf("\n");
//	printf("=================================\n");
//	printf("非递归\n");
//	BST_preorderI(head, visit);
//	printf("\n");
//	printf("=================================\n");
//	printf("=================================\n");
//	printf("=================================\n");//
//	
//	//BST_postorderI(head, visit);
//   	printf("Hello, World!\n");
//    BST_levelOrder(head, visit);
//    system("pause");
    return 0;
}
