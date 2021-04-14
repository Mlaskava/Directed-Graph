#include "Graph.h"
#include <iostream>
#include <fstream>


void Graph::readFromFile(const std::string &path) {

    std::ifstream file;
    std::string line;
    int space;
    int vertex1;
    int vertex2;

    file.open(path, std::ios::in);
    if (file.is_open()) {

        std::getline(file, line);
        this->createVertices(std::stoi(line));

        while (std::getline(file, line)) {

            for (space = 0; space < line.size(); space++) {
                if (line[space] == ' ') {
                    break;
                }
            }

            vertex1 = stoi(line.substr(0, space));
            vertex2 = stoi(line.substr(space + 1, line.size() - space));
            this->addEdge(vertex1, vertex2);

        }

        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}
