//list implementation
#include "node.h"
#include "list.h"
#include <string>
#include <iostream>

List::List()
{
    head = NULL;
    tail = NULL;
    listLength = 0;
    ID = 0;
}

List::~List()
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    Node *next = head->getNext();
    delete head;
    while (next != NULL)
    {
        curr = next;
        next = curr->getNext();
        delete curr;
    }
}

void List::createNode(int y, int m, int d, std::string newDescription)
{
    Node *newNode = new Node(y, m, d, newDescription, ID);
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else if (newNode->getDayNumber() < head->getDayNumber() && (tail == head))
    {
        head->setNext(newNode);
        tail = newNode;
    }
    else if (newNode->getDayNumber() > head->getDayNumber())
    {
        newNode->setNext(head);
        head = newNode;
    }
    else if (newNode->getDayNumber() < tail->getDayNumber())
    {
        tail->setNext(newNode);
        tail = newNode;
    }
    else
    {
        Node *currNode = head;
        Node *nextNode = currNode->getNext();
        while (currNode != NULL)
        {
            if(newNode->getDayNumber() == currNode->getDayNumber()){
                currNode->setNext(newNode);
                newNode->setNext(nextNode);
            }
            if (newNode->getDayNumber() < currNode->getDayNumber())
            {
                if (currNode != tail && (newNode->getDayNumber() > nextNode->getDayNumber()))
                {
                    currNode->setNext(newNode);
                    newNode->setNext(nextNode);
                    break;
                }
                else
                {
                    currNode = nextNode;
                    nextNode = currNode->getNext();
                }
            }
            else
            {
                currNode = nextNode;
                nextNode = currNode->getNext();
            }
        }
    }
    listLength++;
    ID++;
}

void List::printList()
{
    Node *currNode = head;
    while (currNode != NULL)
    {
		std::cout <<  "Node ID: " << currNode->getID() << std::endl;
        std::cout << "Date: " << currNode->getYear() << "/" << currNode->getMonth() << "/" << currNode->getDay() << std::endl ;
		std::cout << "Entry " << currNode->getDescription() << std::endl;
		std::cout << std::endl;
        currNode = currNode->getNext();
    }
}

void List::deleteNode(int y, int m, int d)
{
    bool nodeFound = false;
    Node *currNode = head;
    Node *nextNode = currNode->getNext();
    if (currNode->getYear() == y && currNode->getMonth() == m && currNode->getDay() == d)
    {
        head = currNode->getNext();
        delete currNode;
        nodeFound = true;
    }
    else
    {
        while (currNode != NULL && nodeFound == false)
        {
            if (nextNode->getYear() == y && nextNode->getMonth() == m && nextNode->getDay() == d)
            {
                if (nextNode == tail)
                {
                    tail = currNode;
                    currNode->setNext(NULL);
                    delete nextNode;
                }
                else
                {
                    currNode->setNext(nextNode->getNext());
                    delete nextNode;
                }
                nodeFound = true;
            }
            else
            {
                currNode = currNode->getNext();
                nextNode = currNode->getNext();
            }
        }
    }
    if (nodeFound == false)
    {
        std::cout << "Node not found.";
    }
}

void List::deleteNodeID(int id)
{
    bool nodeFound = false;
    Node *currNode = head;
    Node *nextNode = currNode->getNext();
    if (currNode->getID() == id)
    {
        head = currNode->getNext();
        delete currNode;
        nodeFound = true;
    }
    else
    {
        while (currNode != NULL && nodeFound == false)
        {
            if (nextNode->getID() == id)
            {
                if (nextNode == tail)
                {
                    tail = currNode;
                    currNode->setNext(NULL);
                    delete nextNode;
                }
                else
                {
                    currNode->setNext(nextNode->getNext());
                    delete nextNode;
                }
                nodeFound = true;
            }
            else
            {
                currNode = currNode->getNext();
                nextNode = currNode->getNext();
            }
        }
    }
    if (nodeFound == false)
    {
        std::cout << "Node not found.";
    }
}

void List::swapNodes(Node *node1, Node *node2)
{
    int y1, m1, d1, id1;
    std::string descrip1;
    y1 = node1->getYear();
    m1 = node1->getMonth();
    d1 = node1->getDay();
    id1 = node1->getID();
    descrip1 = node1->getDescription();
    int y2, m2, d2, id2;
    std::string descrip2;
    y2 = node2->getYear();
    m2 = node2->getMonth();
    d2 = node2->getDay();
    id2 = node2->getID();
    descrip2 = node2->getDescription();
    node1->setNodeDate(y2, m2, d2);
    node1->setDescription(descrip2);
    node1->setID(id2);
    node2->setNodeDate(y1, m1, d1);
    node2->setDescription(descrip1);
    node2->setID(id1);
}
void List::swap12()
{
    Node *currNode = head;
    Node *nextNode = currNode->getNext();
    swapNodes(currNode, nextNode);
}

int List::ID = 0;