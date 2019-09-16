//Lily Zelt
//bzgkd@mail.umkc.edu

#include <iostream>
#include <string>
using namespace std;

int main() {

	//Modified single linked list structure pulled from lecture_4.ppt on canvas.
	struct Node {
		// Data Fields
		/** The data */
		string data;
		/** The pointer to the next node. */
		Node* next;

		// Constructor
		/** Creates a new Node that points to another Node.
		@param data_item The data stored
		@param next_ptr Pointer to the Node that is
		pointed to by the new Node
		*/
		Node(const string& data_item, Node* next_ptr = NULL) {
			data = data_item;
			next = next_ptr;
		};
	};
	
	//Initializing linked list.
	//head points at first node.
	Node* head = new Node("Tom");
	head->next = new Node("John");
	head->next->next = new Node("Harry");
	head->next->next->next = new Node("Sam");

	//tail points at last node.
	Node* tail = head->next->next->next;

	//5a. - Insert "Bill" before "Tom"
	head = new Node("Bill", head);

	//5b. - Insert "Sue" before "Sam"
	Node* iterator = head;
	Node* temp_ptr;
	while (iterator->next->data != "Sam") {
		iterator = iterator->next;
	}
	temp_ptr = iterator->next;
	iterator->next = new Node("Sue");
	iterator->next->next = temp_ptr;


	//5c. - Remove "Bill".
	//Bill is the first Node, so delete Bill and remap head to second node.
	iterator = head;
	if (iterator->data == "Bill") {
		temp_ptr = iterator->next;
		delete iterator;
		head = temp_ptr;
	}
	//Bill is not the First Node, so delete Bill and remap previous node to Bill's next node.
	else {
		while (iterator->next->data != "Bill") {
			iterator = iterator->next;
		}
		temp_ptr = iterator->next->next;
		delete iterator->next;
		iterator->next = temp_ptr;
	}
	

	//5d. - Remove "Sam".
	//Sam is the first Node, so delete Sam and remap head to second node.
	iterator = head;
	if (iterator->data == "Sam") {
		temp_ptr = iterator->next;
		delete iterator;
		head = temp_ptr;
	}
	//Sam is not the First Node, so delete Sam and remap previous node to Sam's next node.
	else {
		while (iterator->next->data != "Sam") {
			iterator = iterator->next;
		}
		temp_ptr = iterator->next->next;
		delete iterator->next;
		iterator->next = temp_ptr;
	}

	system("pause");
}