#pragma once
#include "Subtitle.h"

class SubtitleListNode
{
private:

	SubtitleListNode*	next; //Next Content Node
	Subtitle sub;

public:
	SubtitleListNode() : next(nullptr) {}
	~SubtitleListNode() {}

	SubtitleListNode*	getNext()			{ return next; }

	void setNext(SubtitleListNode* next)	 	{ this->next = next; }
};
