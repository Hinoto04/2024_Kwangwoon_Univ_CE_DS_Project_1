#include "SectionList.h"
#include "SubtitleListNode.h"
#include "SubtitleBST.h"

SectionList::SectionList()
{
	this->head = nullptr;
}
SectionList::~SectionList()
{
	return;
}

SectionListNode* SectionList::getHead()
{
	return head;
}

// Insert
void SectionList::insert(SectionListNode* newNode) {
	SectionListNode* now = this->head;
	while(now->getNext() != nullptr) { //To Last Node
		now = now->getNext();
	}
	now->setNext(newNode);
	return;
}
// Search
SectionListNode* SectionList::search(int number) {
	while(true) {
		SectionListNode* now = this->head;
		if(now == nullptr) {
			return nullptr;
		}
		if(now->getNumber() == number) {
			return now;
		}
		now = now->getNext();
	}
	
}