#include<iostream>

using namespace std;

template<class T>
class QueueNode {
public:
	T data;
	QueueNode<T>* next;
	QueueNode()
	{
		this->next = NULL;
	}
	void add(QueueNode<T>* head, T newData)
	{
		if (head->data == NULL)
		{
			head->data = newData;
			head->next = NULL;
		}
		else
		{
			QueueNode<T>* temp = head;
			QueueNode<T>* new_node = new QueueNode<T>();
			new_node->data = newData;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			new_node->next = NULL;
			temp->next = new_node;
		}
	}
	void addToHead(QueueNode<T>* head, T newData)
	{
		if(head->data == NULL)
		{
			head->data = newData;
			head->next = NULL;
		}
		else 
		{
			QueueNode<T>* temp = head;
			QueueNode<T>* tail;
			/*QueueNode<T>* newNode = new QueueNode<T>();
			newNode->data = newData;
			newNode->next = temp;*/

			head->data = newData;
			head->next = temp;
			head = newNode;
		}
	}
	void pop(QueueNode<T>* head)
	{
		QueueNode<T>* temp = head;
		QueueNode<T>* prev = head;
		while (temp->next != NULL)
		{
			temp = temp->next; // 12 45 5 6 9 8 
			if (temp->next != NULL)
			{
				prev = prev->next;
			}
		}
		prev->next = NULL;
	}

	void print(QueueNode<T>* head)
	{
		QueueNode<T>* temp = head;
		while(temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		cout << "***************" << endl;
	}
};

int main()
{
	QueueNode<int>* node = new QueueNode<int>();
	QueueNode<char>* node2 = new QueueNode<char>();
	QueueNode<double>* node3 = new QueueNode<double>();
	
	node->add(node,15);
	node->add(node,55);
	node->add(node,25);
	node->addToHead(node, 61);
	node->add(node,65);
	node->addToHead(node, 67);
	//node->pop(node);
	node->print(node);
	node2->add(node2, 'a');
	node2->add(node2, 'b');
	node2->add(node2, 'c');
	node2->add(node2, 'd');
	node2->pop(node2);
	node2->print(node2);
	node3->add(node3, 15.5);
	node3->add(node3, 55.4);
	node3->add(node3, 25.1);
	node3->add(node3, 65.78);
	node3->print(node3);
	return 0;
}