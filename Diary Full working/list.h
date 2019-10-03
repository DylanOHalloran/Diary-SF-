//list.h
#include "node.h"
#include<string>

#ifndef LIST_H
#define LIST_H

class List{
    private:
        Node* head;
        Node* tail;
        int listLength;
        static int ID;
    public:
        List();
        ~List();
        void createNode(int y, int m, int d, std::string newDescription);
        void deleteNode(int y, int m, int d);
        void deleteNodeID(int id);
        void printList();
        int getListLength(){return listLength;};
        void sortList();
        void swap12();
        void swapNodes(Node* node1, Node* node2);
        Node* getTail(){return tail;}
        Node* getHead(){return head;}
};

#endif