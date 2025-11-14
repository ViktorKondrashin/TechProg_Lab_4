//main.cpp
#include <iostream>
#include <fstream>

#include "Node.h"
#include "TreeIO.h"
#include "HandlerRangeTree.h"

bool selectDataInput();

int main(){
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("asstets/data/input.txt");
    //проверка на открытие потока
    if (!fin) {
        std::cerr << "Не удалось открыть файл\n";
        return 1;
    }
    Node* root = TreeIO::BuildTreeFromStream(selectDataInput() ? fin : std::cin);
    
    HandlerRangeTree HandlerRoot(root, 1, 5);

    std::cout << "Колличество поддеревьев, листья которых находятся в заданном диапазоне высот от корня поддерева." << HandlerRoot.countSubTreeInRange() << std::endl;


    // Node root = new Node(3, 3);
    // Node left = new Node(3, 3);
    
}

bool selectDataInput() {
    std::cout << "Выберите ввод данных:\n"
    "1. Ввести с клавиатуры\n"
    "2. Считать из файла\n"
    "0. Выход\n" << std::endl;

    int choise;
    std::cin >> choise;

    if(choise == 1) {
        std::cout << "Ввод с клавиатуры выбран" << std::endl;
        return 0;
    }
    else if(choise == 2) {
        std::cout << "Ввод из файла выбран" << std::endl;
        return 1;
    }
    else if(choise == 0) {
        std::cout << "Выход из программы" << std::endl;
        exit(0);
    }
    else {
        std::cout << "Некорректный ввод, попробуйте еще раз" << std::endl;
        selectDataInput();
    }
}