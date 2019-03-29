#include<stdio.h>
#include<math.h>
/*���ݽṹ��ҵ��
	����Ҫ������˫��ѭ������ʵ��
*/

typedef struct node {
	int info;//����������
	struct node *prior, *next;
}DLink;

/*����Ĵ���*/
DLink *DLinkCreat() {
	DLink *head, *p, *last;
	int flag = 0;//�����Ƿ�Ϸ�
	char c;
	int num;
	int len = 0;//��¼����
	head = (DLink *) malloc(sizeof(DLink));
	head->next = NULL;
	head->prior = NULL;
	head->info = 1;//����λ
	last = head;

	/*�������;
	��������̽���*/
	while ((c=getchar())!=';')
	{
		if (c == '-') {
			head->info = -1;
			continue;
		}
		/*ĳЩ����³���bug�����û����ϸ�����ÿ��λ��;�ָ�*/
		if (c == ',') {
			continue;
		}
		num = c - '0';
		if (num > 9 || num < 0) {
			flag = -1;//�Ƿ�����
			break;
		}

		p = (DLink *)malloc(sizeof(DLink));
		p->info = num;
		len++;
		if (head->next == NULL) {
			head->next = p;
			p->prior = head;
			last = p;
		}
		else
		{
			p->prior = last;
			last->next = p;
			last = p;
		}
	}
	if (flag == 0) {
		last->next = NULL;
		head->prior = last;
		head->info = (head->info)*len;//ͷ����������Я������ķ����볤��
	}
	else
	{
		head->info = 0;
	}

	return head;
}


DLink *addition(DLink *a, DLink *b) {
	/*�ϳ���������Ϊ������upper
	*/
	int symbol = abs(a->info) / (a->info);
	int len_a = abs(a->info);
	int len_b = abs(b->info);
	DLink *upper, *lower;
	if (len_a > len_b) {
		upper = a;
		lower = b;
	}
	else
	{
		upper = b;
		lower = a;
	}
	int len_up = abs(upper->info);
	int len_low = abs(lower->info);
	int cnt = 0;
	int carry = 0;

	while (cnt != len_up)
	{
		//˫��ѭ�������Ӹ�λ��ʼ����
		upper = upper->prior;
		lower = lower->prior;
		if (cnt < len_low) {
			upper->info = upper->info + lower->info + carry;
		}
		else
		{
			upper->info = upper->info + carry;
		}
		//info����ʮ����λ
		carry = 0;
		if (upper->info >= 10) {
			upper->info -= 10;
			carry = 1;
		}
		++cnt;
	}

	/*ͷ�˲���*/
	if (carry) {
		DLink *p;
		p = (DLink *)malloc(sizeof(DLink));
		p->info = carry;
		p->prior = upper->prior;
		upper->prior->next = p;
		p->next = upper;
		upper->prior = p;
		upper = p;
		++len_up;
	}

	upper = upper->prior;
	upper->info = symbol * len_up;
	return upper;
}

DLink *subtraction(DLink *a, DLink *b) {
	int len_a = abs(a->info);
	int len_b = abs(b->info);
	DLink *upper = NULL;
	DLink *lower = NULL;
	if (len_a > len_b) {
		upper = a;
		lower = b;
	}
	else if (len_a<len_b){
		upper = b;
		lower = a;
	}
	/*len_a == len_b*/
	else
	{
		DLink *temp1 = a, *temp2 = b;
		int cnt = 0;
		temp1 = temp1->next;
		temp2 = temp2->next;
		while (cnt != len_a)
		{
			if (temp1->info > temp2->info) {
				upper = a;
				lower = b;
				break;
			}
			else if(temp1->info<temp2->info)
			{
				upper = b;
				lower = a;
				break;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
			++cnt;
		}
		if (cnt == len_a)
		{
			upper = a;
			lower = b;
		}
	}
	int len_up = abs(upper->info);
	int len_low = abs(lower->info);
	int symbol = abs(upper->info) / (upper->info);
	int cnt = 0;
	int carry = 0;
	while (cnt != len_up)
	{
		upper = upper->prior;
		lower = lower->prior;
		if (cnt < len_low) {
			upper->info = upper->info - lower->info - carry;
		}
		else
		{
			upper->info = upper->info - carry;
		}
		carry = 0;
		if (upper->info < 0) {
			upper->info += 10;
			carry = 1;
		}
		++cnt;
	}
	upper = upper->prior;
	upper->info = symbol * len_up;
	return upper;
}

void printDlink(DLink *head) {
	DLink *p;
	p = head;
	int len = abs(p->info);
	int cnt = 1;
	if (p->info < 0) {
		printf("-");
	}
	p = p->next;
	while (p->info == 0 &&p->next !=NULL)
	{
		p = p->next;
		--len;
	}
	while (len)
	{
		printf("%d", p->info);
		p = p->next;
		--len;
		if (!(len % 4) && len) putchar(',');

	}
}

/*
void main() {
	char n='y';
	char c;
	while (n=='y')
	{
		
	printf("��������������ĳ�����,�Էֺš�;��������������ÿ��������ÿ��λ�ö��š�,������\n");
	DLink *a;
	a = DLinkCreat();
	if (a->info == 0) {
		printf("a invalid input");
	}
	else
	{
		DLink *b;
		b = DLinkCreat();
		if (b->info == 0) {
			printf("b invalid input");
		}
		else
		{
			DLink *c;
			if ((a->info)*(b->info) < 0)
			{
				c = subtraction(a, b);
			}
			else
			{
				c = addition(a, b);
			}
			printDlink(c);
		}
	}
	c=getchar();
	printf("�������������y:\t");
	scanf_s("%c", &n, 1);
	c=getchar();
	}
	system("pause");
}*/