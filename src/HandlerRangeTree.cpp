//HandlerRangeTree.cpp
#include <iostream>
#include "Node.h"
#include "HandlerRangeTree.h"
HandlerRangeTree::HandlerRangeTree(Node* root, size_t minHeight, size_t maxHeight):
    root_(root), minHeight_(minHeight), maxHeight_(maxHeight) {
        SearchSubTree(root_);
    }

// true  - все листья этого поддерева в диапазоне
// false - найден хотя бы один лист вне диапазона
bool HandlerRangeTree::CheckSubtree(Node* node, size_t depthFromRoot) {
    if (!node) return true; // пустая ветка "не портит" поддерево

    bool hasChild = false;
    bool allGood = true;

    for (size_t i = 0; i < node->childCap(); ++i) {
        Node* child = node->childs()[i];
        if (!child) continue;

        hasChild = true;
        if (!CheckSubtree(child, depthFromRoot + 1)) {
            allGood = false;
        }
    }

    // если детей нет — это лист
    if (!hasChild) {
        return depthFromRoot >= minHeight_ && depthFromRoot <= maxHeight_;
    }

    return allGood;
}
void HandlerRangeTree::SearchSubTree(Node* node) {
    if (!node) return;

    if (CheckSubtree(node, 0)) {
        ++trueTree; // это поддерево подходит
    }

    for (size_t i = 0; i < node->childCap(); ++i) {
        Node* child = node->childs()[i];
        if (!child) continue;
        SearchSubTree(child);
    }
}
//         *
//        / \
//       *   *
//      / \

// bool ChekHeightNodeInRange
// в обходе дерева берем перый узел: r
// Пошли дети r:
// 1c
// 11c
//     111c - childs == null, то проверяем высоту(высота листа - рут =),
//      если не в диап, то меняем рут.Если вдиап, то идем дальше
//     112c - childs == null; то же
//     113c - childs == null; то же
// кон 11#c
// 12c
//     аналогично для остальных детей
//     ...
//     ребеноу не в диап. Меняем рут

// возврщаемся обходу. берем второй узел r2, присваиваем его рут
// Пошли дети руь:
// 11c
// и тд

