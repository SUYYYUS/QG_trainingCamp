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



//ջ

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

//��ʽ���нṹ
typedef struct node
{
    ElemType1 data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} LinkNode;

typedef struct Lqueue
{
    LinkNode *front;                   //��ͷ
    LinkNode *rear;
	int length;                   //��β
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

//��ӡ����
void visit(NodePtr temp);
//��ѯ�Ƿ��иýڵ� 
Node* search(Node *temp, ElemType e);
//�ҵ���ǰҶ�ڵ�ķ���Ҫ�����λ��
Node* findlast(Node *temp, ElemType e);

//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ  
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��  
Status getTopLStack(LinkStack *s, ElemType1*e);//�õ�ջ��Ԫ��  
Status clearLStack(LinkStack *s);//���ջ    
Status destroyLStack(LinkStack *s);//����ջ   
Status LStackLength(LinkStack *s,int *length);//���ջ����   
Status pushLStack(LinkStack *s,ElemType1 data);//��ջ   
Status popLStack(LinkStack *s,ElemType1 *data);//��ջ 

//���� 
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
