//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "_UnitTestConfiguration.h"

#include "PCSTree.h"
#include "PCSNode.h"

// Modifying any Unit Test to alter the outcome results is also an Academic Integrity Violation

using namespace Azul;

#pragma warning( push )
#pragma warning( disable : 4883 )

//---------------------------------------------------------------------------
// Test Files:
// Single step throught, set break points, but do not modify it
//---------------------------------------------------------------------------

// Stubbed out
TEST(BIG_PCSTREE_TEST_Enable, TestConfig::ALL)
{

#if BIG_PCSTREE_TEST_Enable


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		tree.GetInfo(info);
		root = tree.GetRoot();

		CHECK(root == nullptr);
		CHECK(info.maxNumNodes == 0);
		CHECK(info.currNumLevels == 0);
		CHECK(info.currNumNodes == 0);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;
		PCSNode nodeRoot("Root");

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		tree.Insert(&nodeRoot, root);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		CHECK(root == &nodeRoot);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 1);
		CHECK(info.maxNumLevels == 1);
		CHECK(info.currNumLevels == 1);
		CHECK(info.currNumNodes == 1);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;
		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		tree.Insert(&nodeRoot, root);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		CHECK(root == &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 1);
		CHECK(info.maxNumLevels == 1);
		CHECK(info.currNumLevels == 1);
		CHECK(info.currNumNodes == 1);

		tree.Insert(&nodeA, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 2);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 2);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;
		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeD("Node_D");

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		tree.Insert(&nodeRoot, root);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		CHECK(root == &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 1);
		CHECK(info.maxNumLevels == 1);
		CHECK(info.currNumLevels == 1);
		CHECK(info.currNumNodes == 1);

		tree.Insert(&nodeA, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 2);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 2);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		tree.Insert(&nodeD, &nodeA);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 3);
		CHECK(info.maxNumLevels == 3);
		CHECK(info.currNumLevels == 3);
		CHECK(info.currNumNodes == 3);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;
		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeD("Node_D");
		PCSNode nodeF("Node_F");

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		tree.Insert(&nodeRoot, root);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		root = tree.GetRoot();
		CHECK(root == &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 1);
		CHECK(info.maxNumLevels == 1);
		CHECK(info.currNumLevels == 1);
		CHECK(info.currNumNodes == 1);

		tree.Insert(&nodeA, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 2);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 2);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		tree.Insert(&nodeD, &nodeA);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 3);
		CHECK(info.maxNumLevels == 3);
		CHECK(info.currNumLevels == 3);
		CHECK(info.currNumNodes == 3);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		tree.Insert(&nodeF, &nodeD);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 4);
		CHECK(info.maxNumLevels == 4);
		CHECK(info.currNumLevels == 4);
		CHECK(info.currNumNodes == 4);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;
		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeD("Node_D");
		PCSNode nodeF("Node_F");
		PCSNode nodeH("Node_H");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeH, &nodeF);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 5);
		CHECK(info.maxNumLevels == 5);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 5);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;
		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");

		root = tree.GetRoot();
		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeB, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 2);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 2);

		CHECK(nodeRoot.GetChild() == &nodeB);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		tree.Insert(&nodeA, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 3);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 3);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 2);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 2);

		CHECK(nodeRoot.GetChild() == &nodeC);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		tree.Insert(&nodeB, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 3);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 3);

		CHECK(nodeRoot.GetChild() == &nodeB);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		tree.Insert(&nodeA, &nodeRoot);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 4);
		CHECK(info.maxNumLevels == 2);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 4);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 7);
		CHECK(info.maxNumLevels == 3);
		CHECK(info.currNumLevels == 3);
		CHECK(info.currNumNodes == 7);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr)
			CHECK(nodeI.GetPrevSibling() == &nodeE);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 9);
		CHECK(info.maxNumLevels == 3);
		CHECK(info.currNumLevels == 3);
		CHECK(info.currNumNodes == 9);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 10);
		CHECK(info.maxNumLevels == 3);
		CHECK(info.currNumLevels == 3);
		CHECK(info.currNumNodes == 10);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 11);
		CHECK(info.maxNumLevels == 4);
		CHECK(info.currNumLevels == 4);
		CHECK(info.currNumNodes == 11);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 13);
		CHECK(info.maxNumLevels == 4);
		CHECK(info.currNumLevels == 4);
		CHECK(info.currNumNodes == 13);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 15);
		CHECK(info.maxNumLevels == 4);
		CHECK(info.currNumLevels == 4);
		CHECK(info.currNumNodes == 15);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 18);
		CHECK(info.maxNumLevels == 4);
		CHECK(info.currNumLevels == 4);
		CHECK(info.currNumNodes == 18);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);
	}



	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 19);
		CHECK(info.maxNumLevels == 5);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 19);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 20);
		CHECK(info.maxNumLevels == 5);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 20);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");

		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");

		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove W
		tree.Remove(&nodeW);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove V
		tree.Remove(&nodeV);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeW);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeU);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove U
		tree.Remove(&nodeU);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeV);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeT);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove T
		tree.Remove(&nodeT);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeU);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove H
		tree.Remove(&nodeH);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove Q
		tree.Remove(&nodeQ);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove O
		tree.Remove(&nodeO);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeP);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove K
		tree.Remove(&nodeK);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeL);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove M
		tree.Remove(&nodeM);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeN);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove N
		tree.Remove(&nodeN);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove J
		tree.Remove(&nodeJ);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove G
		tree.Remove(&nodeG);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeJ);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);
		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove E
		tree.Remove(&nodeE);

		tree.GetInfo(info);
		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 23);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeI);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeD);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove F
		tree.Remove(&nodeF);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 22);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);
		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove D
		tree.Remove(&nodeD);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 21);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeE);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);


		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove I
		tree.Remove(&nodeI);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 21);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);


		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove L
		tree.Remove(&nodeL);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 21);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
		// Remove S
		tree.Remove(&nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 19);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove P
		tree.Remove(&nodeP);

		tree.GetInfo(info);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeQ);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeO);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove R
		tree.Remove(&nodeR);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 15);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == nullptr);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove C
		tree.Remove(&nodeC);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 14);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == nullptr);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == nullptr);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove B
		tree.Remove(&nodeB);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 19);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeC);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeA);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// Remove A
		tree.Remove(&nodeA);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 16);

		CHECK(nodeRoot.GetChild() == &nodeB);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// RemoveROOT
		tree.Remove(&nodeRoot);
		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 0);
		CHECK(info.currNumNodes == 0);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == nullptr);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == nullptr);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		// print the entire tree
		tree.Print();

	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		tree.Remove(&nodeA);
		tree.Remove(&nodeB);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 11);

		CHECK(nodeRoot.GetChild() == &nodeC);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);
		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);


		tree.Remove(&nodeA);
		tree.Remove(&nodeB);
		tree.Remove(&nodeT);
		tree.Remove(&nodeU);
		tree.Remove(&nodeV);
		tree.Remove(&nodeW);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 5);
		CHECK(info.currNumNodes == 7);

		CHECK(nodeRoot.GetChild() == &nodeC);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);

	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		tree.Remove(&nodeA);
		tree.Remove(&nodeB);
		tree.Remove(&nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 4);
		CHECK(info.currNumNodes == 6);

		CHECK(nodeRoot.GetChild() == &nodeC);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);


	}

	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();
		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		tree.Remove(&nodeA);
		tree.Remove(&nodeB);
		tree.Remove(&nodeO);
		tree.Remove(&nodeP);
		tree.Remove(&nodeQ);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 3);
		CHECK(info.currNumNodes == 3);

		CHECK(nodeRoot.GetChild() == &nodeC);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);

	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		tree.Remove(&nodeA);
		tree.Remove(&nodeB);
		tree.Remove(&nodeR);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 2);
		CHECK(info.currNumNodes == 2);

		CHECK(nodeRoot.GetChild() == &nodeC);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == nullptr);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);

	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);


		tree.Remove(&nodeA);
		tree.Remove(&nodeB);
		tree.Remove(&nodeC);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 1);
		CHECK(info.currNumNodes == 1);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == nullptr);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == nullptr);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}


	{
		PCSTree::Info info;
		PCSTree tree;
		PCSNode  *root;

		PCSNode nodeRoot("Root");
		PCSNode nodeA("Node_A");
		PCSNode nodeB("Node_B");
		PCSNode nodeC("Node_C");
		PCSNode nodeD("Node_D");
		PCSNode nodeE("Node_E");
		PCSNode nodeI("Node_I");
		PCSNode nodeK("Node_K");
		PCSNode nodeL("Node_L");
		PCSNode nodeR("Node_R");
		PCSNode nodeF("Node_F");
		PCSNode nodeG("Node_G");
		PCSNode nodeJ("Node_J");
		PCSNode nodeM("Node_M");
		PCSNode nodeN("Node_N");
		PCSNode nodeO("Node_O");
		PCSNode nodeP("Node_P");
		PCSNode nodeQ("Node_Q");
		PCSNode nodeH("Node_H");
		PCSNode nodeS("Node_S");
		PCSNode nodeT("Node_T");
		PCSNode nodeU("Node_U");
		PCSNode nodeV("Node_V");
		PCSNode nodeW("Node_W");

		root = tree.GetRoot();

		tree.Insert(&nodeRoot, root);

		tree.Insert(&nodeC, &nodeRoot);
		tree.Insert(&nodeB, &nodeRoot);
		tree.Insert(&nodeA, &nodeRoot);
		tree.Insert(&nodeI, &nodeA);
		tree.Insert(&nodeE, &nodeA);
		tree.Insert(&nodeD, &nodeA);
		tree.Insert(&nodeL, &nodeB);
		tree.Insert(&nodeK, &nodeB);
		tree.Insert(&nodeR, &nodeC);
		tree.Insert(&nodeF, &nodeD);
		tree.Insert(&nodeJ, &nodeI);
		tree.Insert(&nodeG, &nodeI);
		tree.Insert(&nodeN, &nodeL);
		tree.Insert(&nodeM, &nodeL);
		tree.Insert(&nodeQ, &nodeR);
		tree.Insert(&nodeP, &nodeR);
		tree.Insert(&nodeO, &nodeR);
		tree.Insert(&nodeH, &nodeF);
		tree.Insert(&nodeS, &nodeP);
		tree.Insert(&nodeW, &nodeS);
		tree.Insert(&nodeV, &nodeS);
		tree.Insert(&nodeU, &nodeS);
		tree.Insert(&nodeT, &nodeS);

		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 6);
		CHECK(info.currNumNodes == 24);

		CHECK(nodeRoot.GetChild() == &nodeA);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == &nodeD);
		CHECK(nodeA.GetParent() == &nodeRoot);
		CHECK(nodeA.GetNextSibling() == &nodeB);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == &nodeK);
		CHECK(nodeB.GetParent() == &nodeRoot);
		CHECK(nodeB.GetNextSibling() == &nodeC);
		CHECK(nodeB.GetPrevSibling() == &nodeA);

		CHECK(nodeC.GetChild() == &nodeR);
		CHECK(nodeC.GetParent() == &nodeRoot);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == &nodeB);

		CHECK(nodeD.GetChild() == &nodeF);
		CHECK(nodeD.GetParent() == &nodeA);
		CHECK(nodeD.GetNextSibling() == &nodeE);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == &nodeA);
		CHECK(nodeE.GetNextSibling() == &nodeI);
		CHECK(nodeE.GetPrevSibling() == &nodeD);

		CHECK(nodeI.GetChild() == &nodeG);
		CHECK(nodeI.GetParent() == &nodeA);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == &nodeE);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == &nodeB);
		CHECK(nodeK.GetNextSibling() == &nodeL);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == &nodeM);
		CHECK(nodeL.GetParent() == &nodeB);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == &nodeK);

		CHECK(nodeR.GetChild() == &nodeO);
		CHECK(nodeR.GetParent() == &nodeC);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == &nodeH);
		CHECK(nodeF.GetParent() == &nodeD);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == &nodeI);
		CHECK(nodeG.GetNextSibling() == &nodeJ);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == &nodeI);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == &nodeG);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == &nodeL);
		CHECK(nodeM.GetNextSibling() == &nodeN);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == &nodeL);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == &nodeM);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == &nodeR);
		CHECK(nodeO.GetNextSibling() == &nodeP);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == &nodeS);
		CHECK(nodeP.GetParent() == &nodeR);
		CHECK(nodeP.GetNextSibling() == &nodeQ);
		CHECK(nodeP.GetPrevSibling() == &nodeO);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == &nodeR);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == &nodeP);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == &nodeF);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == &nodeT);
		CHECK(nodeS.GetParent() == &nodeP);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == &nodeS);
		CHECK(nodeT.GetNextSibling() == &nodeU);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == &nodeS);
		CHECK(nodeU.GetNextSibling() == &nodeV);
		CHECK(nodeU.GetPrevSibling() == &nodeT);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == &nodeS);
		CHECK(nodeV.GetNextSibling() == &nodeW);
		CHECK(nodeV.GetPrevSibling() == &nodeU);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == &nodeS);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == &nodeV);

		tree.Remove(&nodeRoot);
		tree.GetInfo(info);

		CHECK(info.maxNumNodes == 24);
		CHECK(info.maxNumLevels == 6);
		CHECK(info.currNumLevels == 0);
		CHECK(info.currNumNodes == 0);

		CHECK(nodeRoot.GetChild() == nullptr);
		CHECK(nodeRoot.GetParent() == nullptr);
		CHECK(nodeRoot.GetNextSibling() == nullptr);
		CHECK(nodeRoot.GetPrevSibling() == nullptr);

		CHECK(nodeA.GetChild() == nullptr);
		CHECK(nodeA.GetParent() == nullptr);
		CHECK(nodeA.GetNextSibling() == nullptr);
		CHECK(nodeA.GetPrevSibling() == nullptr);

		CHECK(nodeB.GetChild() == nullptr);
		CHECK(nodeB.GetParent() == nullptr);
		CHECK(nodeB.GetNextSibling() == nullptr);
		CHECK(nodeB.GetPrevSibling() == nullptr);

		CHECK(nodeC.GetChild() == nullptr);
		CHECK(nodeC.GetParent() == nullptr);
		CHECK(nodeC.GetNextSibling() == nullptr);
		CHECK(nodeC.GetPrevSibling() == nullptr);

		CHECK(nodeD.GetChild() == nullptr);
		CHECK(nodeD.GetParent() == nullptr);
		CHECK(nodeD.GetNextSibling() == nullptr);
		CHECK(nodeD.GetPrevSibling() == nullptr);

		CHECK(nodeE.GetChild() == nullptr);
		CHECK(nodeE.GetParent() == nullptr);
		CHECK(nodeE.GetNextSibling() == nullptr);
		CHECK(nodeE.GetPrevSibling() == nullptr);

		CHECK(nodeI.GetChild() == nullptr);
		CHECK(nodeI.GetParent() == nullptr);
		CHECK(nodeI.GetNextSibling() == nullptr);
		CHECK(nodeI.GetPrevSibling() == nullptr);

		CHECK(nodeK.GetChild() == nullptr);
		CHECK(nodeK.GetParent() == nullptr);
		CHECK(nodeK.GetNextSibling() == nullptr);
		CHECK(nodeK.GetPrevSibling() == nullptr);

		CHECK(nodeL.GetChild() == nullptr);
		CHECK(nodeL.GetParent() == nullptr);
		CHECK(nodeL.GetNextSibling() == nullptr);
		CHECK(nodeL.GetPrevSibling() == nullptr);

		CHECK(nodeR.GetChild() == nullptr);
		CHECK(nodeR.GetParent() == nullptr);
		CHECK(nodeR.GetNextSibling() == nullptr);
		CHECK(nodeR.GetPrevSibling() == nullptr);

		CHECK(nodeF.GetChild() == nullptr);
		CHECK(nodeF.GetParent() == nullptr);
		CHECK(nodeF.GetNextSibling() == nullptr);
		CHECK(nodeF.GetPrevSibling() == nullptr);

		CHECK(nodeG.GetChild() == nullptr);
		CHECK(nodeG.GetParent() == nullptr);
		CHECK(nodeG.GetNextSibling() == nullptr);
		CHECK(nodeG.GetPrevSibling() == nullptr);

		CHECK(nodeJ.GetChild() == nullptr);
		CHECK(nodeJ.GetParent() == nullptr);
		CHECK(nodeJ.GetNextSibling() == nullptr);
		CHECK(nodeJ.GetPrevSibling() == nullptr);

		CHECK(nodeM.GetChild() == nullptr);
		CHECK(nodeM.GetParent() == nullptr);
		CHECK(nodeM.GetNextSibling() == nullptr);
		CHECK(nodeM.GetPrevSibling() == nullptr);

		CHECK(nodeN.GetChild() == nullptr);
		CHECK(nodeN.GetParent() == nullptr);
		CHECK(nodeN.GetNextSibling() == nullptr);
		CHECK(nodeN.GetPrevSibling() == nullptr);

		CHECK(nodeO.GetChild() == nullptr);
		CHECK(nodeO.GetParent() == nullptr);
		CHECK(nodeO.GetNextSibling() == nullptr);
		CHECK(nodeO.GetPrevSibling() == nullptr);

		CHECK(nodeP.GetChild() == nullptr);
		CHECK(nodeP.GetParent() == nullptr);
		CHECK(nodeP.GetNextSibling() == nullptr);
		CHECK(nodeP.GetPrevSibling() == nullptr);

		CHECK(nodeQ.GetChild() == nullptr);
		CHECK(nodeQ.GetParent() == nullptr);
		CHECK(nodeQ.GetNextSibling() == nullptr);
		CHECK(nodeQ.GetPrevSibling() == nullptr);

		CHECK(nodeH.GetChild() == nullptr);
		CHECK(nodeH.GetParent() == nullptr);
		CHECK(nodeH.GetNextSibling() == nullptr);
		CHECK(nodeH.GetPrevSibling() == nullptr);

		CHECK(nodeS.GetChild() == nullptr);
		CHECK(nodeS.GetParent() == nullptr);
		CHECK(nodeS.GetNextSibling() == nullptr);
		CHECK(nodeS.GetPrevSibling() == nullptr);

		CHECK(nodeT.GetChild() == nullptr);
		CHECK(nodeT.GetParent() == nullptr);
		CHECK(nodeT.GetNextSibling() == nullptr);
		CHECK(nodeT.GetPrevSibling() == nullptr);

		CHECK(nodeU.GetChild() == nullptr);
		CHECK(nodeU.GetParent() == nullptr);
		CHECK(nodeU.GetNextSibling() == nullptr);
		CHECK(nodeU.GetPrevSibling() == nullptr);

		CHECK(nodeV.GetChild() == nullptr);
		CHECK(nodeV.GetParent() == nullptr);
		CHECK(nodeV.GetNextSibling() == nullptr);
		CHECK(nodeV.GetPrevSibling() == nullptr);

		CHECK(nodeW.GetChild() == nullptr);
		CHECK(nodeW.GetParent() == nullptr);
		CHECK(nodeW.GetNextSibling() == nullptr);
		CHECK(nodeW.GetPrevSibling() == nullptr);
	}

#endif
} TEST_END

#pragma warning( pop )

// --- End of File ---
