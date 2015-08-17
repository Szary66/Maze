#pragma once
#include <iostream>
#include <math.h>
#include <cstdlib>

class TLink;

class TNode
{
public:
	TLink *Roads;

	int NumberOfRoards;
	double X, Y, Z;
	bool Examined;

	void RandomPosition();
	bool operator==(TNode node);
	bool operator==(TNode *node);
	TNode(void);
	~TNode(void);

};

class  TLink
{
public:
	TNode Node1;
	TNode Node2;

	double Distance();

	//void RandomPair();
	TLink(void);
	~TLink(void);
	bool Examined;
};

class TMaze
{
public:
	TMaze(int ANumerOfNodes, int ANumberOfLinks);
	//~TMaze();
	TNode *Nodes;
	TLink *Links;

	int NumberOfNodes, NumberOfLinks;

	bool CheckCorrectessOfKand();
	bool NodeAreEquals(TNode ANode1, TNode ANode2);
	bool LinksAreEquals(TLink ALink1, TLink ALink2);
	//bool NewRoad(), NewNode();

	//void DoNextStep(TNode ActualPosition);
	void CountDehiscence();
};

