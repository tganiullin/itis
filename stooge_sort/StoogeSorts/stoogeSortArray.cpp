#include <iostream>

using namespace std;

void StoogeSortArray(int *arr, int left, int right, long long& counter) {
    //Если значение элемента в конце списка меньше, чем значение элемента в начале, то поменять их местами.
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    counter++;
    //Если есть 3 или более элементов в текущем подмножестве списка, то:
    if (right - left > 1) {
        int t = (right - left + 1) / 3;
        //Рекурсивно вызвать Stooge sort для первых 2/3 списка
        StoogeSortArray(arr, left, right - t, counter);
        //Рекурсивно вызвать Stooge sort для последних 2/3 списка
        StoogeSortArray(arr, left + t, right, counter);
        //Рекурсивно вызвать Stooge sort для первых 2/3 списка снова
        StoogeSortArray(arr, left, right - t, counter);
    }
}