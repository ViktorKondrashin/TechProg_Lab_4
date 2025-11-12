//main.cpp
#include <iostream>
#include <fstream>

#include "Node.h"
#include "TreeIO.h"

bool selectDataInputMethod();

int main(){
    setlocale(LC_ALL, "Russian");
    std::ifstream fin("input.txt");
    Node* root = TreeIO::BildTreeFromStream(selectDataInputMethod() ? std::cin : fin);

    // Node root = new Node(3, 3);
    // Node left = new Node(3, 3);
    
}

bool selectDataInputMethod() {
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
        selectDataInputMethod();
    }
}