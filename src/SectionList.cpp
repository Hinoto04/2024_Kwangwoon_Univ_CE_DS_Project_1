#include "SectionList.h"
#include "SubtitleListNode.h"
#include "SubtitleBST"

SectionList::SectionList():
{
	this->head = nullptr;
}
SectionList::~SectionList()
{
	
}

SectionListNode* SectionList::getHead()
{
	return head;
}

// Insert
void SectionList::insert(SubtitleListNode* head, int number) {
	SectionListNode* now = this->head;
	while(now->next != nullptr) {
		now = now->next;
	}
	now.head = new SectionListNode(number, head);
	return;
}
// Search
SectionListNode* SectionList::search(int number) {
	while(true) {
		SectionList* now = this->head;
		if(now == nullptr) {
			return nullptr;
		}
		if(now.getNumber() == number) {
			return now;
		}
		now = now->getNext();
	}
	
}