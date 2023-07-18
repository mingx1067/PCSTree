//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeReverseIterator.h"

namespace Azul
{
	PCSTreeReverseIterator::PCSTreeReverseIterator(PCSNode *rootNode)
		:root(rootNode),current(rootNode),prevNode(nullptr)
	{
	}

	PCSNode *PCSTreeReverseIterator::First()
	{
		//find the last one, circular queue
		this->current = this->root->GetReverse();
		//Keep prev nullptr, means First
		//this->prevNode = this->root;
		return  this->current;
	}

	PCSNode *PCSTreeReverseIterator::Next()
	{
		this->prevNode = this->current;
		this->current = this->current->GetReverse();
		return  this->current;
	}

	bool PCSTreeReverseIterator::IsDone()
	{
		return (this->prevNode == this->root);
	}

	PCSNode *PCSTreeReverseIterator::CurrentItem()
	{
		return  this->current;
	}

}

// ---  End of File ---------------
