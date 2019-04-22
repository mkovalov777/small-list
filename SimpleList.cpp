#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
template <class L>
class List
	{
	private:
		class Element
		{
		private:
			L value;
			Element* next;
			Element* previous;
		public:
			Element() {}
			~Element() {}
			friend List;
		};
		Element* list;
		Element* circleElement;
	public:
		List() {}
		void addElement(L Value) 
		{
			Element* pointer = new Element;
			Element* temp = new Element;
			pointer = list;
			if (list == NULL)
			{
				temp->value = Value;
				temp->next = NULL;
				temp->previous = NULL;
				list = temp;
			}
			else
				if (list->next == NULL)
				{
					temp->value = Value;
					temp->previous = list;
					temp->next = NULL;
					list->next = temp;
				}
				else
				{
					while (pointer->next != NULL)
					{
						pointer = pointer->next;
					}
					temp->value = Value;
					temp->previous = pointer;
					temp->next = NULL;
					pointer->next = temp;

				}
		}
		void Show()
		{
			Element* pointer = new Element;
			pointer = list;
			while (pointer != NULL)
			{
				cout << pointer->value << " ";
				pointer = pointer->next;
			}
			cout << endl;
		}
		void countElements()
		{
			Element* pointer = new Element;
			pointer = list;
			int count = 0;
			while (pointer != NULL)
			{
				count++;
				pointer = pointer->next;
			}
			cout << "Amount of elements: " << count << " " << endl;
		}
		void deleteElement(L element)
		{
			Element* pointer = new Element;
			pointer = list;
			while (pointer != NULL)
			{
				if (pointer->value == element)
				{
					Element* nextToDeleted = new Element;
					Element* previousToDeleted = new Element;
					if (pointer->next != NULL && pointer->previous != NULL)
					{
						nextToDeleted = pointer->next;
						previousToDeleted = pointer->previous;
						nextToDeleted->previous = previousToDeleted;
						previousToDeleted->next = nextToDeleted;
						pointer = NULL;
						break;
					}
					else
						if (pointer->next != NULL && pointer->previous == NULL)
						{
							list = list->next;
							list->previous = NULL;
							break;
						}
						else
							if (pointer->next == NULL && pointer->previous != NULL)
							{
								pointer = pointer->previous;
								pointer->next = NULL;
							}

				}
				else
					pointer = pointer->next;
			}
		}
		void putCircle(L circleElement)
		{
			Element* pointer = new Element;
			pointer = list;
			while (pointer->value!=circleElement && pointer!=NULL)
			{
				pointer = pointer->next;
			}
			this->circleElement = pointer;
		}
		void showWithCircle()
		{
			Element* pointer = new Element;
			Element* endOfList = new Element;
			string answer;
			endOfList = list;
			pointer = circleElement;
			while (endOfList->next != NULL)
				endOfList = endOfList->next;
			endOfList->next = circleElement;
			while (pointer != NULL)
			{
				if (pointer == this->circleElement)
				{
					cout << endl;
					cout << "Continue circle?";
					cin >> answer;
					if(answer=="yes")
						cout << pointer->value << " ";
						pointer = pointer->next;
					if (answer == "no") break;
				}
				cout << pointer->value << " ";
				pointer = pointer->next;
			}
		}
		~List() {}
	};
int main()
{
	List<int> newlist;
	int x, elementToDelete,circleElement;
	cout << "Enter your list(CTRL+Z to end input): ";
	while (cin >> x)
		newlist.addElement(x);
	cout << "Your list: ";
	newlist.Show();
	newlist.countElements(); 
	cout << endl;
	cout << "Enter element to delete:"; 
	cin.clear();
	cin >> elementToDelete;
	newlist.deleteElement(elementToDelete);
	cout << "List after deleting element: ";
	newlist.Show();
	newlist.countElements();
	cout << "Enter element to put circle on:";
	cin.clear();
	cin >> circleElement;
	newlist.putCircle(circleElement);
	cout << endl;
	cout << "Printing list with circle:";
	newlist.showWithCircle();
	system("pause");
    return 0;
}
