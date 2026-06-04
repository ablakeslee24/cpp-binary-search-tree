#include <iostream>
#include "SearchTree.h"
using namespace std;

int main() {
    SearchTree<int> bst;

    cout << "Empty? " << boolalpha << bst.empty() << endl;

    bst.print();

    bst.insert(5);
    bst.insert(2);
    bst.insert(8);
    bst.insert(6);
    bst.insert(9);
    bst.insert(1);
    bst.insert(3);

    cout << "\nTree after inserts:\n";
    bst.print();

    cout << "Min: " << bst.find_min() << endl;
    cout << "Max: " << bst.find_max() << endl;

    cout << "Contains 3? " << bst.contains(3) << endl;
    cout << "Contains 10? " << bst.contains(10) << endl;

    bst.remove(8);
    cout << "\nAfter removing 8:\n";
    bst.print();

    bst.remove(5);
    cout << "\nAfter removing root (5):\n";
    bst.print();

    bst.remove(42);
    cout << "\nAfter trying to remove 42:\n";
    bst.print();

    bst.remove(1);
    bst.remove(2);
    bst.remove(3);
    bst.remove(6);
    bst.remove(9);

    cout << "\nAfter removing everything:\n";
    bst.print();

    cout << "Empty now? " << bst.empty() << endl;

    return 0;
}