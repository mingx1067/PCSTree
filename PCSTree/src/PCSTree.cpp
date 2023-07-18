//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTree.h"
#include "PCSNode.h"
#include"PCSTreeForwardIterator.h"
#include"PCSTreeReverseIterator.h"

#define getbit(from, which) ((from >> which) & 0x01) 
#pragma warning(disable : 4996)		// not going to replace SHA1 to SHA256 or SHA512

namespace Azul
{

	// constructor
	PCSTree::PCSTree()
		:mInfo(), pRoot(nullptr)
	{
	};

	// destructor
	PCSTree::~PCSTree()
	{
		//Do Nothing
	};

	// get Root
	PCSNode* PCSTree::GetRoot() const
	{
		return this->pRoot;
	}
	// insert
	//modify for Iterator
	void PCSTree::Insert(PCSNode * const pInNode, PCSNode * const pParent)
	{
		assert(pInNode != nullptr);
		if (pParent == nullptr)
		{
			//still no root
			if (this->pRoot == nullptr)
			{
				this->pRoot = pInNode;
			}
			else
			{
				//should not get in.
				assert(pParent != nullptr);
			}
		}
		else
		{
			PCSNode* tmp = pParent->GetChild();
			pParent->SetChild(pInNode);
			pInNode->SetParent(pParent);
			if (tmp == nullptr)
			{
				//Forward Setter
				pInNode->SetForward(pParent->GetForward());
				pParent->SetForward(pInNode);
				//Reverse Setter
				if (pInNode->GetForward() != nullptr)
				{
					pInNode->GetForward()->SetReverse(pInNode);
				}
				else
				{
					//last one, circular queue to get tail
					this->pRoot->SetReverse(pInNode);
				}
				pInNode->SetReverse(pParent);

				
			}
			else
			{
				pInNode->SetNextSibling(tmp);
				tmp->SetPrevSibling(pInNode);

				//Forward Setter
				pParent->SetForward(pInNode);
				pInNode->SetForward(tmp);
				
				//Reverse Setter
				tmp->SetReverse(pInNode);
				pInNode->SetReverse(pParent);
			}

		}
		//build helper function for Level and NodeNum
		this->Countinfo();
	}

	// Remove
	//modify for Iterator
	//only remove no child node
	void PCSTree::Remove(PCSNode * const pInNode)
	{
		assert(pInNode != nullptr);
		//Remove Root
		if (pInNode == this->pRoot)
		{
			this->pRoot = nullptr;
		}
		//no Siblings
		else if (pInNode->GetPrevSibling() == nullptr && pInNode->GetNextSibling() == nullptr)
		{
			pInNode->GetParent()->SetChild(nullptr);
		}
		//1st child
		else if (pInNode->GetPrevSibling() == nullptr)
		{
			pInNode->GetParent()->SetChild(pInNode->GetNextSibling());
			pInNode->GetNextSibling()->SetPrevSibling(nullptr);
		}
		//last child
		else if (pInNode->GetNextSibling() == nullptr)
		{
			pInNode->GetPrevSibling()->SetNextSibling(nullptr);
		}
		//other
		else
		{
			pInNode->GetNextSibling()->SetPrevSibling(pInNode->GetPrevSibling());
			pInNode->GetPrevSibling()->SetNextSibling(pInNode->GetNextSibling());
		}
		//Change Forward & Reverse
		if (pInNode->GetForward() == nullptr && pInNode->GetReverse() == nullptr)
		{
			//Error!!! Should not get here
		}
		//last one
		else if (pInNode->GetForward() == nullptr)
		{
			pInNode->GetReverse()->SetForward(nullptr);
			this->pRoot->SetReverse(pInNode->GetReverse());
		}
		else if (pInNode->GetReverse() == nullptr)
		{
			//Should not get here
		}
		else
		{
			pInNode->GetForward()->SetReverse(pInNode->GetReverse());
			pInNode->GetReverse()->SetForward(pInNode->GetForward());
		}
		

		//Assume remove a Node with Child
		PCSNode* iter = pInNode->GetChild();
		PCSNode* delNode = iter;
		while (iter != nullptr)
		{
			iter = iter->GetNextSibling();
			RemoveHelper(delNode);
			delNode = iter;
		}
		pInNode->SetChild(nullptr);
		pInNode->SetNextSibling(nullptr);
		pInNode->SetPrevSibling(nullptr);
		pInNode->SetParent(nullptr);
		pInNode->SetForward(nullptr);
		pInNode->SetReverse(nullptr);
		//delete pInNode;
		//build helper function for Level and NodeNum
		this->Countinfo();
	}

	void PCSTree::RemoveHelper(PCSNode* const pInNode)
	{
		if (pInNode->GetPrevSibling() == nullptr && pInNode->GetNextSibling() == nullptr)
		{
			pInNode->GetParent()->SetChild(nullptr);
		}
		//1st child
		else if (pInNode->GetPrevSibling() == nullptr)
		{
			pInNode->GetParent()->SetChild(pInNode->GetNextSibling());
			pInNode->GetNextSibling()->SetPrevSibling(nullptr);
		}
		//last child
		else if (pInNode->GetNextSibling() == nullptr)
		{
			pInNode->GetPrevSibling()->SetNextSibling(nullptr);
		}
		//other
		else
		{
			pInNode->GetNextSibling()->SetPrevSibling(pInNode->GetPrevSibling());
			pInNode->GetPrevSibling()->SetNextSibling(pInNode->GetNextSibling());
		}

		//Change Forward & Reverse
		if (pInNode->GetForward() == nullptr && pInNode->GetReverse() == nullptr)
		{
			//Error!!! Should not get here
		}
		//last one
		else if (pInNode->GetForward() == nullptr)
		{
			pInNode->GetReverse()->SetForward(nullptr);
			this->pRoot->SetReverse(pInNode->GetReverse());
		}
		else if (pInNode->GetReverse() == nullptr)
		{
			//Should not get here
		}
		else
		{
			pInNode->GetForward()->SetReverse(pInNode->GetReverse());
			pInNode->GetReverse()->SetForward(pInNode->GetForward());
		}

		PCSNode* iter = pInNode->GetChild();
		PCSNode* delNode = iter;
		while (iter != nullptr)
		{
			iter = iter->GetNextSibling();
			RemoveHelper(delNode);
			delNode = iter;
		}
		pInNode->SetChild(nullptr);
		pInNode->SetNextSibling(nullptr);
		pInNode->SetPrevSibling(nullptr);
		pInNode->SetParent(nullptr);
	}

	void PCSTree::Countinfo()
	{
		if (this->pRoot == nullptr)
		{
			this->mInfo.currNumLevels = 0;
			this->mInfo.currNumNodes = 0;
		}
		else
		{
			PCSNode* iter = this->pRoot->GetChild();
			int NodeNum = 1;
			int Level = 1;
			int subLevel = 0;
			while (iter != nullptr)
			{
				NodeNum += CountNodes(iter);
				subLevel = CountLevel(iter);
				if (subLevel + 1 > Level)
				{
					Level = subLevel + 1;
				}
				iter = iter->GetNextSibling();
			}
			this->mInfo.currNumLevels = Level;
			this->mInfo.currNumNodes = NodeNum;
			if (this->mInfo.maxNumLevels < Level)
			{
				this->mInfo.maxNumLevels = Level;
			}
			if (this->mInfo.maxNumNodes < NodeNum)
			{
				this->mInfo.maxNumNodes = NodeNum;
			}
		}
	}

	int PCSTree::CountNodes(PCSNode* root)
	{
		PCSNode* iter = root->GetChild();
		int ans = 1;
		while (iter != nullptr)
		{
			ans += CountNodes(iter);
			iter = iter->GetNextSibling();
		}
		return ans;
	}

	int PCSTree::CountLevel(PCSNode* root)
	{
		PCSNode* iter = root->GetChild();
		int ans = 1;
		int subLevel = 0;
		while (iter != nullptr)
		{
			subLevel = CountLevel(iter);
			if (subLevel + 1 > ans)
			{
				ans = subLevel + 1;
			}
			iter = iter->GetNextSibling();
		}
		return ans;
	}

	// get tree info
	void PCSTree::GetInfo(Info & info)
	{
		info = this->mInfo;
	}

	void PCSTree::Print() const
	{
		char tmp[32];
		this->pRoot->GetName(tmp, 32);
		//need print entire tree
		Trace::out("PCSTree: \n");
		Trace::out("Root: %s(%p)\n", tmp, this->pRoot);
		PCSNode* iter = this->pRoot->GetChild();
		while (iter != nullptr)
		{
			PrintTree(iter);
			iter = iter->GetNextSibling();
		}
	}

	void PCSTree::PrintTree(PCSNode* root) const
	{
		char tmp[32];
		root->GetName(tmp, 32);
		Trace::out("Root: %s(%p)\n", tmp, root);
		PCSNode* iter = root->GetChild();
		while (iter != nullptr)
		{
			PrintTree(iter);
			iter = iter->GetNextSibling();
		}
	}

	int PCSTree::check_sha1(PCSNode* curr, PCSNode* prev)
	{
		SHA_CTX ctx;
		SHA1_Init(&ctx);
		unsigned char fp[PCSNode::FP_SIZE];

		SHA1_Update(&ctx, curr->fingerprint, 20);
		if (prev) {
			SHA1_Update(&ctx, prev->fingerprint, 20);
			SHA1_Final(fp, &ctx);
			unsigned char b = fp[19];
			if (!getbit(b, 0) && !getbit(b, 1)) {
				return 1;
			}
		}
		else {
		}
		return 0;
	}

}

// ---  End of File ---
