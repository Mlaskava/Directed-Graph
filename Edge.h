#pragma once

struct Edge
{
    int index1;
    int index2;

public:
    Edge(int index1, int index2);
    bool operator==(Edge edge) const;
};


