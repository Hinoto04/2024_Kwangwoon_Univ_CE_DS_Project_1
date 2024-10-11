#pragma once
#include "SubtitleListNode.h"

class SectionListNode
{
private:
	int number; //Section Number
	SectionListNode* next; //Next Section Node
	SubtitleListNode* head; //Content List Head

public:
	SectionListNode() : next(nullptr) {}
	~SectionListNode() {}

	SectionListNode*	getNext()		 	{ return next; }
	
	void setNext(SectionListNode* next)	 					{ this->next = next; }
};
