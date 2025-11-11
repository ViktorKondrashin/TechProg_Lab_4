//Node.h
#pragma once

class Node{
public:

//значение и кол детей
Node(int a, int b);
//
bool addChild();

private:
//значение узла
int value;

//количество узлов детей
int childCount;

//емкость массива детей
int childCap;

//высота узла
int height;

//создать ребенка
void makeChild();

};