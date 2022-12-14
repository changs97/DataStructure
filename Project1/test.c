#include <stdio.h>
#include <stdlib.h>

typedef int element; // ����� Ÿ��
typedef struct DlistNode { // ����� Ÿ��
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;
typedef struct DequeType { // ���� Ÿ��
	DlistNode* head;
	DlistNode* tail;
} DequeType;


void init(DequeType* dq) // �� �ʱ�ȭ �Լ�
{
	dq->head = dq->tail = NULL;
}

int is_empty(DequeType* dq) // ���� ����ִ��� Ȯ���ϴ� �Լ�
{
	return (dq->head == NULL);
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) // ��带 �����ϴ� �Լ�
{
	DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode)); // ���� �޸� �Ҵ�
	new_node->llink = llink; // �� ����� llink ����
	new_node->data = item; // �� ����� data ����
	new_node->rlink = rlink; // �� ����� rlink ����
	return new_node;
}

void add_front(DequeType* dq, element item) // ���� �տ��� ��带 �����ϴ� �Լ�
{
	// �� ��� ���� (�� ��尡 head�� �Ǳ� ������ llink�� NULL, rlink�� head)
	DlistNode* new_node = create_node(NULL, item, dq->head); 
	if (is_empty(dq)) // ���� ��� ������
		dq->tail = new_node; // ���� tail�� �� ��� ����
	else // ���� ��� ���� ������
		dq->head->llink = new_node; // ���� head�� llink�� �� ��� ���� (new_node�� rlink�� head�� ����)
	dq->head = new_node; // ���� head�� �� ��� ����
}

void add_rear(DequeType* dq, element item) // ���� �ڿ��� ��带 �����ϴ� �Լ�
{
	// �� ��� ���� (�� ��尡 tail�� �Ǳ� ������ llink�� tail, rlink�� NULL)
	DlistNode* new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) // ���� ��� ������
		dq->head = new_node; // ���� head�� �� ��� ����
	else
		dq->tail->rlink = new_node; // ���� tail�� rlink�� �� ��� ���� (new_node�� llink�� tail�� ����)
	dq->tail = new_node; // ���� tail�� �� ��� ����
}

element delete_front(DequeType* dq) // ���� �տ��� ��带 �����ϴ� �Լ�
{
	element item;
	DlistNode* removed_node;

	removed_node = dq->head; // ������ ���
	item = removed_node->data; // ������ ����
	dq->head = dq->head->rlink; // ��� ������ ����
	free(removed_node); // �޸� ���� �ݳ�
	if (dq->head == NULL) // ��������̸�
		dq->tail = NULL;
	else // ������°� �ƴϸ�
		dq->head->llink = NULL;
	
	return item;
}


int main() {

	DequeType dq;
	DequeType* pdq;
	pdq = &dq;
	                 
	init(pdq);  // NULL NULL
	add_front(pdq, 1); // NULL 1
	add_front(pdq, 2); // 2 1
	add_rear(pdq, 3); // 2 1 3
	delete_front(pdq); // 1 3

	return 0;
}