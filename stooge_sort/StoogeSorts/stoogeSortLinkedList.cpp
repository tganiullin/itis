#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void StoogeSortLinkedList(list<int>::iterator left, list<int>::iterator right,
                          int leftInd, int rightInd, long long &counter) {
    //Если значение элемента в конце списка меньше, чем значение элемента в начале, то поменять их местами.
    if (*left > *right) {
        iter_swap(left, right);
    }

    counter++;

    //Если есть 3 или более элементов в текущем подмножестве списка, то:
    if (rightInd - leftInd > 1) {
        int t = (rightInd - leftInd + 1) / 3;
        counter += t * 3;
        //Рекурсивно вызвать Stooge sort для первых 2/3 списка
        auto rightMinusT = right;
        advance(rightMinusT, -t);
        StoogeSortLinkedList(left, rightMinusT, leftInd, rightInd - t, counter);
        //Рекурсивно вызвать Stooge sort для последних 2/3 списка
        auto leftPlusT = left;
        advance(leftPlusT, t);
        StoogeSortLinkedList(leftPlusT, right, leftInd + t, rightInd, counter);
        //Рекурсивно вызвать Stooge sort для первых 2/3 списка снова
        StoogeSortLinkedList(left, rightMinusT, leftInd, rightInd - t, counter);
    }
}