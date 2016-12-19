#include <iostream>
#include <string>
#include "list.h"

using namespace std;

struct ListElement
{
	string name;
	string phone;
	ListElement *next;
};

struct List
{
	int length;
	ListElement *head;
};

List* createList()
{
	auto list = new List{ 0, nullptr };
	return list;
}

ListElement* createListElement(ListElement *next, const string &name, const string &phone)
{
	auto newListElement = new ListElement{ name, phone, next };
	return newListElement;
}

void addToHead(List *list, const string &name, const string &phone)
{
	list->head = createListElement(list->head, name, phone);
	++list->length;
}

bool isEmpty(List *list)
{
	return list->length	 == 0;
}

void printList(List *list)
{
	auto cursor = list->head;
	while (cursor != nullptr)
	{
		cout << "���: " << cursor->name << " �������: " << cursor->phone << endl;
		cursor = cursor->next;
	}
}

void removeList(List *&list)
{
	while (list->head != nullptr)
	{
		auto toDelete = list->head;
		list->head = list->head->next;
		delete toDelete;
	}
	delete list;
	list = nullptr;
}