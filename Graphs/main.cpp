// -----------------------------------------------------------------------------
// Name: Devin Kennedy
// Course-Section: CS355-01
// Assignment: Assignment #9 - Weighted Graphs and Shortest Paths
// Date due: 12/03/2025
// Description:
// -----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "weightedGraph.h"

using namespace std;

int main()
{
    weightedGraphType wG(20);
    wG.createWeightedGraph();

    wG.printWgraph();

    wG.shortestPath(0);
    wG.printShortestDistance(0);
    cout << "++++++++++++++" << endl << endl;

    wG.allShortestPathWeights();

	return 0;
}
