



/**问题描述：约瑟夫环问题
	N个人围成一圈，从第一个人开始报数，报到m的人出圈，剩下的人继续从1开始报数，报到m的人出圈；如此往复，直到所有人出圈。
*/

#include<stdio.h>

/*数组实现1,未对出圈的人的节点进行删除操作,
若为(10,2)结束之后原数组序数仍为{1,2,3,4,5,6,7,8,9,10}
	时间复杂度分析:
*/
void josephus1(int amount, int doom) {
	int alive = amount;	//幸存人数
	int number = 0;	//计数，当number == doom时，淘汰这个人
	int index = 0;	//下标，为总人数-1
	int *circle = NULL;	//根据需求设为循环数组，存储每个人

	/*用calloc()函数申请得到的空间，自动初始化每个元素为0，0为幸存，1为淘汰的人*/
	circle = (int *)calloc(sizeof(int), amount);

	//直到所有人出圈
	while (alive > 0)
	{
		number += 1 - circle[index];//不管"0"还是"1"都进行计数
		if (number == doom) {
			alive == 1 ? printf("%d", index + 1) : printf("%d,", index + 1);//输出位置
			circle[index] = 1;//标记其出圈
			//幸存人数减1 计数器置零
			alive--;
			number = 0;
		}
		index = (index + 1) % amount;
	}
	printf("\n");
	free(circle);
}

/*数组实现2，对出圈的人的节点进行删除操作，优化其时间复杂度,
若为(10,2)结束之后原数组序数仍为{4,2,4,4,4,6,8,8,4,0}
	时间复杂度分析:
*/

void josephus2(int amount,int doom) {
	int alive = amount;
	int number = 0;
	int curIndex = 0;
	int preIndex = amount - 1;
	int *circle = NULL;
	int index;

	circle = (int*)malloc(sizeof(int)*amount);

	for (index = 0; index < amount; index++) {
		circle[index] = (index + 1) % amount;
	}

	while (alive>0)
	{
		number++;
		if (number == doom) {
			alive == 1 ? printf("%d", curIndex + 1) : printf("%d,", curIndex + 1);
			alive--;
			number = 0;
			circle[preIndex] = circle[curIndex];//出圈
		}
		else
		{
			preIndex = curIndex;//继续处理下一个人
		}
		curIndex = circle[curIndex];
	}
	free(circle);
}


/*数组实现3，对出圈的人的节点进行删除操作，优化其时间复杂度,
	时间复杂度分析:
*/
void josephus3(int amount, int doom) {
	int alive = amount;	
	int curIndex = 0;			
	int preIndex = amount - 1; 
	int *circle = NULL;
	int index;

	circle = (int *)malloc(sizeof(int) * amount);
	for (index = 0; index < amount; index++) {
		circle[index] = (index + 1) % amount;	// 初始化链表
	}

	while (alive > 0) {	
		int num = doom % alive - 1; // 直接计算出需要移动的人数，
		// 直接定位到要出圈的人
		for (index = 0; index < (num == -1 ? alive - 1 : num); index++) {
			preIndex = curIndex;
			curIndex = circle[curIndex];
		}
		// 该人出圈！
		alive == 1 ? printf("%d", curIndex + 1) : printf("%d,", curIndex + 1);
		alive--;
		circle[preIndex] = circle[curIndex]; // 真正的出圈操作！
		curIndex = circle[curIndex]; // 继续处理下一个人
	}
	// 这个算法比normalJoseph.c效率提高30%！

	free(circle);
}

/*约瑟夫环变化版（数组实现）：
变化的doom，初始化时每个人次有一个随机化密码（正整数），出圈的人密码将成为下一轮报数时的doom
*/
void josephus_changeDoom(int amount, int doom,int password[]) {
	int alive = amount;	//幸存人数
	int number = 0;	//计数，当number == doom时，淘汰这个人
	int index = 0;	//下标，为总人数-1
	int *circle = NULL;	//根据需求设为循环数组，存储每个人

	/*用calloc()函数申请得到的空间，自动初始化每个元素为0，0为幸存，1为淘汰的人*/
	circle = (int *)calloc(sizeof(int), amount);

	//直到所有人出圈
	while (alive > 0)
	{
		number += 1 - circle[index];//不管"0"还是"1"都进行计数
		if (number == doom) {
			alive == 1 ? printf("%d", index + 1) : printf("%d,", index + 1);//输出位置
			circle[index] = 1;//标记其出圈
			doom = password[index];//将他的密码作为新的doom
			//幸存人数减1 计数器置零
			alive--;
			number = 0;
		}
		index = (index + 1) % amount;
	}
	printf("\n");
	free(circle);

}

/*数据结构作业：变化的doom，初始化时每个人次有一个随机化密码（正整数），出圈的人密码将成为下一轮报数时的doom
	基本要求：利用单向循环链表存储结构模拟此过程
*/
typedef struct {
	int payload;
	int password;
	struct Node* next;
}Node;

Node *create(int n,int password[]){
	Node *p, *q, *head;
	int i;
	p = (Node *)malloc(sizeof(Node));
	head = p;
	p->payload = 1;
	p->password = password[0];
	//printf("payload:%d,password:%d\t", p->payload,p->password);

	/*尾增法*/
	for (i = 2; i <= n; i++) {
		q = (Node *)malloc(sizeof(Node));
		q->payload = i;
		q->password = password[i-1];
		p->next = q;
		p = q;
		//printf("payload:%d,password:%d\t", p->payload, p->password);
	}
	/*使之成为循环链表*/
	p->next = head;
	//printf("headpayload:%d,headpassword:%d\t", head->payload,head->password);
	return head;
}

void homework_josephus(Node *head , int doom) {
	int i;
	Node *p = head;
	Node *tmp1 =NULL;
	//printf("doom:%d\t", doom);

	/**/
	while (p->next != p)//直到最后一个
	{
		for ( i = 1; i < doom; i++)
		{
			tmp1 = p;
			p = p->next;
		}
		printf("%d,", p->payload);
		doom = p->password;
		//printf("doom:%d\t", doom);

		tmp1->next = p->next;
		free(p);
		p = tmp1->next;

	}
	printf("%d", p->payload);
	free(p);
}

/*
int main(void) {
	//josephus1(100, 2);
	//printf("\n___________________________________________________________________________________________________\n\n");
	//josephus2(10, 2);
	//printf("\n___________________________________________________________________________________________________\n\n");
	//josephus3(10, 2);
	//printf("\n___________________________________________________________________________________________________\n\n");
	int password[] ={ 3,1,7,2,4,8,4 };//长度为7
	//josephus_changeDoom(7, 20, password);
	//printf("\n___________________________________________________________________________________________________\n\n");
	Node *head = create(7, password);
	homework_josephus(head,20);
	getchar();//命令行停留
	return 1;
}
*/