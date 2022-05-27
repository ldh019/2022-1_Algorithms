#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list* next;
}node;

int list_size(node* list) {
	int cnt = 0;
	while (list->next) {
		cnt++;
		list = list->next;
	}
	return cnt;
}

void list_append(node* list, int data) {
	if (list->next == NULL) {
		node* append = malloc(sizeof(node));
		append->data = data;
		append->next = NULL;

		list->next = append;
	}
	else {
		node* last = list;
		node* append = malloc(sizeof(node));
		while (last->next)
			last = last->next;

		last->next = append;
		append->data = data;
		append->next = NULL;
	}
}

void list_insert(node* list, int data, int position) {
	node* target = list;
	node* insert = malloc(sizeof(node));

	if (position == 0) {
		insert->next = list->next;
		list->next = insert;
	}
	else {
		int cnt = 0;

		while (cnt != position) {
			if (cnt == position - 1) {
				insert->next = target->next;
				target->next = insert;
			}
			target = target->next;
			cnt++;
		}
	}
}

void list_traverse(node* list, int* ret) {
	while (list->next) {
		list = list->next;
		*(ret++) = list->data;
	}
}

void list_remove(node* list, int position) {
	if (position == 0) {
		node* remove = list->next;
		node* next = remove->next;

		list->next = next;
		free(remove);
	}
	else {
		int cnt = 0;
		node* remove = list->next;
		node* next = remove->next;

		while (cnt != position) {
			
			if (cnt == position - 1) {
				list->next = next;
				free(remove);
				break;
			}
			remove = next;
			next = remove->next;
			cnt++;
		}
	}
}

node* list_reverse(node* head) {
	node* origin, * ret, * back;

	origin = head;
	ret = NULL;

	while (origin) {
		back = ret;
		ret = origin;
		origin = origin->next;
		ret->next = back;
	}

	return ret;
}

int main() {
	node* head = malloc(sizeof(node));
	srand(time(NULL));

	head->next = NULL;

	for (int i = 0; i < 10; i++) {
		list_append(head, rand() % 10);
	}

	int len = list_size(head);
	int* arr = malloc(sizeof(int) * len);
	list_traverse(head, arr);
	printf("Original linked list\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);

	node* reverse = malloc(sizeof(node) * len);
	reverse->next = list_reverse(head);

	arr = malloc(sizeof(int) * len);
	list_traverse(reverse, arr);
	printf("Reversed linked list\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}