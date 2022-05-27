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

void list_find_dupl(node* list) {
	node* check, * remove;
	check = list->next;

	while (check) {
		remove = check;
		while (remove->next) {
			if (check->data == (remove->next)->data)
				remove->next = (remove->next)->next;

			else
				remove = remove->next;
		}
		check = check->next;
	}
}

int main() {
	node* head = malloc(sizeof(node));
	srand(time(NULL));

	head->next = NULL;

	for (int i = 0; i < 20; i++) {
		list_append(head, rand() % 50 + 1);
	}

	int len = list_size(head);
	int* arr = malloc(sizeof(int) * len);
	list_traverse(head, arr);
	printf("Original linked list\n");
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);

	list_find_dupl(head);
	len = list_size(head);
	arr = malloc(sizeof(int) * len);
	list_traverse(head, arr);
	printf("Linked list removed duplicate numbers\n");
	for (int i = 0; i < list_size(head); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}