#ifndef H_graph
#define H_graph

#include <iostream>
#include <fstream>
#include <iomanip>
#include "linkedList.h"
#include "unorderedLinkedList.h"
#include "linkedQueue.h"

using namespace std;

//------------------------------------------------------------------------------
/* graphType
* An implementation of a graph.
* Attributes are present for the max size of the graph, the current size of the
* graph, and a pointer to the graph.
* Methods are available to check if the graph is empty, create a graph, clear
* the graph, print the graph, and perform both depth and breadth first searches.
*/
class graphType
{
    public:
        //----------------------------------------------------------------------
        /* isEmpty() determines whether the graph is empty
        */
        bool isEmpty() const
        {
            return (gSize == 0);
        }

        //----------------------------------------------------------------------
        /* createGraph() creates a graph using the adjacency list representation
        */
        void createGraph()
        {
            ifstream infile;
            char fileName[50];

            int index;
            int vertex;
            int adjacentVertex;

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

            for (index = 0; index < gSize; index++)
            {
                infile >> vertex;
                infile >> adjacentVertex;

                while (adjacentVertex != -999)
                {
                    graph[vertex].insertLast(adjacentVertex);
                    infile >> adjacentVertex;
                }
            }

            infile.close();
        }

        //----------------------------------------------------------------------
        /* clearGraph() deallocates memory occupied by each vertex and sets the
        *  graph size back to 0.
        */
        void clearGraph()
        {
            int index;

            for (index = 0; index < gSize; index++)
            {
                graph[index].destroyList();
            }

            gSize = 0;
        }

        //----------------------------------------------------------------------
        /* printGraph() prints each value in the graph.
        */
        void printGraph() const
        {
            //cout<<gSize<<": is gSize"<<endl;
            int index;

            for (index = 0; index < gSize; index++)
            {
                cout << index << " ";
                graph[index].print();
                cout << endl;
            }

            cout << endl;
        }

        //----------------------------------------------------------------------
        /* depthFirstTraversal() performs a depth first traversal of the entire
        *  graph, printing each vertex
        */
        void depthFirstTraversal()
        {
            bool *visited; //pointer to create the array to keep
                           //track of the visited vertices
            visited = new bool[gSize];

            int index;

            for (index = 0; index < gSize; index++)
            {
                visited[index] = false;
            }

            // For each vertex that is not visited, do a depth first traversal
            for (index = 0; index < gSize; index++)
            {
                if (!visited[index])
                {
                    dft(index,visited);
                }
            }
            delete [] visited;
        }

        //----------------------------------------------------------------------
        /* dftAtVertex() performs a depth first traversal of the graph at a
        *  specified node by the parameter.
        */
        void dftAtVertex(int vertex)
        {
            bool *visited;

            visited = new bool[gSize];

            for (int index = 0; index < gSize; index++)
            {
                visited[index] = false;
            }

            dft(vertex, visited);

            delete [] visited;
        }

        //----------------------------------------------------------------------
        /* breadthFirstTraversal() performs a breadth first traversal of the
        *  entire graph
        */
        void breadthFirstTraversal()
        {
            linkedQueueType<int> queue;

            bool *visited;
            visited = new bool[gSize];

            for (int ind = 0; ind < gSize; ind++)
            {
                visited[ind] = false; // initialize the array visited to false
            }

            linkedListIterator<int> graphIt;

            for (int index = 0; index < gSize; index++)
            {
                if (!visited[index])
                {
                    queue.addQueue(index);
                    visited[index] = true;
                    cout << " " << index << " ";

                    while (!queue.isEmptyQueue())
                    {
                        int u = queue.front();
                        queue.deleteQueue();

                        for (graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                        {
                            int w = *graphIt;
                            if (!visited[w])
                            {
                                queue.addQueue(w);
                                visited[w] = true;
                                cout << " " << w << " ";
                            }
                        }
                    }
                }
            }

            delete [] visited;
        }

        //----------------------------------------------------------------------
        /* Constructor
        */
        graphType(int size = 0)
        {
            maxSize = size;
            gSize = 0;
            graph = new unorderedLinkedList<int>[size];
        }

        //----------------------------------------------------------------------
        /* Destructor
        */
        ~graphType()
        {
            clearGraph();
        }

    protected:
        int maxSize;    // maximum number of vertices
        int gSize;      // current number of vertices
        unorderedLinkedList<int> *graph; // array to create adjacency lists

    private:
        //----------------------------------------------------------------------
        /* dft() performs a depth first traversal of the graph at a node
        *  specified by the parameter v
        */
        void dft(int v, bool visited[])
        {
            visited[v] = true;
            cout << " " << v << " "; // visit the vertex

            linkedListIterator<int> graphIt;

            // for each vertex adjacent to v
            for (graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
            {
                int w = *graphIt;
                if (!visited[w])
                {
                    dft(w, visited);
                }
            }
        }
};

#endif
