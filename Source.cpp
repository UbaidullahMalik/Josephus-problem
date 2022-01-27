#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class CircularList
{
	Node* head;

public:
	CircularList()
	{
		head = NULL;
	}

	void Insert(int d)
	{

		if (head == NULL)
		{
			head = new Node();
			head->data = d;
			head->next = head;
		}
		else
		{
			Node* curr = head;
			
			while (curr->next != head)
			{
				curr = curr->next;
			}
			curr->next = new Node;
			curr->next->data = d;
			curr->next->next = head;
			
		}
	}
	void remove(int M)
	{
		if (head == NULL)
		{
			cout << "The List is Empty!" << endl;
			return;
		}
		else
		{
			int iterator = 0;
			Node* curr = head;
			if (M == 0)
			{
				while (curr->next != head)
				{
					
					Node* temp = curr;
					curr = curr->next;
					cout << temp->data;
					delete temp;
					cout << endl;
				}
				
				return;
			}

			while (curr->next != curr)
			{
				
				iterator++;
				if (iterator == M)
				{
					Node* temp = curr->next;
					curr->next = curr->next->next;
					if (temp == head)
					{
						head = curr;
					}
					cout << temp->data<<endl;
					delete temp;
					iterator = 0;
				}
				curr = curr->next;
			}
		}
	}
	void Display()
	{
		if (head != NULL)
		{
			Node* curr = head;
			do
			{
				cout << curr->data<<" ";
				curr = curr->next;
			} while (curr != head);
		}
		else
		{
			cout << "The List is Empty"<<endl;
		}
	}
};

int main()
{
	CircularList C1;
	C1.Insert(1);
	C1.Insert(2);
	C1.Insert(3);
	C1.Insert(4);
	C1.Insert(5);
	C1.Display();
	cout << endl;
	C1.remove(2);

}

