//Node.cpp
#include "Node.h"

Node::Node(std::size_t valueNode, std::size_t childCap) : valueNode_(valueNode), childCap_(childCap) {
    if (childCap_ == 0) return;
    childs_ = new Node*[childCap]{};
}

Node::~Node() {
    for (size_t i = 0; i < childCap_; ++i) {
        delete childs_[i];
    }
    delete[] childs_;
}

bool Node::addChild(Node* child, size_t number){
    if ((childCount_ >= childCap_ || number >= childCap_)) {
        return false; // инвариант нарушен
    }

    if(childs_[number] == nullptr){
        childs_[number] = child;
        ++childCount_;
        child->height_ = this->height_ + 1;
        return true;
    }
    return false; // место занято
}

