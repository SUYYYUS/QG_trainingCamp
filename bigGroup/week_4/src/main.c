#include <stdio.h>
#include <stdlib.h>
#include"binary_sort_tree.h"
//07/04/24 15:37
//���˵�
void welcome(){
	printf("*-------------------------------*\n");
	printf("|\t�����ܴ�����ҵ\t\t|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.����һ��������\t|\n");
	printf("|\t2.��������\t\t|\n");
	printf("|\t3.��������\t\t|\n");
	printf("|\t4.ɾ������\t\t|\n"); 
	printf("|\t5.����������ݹ飩\t|\n");
	printf("|\t6.����������ǵݹ飩\t|\n");
	printf("|\t7.��α���      \t|\n");
	printf("|\t8.�˳�ϵͳ\t\t|\n");  
	//printf("|\t9.�˳�ϵͳ\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
} 

//6�˵�
void welcome6(){
	printf("*-------------------------------*\n");
	printf("|\t1.�������\t\t|\n");
	printf("|\t2.�������\t\t|\n");
	printf("|\t3.�������\t\t|\n");
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
}


//��ʼ��һ�������ڵ� 
Status BST_init(BinarySortTreePtr head){
	head->root = NULL;
	printf("success\n"); 
	return true;	 
}

//�ҵ���ǰҶ�ڵ�ķ���Ҫ�����λ��
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

//�����������Ĳ��� 
Status BST_insert(BinarySortTreePtr head, ElemType e){
	//�ж��Ƿ��ʼ��
	if(head == NULL){
		printf("��û��һ����\n");
		return false;
	}
	//����Ϊͷ�ڵ� 
	if(head->root == NULL){
		head->root = (Node *)malloc(sizeof(Node));
		
		head->root->value = e;
		head->root->left = NULL;
		head->root->right = NULL;
		return true;
	}
	//Ѱ�ҵ�ǰ������ײ�Ҷ�ڵ� 
	Node *temp = (Node *)malloc(sizeof(Node));
	temp = findlast(head->root,e);
	//�����µ�Ҷ�ӽڵ�
	if(temp == NULL){
		printf("�����Ѵ���\n");
		return false;
	}
	if(temp->value > e){
		temp->left = (Node *)malloc(sizeof(Node));
		if(temp->left == NULL){
			printf("ʧ��\n");
			return false; 
		}
		temp->left->value = e;
		temp->left->left = NULL;
		temp->left->right = NULL;
		return true;
	}else if(temp->value < e){
		//Node *rchild = (Node *)malloc(sizeof(Node));
		//�������µ�Ҷ�ڵ� 
		temp->right= (Node *)malloc(sizeof(Node));
		if(temp->right == NULL){
			printf("ʧ��\n");
			return false; 
		}
		//�����µ�Ҷ�ڵ� 
		temp->right->value = e;
		temp->right->right = NULL;
		temp->right->left = NULL;
		return true;
	} 

	
}

//��ѯ�Ƿ��иýڵ� 
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
		printf("û�и�����\n");
	} 
	else {
		printf("���ҵ���\n");
	}
	return temp;
}

//�����������Ĳ�ѯ 
Status BST_search(BinarySortTreePtr head, ElemType e){
	//�ж��Ƿ��ʼ��
	if(head == NULL){
		printf("��û��һ����\n");
		return false;
	}
	//�ж��Ƿ����ҵ��ýڵ� 
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

//��ӡ����
void visit(NodePtr temp){
	if(temp == NULL){
		return;
	}
	printf("%d\t",temp->value);
}

//����������ݹ飩
Status BST_preorderR(NodePtr temp, void (*visit)(NodePtr)){
	if(temp == NULL){
		return true;
	}	
	visit(temp);
	BST_preorderR(temp->left, visit);
	BST_preorderR(temp->right, visit);
} 

//����������ݹ飩 
Status BST_inorderR(NodePtr temp, void (*visit)(NodePtr)){
	if(temp == NULL){
		return true;
	}
	BST_preorderR(temp->left, visit);
	visit(temp);
	BST_preorderR(temp->right, visit);
}

//����������ݹ飩 
Status BST_postorderR(NodePtr temp, void (*visit)(NodePtr)){
	if(temp == NULL){
		return true;
	}
	BST_preorderR(temp->left, visit);
	BST_preorderR(temp->right, visit);
	visit(temp);
}

//�ҵ�ֱ�Ӻ��
Node * findson(NodePtr temp) {
	Node *son = (Node *)malloc(sizeof(Node));
	son = temp->right;
	while(son->left != NULL){
		son = son->left;
	}
	return son;
}

//������������ɾ�� 
Status BST_delete(BinarySortTreePtr head, ElemType e){
	//�ж��Ƿ��ʼ��
	if(head == NULL){
		printf("��û��һ����\n");
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
		printf("û�и�����\n");
		return false;
	}
	
	//���һ�����ҽڵ㶼��
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
	
	//����������ҽڵ㶼û��
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
	
	//�����Ҫô����ڵ㣬Ҫô���ҽڵ�
	 //��
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
//		//���浱ǰ�ڵ�ĸ��ڵ� 
//		dad = temp;
//		if(e > temp->value){
//			temp = temp->right;
//		}else if(e < temp->value){
//			temp = temp->left;
//		}
//	}
//	//�ж��Ƿ��з���ɾ�������� 
//	if(temp == NULL){
//		printf("û�и�����\n");
//		return false;
//	}
//	//1.���һ ��Ҫɾ���Ľڵ�ΪҶ�ڵ㣬û���ӽڵ�
//	if(temp->left == NULL && temp->right == NULL){
//		//Ϊ���ڵ��ʱ�� 
//		if(dad == NULL){
//			temp = NULL;
//		}
//		//ͨ���ýڵ�ĸ��ڵ����Ըýڵ����ɾ�� 
//		else if (dad->left == temp){
//			dad->left = NULL;
//		}else if(dad->right == temp){
//			dad->right = NULL;
//		}
//		free(temp);
//	}
//	//�������Ҫô����ڵ㣬Ҫô���ҽڵ�
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
//	//�������Ҫɾ���Ľڵ������ڵ�Ҳ���ҽڵ�
//	if(temp->left != NULL && temp->right != NULL){
//		//���ҳ�ֱ�Ӻ��
//		Node *son = findson(temp);
//		//��ֱ�Ӻ�̵�ֵ����Ҫɾ�����Ǹ��ط� 
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

//��ʼ��ջ
Status initLStack(LinkStack *s){
	s = (LinkStack *)malloc(sizeof(LinkStack));
	if( s ==NULL){
		printf("failed\n");//���ٿռ�ʧ�� 
		return false;
	}
	//���ջ������
	s->top = NULL;
	s->count = 0;
	//printf("��ʼ���ɹ�\n");
	return true;
}

//��ջ 
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

//��ջ
Status popLStack(LinkStack *s,ElemType1 *data){
	if(isEmptyLStack(s)){
		printf("��ջ\n");
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

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if( s->count ==0 )
	{
		return true;
	}else {
	  return false;	
	}
}

//���ջ
Status clearLStack(LinkStack *s){
	
	if(isEmptyLStack(s) == true){
		printf("��ǰջ�ѿ�\n");
		return false;
	}else {
		//��ջ��һ��һ��ɾ��
		while(s->top != NULL){
		struct StackNode * temp = s->top;
		s->top = s->top->next;
		free(temp);
		} 
		//���������� 
		s->count = 0;
		return true; 
	}
}


//����ջ
Status destroyLStack(LinkStack *s){
	if(isEmptyLStack(s) == false){
		//����� 
		clearLStack(s);
	}
	LinkStackPtr temp = s->top;
	free(temp);
	s->top = NULL;
	//printf("11111\n");
	return true;
}

//����������ǵݹ飩 
Status BST_preorderI(BinarySortTreePtr head, void (*visit)(NodePtr)){
	Node *temp = head->root;
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	//��ʼ��ջ 
	initLStack(s);
	
	while(temp != NULL || !isEmptyLStack(s)){

		while (temp != NULL)
		{
			//�ȰѸ���ӡ���� 
			visit(temp);
			//һֱ���������ջ 
			pushLStack(s, temp);
			temp = temp->left;
		}
		// ��ڵ������� ȡջ�� ���ҽڵ� 
		if (!isEmptyLStack(s))
		{
			popLStack(s, &temp);
			temp = temp->right;
			//�ٰ��ҽڵ��е�ƫ��ڵ������� 
		}
	}
	//����ջ 
	destroyLStack(s);
	return true;
	
}

//����������ǵݹ飩
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
			//��ӡ��ֵ
			 popLStack(s, &temp);
			visit(temp);
			
			temp = temp->right;
		}
	}
	destroyLStack(s);
	return true; 
} 

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType1 *e){
	if(s == NULL || s->top == NULL){
		//printf("��Ϊ��ջ\n");
		return false;
	}
		*e = s->top->data;
		//printf("��ջ������Ϊ��%d\n",*e);
		return true;
}



//����������ǵݹ飩 
Status BST_postorderI(BinarySortTreePtr head, void (*visit)(NodePtr)){
	Node *temp = head->root;
	Node *p = temp;
	int i = -1;
	LinkStack *s = (LinkStack *)malloc(sizeof(LinkStack));
	
	//ElemType1 *data = (ElemType1 *)malloc(sizeof(ElemType1));
	initLStack(s);
	
	//���ڵ���ջ 
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


//��ʼ������
void InitLQueue(LQueue *Q){
//	LinkNode *head = (LinkNode *)malloc(sizeof(LinkNode));
//	Q->front = Q->rear = head;
//	Q->front->next = Q->rear->next = NULL;
//	Q->front->data = Q->rear->data = NULL;
//	Q->length = 0;
//	printf("��ʼ���ɹ�\n");
LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	head->next = NULL;
	head->data = NULL;
	Q->front = Q->rear = head;
}

//�ж��Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		return true;
	}else{
		return false;
	}
}

//��Ӳ��� 
Status EnLQueue(LQueue *Q, ElemType1 data){
	//���ٿռ� 
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

//���Ӳ��� 
Status DeLQueue(LQueue *Q){
	//�ж��Ƿ�Ϊ��
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

//��ȡ��Ԫ�� 
Status GetHeadLQueue(LQueue *Q, ElemType1 *e){
	//�ж��Ƿ�Ϊ��
	if(IsEmptyLQueue(Q)){
		printf("��\n");
		return false;
	}
	*e = Q->front->next->data;

		return true;

}

//// ���ٶ���
//void DestoryLQueue(LQueue* Q) {
//	ClearLQueue(Q);
//	free(Q->front);
//	Q->front = Q->rear = NULL;
//}
//
//// ��ն���
//void ClearLQueue(LQueue* Q) {
//	while (DeLQueue(Q));
//}

//��α���
Status BST_levelOrder(BinarySortTreePtr head, void (*visit)(NodePtr)){
	LQueue *Q = (LQueue *)malloc(sizeof(LQueue));
	InitLQueue(Q);
	
	Node *temp = head->root;
	if(head->root == NULL){
		return false;
	}
	//���
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
	//��ʼ�����ڵ�
	
	while(1){
		welcome();
		char s = getch();
		switch(s){
			case '1': //��ʼ����
			if(flag == 1){
				printf("�Ѿ�������\n");
			}else{
			status = BST_init(head);
   			if(status == true){
   			printf("��ʼ���ɹ�\n");
   			flag = 1;
   			}else{
   			printf("��ʼ��ʧ��\n");
	   		}
			}			 
	   		system("pause");
	   		system("cls");
	   		break;
	   		case '2': //��������
	   		if(flag == 0){
	   			printf("��û������������һͷ��\n");
			   }else{
			   	printf("������뼸�����ݣ�\n");
			 scanf("%d",&n);
			 for(i = 0; i<n ;i++){
			 	printf("������Ҫ��������֣�\n");
				scanf("%d",&num);
				status = BST_insert(head,num);
				if(status == true){
   				printf("����ɹ�\n");
   				}else{
   				printf("����ʧ��\n");
				i--;
	   			}
			 }
			 }
			system("pause");
	   		system("cls");
	   		break; 
			 case '3': //��ѯ����
			 if(flag == 0){
	   			printf("��û������������һͷ��\n");
			   }else{
			   	printf("��������Ҫ���ҵ����ݣ�\n");
			 scanf("%d",&num);
			 BST_search(head, num);
			} 
			system("pause");
	   		system("cls");
			break;  
			case '4'://ɾ������
			if(flag == 0){
	   			printf("��û������������һͷ��\n");
			   }else{
			   	printf("������ɾ��������:\n");
				scanf("%d",&num);
				status = BST_delete(head, num);
				if(status == true){
					printf("ɾ���ɹ�\n");
				} 
			   }
			system("pause");
	   		system("cls");
			break;
			case '5': //��������ݹ�
			if(flag == 0){
	   			printf("��û������������һͷ��\n");
			   }else{
			   	printf("�������:\n");
	BST_preorderR(head->root, visit);
	printf("\n"); 
	printf("=================================\n");
	printf("�������:\n");
	BST_inorderR(head->root, visit);
	printf("\n");
	printf("=================================\n");
	printf("�������:\n");
	BST_postorderR(head->root, visit);
	printf("\n");
	printf("=================================\n");
			   }
			 system("pause");
	   		system("cls");
			break;
			case '6' : //��������ǵݹ�
			 if(flag == 0){
	   			printf("��û������������һͷ��\n");
			   }else{
			   	system("cls");
			   	welcome6();
				   char s6 = getch();
				   switch(s6){
				   	case '1':
				   		printf("�������:\n");
							BST_preorderI(head, visit); 
							printf("\n");
							printf("=================================\n");
							break;
							case '2':
							 printf("�������:\n");
							BST_inorderI(head, visit);
							printf("\n");
							printf("=================================\n");
							break;
							case '3':
							printf("�������:\n");
							BST_postorderI(head, visit);
							printf("\n");
							printf("=================================\n");
							break;	
				   } 
			   	printf("��û��ɣ���©��\n");
			   }
			 system("pause");
	   		system("cls");
			break;
			case '7' ://��α���
			if(flag == 0){
				printf("��û������������һͷ��\n");
			}else {
				printf("��������������ȫ�����ִ�м��μ���\n"); 
				printf("��α���\n");
				BST_levelOrder(head, visit);
				//printf("������ѭ����\n");
				printf("\n");
			}
			 
			 system("pause");
	   		system("cls");
			break;
			 
			case '8': //�˳�ϵͳ
			printf("��ӭ�´��ټ�\n");
			return ;
			default ://�������
			printf("����������\n");
			system("pause");
	   		system("cls");
			break; 
		} 
	}
	
	
	
	


	
//	
//   	status = BST_init(head);
//   	if(status == true){
//   		printf("��ʼ���ɹ�\n");
//   	}else{
//   		printf("��ʼ��ʧ��\n");
//	   }
//	for(i = 0;i<5;i++){
//	printf("������Ҫ��������֣�\n");
//	scanf("%d",&num);
//	status = BST_insert(head,num);
//	if(status == true){
//   		printf("����ɹ�\n");
//   	}else{
//   		printf("����ʧ��\n");
//		i--;
//	   }
//	}
//	printf("=================================\n");
//	printf("�������ѯ������:\n");
//	scanf("%d",&num);
//	BST_search(head, num);
//	printf("=================================\n");
	//printf("�������:\n");
	//BST_preorderR(head->root, visit);
	//printf("\n"); 
	//printf("=================================\n");
	//printf("�������:\n");
	//BST_inorderR(head->root, visit);
	//printf("\n");
	//printf("=================================\n");
	//printf("�������:\n");
	//BST_postorderR(head->root, visit);
	//printf("\n");
	//printf("=================================\n");
	//printf("=================================\n");
//	printf("=================================\n");//
	//printf("������ɾ��������:\n");
	//scanf("%d",&num);
	///BST_delete(head, num);
	//BST_postorderR(head->root, visit);
	//printf("\n");
//	printf("=================================\n");
//	printf("�ǵݹ�\n");
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
