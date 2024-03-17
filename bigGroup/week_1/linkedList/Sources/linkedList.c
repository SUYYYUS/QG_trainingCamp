#include"linkedList.h"

//主菜单
void welcome(){
	printf("*-------------------------------*\n");
	printf("|欢迎来到Suyyyus的第一周大组作业|\n");
	printf("*-------------------------------*\n");
	printf("|\t1.初始化单链表\t\t|\n");
	printf("|\t2.插入数据\t\t|\n");
	printf("|\t3.查询链表信息\t\t|\n");
	printf("|\t4.销毁整个链表\t\t|\n"); 
	printf("|\t5.销毁某个节点\t\t|\n");
	printf("|\t6.通过值来找节点\t|\n");
	printf("|\t7.反转链表      \t|\n"); //两种方式再选择（递归和非递归）
	printf("|\t8.判断链表是否成环\t|\n");
	printf("|\t9.找到单链表的中点\t|\n");
	printf("|\t0.退粗          \t|\n"); 
	printf("*-------------------------------*\n");
	printf("请选择想要执行的功能：\t\n");
} 


//反转链表的菜单
void reverse_LinkedList_welcome(){
	printf("*-----------------------*\n");
	printf("|请选择想要反转的方式~~~|\n");
	printf("*-----------------------*\n");
	printf("|1.递归方式       \t|\n");
	printf("|2.非递归方式     \t|\n");
	printf("|其他输入则退出该功能   \t|\n");
	printf("*-----------------------*\n");

}

//初始化一个单链表 头节点 
Status InitList(LinkedList *L){
    *L = (struct LNode*) malloc (sizeof(struct LNode)); //创建内存
    (*L) -> next = NULL;
    return SUCCESS;
}

//插入数据
Status InsertList(LNode *p, LNode *q){	
	//观察上个节点的指针是否指向空 
	while(p->next != NULL){
		p = p->next;
	}
	//连接新加入的节点
	p->next = q; 
	return SUCCESS;
} 

//遍历链表并输出所有 
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

//打印数据 
void visit(ElemType e){
	printf("%d\t",e);
}

//销毁整个链表 
void DestroyList(LinkedList *L){
	struct LNode* p;
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

//删除p节点后的第一个节点  
Status DeleteList(LNode *p, ElemType *e){
	struct LNode* p1 = p;
	struct LNode* p2 = p1->next;
	p1->next = p2->next;
	free(p2);//释放节点内存 
	return SUCCESS;
	
}

//通过值找节点 
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
 
//反转链表(非递归） 
Status ReverseList(LinkedList *L) {
	struct LNode* p2 = (*L)->next;
	struct LNode* p1 =NULL;//在p2前一位
	struct LNode* p3 =NULL;//在p2后一位 
	while(p2 != NULL){
		p3 = p2->next;
		p2->next=p1;//把指针的指向调换
		p1=p2;
		p2=p3;
	}
    (*L)->next= p1;//让头指针的next指向原本在尾部的节点 
	return SUCCESS;
}

//判断链表是否成环 
Status IsLoopList(LinkedList L){
	struct LNode* fast;//一个走两步 
	struct LNode* slow;//一个走一步 
	fast = L->next;
	slow = L->next;
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next; //快指针走两步 
		slow = slow->next; //慢指针走一步 
		//若相遇，则一定有环 
		if(fast == slow){
			return SUCCESS;
		}
	}
	return ERROR;
}

//求链表长度
int length_linkedList(LinkedList q) {
	struct LNode* p = q->next; 
	int n = 1;
	//知道链表长度 
	while(p != NULL){
		p=p->next;
		n++;
	}
	return n;
}

//寻找链表中点
LNode* FindMidNode(LinkedList *L){
	struct LNode* p = (*L)->next; 
	int n = length_linkedList(p);
	printf("链表长度为：%d\n",n);
	struct LNode* fast ;
	struct LNode* slow ;
		//分奇偶判断
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
	//创建头节点
	ElemType i;
	LNode* L = NULL;//单链表
	Status status;//表明状态 
	ElemType *e = NULL;
	ElemType value = 0;
	struct LNode* MID = NULL; //服务为第九条功能 
	int s,s7;
	while(1){
		//显示主菜单 
		welcome();
	scanf("%d",&s);
	switch(s){
		case 1: //初始化一个链表 
			status = InitList(&L);
			if(status == SUCCESS){
		printf("初始化成功！\n");
			}else {
		printf("初始化失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 2: //插入数据
			if(L ==NULL){
				printf("当前还没有链表，请先初始化一个链表\n");
				system("pause");//暂停
				system("cls");//清屏
				break;
			}
			printf("请输入数字：\n");
			scanf("%d",&i);
			LNode* temp = (struct LNode*) malloc (sizeof(struct LNode));
			temp->data = i;
			temp->next = NULL; 
			status = InsertList(L, temp);
			if(status == SUCCESS){
				printf("插入成功！"); 
			}else {
				printf("插入失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 3://遍历链表并打印
			 TraverseList(L, visit);
			 printf("打印完成啦\n");
			 system("pause");//暂停
			 system("cls");//清屏
			 break;
			 case 4: //销毁整个链表
			 DestroyList(&L);
			 system("pause");//暂停
			 system("cls");//清屏
			 break;
			 case 5: //销毁某个节点的下一个节点 
			status = DeleteList(L,e);
			if(status == SUCCESS){
			printf("删除成功！"); 
			}else {
			printf("删除失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			 break;
			case 6: //通过值来找节点
			printf("输入你想找的数字：\n");
			scanf("%d",&value);
			status = SearchList(L,value);
			if(status == SUCCESS){
			printf("查找成功！\n"); 
			}else {
			printf("查找失败！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 7: //反转链表并打印
				//选择菜单 
			   reverse_LinkedList_welcome();
			   printf("输入想要的方式：\n");
			   scanf("%d",&s7);
			    switch(s7){
			    	case 1://非递归
					 status = ReverseList(&L);
					 if(status == SUCCESS){
						printf("反转成功！\n"); 
						}else {
						printf("反转失败！\n");
						}
						TraverseList(L, visit);
					 break;
					 case 2://递归
					 printf("小陈还没有开发出来<__>\n");
					 default: //任意键退出 
					 break;
				}			
			system("pause");//暂停
			system("cls");//清屏
			break; 
			case 8://判断链表成环
			 status = IsLoopList(L);
			 if(status == SUCCESS){
			printf("是成环！\n"); 
			}else if(status == ERROR){
			printf("不是成环！\n");
			}
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 9: //找到单链表的中点
			MID = FindMidNode(&L);
			printf("该中间节点的数据为：%d\n",MID->data);
			system("pause");//暂停
			system("cls");//清屏
			break;
			case 0:
				printf("欢迎下次再见~~\n");
				return ;
		default:
			break;
	}	
	}
return 0;	
}
