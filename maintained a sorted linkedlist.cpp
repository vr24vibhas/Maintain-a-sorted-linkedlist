#include<iostream>
using namespace std

//creating a class of node type
class Node {
    public:
		int data;
		Node* next;

		Node() {        //custom default constructor
			data = 0;
			next = NULL;
		}

		Node(int d) {   //custom argument constructor
         
			data = d;
			next = NULL;
		}

};

//creating a class for head creation 
class create_head {
    public:
		Node* head;

		create_head() {   //custom default constructor
			head = NULL;
		}

		create_head(Node* n) {
			head = n;
		}
        
}

//Function for creation of inserting Node 
Node * create_node(int d) {
	return new Node(d);
}


//Function for Insertion of new Node 
void Insert_and_sort_node(Node ** N, Node *New_node) {
	Node* temp;
	temp = New_node;
	New_node->next = *N;
	*N = temp;
}


int main() {
	int d;
	char ch;
	

	//For creating first Node
	cout << "Enter the data of first Node \n";
	cin >> d;
	create_head s(new Node(d));
	Node* temp;
	temp = s.head;

	//For Creating and adding further Nodes in the list
	cout << "Enter y or Y for creating a node \n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		while (true) {
			cout << "Enter the data of new node in sorted manner\n";
			cin >> d;
			
			if (d > 0) {
				temp->next=new Node(d);
				temp = temp->next;
			}
			else { break; }
		}
	}

	//For Printing Linklist
	Node* temp1;
	temp1 = s.head;
	cout << "Link List Elements in sorted manner \n";
	while (temp1 != NULL) {
		cout << temp1->data << " ";
		temp1 = temp1->next;
	}
	cout << "\n";

	//For insertion of Node
	cout << "Enter y or Y for inserting a node \n";
	cin >> ch;
	if (ch == 'y' || ch == 'Y') {
		cout << "Enter the data you want to store in new Node \n";
		cin >> d;
		Node* New_node;
		New_node = create_node(d);

		Node* ptr;
		ptr = s.head;
		while (ptr != NULL) {
			if (New_node->data > ptr->data && New_node->data < ptr->next->data) {
				Insert_and_sort_node(&ptr->next, New_node);
			}
			ptr = ptr->next;
		}

		//For Printing Linklist
		Node* temp2;
		temp2 = s.head;
		cout << "Link List Elements in sorted manner \n";
		while (temp2 != NULL) {
			cout << temp2->data << " ";
			temp2 = temp2->next;
		}
	}
	

	return 0
}
