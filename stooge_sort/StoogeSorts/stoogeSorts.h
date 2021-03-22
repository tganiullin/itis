#ifndef STOOGE_SORT_STOOGESORTS_H
#define STOOGE_SORT_STOOGESORTS_H

#include <list>

using namespace std;

void StoogeSortArray(int *arr, int left, int right, long long &counter);
void StoogeSortLinkedList(list<int>::iterator left, list<int>::iterator right, int leftInd, int rightInd, long long &counter);

#endif //STOOGE_SORT_STOOGESORTS_H
