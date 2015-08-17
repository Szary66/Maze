#pragma once
#include "uMazeClasses.h"

class TExplorer
{
public:
	TExplorer(void);
	~TExplorer(void);

	void DoNextStep(TNode *ActualPosition);
	void CountLinks(TMaze Maze, TNode ActualSpace);
	TLink *RememberRoad(int NunberOfSteps);
	
};














