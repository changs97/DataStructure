#include <stdio.h>
#include <stdlib.h>

typedef int element; // 요소의 타입
typedef struct DlistNode { // 노드의 타입
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
} DlistNode;
typedef struct DequeType { // 덱의 타입
	DlistNode* head;
	DlistNode* tail;
} DequeType;


void init(DequeType* dq) // 덱 초기화 함수
{
	dq->head = dq->tail = NULL;
}

int is_empty(DequeType* dq) // 덱이 비어있는지 확인하는 함수
{
	return (dq->head == NULL);
}

DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) // 노드를 생성하는 함수
{
	DlistNode* new_node = (DlistNode*)malloc(sizeof(DlistNode)); // 동적 메모리 할당
	new_node->llink = llink; // 새 노드의 llink 지정
	new_node->data = item; // 새 노드의 data 지정
	new_node->rlink = rlink; // 새 노드의 rlink 지정
	return new_node;
}

void add_front(DequeType* dq, element item) // 덱의 앞에서 노드를 삽입하는 함수
{
	// 새 노드 생성 (새 노드가 head가 되기 때문에 llink는 NULL, rlink는 head)
	DlistNode* new_node = create_node(NULL, item, dq->head); 
	if (is_empty(dq)) // 덱이 비어 있으면
		dq->tail = new_node; // 덱의 tail에 새 노드 지정
	else // 덱이 비어 있지 않으면
		dq->head->llink = new_node; // 덱의 head의 llink에 새 노드 지정 (new_node의 rlink는 head인 상태)
	dq->head = new_node; // 덱의 head에 새 노드 지정
}

void add_rear(DequeType* dq, element item) // 덱의 뒤에서 노드를 삽입하는 함수
{
	// 새 노드 생성 (새 노드가 tail이 되기 때문에 llink는 tail, rlink는 NULL)
	DlistNode* new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) // 덱이 비어 있으면
		dq->head = new_node; // 덱의 head에 새 노드 지정
	else
		dq->tail->rlink = new_node; // 덱의 tail의 rlink에 새 노드 지정 (new_node의 llink는 tail인 상태)
	dq->tail = new_node; // 덱의 tail에 새 노드 지정
}

element delete_front(DequeType* dq) // 덱의 앞에서 노드를 삽입하는 함수
{
	element item;
	DlistNode* removed_node;

	removed_node = dq->head; // 삭제할 노드
	item = removed_node->data; // 데이터 추출
	dq->head = dq->head->rlink; // 헤드 포인터 변경
	free(removed_node); // 메모리 공간 반납
	if (dq->head == NULL) // 공백상태이면
		dq->tail = NULL;
	else // 공백상태가 아니면
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