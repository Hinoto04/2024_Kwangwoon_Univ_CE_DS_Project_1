#pragma once
#include "SubtitleListNode.h"

class SectionListNode
{
private:
	int number; //Section Number
	SectionListNode* next; //Next Section Node
	SubtitleListNode* head; //Content List Head

public:
	SectionListNode(int number, SubtitleListNode* head) : next(nullptr) {
		this->number = number;
		this->head = head;
	}
	~SectionListNode() {}

	SectionListNode*	getNext()		 	{ return next; }
	void setNext(SectionListNode* next)	 					{ this->next = next; }

	int getNumber() { return this->number; }
};
