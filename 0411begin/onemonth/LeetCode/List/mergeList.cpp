#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}LinkNode;

LinkNode *createLink(int n) {
	LinkNode *head,*tail,*p;
	head = new LinkNode;
	head->next = NULL;
	tail = head;
	while (n --)
	{
		p = new LinkNode;
		cin >> p->data;
        tail ->next = p;
        tail = p;
	}
	return head;
}

LinkNode *mergeLink(LinkNode *head1, LinkNode *head2) {
	LinkNode *p1, *p2,*tail,*head;
	p1 = head1->next;
	p2 = head2->next;
	tail = head;
	while (p1 && p2)
	{
		if (p1->data < p2->data) {
			tail->next = p1;
			tail = p1;
			p1 = p1->next;
		}
		else
		{
			tail->next = p2;
			tail = p2;
			p2 = p2->next;
		}
	}
	if (p1) {
		tail->next = p1;
	}
	else
	{
		tail->next = p2;
	}

	return head;

}


int main() {
	int M, N;
	cin >> M;
	cin >> N;
	LinkNode *head1, *head2,*head;
	head1 =createLink(M);
	head2 =createLink(N);
    head = mergeLink(head1, head2);
	head = head ->next;

	while (head)
	{
		if (head->next != NULL) {
			cout << head->data << " ";
		}
		else
		{
			cout << head->data << endl;
		}
		head = head->next;
	}


}
