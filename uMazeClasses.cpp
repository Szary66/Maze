#include "uMazeClasses.h"



TNode::TNode(void): NumberOfRoards(0), Examined(false)
{

}


TNode::~TNode(void)
{
}

TMaze::TMaze(int ANumerOfNodes, int ANumberOfLinks)
{
	NumberOfNodes = ANumerOfNodes;
	NumberOfLinks = ANumberOfLinks;

	if(!CheckCorrectessOfKand())
	{
		std::cout<<"Error!";
		return ;
	}

	Nodes = new TNode[NumberOfNodes];
	Links = new TLink[NumberOfLinks];

	TNode *oNode;
	bool bSucces = false;
	for(int iK = 0; iK < NumberOfNodes; iK++)
	{
		oNode = new TNode;
		while(!bSucces)
		{
			bSucces = true;
			oNode->RandomPosition();
			for(int iI = 0; iI < iK; iI++)
			{
				if(NodeAreEquals(*oNode, Nodes[iI]))
				{
					bSucces = false;
					break;
				}
			}
		}
		Nodes[iK] = *oNode;
	}

	for(int iK = 0; iK < NumberOfLinks; iK++)
	{
		bool BSucces = false;
		TNode oNode1, oNode2;
		TLink *oLink;

		while(!BSucces)
		{
			oLink = new TLink;
			BSucces = true;
			oNode1 = Nodes[rand() % NumberOfNodes];
			oNode2 = Nodes[rand() % NumberOfNodes];
			if(NodeAreEquals(oNode1, oNode2))
			{
				BSucces = false;
			}
			if(BSucces)
			{
				Links[iK] = *oLink;
				for(int iI = 0; iI < iK; iI++)
				{
					TLink oLinkTemp = Links[iI];

					if(!LinksAreEquals(*oLink, oLinkTemp))
					{
						BSucces = false;
					}

				}
			}
		}
			Links[iK] = *oLink;
	}
}

bool TMaze::CheckCorrectessOfKand()
{
	return NumberOfLinks <= NumberOfNodes * (NumberOfNodes - 1) * ((NumberOfNodes - 1) / 2);
}

TLink::TLink(): Examined(false)
{

}

TLink::~TLink()
{

}

void TNode::RandomPosition()
{
	X = rand() % 100;
	Y = rand() % 100;
	Z = rand() % 100;
}

bool TMaze::NodeAreEquals(TNode ANode1, TNode ANode2)
{
	return ANode1.X == ANode2.X && ANode1.Y == ANode2.Y && ANode1.Z == ANode2.Z;
}

bool TMaze::LinksAreEquals(TLink ALink1, TLink ALink2)
{
	return (NodeAreEquals(ALink1.Node1, ALink2.Node1) && NodeAreEquals(ALink1.Node2, ALink2.Node2)) ||
		(NodeAreEquals(ALink1.Node1, ALink2.Node2) && NodeAreEquals(ALink1.Node2, ALink2.Node1));
}

bool TNode::operator==(TNode node)
{
	if(TNode::X == node.X && TNode::Y == node.Y && TNode::Z == node.Z)
		return true;
	else
		return false;
}

void TMaze::CountDehiscence()
{
	for(int iK = 0; iK < NumberOfLinks; iK++)
	{
		Links[iK].Node1.Roads[Links[iK].Node1.NumberOfRoards++] = Links[iK];
		Links[iK].Node2.Roads[Links[iK].Node1.NumberOfRoards++] = Links[iK];
	}
}

bool TNode::operator==(TNode *node)
{
	if(TNode::X == node->X && TNode::Y == node->Y && TNode::Z == node->Z)
		return true;
	else
		return false;
}


