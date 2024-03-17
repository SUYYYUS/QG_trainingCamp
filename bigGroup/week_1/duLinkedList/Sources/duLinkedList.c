#include"dulinkedList.h"

//���˵�
void welcome(){
	printf("*-------------------------------*\n");
	printf("|��ӭ����Suyyyus�ĵ�һ�ܴ�����ҵ|\n");	
	printf("*-------------------------------*\n");
	printf("|\t1.��ʼ��˫����\t\t|\n");
	printf("|\t2.ͷ��������\t\t|\n");
	printf("|\t3.β��������\t\t|\n");
	printf("|\t4.��ѯ������Ϣ\t\t|\n");
	printf("|\t5.������������\t\t|\n"); 
	printf("|\t6.����ĳ���ڵ�\t\t|\n");
	printf("|\t0.�˴�          \t|\n"); 
	printf("*-------------------------------*\n");
	printf("��ѡ����Ҫִ�еĹ��ܣ�\t\n"); 
}

//��ʼ��˫���� 
Status InitList_DuL(DuLinkedList *L){
	(*L) = (struct DuLNode*)malloc(sizeof(struct DuLNode));
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS;
}

//ͷ�巨��������
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
		if(p->next == NULL){//�����һ���ڵ�ʱ������������һ��
            p->next = q;
            q->prior = p;
            q->next = NULL;
        }
        else{
            q->next = p->next;
            p->next->prior = q;
            p->next = q;
            q->prior = p;
        }
        return SUCCESS;
} 

//β�巨��������
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
		//�۲��ϸ��ڵ��ָ���Ƿ�ָ��� 
	while(p->next != NULL){
		p = p->next;
	}
	q->prior = p;
	p->next = q; 
	return SUCCESS;
} 

//��ѯ����ȫ����Ϣ 
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	struct DuLNode* p= L;
    p = p -> next;
    while (p !=NULL)
    {
    	visit(p->data);
        p = p -> next;
    }
	printf("\n");
} 

void visit(ElemType e){
	printf("%d\t",e);
}

//������������
void DestroyList_DuL(DuLinkedList *L){
		struct DuLNode* p;
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

//���ٽڵ���һ����
Status DeleteList_DuL(DuLNode *p, ElemType *e){
	struct DuLNode* p1;
	struct DuLNode* p2;
	p1=p->next;
	p2=p1->next;
	
	free(p1);//�ͷ�p1�ڵ���ڴ� 
	p2->prior = p;
	p->next = p2;
	return SUCCESS; 
} 

int main(){
	DuLNode* L = NULL;//˫����
	Status status;//����״̬
	ElemType i;
	ElemType *e = NULL;
	int s ;
	while(1){
		welcome();
		scanf("%d",&s);
		switch(s){
			case 1:// ��ʼ��
			status = InitList_DuL(&L);
			if(status == SUCCESS){
		printf("��ʼ���ɹ���\n");
			}else {
		printf("��ʼ��ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 2://ͷ�巨��������
			if(L ==NULL ){
				printf("��ǰ��û���������ȳ�ʼ��һ������\n");
				system("pause");//��ͣ
				system("cls");//����
				break;
			}
			printf("���������������ݣ�\n");
			scanf("%d",&i);
			DuLNode* temp1 = (struct DuLNode*)malloc(sizeof(struct DuLNode));
			temp1->data = i;
			temp1->next = NULL;
			temp1->prior = NULL;
			status = InsertBeforeList_DuL(L, temp1); 
			if(status == SUCCESS){
		printf("����ɹ���\n");
			}else {
		printf("����ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 3://β�巨��������
			if(L ==NULL){
				printf("��ǰ��û���������ȳ�ʼ��һ������\n");
				system("pause");//��ͣ
				system("cls");//����
				break;
			}
			printf("���������������ݣ�\n");
			scanf("%d",&i);
			DuLNode* temp = (struct DuLNode*)malloc(sizeof(struct DuLNode));
			temp->data = i;
			temp->next = NULL;
			temp->prior = NULL;
			status = InsertAfterList_DuL(L, temp); 
			if(status == SUCCESS){
		printf("����ɹ���\n");
			}else {
		printf("����ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 4://��ѯ������Ϣ
			TraverseList_DuL(L, visit); 
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 5://������������ 
			 DestroyList_DuL(&L);
			system("pause");//��ͣ
			system("cls");//����
			break;
			case 6://����ĳ���ڵ�
			status = DeleteList_DuL(L, e);
			printf("%p\n",e); //���e 
			if(status == SUCCESS){
		printf("���ٳɹ���\n");
			}else {
		printf("����ʧ�ܣ�\n");
			}
			system("pause");//��ͣ
			system("cls");//���� 
			break;
			case 0://�˳�ϵͳ
			return;
			default://�������
			printf("�������������ܰ�~\n");
			system("pause");//��ͣ
			system("cls");//����
			break; 
		}
	}
	return 0;
} 
