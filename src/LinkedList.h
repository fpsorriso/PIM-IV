/*
 * LinkedList.h
 *
 *  Created on: 18 de nov de 2018
 *      Author: sorriso
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

#include <stdlib.h>
#include <Exceptions.h>

struct node {
	void* value;
	struct node* next;
};

typedef struct node Node;
typedef struct node LinkedList;

typedef int (*comparable)(void* value, anotherValue);

Node* linkedList_put(void* value, Node* next) {
	Node* new_node = (Node*) malloc(sizeof(Node));

	if (new_node == NULL) {
		exit(throwStackOverFlowException());
	}

	new_node->value = value;
	new_node->next = next;

	return new_node;
}

int linkedList_count(Node *head) {
	Node *cursor = head;
	int c = 0;

	while (cursor != NULL) {
		c++;
		cursor = cursor->next;
	}

	return c;
}

Node* linkedList_search(Node* head, void* value, comparable compareFunction) {

	if (head != NULL) {
		if (compareFunction(head->value, value)) {
			return head;
		}

		return search(head->next, value, compareFunction);
	}

	return NULL;
}

Node* linkedList_removeFront(Node* head) {
	if (head == NULL)
		return NULL;
	Node *front = head;
	head = head->next;
	front->next = NULL;
	/* is this the last node in the list */
	if (front == head)
		head = NULL;
	free(front);
	return head;
}

Node* linkedList_removeBack(Node* head) {
	if (head == NULL)
		return NULL;

	Node *cursor = head;
	Node *back = NULL;
	while (cursor->next != NULL) {
		back = cursor;
		cursor = cursor->next;
	}
	if (back != NULL)
		back->next = NULL;

	/* if this is the last node in the list*/
	if (cursor == head)
		head = NULL;

	free(cursor);

	return head;
}

Node* linkedList_remove(Node* head, Node* nd) {
	/* if the node is the first node */
	if (nd == head) {
		head = linkedList_removeFront(head);
		return head;
	}

	/* if the node is the last node */
	if (nd->next == NULL) {
		head = linkedList_removeBack(head);
		return head;
	}

	/* if the node is in the middle */
	Node* cursor = head;
	while (cursor != NULL) {
		if (cursor->next = nd) {
			break;
		}

		cursor = cursor->next;
	}

	if (cursor != NULL) {
		Node* tmp = cursor->next;
		cursor->next = tmp->next;
		tmp->next = NULL;
		free(tmp);
	}

	return head;
}

void linkedList_dispose(Node *head) {
	Node *cursor, *tmp;

	if (head != NULL) {
		cursor = head->next;
		head->next = NULL;

		while (cursor != NULL) {
			tmp = cursor->next;
			free(cursor);
			cursor = tmp;
		}
	}
}

#endif /* SRC_LINKEDLIST_H_ */
