#include "Graph.h"
#include <vector>
#include <string>

#define MaxVerticles 2000

class AdjacencyMatrix : public Graph
{

    int matrix[MaxVerticles][MaxVerticles]{};
    int numberOfVertices;
    int amountOfEdges;

public:
    AdjacencyMatrix();
    void createVertices(int count) override;
    void addEdge(int index1, int index2) override;
    void removeEdge(int index1, int index2);
    bool checkEdge(int index1, int index2);
    int vertexDegree(int index);
    std::vector<int> getNeighbourIndices(int index);
    void printNeighbourIndices(int index);
    int getNumberOfEdges() const;

private:
    void clear();
};

