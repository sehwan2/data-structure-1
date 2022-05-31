#include <stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;		//헤드 포인터의 값을 복사
	head = p;			//헤드 포인터 변경
	return head;		//변경된 헤드 포인터 반환
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
void print_list(ListNode* head)
{
	for (ListNode *p = head; p!=NULL; p=p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main(void)
{
	ListNode* head = NULL;

		head = insert_first(head, 10);	print_list(head);
		head = insert_first(head, 20);	print_list(head);
		head = insert(head, head, 30);	print_list(head);
	
	return 0;

}