#include "AdjacencyMatrix.h"
#include <iostream>
#include <vector>

AdjacencyMatrix::AdjacencyMatrix() : numberOfVertices(0), amountOfEdges(0) {

    for (auto & i : matrix) {
        for (int & j : i) {
            j = 0;
        }
    }

}

void AdjacencyMatrix::createVertices(int count) {
    if (count < MaxVerticles) {
        numberOfVertices = count;
    } else {
        std::cout << "Index out of bounds!" << std::endl;
    }
}

bool AdjacencyMatrix::checkEdge(int index1, int index2) {
    if (index1 <= numberOfVertices && index2 <= numberOfVertices) {
        if (matrix[index1][index2] == 1) {
            return true;
        } else {
            return false;
        }
    } else {
        std::cout << "Vertex does not exist!" << std::endl;
        return false;
    }
}

void AdjacencyMatrix::addEdge(int index1, int index2) {
    if (index1 <= numberOfVertices && index2 <= numberOfVertices) {
        if (!checkEdge(index1, index2)) {
            matrix[index1][index2] = 1;
            amountOfEdges++;
        }
    } else {
        std::cout << "Vertex does not exist!" << std::endl;
    }
}

void AdjacencyMatrix::removeEdge(int index1, int index2) {
    if (index1 <= numberOfVertices && index2 <= numberOfVertices) {
        if (checkEdge(index1, index2)) {
            matrix[index1][index2] = 0;
            amountOfEdges--;
        }
    } else {
        std::cout << "Vertex does not exist!" << std::endl;
    }
}

int AdjacencyMatrix::vertexDegree(int index) {
    int vertexDegree = 0;
    for (int i = 0; i < numberOfVertices; i++) {
        if (checkEdge(index, i)) {
            vertexDegree++;
        }
    }
    return vertexDegree;
}

std::vector<int> AdjacencyMatrix::getNeighbourIndices(int index) {
    std::vector<int> indices;
    for (int i = 0; i < numberOfVertices; i++) {
        if (checkEdge(index, i)) {
            indices.push_back(i);
        }
    }
    return indices;
}

void AdjacencyMatrix::printNeighbourIndices(int index) {
    std::vector<int> indices = getNeighbourIndices(index);
    for (int i : indices) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int AdjacencyMatrix::getNumberOfEdges() const {
    return amountOfEdges;
}

//void AdjacencyMatrix::readFromFile(const std::string &path) {
//    read(path, *this);
//}

void AdjacencyMatrix::clear() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            matrix[i][j] = 0;
        }
    }
}
