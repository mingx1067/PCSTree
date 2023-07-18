//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PCSTREE_H
#define PCSTREE_H



namespace Azul
{

	// forward declare
	class PCSNode;

	// PCSTree class 
	class PCSTree
	{
	public:
		// Simple data structure
		struct Info
		{
			int currNumNodes;
			int maxNumNodes;
			int currNumLevels;
			int maxNumLevels;
		};

	public:
		// constructor
		PCSTree();

		// copy constructor 
		PCSTree(const PCSTree &in) = delete;

		// assignment operator
		PCSTree &operator = (const PCSTree &in) = delete;

		// destructor
		~PCSTree();

		// get Root
		PCSNode *GetRoot() const;

		// insert
		void Insert(PCSNode *const pInNode, PCSNode *const pParent);

		// remove
		void Remove(PCSNode *const pInNode);
		void RemoveHelper(PCSNode* const root);
		//helper funcion
		void Countinfo();
		int CountNodes(PCSNode* root);
		int CountLevel(PCSNode* root);

		// get info
		void GetInfo(Info &info);
		void Print() const;
		void PrintTree(PCSNode* root) const;

	private:

		// Data
		Info	mInfo;
		PCSNode *pRoot;

	};

}

#endif

// ---  End of File ---
