



/**����������Լɪ������
	N����Χ��һȦ���ӵ�һ���˿�ʼ����������m���˳�Ȧ��ʣ�µ��˼�����1��ʼ����������m���˳�Ȧ�����������ֱ�������˳�Ȧ��
*/

#include<stdio.h>

/*����ʵ��1,δ�Գ�Ȧ���˵Ľڵ����ɾ������,
��Ϊ(10,2)����֮��ԭ����������Ϊ{1,2,3,4,5,6,7,8,9,10}
	ʱ�临�Ӷȷ���:
*/
void josephus1(int amount, int doom) {
	int alive = amount;	//�Ҵ�����
	int number = 0;	//��������number == doomʱ����̭�����
	int index = 0;	//�±꣬Ϊ������-1
	int *circle = NULL;	//����������Ϊѭ�����飬�洢ÿ����

	/*��calloc()��������õ��Ŀռ䣬�Զ���ʼ��ÿ��Ԫ��Ϊ0��0Ϊ�Ҵ棬1Ϊ��̭����*/
	circle = (int *)calloc(sizeof(int), amount);

	//ֱ�������˳�Ȧ
	while (alive > 0)
	{
		number += 1 - circle[index];//����"0"����"1"�����м���
		if (number == doom) {
			alive == 1 ? printf("%d", index + 1) : printf("%d,", index + 1);//���λ��
			circle[index] = 1;//������Ȧ
			//�Ҵ�������1 ����������
			alive--;
			number = 0;
		}
		index = (index + 1) % amount;
	}
	printf("\n");
	free(circle);
}

/*����ʵ��2���Գ�Ȧ���˵Ľڵ����ɾ���������Ż���ʱ�临�Ӷ�,
��Ϊ(10,2)����֮��ԭ����������Ϊ{4,2,4,4,4,6,8,8,4,0}
	ʱ�临�Ӷȷ���:
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
			circle[preIndex] = circle[curIndex];//��Ȧ
		}
		else
		{
			preIndex = curIndex;//����������һ����
		}
		curIndex = circle[curIndex];
	}
	free(circle);
}


/*����ʵ��3���Գ�Ȧ���˵Ľڵ����ɾ���������Ż���ʱ�临�Ӷ�,
	ʱ�临�Ӷȷ���:
*/
void josephus3(int amount, int doom) {
	int alive = amount;	
	int curIndex = 0;			
	int preIndex = amount - 1; 
	int *circle = NULL;
	int index;

	circle = (int *)malloc(sizeof(int) * amount);
	for (index = 0; index < amount; index++) {
		circle[index] = (index + 1) % amount;	// ��ʼ������
	}

	while (alive > 0) {	
		int num = doom % alive - 1; // ֱ�Ӽ������Ҫ�ƶ���������
		// ֱ�Ӷ�λ��Ҫ��Ȧ����
		for (index = 0; index < (num == -1 ? alive - 1 : num); index++) {
			preIndex = curIndex;
			curIndex = circle[curIndex];
		}
		// ���˳�Ȧ��
		alive == 1 ? printf("%d", curIndex + 1) : printf("%d,", curIndex + 1);
		alive--;
		circle[preIndex] = circle[curIndex]; // �����ĳ�Ȧ������
		curIndex = circle[curIndex]; // ����������һ����
	}
	// ����㷨��normalJoseph.cЧ�����30%��

	free(circle);
}

/*Լɪ�򻷱仯�棨����ʵ�֣���
�仯��doom����ʼ��ʱÿ���˴���һ����������루������������Ȧ�������뽫��Ϊ��һ�ֱ���ʱ��doom
*/
void josephus_changeDoom(int amount, int doom,int password[]) {
	int alive = amount;	//�Ҵ�����
	int number = 0;	//��������number == doomʱ����̭�����
	int index = 0;	//�±꣬Ϊ������-1
	int *circle = NULL;	//����������Ϊѭ�����飬�洢ÿ����

	/*��calloc()��������õ��Ŀռ䣬�Զ���ʼ��ÿ��Ԫ��Ϊ0��0Ϊ�Ҵ棬1Ϊ��̭����*/
	circle = (int *)calloc(sizeof(int), amount);

	//ֱ�������˳�Ȧ
	while (alive > 0)
	{
		number += 1 - circle[index];//����"0"����"1"�����м���
		if (number == doom) {
			alive == 1 ? printf("%d", index + 1) : printf("%d,", index + 1);//���λ��
			circle[index] = 1;//������Ȧ
			doom = password[index];//������������Ϊ�µ�doom
			//�Ҵ�������1 ����������
			alive--;
			number = 0;
		}
		index = (index + 1) % amount;
	}
	printf("\n");
	free(circle);

}

/*���ݽṹ��ҵ���仯��doom����ʼ��ʱÿ���˴���һ����������루������������Ȧ�������뽫��Ϊ��һ�ֱ���ʱ��doom
	����Ҫ�����õ���ѭ������洢�ṹģ��˹���
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

	/*β����*/
	for (i = 2; i <= n; i++) {
		q = (Node *)malloc(sizeof(Node));
		q->payload = i;
		q->password = password[i-1];
		p->next = q;
		p = q;
		//printf("payload:%d,password:%d\t", p->payload, p->password);
	}
	/*ʹ֮��Ϊѭ������*/
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
	while (p->next != p)//ֱ�����һ��
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
	int password[] ={ 3,1,7,2,4,8,4 };//����Ϊ7
	//josephus_changeDoom(7, 20, password);
	//printf("\n___________________________________________________________________________________________________\n\n");
	Node *head = create(7, password);
	homework_josephus(head,20);
	getchar();//������ͣ��
	return 1;
}
*/