#pragma once
#include <iostream>

struct Node;

namespace TreeIO {

    Node* BildTreeFromStream(std::istream& in);
};