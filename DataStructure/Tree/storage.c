/*
	双亲表示法
*/

//双亲表达法1
#define MAX_TREE_SIZE 100

typedef int TElemType;

typedef struct  {
	TElemType data;
	int parent;//双亲位置
}PTNode;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //结点数组
	int r, n; //r为根位置,n是结点数

}PTree;

//缺点：查找孩子或者兄弟，耗时大

/*-----------------------------------------------------*/

//双亲表达法2
typedef struct {
	TElemType data;
	int parent;//双亲位置
	/*根据树的度添加*/
	int child1;
	int child2;
	int child3;
}PTNode2;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //结点数组
	int r, n; //r为根位置,n是结点数

}PTree2;
//解决了双亲表达法1的缺点，但消耗空间且不必要。

/*----------------------------------------------------*/

//双亲表达法3
typedef struct {
	TElemType data;
	int parent;//双亲位置
	int firstchild;//长子域
}PTNode3;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //结点数组
	int r, n; //r为根位置,n是结点数

}PTree3;

/*----------------------------------------------------*/

//双亲表达法4
typedef struct {
	TElemType data;
	int parent;//双亲位置
	int rightsib;//右兄弟结点
}PTNode4;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //结点数组
	int r, n; //r为根位置,n是结点数

}PTree4;



/*
	孩子表示法
*/
//孩子表示法1
typedef struct CTNode{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct {
	TElemType data;
	ChildPtr firstChild;
}CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
}CTree;

/*----------------------------------------------------*/
//孩子表示法2
typedef struct CTNode {
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct {
	TElemType data;
	int parent;
	ChildPtr firstChild;
}CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r, n;
}CTree;


/*
	孩子兄弟表示法
*/

typedef struct CSNode{
	TElemType data;
	struct CSNode *firstchild, *nextsibling;
}CSNode,*CSTree;
