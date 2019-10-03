//node h file 
#include <string>
#include "dateDayAndWeek.h"
#ifndef NODE_H
#define NODE_H

class Node
{
    private:
        dateDayAndWeek* ddawPtr; //dateDayAndWeek pointer.
        Node* next;
        std::string description;
        int ID;
    public:
        Node(int y, int m, int d, std::string newDescription, int newID);
        void setNext(Node *nextPtr);
        Node* getNext();
        int getYear();
        int getMonth();
        int getDay();
        std::string getDescription();
        int getID();
        int getDayNumber();
        void setNodeDate(int y, int m, int d);
        void setDescription(std::string desToSet);
        void setID(int idToSet);
};

#endif