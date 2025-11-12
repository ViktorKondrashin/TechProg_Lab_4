#include "TreeIO.h"
#include "Node.h"
#include <vector>
namespace TreeIO {
    ///вспомогательные функции и структуры
    namespace detail{
        //структура для хранения информации об узле при вводе
        struct NodeInputInfo{
            int id;
            int value;
            std::vector<int> arrChildsId;
        };
        //вспомогательная информация для пользователя
        void IntroductoryInformation(){
            std::cout << R"(Формат ввода данных:
            1. N - первой строке указвается число узлов в дереве.
            2. rootId - во второй строке укаывается id корня дерева.
            3. Далее для каждого узла указывается:
            
            id value child_count child_1 ... child_k 
            
            где:
            a. id - id узла, 1 <= id <= N
            b. value - значение узла
            c. child_Cap - емкость массива детей у узла
            d. child_id_1, child_id_2, ..., child_id_k - id детей узла, k - количество детей
            P.s. id = 0 - означает Node* = nullptr
            
            Пример ввода:
            5
            1
            1 10 2 2 3
            2 20 0
            3 30 2 4 5
            4 40 0
            5 50 0)" << std::endl;
        }
        
        Node* BildTreeFromDataRecursive(Node* currentNode, const int currentNodeId, detail::NodeInputInfo* nodesData, size_t& counter){
            if (nodesData[currentNodeId].arrChildsId[counter] == 0){
                ++counter;
                return;
            }
           currentNode->addChild(BildTreeFromData(nodesData[currentNodeId].arrChildsId[counter], nodesData, counter), counter);
        }
        //
        Node*BildTreeFromData(const int rootSubtreeId, detail::NodeInputInfo* nodesData, size_t& counter){
            //создаем корень поддерева
            Node* rootSubtree = new Node(nodesData[rootSubtreeId].value, nodesData[rootSubtreeId].arrChildsId.size());//!!! не факт что правильный размер

            BildTreeFromDataRecursive(rootSubtree, rootSubtreeId, nodesData, counter);
        }
    }
    /// @brief построение дерева из потока
    Node* BildTreeFromStream(std::istream& in){
        detail::IntroductoryInformation();
        //создали данные для считывания
        int NodeCount;
        int rootId;
        detail::NodeInputInfo *nodesData = new detail::NodeInputInfo[NodeCount]{};
        // считываем данные, без защиты от дурака
        in >> NodeCount;
        in >> rootId;
        if(rootId > NodeCount || rootId <= 0){
                std::cerr << "Invalid node id: " << rootId << std::endl;
                delete[] nodesData;
                return nullptr;
            }
        //считываем информацию об узлах
        for(size_t ind = 0; ind < NodeCount; ++ind){
            in >> nodesData[ind].id;
            if(nodesData[ind].id > NodeCount || nodesData[ind].id <= 0){
                std::cerr << "Invalid node id: " << nodesData[ind].id << std::endl;
                delete[] nodesData;
                return nullptr;
            }
            in >> nodesData[ind].value;
            
            //считываем id детей
            int ChildId;
            for (size_t ind2 = 0; ind2 < NodeCount -1 ; ++ind2){
                in >> ChildId;
                if (ChildId == '\n'){
                    break;
                }
                else{
                    if (!ChildId){
                        continue;
                    }
                    else{
                        nodesData[ind].arrChildsId[ind2] = ChildId;
                    }
                }
            }
        }
        size_t counter = 0;
        BildTreeFromData(rootId, nodesData, counter);

        delete[] nodesData;
        return nullptr;
    }

    



};