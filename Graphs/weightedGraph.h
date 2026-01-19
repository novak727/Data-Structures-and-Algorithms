#ifndef H_weightedGraph
#define H_weightedGraph

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class weightedGraphType: public graphType
{
    public:
        //----------------------------------------------------------------------
        /* createWeightedGraph() creates a graph and the weight matrix from file
        *  input.
        */
        void createWeightedGraph()
        {
            ifstream infile;
            char fileName[50];

            int vertex;
            int adjacentVertex;
            double weight;

            if (gSize != 0)	// if the graph is not empty, make it empty
            {
                clearGraph();
            }

            cout << "Enter input file name: ";
            cin >> fileName;
            cout << endl;

            infile.open(fileName);

            if (!infile)
            {
                cout << "Cannot open input file." << endl;
                return;
            }

            infile >> gSize;  // get the number of vertices

            while (!infile.eof())
            {
                infile >> vertex >> adjacentVertex >> weight;
                graph[vertex].insertLast(adjacentVertex);
                weights[vertex][adjacentVertex] = weight;
            }

            infile.close();
        }

        //----------------------------------------------------------------------
        /* shortestPath() determines the weight of a shortest path from a source
        *  vertex to every other vertex in the graph
        */
        void shortestPath(int vertex)
        {
            for (int j = 0; j < gSize; j++)
            {
                smallestWeight[j] = weights[vertex][j];
            }

            bool *weightFound;
            weightFound = new bool[gSize];

            for (int j = 0; j < gSize; j++)
            {
                weightFound[j] = false;
            }

            weightFound[vertex] = true;
            smallestWeight[vertex] = 0;

            for (int i = 0; i < gSize - 1; i++)
            {
                double minWeight = DBL_MAX;
                int v;

                for (int j = 0; j < gSize; j++)
                {
                    if (!weightFound[j])
                    {
                        if (smallestWeight[j] < minWeight)
                        {
                            v = j;
                            minWeight = smallestWeight[v];
                        }
                    }
                }

                weightFound[v] = true;

                for (int j = 0; j < gSize; j++)
                {
                    if (!weightFound[j])
                    {
                        if (minWeight + weights[v][j] < smallestWeight[j])
                        {
                            smallestWeight[j] = minWeight + weights[v][j];
                        }
                    }
                }
            }
        }

        //----------------------------------------------------------------------
        /* printShortestDistance() prints the shortest weight from one vertex to
        *  another vertex in the graph
        */
        void printShortestDistance(int vertex)
        {
            cout << "Source Vertex: " << vertex << endl;
            cout << "Shortest Distance from Source to each Vertex." << endl;
            cout << "Vertex Shortest_Distance" << endl;

            for (int j = 0; j < gSize; j++){
                if(smallestWeight[j]<DBL_MAX)
                {
                    cout << setw(4) << j << setw(12) << smallestWeight[j]
                        << endl;
                }
                else
                {
                    cout << setw(4) << j << setw(12) << "UN"<< endl;
                }
            }
            cout << endl;
        }

        //----------------------------------------------------------------------
        /* allShortestPathWeights() calls printShortestPath() for all vertices
        *  of the graph.
        */
        void allShortestPathWeights()
        {
            for (int i = 0; i < gSize; i++)
            {
                shortestPath(i);
                printShortestDistance(i);
            }
        }

        //----------------------------------------------------------------------
        /* printWgraph() prints out the weighted graph.
        */
        void printWgraph()
        {
            printGraph();
            cout << "::Weight Matrix::" << endl;
            for (int i = 0; i < gSize; i++)
            {
                for (int j = 0; j < gSize; j++)
                {
                    if (weights[i][j] < DBL_MAX)
                    {
                        cout << weights[i][j] << " ";
                    }
                    else
                    {
                        cout << "UN "; // UN stands for undefined (treated in code as infinity)
                    }
                }
                cout << endl;
            }
            cout << ":::::::::::::" << endl;
        }

        //----------------------------------------------------------------------
        /* Constructor
        */
        weightedGraphType(int size = 0) : graphType(size)
        {
            weights = new double*[size];

            for (int i = 0; i < size; i++)
            {
                weights[i] = new double[size];
            }

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    weights[i][j] = DBL_MAX;
                }
            }

            smallestWeight = new double[size];
        }

        //----------------------------------------------------------------------
        /* Destructor
        */
        ~weightedGraphType()
        {
            for (int i = 0; i < gSize; i++)
            {
                delete [] weights[i];
            }

            delete [] weights;
            delete smallestWeight;
        }

    protected:
        double **weights;   // pointer to create weight matrix
        double *smallestWeight;	// pointer to create the array to store the
                                // smallest weight from source to vertices
};

#endif
