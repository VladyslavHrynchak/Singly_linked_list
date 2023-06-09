#include <iostream>
#include "singly_linked_list.h"

using namespace std;

int main()
{
    Singly_linked_list<int> l1;
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.print();
    std::cout << std::endl;

    l1.remove(1);

    l1.print();

//    Singly_linked_list<int> l2(std::move(l1));
//    std::cout << "l2" << std::endl;
//    l2.print();
//    std::cout << std::endl;


//    std::cout << "l1" << std::endl;
//    l1.print();
//    std::cout << std::endl;


    return 0;
}
