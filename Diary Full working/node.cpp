//node.h
#include "node.h"
#include <string>
Node::Node(int y, int m, int d, std::string newDescription, int newID)
{
    next = NULL;
    ddawPtr = new dateDayAndWeek(y, m, d);
    description = newDescription;
    ID = newID;
}

void Node::setNext(Node *nextPtr)
{
    next = nextPtr;
}

Node *Node::getNext()
{
    return next;
}

int Node::getID()
{
    return ID;
}

int Node::getYear()
{
    return ddawPtr->getYear();
}

int Node::getMonth()
{
    return ddawPtr->getMonth();
}

int Node::getDay()
{
    return ddawPtr->getDay();
}

std::string Node::getDescription()
{
    return description;
}

int Node::getDayNumber()
{
    return ddawPtr->getDayNumber();
}

void Node::setNodeDate(int y, int m, int d)
{
    ddawPtr->setDate(y, m, d);
}

void Node::setDescription(std::string desToSet)
{
    description = desToSet;
}

void Node::setID(int idToSet)
{
    ID = idToSet;
}