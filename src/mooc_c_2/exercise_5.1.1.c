/*
 *
 *  Created on: Apr 9, 2015
 *      Author: lisong
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef struct {
	int size;
	Node *head;
	Node *last;
} List;

List list_create();

void print_list(const List *p);

int list_size();

void list_add(List *p, int value);

void list_remove(List *p, int value);

int main(void) {
	int x;
	List a = list_create();

	while(1) {
		scanf("%d", &x);
		if (x == -1) {
			break;
		}
		list_add(&a, x);
	}

	int i,j;
	for (i=list_size(&a) - 1; i>=0; i--) {
		Node *x = a.head;
		for (j=0; j<i; j++) {
			x = x->next;
		}
		printf("%d", x->value);
		if (i) {
			printf(" ");
		}
	}
	return 0;
}

List list_create() {
	List a;
	a.size = 0;
	a.head = NULL;
	a.last = NULL;

	return a;
}

void list_add(List *p, int value) {
	Node *n = (Node*) malloc(sizeof(Node));
	n->value = value;
	n->next = NULL;
	if (p->head) {
		p->last->next = n;
		p->last = n;
	} else {
		p->head = n;
		p->last = n;
	}
	p->size++;
}

void list_remove(List *p, int value) {
	if (list_size(p)) {
		Node *x;
		Node *y = NULL; // the last one
		for (x = p->head; x;) {
			if (x->value == value) {
				if (x == p->head) {
					p->head = x->next;

				} else if (x == p->last) {
					if (y) {
						y->next = NULL;
					}
				} else {
					if (y) {
						y->next = x->next;
					}
				}
				free(x);
				p->size--;
				break;
			}
			y = x;
			x = x->next;
		}
	}
}

void print_list(const List *p) {
	if (list_size(p)) {
		Node *x = p->head;
//			printf("%p", x);
		while (x->next) {
			printf("%d", x->value);
			x = x->next;
		}
		printf("%d", x->value);
	}
	printf("\nsize(%d)\n", list_size(p));
}

int list_size(const List *p) {
	return p->size;
}
