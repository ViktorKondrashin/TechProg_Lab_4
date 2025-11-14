//HandlerRangeTree.cpp
#include <iostream>
#include "Node.h"
#include "HandlerRangeTree.h"
HandlerRangeTree::HandlerRangeTree(Node* root, size_t minHeight, size_t maxHeight):
    root_(root), minHeight_(minHeight), maxHeight_(maxHeight) {
        SearchSubTree(root_);
    }

void HandlerRangeTree::SearchSubTree(Node* node){
    if (!node) return;

    //обрабатываем всегда когда заходим в новый узел и только
    root_ = node;
    ChekHeightNodeInRange(node);
    
    for (size_t i = 0; i < node->childCap(); ++i) {
        
        
        SearchSubTree(node->childs()[i]);
        
    }
}
//проходимся полнотью по поддереву до листов, высчитывая входимость в диапазон
void HandlerRangeTree::ChekHeightNodeInRange(Node* rootSubTree){
 
    //если пришли к листу
    if(rootSubTree->childs() == nullptr){
        size_t currentHeight = root_-> height() - rootSubTree->height();
        if (currentHeight <= maxHeight_ || currentHeight >= minHeight_)
        {
            ++trueTree;
            return;
        }
        else
        {
            return;
        }
        
    }

    for(size_t indChild = 0; indChild < rootSubTree->childCap(); ++indChild){
        ChekHeightNodeInRange(rootSubTree->childs()[indChild]);
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

