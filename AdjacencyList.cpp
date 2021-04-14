#include "AdjacencyList.h"
#include <iostream>

AdjacencyList::AdjacencyList() = default;

void AdjacencyList::createVertices(int count) {
    vertexList.resize(count);

}

bool AdjacencyList::checkEdge(int index1, int index2) {
    return (std::find(vertexList[index1].begin(), vertexList[index1].end(), Edge(index1, index2)) !=
            vertexList[index1].end());
}

void AdjacencyList::addEdge(int index1, int index2) {


    if (index1 < vertexList.size() && index2 < vertexList.size()) {

        if (!checkEdge(index1, index2)) {
            vertexList[index1].emplace_back(Edge(index1, index2));
        }
    }

    else {
        std::cout << "Index out of bounds!" << std::endl;
    }
}

bool AdjacencyList::removeEdge(int index1, int index2) {
    if (index1 < vertexList.size() && index2 < vertexList.size()) {

        auto index1It = std::find(vertexList[index1].begin(), vertexList[index1].end(), Edge(index1, index2));

        if (index1It != vertexList[index1].end()) {
            vertexList[index1].erase(index1It);
        }


        return true;
    }

    else {
        std::cout << "Index out of bounds!" << std::endl;
        return false;
    }

}



int AdjacencyList::vertexDegree(int index) {

    if (index < vertexList.size()) {
        return vertexList[index].size();
    }

    else {
        std::cout << "Index out of bounds!" << std::endl;
        return 0;
    }
}

std::vector<int> AdjacencyList::getNeighbourIndices(int index) {
    std::vector<int> indices;

    if (index < vertexList.size()) {
        for (Edge &e : vertexList[index]) {
            indices.emplace_back(e.index2);
        }

    }

    else {
        std::cout << "Index out of bounds!" << std::endl;
    }

    return indices;
}

void AdjacencyList::printNeighbourIndices(int index) {

    std::vector<int> indices = getNeighbourIndices(index);

    for (int &i : indices) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int AdjacencyList::getNumberOfEdges() {

    int amountOfEdges = 0;

    for (const std::vector<Edge>& v : vertexList) {
        amountOfEdges += v.size();
    }

    return amountOfEdges;
}
