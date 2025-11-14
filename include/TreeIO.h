#pragma once
#include <iostream>

struct Node;

namespace TreeIO {

    Node* BuildTreeFromStream(std::istream& in);
};