/*
 * LinkedList.h
 *
 *  Created on: 18 de nov de 2018
 *      Author: sorriso
 */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct node {
	void* value;
	struct node* next;
};

typedef struct node Node;
typedef struct node LinkedList;

typedef int (*comparable)(void* value, void* anotherValue);
typedef void (*callback)(Node* value);

LinkedList* linkedList_put(void* value, Node* next);

int linkedList_count(LinkedList* head);

Node* linkedList_search(LinkedList* head, void* value, comparable compareFunction);

Node* linkedList_removeFront(LinkedList* head);

Node* linkedList_removeBack(LinkedList* head);

Node* linkedList_remove(LinkedList* head, Node* node);

void linkedList_foreach(LinkedList* head, callback function);

void linkedList_dispose(Node *head);

#endif /* _LINKEDLIST_H_ */
