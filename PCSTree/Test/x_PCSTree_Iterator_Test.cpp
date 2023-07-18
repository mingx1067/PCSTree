//----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "_UnitTestConfiguration.h"

#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

using namespace Azul;

// Modifying any Unit Test to alter the outcome results is also an Academic Integrity Violation

//---------------------------------------------------------------------------
// Test Files:
// Single step throught, set break points, but do not modify it
//---------------------------------------------------------------------------

// Stubbed out
TEST(FullTree_Forward_Enable, TestConfig::ALL)
{
#if FullTree_Forward_Enable

	PCSTree::Info info;
	PCSTree tree;
	PCSNode *root;

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

	//Trace::out("\n\n\n--------\n\n\n");

	PCSTreeForwardIterator pForIterCount(tree.GetRoot());
	int count = 0;

	for (PCSNode *pNodeCount = pForIterCount.First();
		!pForIterCount.IsDone();
		pNodeCount = pForIterCount.Next())
	{
		count++;
	//	pNodeCount->PrintNode();
	}


	CHECK(count == 24);

	count = 0;
	PCSTreeForwardIterator pForIter(tree.GetRoot());
	PCSNode *pNode = pForIter.First();

	CHECK(count == 0);
	CHECK(pNode == &nodeRoot);
	pNode = pForIter.Next();
	count++;
	
	CHECK(count == 1);
	CHECK(pNode == &nodeA);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 2);
	CHECK(pNode == &nodeD);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 3);
	CHECK(pNode == &nodeF);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 4);
	CHECK(pNode == &nodeH);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 5);
	CHECK(pNode == &nodeE);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 6);
	CHECK(pNode == &nodeI);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 7);
	CHECK(pNode == &nodeG);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 8);
	CHECK(pNode == &nodeJ);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 9);
	CHECK(pNode == &nodeB);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 10);
	CHECK(pNode == &nodeK);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 11);
	CHECK(pNode == &nodeL);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 12);
	CHECK(pNode == &nodeM);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 13);
	CHECK(pNode == &nodeN);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 14);
	CHECK(pNode == &nodeC);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 15);
	CHECK(pNode == &nodeR);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 16);
	CHECK(pNode == &nodeO);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 17);
	CHECK(pNode == &nodeP);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 18);
	CHECK(pNode == &nodeS);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 19);
	CHECK(pNode == &nodeT);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 20);
	CHECK(pNode == &nodeU);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 21);
	CHECK(pNode == &nodeV);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 22);
	CHECK(pNode == &nodeW);
	pNode = pForIter.Next();
	count++;

	CHECK(count == 23);
	CHECK(pNode == &nodeQ);
	pNode = pForIter.Next();
	count++;

	CHECK(pForIter.IsDone() == true);

#endif
} TEST_END

// Stubbed out
TEST(FullTree_Reverse_Enable, TestConfig::ALL)
{
#if FullTree_Reverse_Enable

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

	//Trace::out("\n\n\n--------\n\n\n");

	PCSTreeReverseIterator pRevIterCount(tree.GetRoot());
	int count = 0;

	for (PCSNode *pNodeCount = pRevIterCount.First(); 
		!pRevIterCount.IsDone(); 
		pNodeCount = pRevIterCount.Next())
	{
		count++;
	//	pNodeCount->PrintNode();
	}
		

	CHECK(count == 24);

	count = 0;
	PCSTreeReverseIterator pRevIter(tree.GetRoot());
	PCSNode *pNode = pRevIter.First();

	CHECK(count == 0);
	CHECK(pNode == &nodeQ);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 1);
	CHECK(pNode == &nodeW);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 2);
	CHECK(pNode == &nodeV);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 3);
	CHECK(pNode == &nodeU);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 4);
	CHECK(pNode == &nodeT);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 5);
	CHECK(pNode == &nodeS);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 6);
	CHECK(pNode == &nodeP);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 7);
	CHECK(pNode == &nodeO);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 8);
	CHECK(pNode == &nodeR);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 9);
	CHECK(pNode == &nodeC);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 10);
	CHECK(pNode == &nodeN);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 11);
	CHECK(pNode == &nodeM);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 12);
	CHECK(pNode == &nodeL);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 13);
	CHECK(pNode == &nodeK);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 14);
	CHECK(pNode == &nodeB);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 15);
	CHECK(pNode == &nodeJ);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 16);
	CHECK(pNode == &nodeG);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 17);
	CHECK(pNode == &nodeI);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 18);
	CHECK(pNode == &nodeE);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 19);
	CHECK(pNode == &nodeH);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 20);
	CHECK(pNode == &nodeF);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 21);
	CHECK(pNode == &nodeD);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 22);
	CHECK(pNode == &nodeA);
	pNode = pRevIter.Next();
	count++;

	CHECK(count == 23);
	CHECK(pNode == &nodeRoot);
	pNode = pRevIter.Next();
	count++;

	CHECK(pRevIter.IsDone() == true);

#endif
} TEST_END

// --- End of File ---
