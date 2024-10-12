#pragma once
#include "SectionListNode.h"

class SectionList
{
private:
	SectionListNode* head; //Section List Head

public:
	SectionList();
	~SectionList();

	SectionListNode* getHead();

	// Insert
	void insert();
	// Search
	SectionListNode* search(int number);
};
