/*
 * LinkedList.c
 *
 *  Created on: 19 de nov de 2018
 *      Author: sorriso
 */

#include "../def/LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include "../def/Constante.h"

Node* linkedListPut(void* pValue, Node* pNext) {
	Node* new_node = (Node*) malloc(sizeof(Node));

	if (new_node == NULL) {
		printf("%d - %s", _ERROR_CODE_MEMORIA_INSUFICIENTE,
		_EXCEPTION_MEMORIA_INSUFICIENTE);
		return NULL ;
	}

	new_node->value = pValue;
	new_node->next = pNext;

	return new_node;
}

int linkedListCount(Node *pHead) {
	Node *cursor = pHead;
	int c = 0;

	while (cursor != NULL ) {
		c++;
		cursor = cursor->next;
	}

	return c;
}

Node* linkedListSearch(Node* pHead, void* pValue, comparable pCompareFunction) {

	if (pHead != NULL) {
		if (pCompareFunction(pHead->value, pValue) == 0) {
			return pHead;
		}

		return linkedListSearch(pHead->next, pValue, pCompareFunction);
	}

	return NULL ;
}

Node* linkedListRemoveFront(Node* pHead) {
	if (pHead == NULL) {
		return NULL ;
	}

	Node *front = pHead;
	pHead = pHead->next;
	front->next = NULL;

	/* is this the last node in the list */
	if (front == pHead) {
		pHead = NULL;
	}

	free(front);
	return pHead;
}

Node* linkedListRemoveBack(Node* pHead) {
	if (pHead == NULL) {
		return NULL ;
	}

	Node *cursor = pHead;
	Node *back = NULL;

	while (cursor->next != NULL ) {
		back = cursor;
		cursor = cursor->next;
	}

	if (back != NULL) {
		back->next = NULL;
	}

	/* if this is the last node in the list*/
	if (cursor == pHead) {
		pHead = NULL;
	}

	free(cursor);

	return pHead;
}

Node* linkedListRemove(LinkedList* pHead, Node* pNode) {
	/* if the node is the first node */
	if (pNode == pHead) {
		pHead = linkedListRemoveFront(pHead);
		return pHead;
	}

	/* if the node is the last node */
	if (pNode->next == NULL) {
		pHead = linkedListRemoveBack(pHead);
		return pHead;
	}

	/* if the node is in the middle */
	Node* cursor = pHead;

	while (cursor != NULL ) {
		if (cursor->next == pNode) {
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

	return pHead;
}

void linkedListDispose(LinkedList* pHead) {
	Node *cursor, *tmp;

	if (pHead != NULL) {
		cursor = pHead->next;
		pHead->next = NULL;

		while (cursor != NULL ) {
			tmp = cursor->next;
			free(cursor);
			cursor = tmp;
		}
	}
}

void linkedListForeach(LinkedList* head, callback function) {
	if (head != NULL) {
		function(head->value);
		linkedListForeach(head->next, function);
	}
}
