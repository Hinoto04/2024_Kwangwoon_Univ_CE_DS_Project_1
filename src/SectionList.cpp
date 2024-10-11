#include "SectionList.h"

SectionList::SectionList(int number):
{
	this.number = number;
	this.head = nullptr;
}
SectionList::~SectionList()
{
	
}

SectionListNode* SectionList::getHead()
{
	return head;
}

int SectionList::getNumber() {
	return this.number;
}

// Insert
void SectionList::insert() {
	return;
}
// Search
void SectionList::search() {
	return;
}