#include "ArrayList.h"

int main() {
    ArrayList<int> list = *new ArrayList<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(6, 100);

    list.printList();
}