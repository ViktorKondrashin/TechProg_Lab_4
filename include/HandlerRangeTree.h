//HandlerRangeTree.h
#pragma once

class Node;

class HandlerRangeTree{
public:

//Собирает состояние дерева
HandlerRangeTree(Node* root, size_t minHeight, size_t maxHeight);
inline size_t countSubTreeInRange () {return trueTree;}
private:
    //добовляет поддеревья, подходящие под диапазон
    bool CheckSubtree(Node* node, size_t depthFromRoot);
    //Поиск всех поддеревье, листья которых находятся 
    //в заданном диапазоне высот от корня поддерева.
    void SearchSubTree(Node* node);
    Node* root_;
    size_t minHeight_;
    size_t maxHeight_;
    size_t trueTree = 0;
};