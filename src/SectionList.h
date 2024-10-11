#pragma once
#include "SectionListNode.h"

class SectionList
{
private:
	SectionListNode* head; //Section List Head

public:
	SectionList(int number);
	~SectionList();

	SectionListNode* getHead();
	int getNumber();

	// Insert
	void insert();
	// Search
	SectionListNode* search();
};
