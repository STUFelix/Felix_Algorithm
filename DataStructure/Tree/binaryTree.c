#include <stdio.h>
typedef int TreeData;
typedef struct node {
	TreeData Data;
	struct node *Left, *Right;
}BinTreeNode;
typedef BinTreeNode *BinTree;

/*
	二叉树的递归
*/
/*二叉树的中序遍历*/
void inOrder(BinTreeNode *T) {
	if (T) {
		inOrder(T->Left);
		printf(T->Data);
		inOrder(T->Right);
	}
}

/*二叉树的前序遍历*/
void preOrder(BinTreeNode *T) {
	if (T) {
		printf(T->Data);
		inOrder(T->Left);
		inOrder(T->Right);
	}
}

/*二叉树的后序遍历*/
void postOrder(BinTreeNode *T) {
	if (T) {
		inOrder(T->Left);
		inOrder(T->Right);
		printf(T->Data);
	}
}

/*计算二叉树的结点个数*/
int CountBT(BinTreeNode *T) {
	if (!T) return 0;
	else return 1 + CountBT(T->Left) + CountBT(T->Right);
}

/*计算二叉树的叶子结点个数*/
int leaf_BTCount(BinTreeNode *T) {
	if (!T) return 0;
	else if (!T->Left && !T->Right) return 1;
	else return leaf_BTCount(T->Left) + leaf_BTCount(T->Right);
}

/*计算二叉树的高度*/
int hight_BTCount(BinTreeNode *T) {
	if (!T) return 0;
	else
	{
		int m = hight_BTCount(T->Left);
		int n = hight_BTCount(T->Right);
		return (m > n) ? m + 1 : n + 1;
	}
}
/*复制二叉树*/
BinTreeNode *BTCopy(BinTreeNode *T) {
	if (!T) return NULL;
	BinTreeNode *temp= malloc(sizeof(BinTreeNode));
	temp->Data = T->Data;
	temp->Left = BTCopy(T->Left);
	temp->Right = BTCopy(T->Right);
}

/*判断二叉树等价与否*/
int BTEqual(BinTreeNode *Ta, BinTreeNode *Tb) {
	if (Ta == NULL && Tb == NULL) {
		return 1;
	}

	if (Ta != NULL && Tb != NULL && Ta->Data == Tb->Data && BTEqual(Ta->Left, Tb->Left) && BTEqual(Ta->Right, Tb->Right)) {
		return 1;
	}
	return 0;
}

/*---------------------------------------------------------------------------------*/



/*
	二叉树用栈实现遍历
*/



/*
	二叉树的层次遍历
*/

void LevelOrderTraversal(BinTreeNode *BT) {
	Queue *Q;
	BinTree T;
	if (!BT) return;
	Q = CreatQueue(MaxSize);
	AddQ(Q, BT);
	while (!isEmptyQ(Q))
	{
		T = DeleteQ(Q);
		printf("%d ", BT->Data);
		if (T->Left) AddQ(Q, T->Left);
		if (T->Right)AddQ(Q, T->Right);
	}
}
