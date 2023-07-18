//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PCSNODE_H
#define PCSNODE_H

#include <openssl/sha.h>


//struct node {
//	struct node** children;
//	struct node* next;
//	int height;
//	int type;
//	int num_children;
//	fingerprint fp;
//};
//typedef struct node node;

namespace Azul
{
	class PCSNode
	{
	public:
		// Constants for the library
		static const unsigned int FP_SIZE = 20;
		static const unsigned int NAME_SIZE = 20;
		static const unsigned int MAJOR_VERSION = 3;
		static const unsigned int MINOR_VERSION = 1;

	public:
		// Enums
		enum class Code : uint32_t
		{
			SUCCESS,
			FAIL_NULL_PTR,
			FAIL_RETURN_NOT_INITIALIZED
		};


	public:
		// constructor
		PCSNode();

		// copy constructor
		PCSNode(const PCSNode &in);

		// Specialize Constructor
		PCSNode(PCSNode *const pInParent,
			PCSNode *const pInChild,
			PCSNode *const pInNextSibling,
			PCSNode *const pInPrevSibling,
			const char *const pInName);

		PCSNode(const char *const pInName);

		// destructor
		virtual ~PCSNode();

		// assignment operator
		PCSNode &operator = (const PCSNode &in);

		// accessors
		void SetParent(PCSNode *const pIn);
		void SetChild(PCSNode *const pIn);
		void SetNextSibling(PCSNode *const pIn);
		void SetPrevSibling(PCSNode *const pIn);
		void SetForward(PCSNode *const pIn);
		void SetReverse(PCSNode *const pIn);

		PCSNode *GetParent(void) const;
		PCSNode *GetChild(void) const;
		PCSNode *GetNextSibling(void) const;
		PCSNode *GetPrevSibling(void) const;
		PCSNode *GetForward(void) const;
		PCSNode *GetReverse(void) const;

		// name
		Code SetFP(const unsigned char *const pInFP);
		Code SetName(const char* const pInName);
		Code GetName(char *const pOutBuffer, unsigned int sizeOutBuffer) const;

		// print
		void PrintNode() const;
		void PrintChildren() const;
		void PrintSiblings() const;

		// get number of children/siblings
		int GetNumSiblings() const;
		int GetNumChildren() const;


		//public data, for convience
		unsigned char     fingerprint[PCSNode::FP_SIZE];

	private:
		PCSNode *pParent;
		PCSNode *pChild;
		PCSNode *pNextSibling;
		PCSNode *pPrevSibling;
		PCSNode *pForward;
		PCSNode *pReverse;

		
		char* pName;
	};

}

#endif

// ---  End of File ---
