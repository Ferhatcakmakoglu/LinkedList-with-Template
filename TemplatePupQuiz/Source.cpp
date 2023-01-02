#include<iostream>

using namespace std;

template<class T>
class QueueNode {
public:
	T data;
	QueueNode<T>* sonra;
	//QueueNode<T>* head;
	QueueNode()
	{
		//this->head = NULL;
		this->sonra = NULL;
	}
	void add(QueueNode<T>* head, T newData)
	{
		if (head->data == NULL)
		{
			head->data = newData;
			head->sonra = NULL;
		}
		else
		{
			QueueNode<T>* temp = head;
			QueueNode<T>* new_node = new QueueNode<T>();
			new_node->data = newData;
			while (temp->sonra != NULL)
			{
				temp = temp->sonra;
			}
			new_node->sonra = NULL;
			temp->sonra = new_node;
		}
	}

	void pop(QueueNode<T>* head)
	{
		QueueNode<T>* temp = head;
		QueueNode<T>* prev = head;
		while (temp->sonra != NULL)
		{
			temp = temp->sonra; // 12 45 5 6 9 8 
			if (temp->sonra != NULL)
			{
				prev = prev->sonra;
			}
		}
		prev->sonra = NULL;
	}

	void print(QueueNode<T>* head)
	{
		QueueNode<T>* temp = head;
		while(temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->sonra;
		}
		cout << "***************" << endl;
	}
};
//inan ülgü
int main()
{
	QueueNode<int>* node = new QueueNode<int>();
	QueueNode<char>* node2 = new QueueNode<char>();
	
	node->add(node,15);
	node->add(node,55);
	node->add(node,25);
	node->add(node,65);
	node->pop(node);
	node->print(node);
	node2->add(node2, 'a');
	node2->add(node2, 'b');
	node2->add(node2, 'c');
	node2->add(node2, 'd');
	node2->pop(node2);
	node2->print(node2);
	
	return 0;
}