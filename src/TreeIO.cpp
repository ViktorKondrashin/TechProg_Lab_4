#include <iostream>
#include "TreeIO.h"
#include "Node.h"
#include <vector>
namespace TreeIO {
    ///вспомогательные функции и структуры
    namespace detail{
        //структура для хранения информации об узле при вводе
        struct NodeInputInfo{
            size_t id;
            int value;
            size_t childCap;
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
            d. child_id_1, child_id_2, ..., child_id_k - id детей узла, которые сответствуют расположению в дереве у узла, k - количество детей
            P.s. id = 0 - означает Node* = nullptr
            
            Пример ввода:
            5
            1
            1 10 3 2 0 3
            2 20 0 
            3 30 2 4 5
            4 40 0
            5 50 0)" << std::endl;
        }
        
        
        Node*BuildTreeFromData(const size_t rootSubtreeId, const detail::NodeInputInfo* nodesData, const size_t NodeCount){
            
            //Перед созданием корня нужно его индекс нужно найти в массиве структр nodeData через поле id

            ///индекс в массиве nodesData, соответсвующий rootSubreeId
            size_t nodesDataInd;
            for (size_t i = 0; i < NodeCount; i++)
            {
                if(nodesData[i].id == rootSubtreeId) {nodesDataInd = i; break;}
            }    
            
            //создаем корень поддерева
            Node* rootSubtree = new Node(nodesData[nodesDataInd].value, nodesData[nodesDataInd].arrChildsId.size());

            if (nodesData[nodesDataInd].arrChildsId.size() == 0){
                return rootSubtree;
            }
            for(int placeInNode = 0; placeInNode < nodesData[nodesDataInd].arrChildsId.size(); ++placeInNode){
                if (nodesData[nodesDataInd].arrChildsId[placeInNode] !=0){
                rootSubtree->addChild(BuildTreeFromData(nodesData[nodesDataInd].arrChildsId[placeInNode], nodesData, NodeCount), placeInNode);
                }
            }
            return rootSubtree;
        }
    }
    /// @brief построение дерева из потока
    Node* BuildTreeFromStream(std::istream& in){
        detail::IntroductoryInformation();

        //создали данные для считывания
        size_t NodeCount;
        size_t rootId;

        // считываем данные, без защиты от дурака
        in >> NodeCount;

        if (NodeCount == 0){
            std::cerr << "The tree is empty" << std::endl;
            return nullptr;
        }
        in >> rootId;
        

        detail::NodeInputInfo *nodesData = new detail::NodeInputInfo[NodeCount]{};
        if(rootId > NodeCount || rootId <= 0){
            std::cerr << "Invalid root id: " << rootId << std::endl;
            delete[] nodesData;
            return nullptr;
        }

        //считываем информацию об узлах
        for(size_t ind = 0; ind < NodeCount; ++ind){
            //записали id узла
            in >> nodesData[ind].id;
            if(nodesData[ind].id > NodeCount || nodesData[ind].id <= 0){
                std::cerr << "Invalid node id: " << nodesData[ind].id << std::endl;
                delete[] nodesData;
                return nullptr;
            }

            //записали значение узла
            in >> nodesData[ind].value;

            //записали емкость массива детей
            in >> nodesData[ind].childCap;
            
            //считываем id детей
            int ChildId;
            for (size_t ind2 = 0; ind2 < nodesData[ind].childCap; ++ind2){
                //выставляем количество элементов в массиве для корректного индексирования
                nodesData[ind].arrChildsId.resize(nodesData[ind].childCap);
                
                in >> ChildId;
                
                
                if (!ChildId){
                    continue;
                }
                else{
                    nodesData[ind].arrChildsId[ind2] = ChildId;
                }
            
            }
            //проверка на работу потока
            if(!in){
                std::cerr << "Invalid node id: " << nodesData[ind].id << std::endl;
                delete[] nodesData;
                return nullptr;
            }
        }
        Node* root = detail::BuildTreeFromData(rootId, nodesData, NodeCount);

        delete[] nodesData;
        return root;
    }

    



};