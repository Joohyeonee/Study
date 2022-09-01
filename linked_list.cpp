#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* nextNode;
	Node* prevNode; 
	Node* last; 
};

Node* init(Node* temp) { 
	temp = new Node();
	temp->nextNode = NULL;
	temp->prevNode = NULL;
	temp->data = 0;
	return temp;
}

Node* insert(Node* head, int data) {
	if (head == NULL) { 
		head = init(head);
		head->data = data;
		head->last = head;
		return head;
	}

	Node* currentNode = head->last;
	Node* newNode = NULL;
	newNode = init(newNode);
	newNode->data = data;
	newNode->prevNode = currentNode;
	currentNode->nextNode = newNode;
	head->last = newNode;
	return head;
}

int getData(Node* head, int index) {
	Node* currentNode = head;
	for (int i = 0; i<index && currentNode != NULL; i++) {
		currentNode = currentNode->nextNode;
	}
	if (currentNode == NULL) {
		return -1; 
	}
	return currentNode->data;
}

Node* remove(Node* head, int index) {
	Node* currentNode = head;
	Node* prevNode = NULL;
	for (int i = 0; i<index && currentNode != NULL; i++) {
		prevNode = currentNode;
		currentNode = currentNode->nextNode;
		if (currentNode == NULL) {
			return head;
		}
		if (prevNode == NULL) {
			head->nextNode->last = head->last;
			head = head->nextNode;
		}
		if (currentNode->nextNode == NULL) {
			head->last = prevNode;
			prevNode->nextNode = NULL;
		}
		prevNode->nextNode = currentNode->nextNode;
		currentNode->nextNode->prevNode = prevNode;
		return head;
	}
}

void print(Node* currentNode) { 
	while (currentNode != NULL) {
		cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}
	cout << endl;
	return;
}

int main() {
	Node* list = NULL;
	list = insert(list, 1);
	list = insert(list, 2);
	list = insert(list, 3);
	list = insert(list, 4);
	list = insert(list, 5);
	print(list);

	list = remove(list, 2);
	cout << "remove: ";
	print(list);
	list = insert(list, 200);
	print(list);

	return 0;
}