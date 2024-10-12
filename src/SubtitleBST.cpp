#include "SubtitleBST.h"

SubtitleBST::SubtitleBST() : root(nullptr)
{

}
SubtitleBST::~SubtitleBST()
{

}

SubtitleBSTNode* SubtitleBST::getRoot()
{
	return this->root;
}

SubtitleBSTNode* SubtitleBST::recursiveSearch(SubtitleBSTNode* now, int timeToSecond) {
	if(!now) return nullptr;
	if(now->sub.toSeconds() == timeToSecond) return now; 
	if(now->sub.toSeconds() > timeToSecond) return this->recursiveSearch(now->getLeft(), timeToSecond);
	return this->recursiveSearch(now->getRight(), timeToSecond);
}

void SubtitleBST::recursivePrint(SubtitleBSTNode* now, ostream& os) {
	if(!now) return;
	this->recursivePrint(now->getLeft(), os);
	os << setfill('0');
	os << setw(2) << now->sub.h << ':';
	os << setw(2) << now->sub.m << ':';
	os << setw(2) << now->sub.s << " - ";
	os << now->sub.str << endl;
	this->recursivePrint(now->getRight(), os);
}

// Insert
void SubtitleBST::insert(Subtitle sub) {
	if(!this->root) {
		this->root = new SubtitleBSTNode(sub);
		return;
	}
	SubtitleBSTNode* now = this->root;
	SubtitleBSTNode* parent;
	while(now) {
		parent = now;
		if(parent->sub.toSeconds() > sub.toSeconds()) {
			now = now->getLeft();
		} else {
			now = now->getRight();
		}
	}
	if(parent->sub.toSeconds() > sub.toSeconds()) {
		parent->setLeft(new SubtitleBSTNode(sub));
	} else {
		parent->setRight(new SubtitleBSTNode(sub));
	}
	return;
}
// Print
void SubtitleBST::print(ostream& os) {
	this->recursivePrint(this->root, os);
}
// Search
SubtitleBSTNode* SubtitleBST::search(int timeToSecond) {
	return this->recursiveSearch(this->root, timeToSecond);
}
// Delete
void SubtitleBST::del(int mode, int timeToSecond) {
	return;
}
// Delete One Node
void SubtitleBST::delOne(int timeToSecond) {
	return;
}
