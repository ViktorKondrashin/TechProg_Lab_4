//HandlerRangeTree.cpp
#include <iostream>
#include "Node.h"
#include "HandlerRangeTree.h"
HandlerRangeTree::HandlerRangeTree(Node* root, size_t minHeight, size_t maxHeight):
    root_(root), minHeight_(minHeight), maxHeight_(maxHeight) {
        SearchSubTree(root, 0);
    }

void HandlerRangeTree::SearchSubTree(Node* node, size_t trueTree){
    if (!node) return;

    for (size_t i = 0; i < node->childCap(); ++i) {
        trueTree += ChekHeightNodeInRange();

        //если нет детей, то массива нет, читать нельзя
        if(node->childs[i]->)
        SearchSubTree(node->childs[i], trueTree);
    }
}
//         *
//        /
//       *
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

