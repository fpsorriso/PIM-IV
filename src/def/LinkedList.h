/*
 * LinkedList.h
 *
 *  Created on: 18 de nov de 2018
 *      Author: sorriso
 */

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

struct sNode {
	void* value;
	struct sNode* next;
};

typedef struct sNode Node;
typedef Node LinkedList;

typedef int (*comparable)(void* pValue, void* pAnotherValue);
typedef void (*callback)(Node* pValue);

LinkedList* linkedListPut(void* pValue, Node* pNext);

int linkedListCount(LinkedList* pHead);

Node* linkedListSearch(LinkedList* pHead, void* pValue, comparable pCompareFunction);

Node* linkedListRemoveFront(LinkedList* pHead);

Node* linkedListRemoveBack(LinkedList* pHead);

Node* linkedListRemove(LinkedList* pHead, Node* node);

void linkedListForeach(LinkedList* pHead, callback function);

void linkedListDispose(Node *pHead);

#endif /* _LINKEDLIST_H_ */
