#include "Edge.h"

Edge::Edge(int index1, int index2)
{
    this->index1 = index1;
    this->index2 = index2;
}

bool Edge::operator==(Edge e) const {
    return (index1 == e.index1 && index2 == e.index2)|| (index1 == e.index2 && index2 == e.index1);
}