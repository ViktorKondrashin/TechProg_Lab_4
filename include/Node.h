//Node.h
#pragma once

#include <cstddef>   
//класс узла N дерева
class Node{
public:

    ///создать узел
    Node(size_t valueNode, size_t childCap);
    //удаляет поддерево от заданного узла
    ~Node();

    /// @brief добавить ребенка
    /// @param child ребенок
    /// @param number место в списке детей, от 0
    /// @return корректный ввод
    bool addChild(Node* child, size_t number);

    ///геттеры
    inline int valueNode() const { return valueNode_; };
    inline size_t childCap() const { return childCap_; };
    inline Node** childs() const { return childs_; };
    inline size_t height() const { return height_; };

private:
    ///массив узлов
    Node** childs_ = nullptr;

    //значение узла
    int valueNode_ = 0;

    //количество узлов детей (кол ненулевых детей)
    size_t childCount_ = 0;

    //емкость массива детей
    size_t childCap_ = 0;

    //высота узла
    size_t height_ = 0;

};