#pragma once
#include "SubtitleBSTNode.h"
#include "SectionListNode.h"
#include "SectionList.h"

class SubtitleBST
{
private:
	SubtitleBSTNode* root;

public:
	SubtitleBST();
	~SubtitleBST();

	SubtitleBSTNode* getRoot();

	// Insert
	void insert();
	// Print
	void print();
	// Search
	void search();
	// Delete
	void del();
};
