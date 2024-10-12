#pragma once
#include "SubtitleBSTNode.h"
#include "SectionList.h"
#include <iostream>
#include <iomanip>

class SubtitleBST
{
private:
	SubtitleBSTNode* root;

	SubtitleBSTNode* recursiveSearch(SubtitleBSTNode* now, int timeToSecond);
	void recursivePrint(SubtitleBSTNode* now, ostream& os);

public:
	SubtitleBST();
	~SubtitleBST();

	SubtitleBSTNode* getRoot();

	// Insert
	void insert(Subtitle sub);
	// Print
	void print(ostream& os);
	// Search
	SubtitleBSTNode* search(int timeToSecond);
	// Delete
	void del(int mode, int timeToSecond);
	// Delete One Node
	void delOne(int timeToSecond);
};
