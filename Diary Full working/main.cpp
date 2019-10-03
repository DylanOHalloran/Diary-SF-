//MAIN LINKED LIST
#include "node.h"
#include "list.h"
#include <iostream>
#include <string>

int main()
{
    List *myList = new List;

    while (true)
    {
		std::cout << "Please enter a date: " << std::endl;
        int y1, m1, d1;
        std::string descrip1;
        std::cout << "Y: ";
        std::cin >> y1;
        std::cout << "M: ";
        std::cin >> m1;
        std::cout << "D: ";
        std::cin >> d1;
        std::cout << "Description: ";

        if (y1 == 0 && m1 == 0 && d1 == 0)
        {
            break;
        }

        std::getline(std::cin >> std::ws, descrip1);
        std::cout << y1 << " " << m1 << " " << d1 << std::endl;
		std::cout << std::endl;
        myList->createNode(y1, m1, d1, descrip1);

    

        myList->printList();
    }
    //telling you how many nodes
    std::cout << "There are " << myList->getListLength() << " nodes in the list" << std::endl;

    //swapping nodes 1 and 2
	char swap;
	std::cout << "Would you like to swap nodes 1 and 2? (y/n)" << std::endl;
	std::cin >> swap;
	if (swap == 'y') {
		myList->swap12();
		std::cout << "Swap me node 1 and 2..." << std::endl;
		myList->printList();
	}

	//deleting node by ID
	std::cout << "Select a node to delete by ID:";
	int idToGo;
	std::cin >> idToGo;
	myList->deleteNodeID(idToGo);
	myList->printList();

    //deleting node by date
    std::cout << "Select a date to delete:";
    int yToGo, mToGo, dToGo;
    std::cout << "\nY: ";
    std::cin >> yToGo;
    std::cout << "M: ";
    std::cin >> mToGo;
    std::cout << "D: ";
    std::cin >> dToGo;
    myList->deleteNode(yToGo, mToGo, dToGo);
    myList->printList();


    delete myList;
}