#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> linkedList = * new LinkedList(1);
    linkedList.push_back(1);
    linkedList.push_back(2);
    linkedList.push_back(3);
    linkedList.push_back(4);

    linkedList.printList();
    linkedList.deleteNode(3);
    linkedList.printList();
}