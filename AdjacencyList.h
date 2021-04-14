#include "Edge.h"
#include "Graph.h"
#include <string>
#include <vector>


class AdjacencyList : public Graph
{
    std::vector<std::vector<Edge>> vertexList;


public:
    AdjacencyList();
    void createVertices(int count) override;
    void addEdge(int index1, int index2) override;
    bool removeEdge(int index1, int index2);
    bool checkEdge(int index1, int index2);
    int vertexDegree(int index);
    std::vector<int> getNeighbourIndices(int index);
    void printNeighbourIndices(int index);
    int getNumberOfEdges();
//    void readFromFile(const std::string& path);
};

