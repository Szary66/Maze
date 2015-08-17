#include "uExplorer.h"


TExplorer::TExplorer(void)
{
}


TExplorer::~TExplorer(void)
{
}

void TExplorer::DoNextStep(TNode *ActualPosition)
{
	for(int iK = 0; iK < ActualPosition->NumberOfRoards; iK++)
	{
		if(ActualPosition->Roads[iK].Examined == false)
		{
			if(ActualPosition->Roads[iK].Node1 == ActualPosition)
				ActualPosition =& ActualPosition->Roads[iK].Node2;
			else
				ActualPosition =& ActualPosition->Roads[iK].Node2;
			DoNextStep(ActualPosition);
		}
	}
}

TLink *TExplorer::RememberRoad(int NunberOfSteps)
{
	TLink *RoadToExtit = new TLink[NunberOfSteps];

	return RoadToExtit;
}

void TExplorer::CountLinks(TMaze Maze, TNode ActualSpace)
{
	int iI = 0;
	for(int iK = 0; iK < Maze.NumberOfLinks; iK++)
	{
		if(Maze.Links[iK].Node1 == ActualSpace || Maze.Links[iK].Node2 == ActualSpace)
		{
			ActualSpace.Roads[iI] = Maze.Links[iK];
			iI++;
		}
	}	
}

//void TExplorer::CountLinks(TMaze Maze)
//{
//
//	for(int iK = 0; iK < Maze.NumberOfLinks; iK++)
//	{
//		Maze.Links[iK].Node1.Roads[Maze.Links[iK].Node1.NumberOfRoards]
//		Maze.Links[iK].Node2
//		{
//			ActualSpace.Roads[iI] = Maze.Links[iK];
//			iI++;
//		}
//	}	
//}

