#include <iostream>
#include "DLCirList.h"

using namespace std;

int main()
{
    CDLinkedList cd;
    cd.addFront(1);
    cd.addFront(2);
    cd.addFront(3);
    cd.addFront(4);
    cout<<"--------------------"<<endl;
    cout<<"Initial list:"<<endl;
    cd.display();
    cout<<"--------------------"<<endl;
    cd.CDrotate(3);
    cout<<"--------------------"<<endl;
    cd.CDrotate(2);
    cout<<"--------------------"<<endl;
    cd.CDrotate(4);
    cout<<"--------------------"<<endl;
    return 0;
}
