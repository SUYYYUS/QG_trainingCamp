#include"linkedList.h"

//���˵�
void welcome(){
	printf("*-------------------------------*\n");
	printf("|��ӭ����Suyyyus�ĵ�һ�ܴ�����ҵ|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.��ʼ��������\t\t|\n");
	printf("|\t2.��������\t\t|\n");
	printf("|\t3.��ѯ������Ϣ\t\t|\n");
	printf("|\t4.������������\t\t|\n"); 
	printf("|\t5.����ĳ���ڵ�\t\t|\n");
	printf("|\t6.ͨ��ֵ���ҽڵ�\t|\n");
	printf("|\t7.��ת����      \t|\n"); //���ַ�ʽ��ѡ�񣨵ݹ�ͷǵݹ飩
	printf("|\t8.�ж������Ƿ�ɻ�\t|\n");
	printf("|\t9.�ҵ���������е�\t|\n");
	printf("|\t0.�˴�          \t|\n"); 
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n");
} 


//��ת����Ĳ˵�
void reverse_LinkedList_welcome(){
	printf("*-----------------------*\n");
	printf("|��ѡ����Ҫ��ת�ķ�ʽ~~~|\n");
	printf("*-----------------------*\n");
	printf("|1.�ݹ鷽ʽ       \t|\n");
	printf("|2.�ǵݹ鷽ʽ     \t|\n");
	printf("|�����������˳��ù���   \t|\n");
	printf("*-----------------------*\n");

}

//��ʼ��һ�������� ͷ�ڵ� 
Status InitList(LinkedList *L){
    *L = (struct LNode*) malloc (sizeof(struct LNode)); //�����ڴ�
    (*L) -> next = NULL;
    return SUCCESS;
}

//��������
Status InsertList(LNode *p, LNode *q){	
	//�۲��ϸ��ڵ��ָ���Ƿ�ָ��� 
	while(p->next != NULL){
		p = p->next;
	}
	//�����¼���Ľڵ�
	p->next = q; 
	return SUCCESS;
} 

//��������������� 
void TraverseList(LinkedList L, void (*visit)(ElemType e)){
	struct LNode* p= L;
    p = p -> next;
    while (p !=NULL)
    {
    	visit(p->data);
        p = p -> next;
    }
	printf("\n");
}

//��ӡ���� 
void visit(ElemType e){
	printf("%d\t",e);
}

//������������ 
void DestroyList(LinkedList *L){
	struct LNode* p;
	//�жϵ�ǰ�Ƿ�������
	if((*L) == NULL){
		printf("��ǰ����û������\n");
		return ;
	}else{
			*L = (*L)->next;
	 while((*L)->next !=NULL){
	 	p = *L;
	    *L = (*L)->next;//��*L������Ҫ���ٵĽڵ����һ���ڵ� 
	    free(p);//���ٸýڵ� 
	 }
	 //�ͷ����һ����ǰ�ڵ� 
	 (*L)->next=NULL;
	 free(*L);
	 printf("��ϲ�㣬�������ٳɹ���~~\n");
	}
}

//ɾ��p�ڵ��ĵ�һ���ڵ�  
Status DeleteList(LNode *p, ElemType *e){
	struct LNode* p1 = p;
	struct LNode* p2 = p1->next;
	p1->next = p2->next;
	free(p2);//�ͷŽڵ��ڴ� 
	return SUCCESS;
	
}

//ͨ��ֵ�ҽڵ� 
Status SearchList(LinkedList L, ElemType e){
		struct LNode* p1 = L;
		while(p1->next !=NULL){
			if(p1->data == e){
				printf("%p\n",p1);
				return SUCCESS; 
			}
			p1 = p1->next; 
		}
		return ERROR;

}
 
//��ת����(�ǵݹ飩 
Status ReverseList(LinkedList *L) {
	struct LNode* p2 = (*L)->next;
	struct LNode* p1 =NULL;//��p2ǰһλ
	struct LNode* p3 =NULL;//��p2��һλ 
	while(p2 != NULL){
		p3 = p2->next;
		p2->next=p1;//��ָ���ָ�����
		p1=p2;
		p2=p3;
	}
    (*L)->next= p1;//��ͷָ���nextָ��ԭ����β���Ľڵ� 
	return SUCCESS;
}

//�ж������Ƿ�ɻ� 
Status IsLoopList(LinkedList L){
	struct LNode* fast;//һ�������� 
	struct LNode* slow;//һ����һ�� 
	fast = L->next;
	slow = L->next;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next; //��ָ�������� 
		slow = slow->next; //��ָ����һ�� 
		//����������һ���л� 
		if(fast == slow){
			return SUCCESS;
		}
	}
	return ERROR;
}

//��������
int length_linkedList(LinkedList q) {
	struct LNode* p = q->next; 
	int n = 1;
	//֪�������� 
	while(p != NULL){
		p=p->next;
		n++;
	}
	return n;
}

//Ѱ�������е�
LNode* FindMidNode(LinkedList *L){
	struct LNode* p = (*L)->next; 
	int n = length_linkedList(p);
	printf("������Ϊ��%d\n",n);
	struct LNode* fast ;
	struct LNode* slow ;
		//����ż�ж�
		if(n%2 != 0){
		fast = (*L)->next;
	    slow = (*L)->next;	
	while(fast->next !=NULL ){
		fast =fast->next->next;
		slow = slow->next;
			}
	}else if(n%2 ==0){
		fast = (*L);
	    slow = (*L);	
	while(fast->next !=NULL ){
		fast =fast->next->next;
		slow = slow->next;
	}
	}
	return slow;
	
}

int main(){
	//����ͷ�ڵ�
	ElemType i;
	LNode* L = NULL;//������
	Status status;//����״̬ 
	ElemType *e = NULL;
	ElemType value = 0;
	struct LNode* MID = NULL; //����Ϊ�ھ������� 
	int s,s7;
	while(1){
		//��ʾ���˵� 
		welcome();
	scanf("%d",&s);
	switch(s){
		case 1: //��ʼ��һ������ 
			status = InitList(&L);
			if(status == SUCCESS){
		printf("��ʼ���ɹ���\n");
			}else {
		printf("��ʼ��ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 2: //��������
			if(L ==NULL){
				printf("��ǰ��û���������ȳ�ʼ��һ������\n");
				system("pause");//��ͣ
				system("cls");//����
				break;
			}
			printf("���������֣�\n");
			scanf("%d",&i);
			LNode* temp = (struct LNode*) malloc (sizeof(struct LNode));
			temp->data = i;
			temp->next = NULL; 
			status = InsertList(L, temp);
			if(status == SUCCESS){
				printf("����ɹ���"); 
			}else {
				printf("����ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 3://����������ӡ
			 TraverseList(L, visit);
			 printf("��ӡ�����\n");
			 system("pause");//��ͣ
			 system("cls");//����
			 break;
			 case 4: //������������
			 DestroyList(&L);
			 system("pause");//��ͣ
			 system("cls");//����
			 break;
			 case 5: //����ĳ���ڵ����һ���ڵ� 
			status = DeleteList(L,e);
			if(status == SUCCESS){
			printf("ɾ���ɹ���"); 
			}else {
			printf("ɾ��ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			 break;
			case 6: //ͨ��ֵ���ҽڵ�
			printf("���������ҵ����֣�\n");
			scanf("%d",&value);
			status = SearchList(L,value);
			if(status == SUCCESS){
			printf("���ҳɹ���\n"); 
			}else {
			printf("����ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 7: //��ת������ӡ
				//ѡ��˵� 
			   reverse_LinkedList_welcome();
			   printf("������Ҫ�ķ�ʽ��\n");
			   scanf("%d",&s7);
			    switch(s7){
			    	case 1://�ǵݹ�
					 status = ReverseList(&L);
					 if(status == SUCCESS){
						printf("��ת�ɹ���\n"); 
						}else {
						printf("��תʧ�ܣ�\n");
						}
						TraverseList(L, visit);
					 break;
					 case 2://�ݹ�
					 printf("С�»�û�п�������<__>\n");
					 default: //������˳� 
					 break;
				}			
			system("pause");//��ͣ
			system("cls");//����
			break; 
			case 8://�ж�����ɻ�
			 status = IsLoopList(L);
			 if(status == SUCCESS){
			printf("�ǳɻ���\n"); 
			}else if(status == ERROR){
			printf("���ǳɻ���\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 9: //�ҵ���������е�
			MID = FindMidNode(&L);
			printf("���м�ڵ������Ϊ��%d\n",MID->data);
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 0:
				printf("��ӭ�´��ټ�~~\n");
				return ;
		default:
			break;
	}	
	}
return 0;	
}
