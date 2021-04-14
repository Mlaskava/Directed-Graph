#pragma once
#include <string>

class Graph{
public:
    void readFromFile(const std::string& path);
    virtual void createVertices(int count) = 0;
    virtual void addEdge(int index1, int index2) = 0;

};


