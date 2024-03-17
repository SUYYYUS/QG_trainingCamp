#include"dulinkedList.h"

//主菜单
void welcome(){
	printf("*-------------------------------*\n");
	printf("|欢迎来到Suyyyus的第一周大组作业|\n");	
	printf("*-------------------------------*\n");
	printf("|\t1.初始化双链表\t\t|\n");
	printf("|\t2.头插入数据\t\t|\n");
	printf("|\t3.尾插入数据\t\t|\n");
	printf("|\t4.查询链表信息\t\t|\n");
	printf("|\t5.销毁整个链表\t\t|\n"); 
	printf("|\t6.销毁某个节点\t\t|\n");
	printf("|\t0.退粗          \t|\n"); 
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n"); 
}

//初始化双链表 
Status InitList_DuL(DuLinkedList *L){
	(*L) = (struct DuLNode*)malloc(sizeof(struct DuLNode));
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS;
}

//头插法插入数据
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
		if(p->next == NULL){//插入第一个节点时与其他方法不一样
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

//尾插法插入数据
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
		//观察上个节点的指针是否指向空 
	while(p->next != NULL){
		p = p->next;
	}
	q->prior = p;
	p->next = q; 
	return SUCCESS;
} 

//查询链表全部信息 
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

//销毁整个链表
void DestroyList_DuL(DuLinkedList *L){
		struct DuLNode* p;
	//判断当前是否有链表
	if((*L) == NULL){
		printf("当前链表没有数据\n");
		return ;
	}else{
		*L = (*L)->next;
	 while((*L)->next !=NULL){
	 	p = *L;
	    *L = (*L)->next;//让*L遍历到要销毁的节点的下一个节点 
	    free(p);//销毁该节点 
	 }
	 //释放最后一个当前节点 
	 (*L)->next=NULL;
	 free(*L);
	 printf("恭喜你，链表销毁成功啦~~\n");
	}
} 

//销毁节点后的一个点
Status DeleteList_DuL(DuLNode *p, ElemType *e){
	struct DuLNode* p1;
	struct DuLNode* p2;
	p1=p->next;
	p2=p1->next;
	
	free(p1);//释放p1节点的内存 
	p2->prior = p;
	p->next = p2;
	return SUCCESS; 
} 

int main(){
	DuLNode* L = NULL;//双链表
	Status status;//表明状态
	ElemType i;
	ElemType *e = NULL;
	int s ;
	while(1){
		welcome();
		scanf("%d",&s);
		switch(s){
			case 1:// 初始化
			status = InitList_DuL(&L);
			if(status == SUCCESS){
		printf("初始化成功！\n");
			}else {
		printf("初始化失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 2://头插法插入数据
			if(L ==NULL ){
				printf("当前还没有链表，请先初始化一个链表\n");
				system("pause");//暂停
				system("cls");//清屏
				break;
			}
			printf("输入你想插入的数据：\n");
			scanf("%d",&i);
			DuLNode* temp1 = (struct DuLNode*)malloc(sizeof(struct DuLNode));
			temp1->data = i;
			temp1->next = NULL;
			temp1->prior = NULL;
			status = InsertBeforeList_DuL(L, temp1); 
			if(status == SUCCESS){
		printf("插入成功！\n");
			}else {
		printf("插入失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 3://尾插法插入数据
			if(L ==NULL){
				printf("当前还没有链表，请先初始化一个链表\n");
				system("pause");//暂停
				system("cls");//清屏
				break;
			}
			printf("输入你想插入的数据：\n");
			scanf("%d",&i);
			DuLNode* temp = (struct DuLNode*)malloc(sizeof(struct DuLNode));
			temp->data = i;
			temp->next = NULL;
			temp->prior = NULL;
			status = InsertAfterList_DuL(L, temp); 
			if(status == SUCCESS){
		printf("插入成功！\n");
			}else {
		printf("插入失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 4://查询链表信息
			TraverseList_DuL(L, visit); 
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 5://销毁整个链表 
			 DestroyList_DuL(&L);
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 6://销毁某个节点
			status = DeleteList_DuL(L, e);
			printf("%p\n",e); //输出e 
			if(status == SUCCESS){
		printf("销毁成功！\n");
			}else {
		printf("销毁失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏 
			break;
			case 0://退出系统
			return;
			default://输入错误
			printf("再试试其他功能吧~\n");
			system("pause");//暂停
			system("cls");//清屏
			break; 
		}
	}
	return 0;
} 
