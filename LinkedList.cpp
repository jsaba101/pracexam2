#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		deleteFront();
	}
}

void LinkedList::insertFront(int item) {
	Node* newNode = new Node(item, head);
	head = newNode;
}

void LinkedList::deleteFront() {
	if(head != nullptr) {
		Node* oldHead = head;
		head = head->link;
		delete oldHead;
	}
}

void LinkedList::printList() {
	Node* currNode = head;
	while(currNode != nullptr) {
		std::cout << currNode->data << " ";
		currNode = currNode->link;
	}
}

/////////// your code goes here... DO NOT change the function signatures ///////////

Node* LinkedList::traverse(int index){
	int position = 0;
	Node *currNode = head;

	while (currNode != nullptr && position < index){
		currNode = currNode->link;
		position++;
	}
	return currNode;
}

bool LinkedList::swap(int pos1, int pos2) {
	Node *pos1Node = traverse(pos1-1);
	Node *pos2Node = traverse(pos2-1);

	if (pos1Node->link == nullptr || pos2Node->link == nullptr){
		return false;
	} else {
		int temp = pos1Node->data;
		pos1Node->data = pos2Node->data;
		pos2Node->data = temp;
		return true;
	}
}

bool LinkedList::find_and_delete(int target) {
	Node *prevNode = head;
	Node *currNode = prevNode;
	int index = 0;

	while (currNode->link != nullptr && currNode->data != target){
		currNode = currNode->link;
		index++;
	}
	prevNode = traverse(index-1);

	if (currNode->link == nullptr && currNode->data != target){
		return false;
	} else {
		currNode = prevNode;
		prevNode = prevNode->link;
		delete currNode;
		return true;
	}
}