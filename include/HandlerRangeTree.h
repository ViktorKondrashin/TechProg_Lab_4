//HandlerRangeTree.cpp
#pragma once

class Node;

class HandlerRangeTree{
public:

//Собирает состояние дерева
HandlerRangeTree(Node* root, size_t minHeight, size_t maxHeight);

private:
    //Поиск всех поддеревье, листья которых находятся 
    //в заданном диапазоне высот от корня поддерева.
    void SearchSubTree(Node* root, int trueTree);
    Node* root_;
    size_t minHeight_;
    size_t maxHeight_;
};