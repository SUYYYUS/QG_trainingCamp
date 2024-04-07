/*
	Name: chen shuyu 
	Copyright: 
	Author: 
	Date: 07/04/24 15:37
	Description: 
*/

// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root ;
} BinarySortTree, *BinarySortTreePtr;



//栈

typedef NodePtr ElemType1;

typedef  struct StackNode
{
	ElemType1 data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//链式队列结构
typedef struct node
{
    ElemType1 data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} LinkNode;

typedef struct Lqueue
{
    LinkNode *front;                   //队头
    LinkNode *rear;
	int length;                   //队尾
} LQueue;



/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr, ElemType);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr, ElemType);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr, ElemType);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr temp, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(BinarySortTreePtr, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr temp, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));

//打印数据
void visit(NodePtr temp);
//查询是否有该节点 
Node* search(Node *temp, ElemType e);
//找到当前叶节点的符合要插入的位置
Node* findlast(Node *temp, ElemType e);

//链栈
Status initLStack(LinkStack *s);//初始化栈  
Status isEmptyLStack(LinkStack *s);//判断栈是否为空  
Status getTopLStack(LinkStack *s, ElemType1*e);//得到栈顶元素  
Status clearLStack(LinkStack *s);//清空栈    
Status destroyLStack(LinkStack *s);//销毁栈   
Status LStackLength(LinkStack *s,int *length);//检测栈长度   
Status pushLStack(LinkStack *s,ElemType1 data);//入栈   
Status popLStack(LinkStack *s,ElemType1 *data);//出栈 

//队列 
void InitLQueue(LQueue *Q);
void DestoryLQueue(LQueue *Q);
Status IsEmptyLQueue(const LQueue *Q);
Status GetHeadLQueue(LQueue *Q, ElemType1 *e);
int LengthLQueue(LQueue *Q);
Status EnLQueue(LQueue *Q, ElemType1 data);
Status DeLQueue(LQueue *Q);
void ClearLQueue(LQueue *Q);
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));


#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
