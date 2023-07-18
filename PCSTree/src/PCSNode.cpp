//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"

namespace Azul
{
	// constructor
	PCSNode::PCSNode()
		:pParent(nullptr),
		pChild(nullptr),
		pNextSibling(nullptr),
		pPrevSibling(nullptr),
		pForward(nullptr),
		pReverse(nullptr)
	{
	}

	// copy constructor
	PCSNode::PCSNode(const PCSNode & in)
	{
		this->pParent = in.pParent;
		this->pChild = in.pChild;
		this->pNextSibling = in.pNextSibling;
		this->pPrevSibling = in.pPrevSibling;
		this->pForward = in.pForward;
		this->pReverse = in.pReverse;
		memcpy_s(this->pName, NAME_SIZE, in.pName, NAME_SIZE);
	}

	// Specialize Constructor
	PCSNode::PCSNode(PCSNode * const pInParent, PCSNode * const pInChild, PCSNode * const pInNextSibling, PCSNode * const pInPrevSibling, const char * const pInName)
	{
		this->pParent = pInParent;
		this->pChild = pInChild;
		this->pNextSibling = pInNextSibling;
		this->pPrevSibling = pInPrevSibling;
		memcpy_s(this->pName, NAME_SIZE, pInName, NAME_SIZE);
	}

	PCSNode::PCSNode(const char * const pInName)
		:pParent(nullptr),
		pChild(nullptr),
		pNextSibling(nullptr),
		pPrevSibling(nullptr),
		pForward(nullptr),
		pReverse(nullptr)
	{
		memcpy_s(this->pName, NAME_SIZE, pInName, NAME_SIZE);
	}

	// destructor
	PCSNode::~PCSNode()
	{
		//Do nothing
	}

	// assignment operator
	PCSNode & PCSNode::operator = (const PCSNode & in)
	{
		this->pParent = in.pParent;
		this->pChild = in.pChild;
		this->pNextSibling = in.pNextSibling;
		this->pPrevSibling = in.pPrevSibling;
		this->pForward = in.pForward;
		this->pReverse = in.pReverse;
		memcpy_s(this->pName, NAME_SIZE, in.pName, NAME_SIZE);
		return *this;
	}

	void PCSNode::SetParent(PCSNode * const pIn)
	{
		this->pParent = pIn;
	}

	void PCSNode::SetChild(PCSNode * const pIn)
	{
		this->pChild = pIn;

	}

	void PCSNode::SetNextSibling(PCSNode * const pIn)
	{
		this->pNextSibling = pIn;
	}

	void PCSNode::SetPrevSibling(PCSNode * const pIn)
	{
		this->pPrevSibling = pIn;
	}

	void PCSNode::SetForward(PCSNode* const pIn)
	{
		this->pForward = pIn;
	}

	void PCSNode::SetReverse(PCSNode* const pIn)
	{
		this->pReverse = pIn;
	}

	PCSNode* PCSNode::GetParent(void) const
	{
		return this->pParent;
	}

	PCSNode* PCSNode::GetChild(void) const
	{
		return this->pChild;
	}

	PCSNode* PCSNode::GetNextSibling(void) const
	{
		return this->pNextSibling;
	}

	PCSNode* PCSNode::GetPrevSibling(void) const
	{
		return this->pPrevSibling;
	}

	PCSNode* PCSNode::GetForward(void) const
	{
		return this->pForward;
	}

	PCSNode* PCSNode::GetReverse(void) const
	{
		return this->pReverse;
	}

	PCSNode::Code PCSNode::SetName(const char * const pInName)
	{
		if (pInName == nullptr)
		{
			return Code::FAIL_NULL_PTR;
		}
		else
		{
			memcpy_s(this->pName, NAME_SIZE, pInName, NAME_SIZE);
			return Code::SUCCESS;
		}
	}

	PCSNode::Code PCSNode::GetName(char * const pOutBuffer, unsigned int sizeOutBuffer) const
	{
		if (this->pName == nullptr)
		{
			return Code::FAIL_RETURN_NOT_INITIALIZED;
		}
		else if (pOutBuffer == nullptr)
		{
			return Code::FAIL_NULL_PTR;
		}
		else
		{
			memcpy_s(pOutBuffer, sizeOutBuffer, this->pName, sizeOutBuffer);
			/*for (size_t i = 0; i < sizeOutBuffer; i++)
			{
				pOutBuffer[i] = this->pName[i];
			}*/
			pOutBuffer[sizeOutBuffer - 1] = '\0';
			return Code::SUCCESS;
		}
	}

	void PCSNode::PrintNode() const
	{
		Trace::out("Node Name:      %s(%p)\n", this->pName, this);
		if (this->pParent == nullptr)
		{
			Trace::out("Node Parent:    %s(%p)\n", "NONE", this->pParent);
		}
		else
		{
			Trace::out("Node Parent:    %s(%p)\n", this->pParent->pName, this->pParent);
		}

		if (this->pChild == nullptr)
		{
			Trace::out("Node 1st Child: %s(%p)\n", "NONE", this->pChild);
		}
		else
		{
			Trace::out("Node 1st Child: %s(%p)\n", this->pChild->pName, this->pChild);
		}

		if (this->pPrevSibling == nullptr)
		{
			Trace::out("Prev Sibling:   %s(%p)\n", "NONE", this->pPrevSibling);
		}
		else
		{
			Trace::out("Prev Sibling:   %s(%p)\n", this->pPrevSibling->pName, this->pPrevSibling);
		}

		if (this->pNextSibling == nullptr)
		{
			Trace::out("Next Sibling:   %s(%p)\n\n", "NONE", this->pNextSibling);
		}
		else
		{
			Trace::out("Next Sibling:   %s(%p)\n\n", this->pNextSibling->pName, this->pNextSibling);
		}
	}

	void PCSNode::PrintChildren() const
	{
		PCSNode* iter = this->pChild;
		Trace::out("Child List: ");
		while (iter != nullptr)
		{
			Trace::out("%s(%p) ", iter->pName, iter);
			iter = iter->pNextSibling;
		}
		Trace::out("\n");
	}

	void PCSNode::PrintSiblings() const
	{
		PCSNode* iter = this->pParent->GetChild();
		while (iter != nullptr)
		{
			Trace::out("%s(%p) ", iter->pName, iter);
			iter = iter->pNextSibling;
		}
		Trace::out("\n");
	}

	int PCSNode::GetNumSiblings() const
	{
		PCSNode* iter = nullptr;
		//root
		if (this->pParent == nullptr)
		{
			return 1;
		}
		iter = this->pParent->pChild;
		int count = 0;
		while (iter != nullptr)
		{
			count++;
			iter = iter->pNextSibling;
		}
		return count;
	}

	int PCSNode::GetNumChildren() const
	{
		PCSNode* iter = this->pChild;
		int count = 0;
		while (iter != nullptr)
		{
			count++;
			iter = iter->pNextSibling;
		}
		return count;
	}
}

// ---  End of File ---
