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

SubtitleBSTNode* SubtitleBST::recursiveDelete(SubtitelBSTNode* now, SubtitleBSTNode* parent, int time) {
	if(!now) return nullptr;

	SubtitelBSTNode* result = nullptr;
	if(now->sub.toSeconds() > time) {
		result = this->recursiveDelete(now->getLeft(), now, time);
	} else if(now->sub.toSeconds() < time) {
		result = this->recursiveDelete(now->getRight(), now, time);
	} else {
		result = now;

		if(!now->getLeft() && !now->getRight()) {
			if(parent->getLeft() == target) parent->setLeft(nullptr);
			else parent->setRight(nullptr);
		} else if(now->getLeft() && !now->getRight()) {
			if(!parent) {
			this->root = target->getLeft();
			} else {
				if(parent->getLeft() == target) parent->setLeft(nullptr);
				else parent->setRight(nullptr);
			}
		} else if(!now->getLeft() && now->getRight()) {
			if(!parent) {
				this->root = target->getRight();
			} else {
				if(parent->getLeft() == target) parent->setLeft(nullptr);
				else parent->setRight(nullptr);
			}
		} else {
			SubtitleBSTNode* minInRight = target->getRight();
			while(minInRight->getLeft()) {
				minInRight = minInRight->getLeft();
			}
			minInRight = this->recursiveDelete(now, nullptr, minInRight->sub.toSeconds());
			now->sub = minInRight->sub;
		}
	}

	return result;
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
int SubtitleBST::delUnder(int timeToSecond) {
	return 0;
}
// Delete One Node
int SubtitleBST::delOne(int timeToSecond) {
	cout << "DELONE" << endl;
	if(this->search(timeToSecond) == nullptr) {
		return -1;
	}
	SubtitleBSTNode* parent;
	SubtitleBSTNode* target;
	SubtitleBSTNode* now = this->root;
	while(now) {
		if(now->getLeft() && now->getLeft()->sub.toSeconds() == timeToSecond) {
			parent = now;
		} else if(now->getRight() && now->getRight()->sub.toSeconds() == timeToSecond) {
			parent = now;
		}
		
		if(now->sub.toSeconds() == timeToSecond) {
			target = now;
			break;
		} else if(now->sub.toSeconds() > timeToSecond) {
			now = now->getLeft();
		} else {
			now = now->getRight();
		}
	}

	if(!target->getRight() && !target->getLeft()) { //No Node in Left and Right
		cout << "CHILD NONE" << endl;
		if(parent->getLeft() == target) parent->setLeft(nullptr);
		else parent->setRight(nullptr);
		delete target;
		return 0;
	}
	if(!target->getRight() && target->getLeft()) { //Node in Left Only
		cout << "LEFT" << endl;
		if(!parent) {
			this->root = target->getLeft();
			delete target;
		} else {
			if(parent->getLeft() == target) parent->setLeft(nullptr);
			else parent->setRight(nullptr);
			delete target;
		}
		return 0;
	}
	if(target->getRight() && !target->getLeft()) { //Node in Right Only
		cout << "RIGHT" << endl;
		if(!parent) {
			this->root = target->getRight();
			delete target;
		} else {
			if(parent->getLeft() == target) parent->setLeft(nullptr);
			else parent->setRight(nullptr);
			delete target;
		}
		return 0;
	}
	//Node in Left and Right
	cout << "LEFT RIGHT" << endl;
	SubtitleBSTNode* minInRight = target->getRight();
	while(minInRight->getLeft()) {
		minInRight = minInRight->getLeft();
	}
	Subtitle temp = minInRight->sub;
	minInRight->sub = target->sub;
	target->sub = temp;
	this->delOne(minInRight->sub.toSeconds());
	return 0;
}
