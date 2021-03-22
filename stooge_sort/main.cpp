#include <iostream>
#include <list>
#include <ctime>
#include <fstream>
#include <cstdio>

#include "StoogeSorts/stoogeSorts.h"
#include "DataGenerator/dataGenerator.h"

using namespace std;

const string arrayCountFileName = "/arrayCount.txt";
const string arrayMsFileName = "/arrayMs.txt";
const string listCountFileName = "/listCount.txt";
const string listMsFileName = "/listMs.txt";

void writeFile(string filePath, string data) {
    ofstream file;
    file.open(filePath, ios::app);
    file << data;
    file.close();
}

void clearFile(string filePath) {
    remove(filePath.c_str());
    writeFile(filePath, "");
}

void clearResults(string directoryPath) {
    clearFile(directoryPath + arrayCountFileName);
    clearFile(directoryPath + arrayMsFileName);
    clearFile(directoryPath + listCountFileName);
    clearFile(directoryPath + listMsFileName);
}

void getResults(string directoryPath, int index) {
    int dataCount;
    vector<int> data = readGeneratedData("data", index, dataCount);


    int arr[dataCount];
    copy(data.begin(), data.end(), arr);
    long long c1 = 0;
    clock_t t1 = clock();

    StoogeSortArray(arr, 0, dataCount - 1, c1);

    t1 = clock() - t1;
    double ms1 = t1 / (CLOCKS_PER_SEC / 1000);
    writeFile(directoryPath + arrayCountFileName, to_string(c1) + "\n");
    writeFile(directoryPath + arrayMsFileName, to_string(ms1) + "\n");


    list<int> list(data.begin(), data.end());
    auto end = list.end();
    advance(end, -1);
    long long c2 = 0;
    clock_t t2 = clock();

    StoogeSortLinkedList(list.begin(), end, 0, list.size() - 1, c2);

    t2 = clock() - t2;
    double ms2 = t2 / (CLOCKS_PER_SEC / 1000);
    writeFile(directoryPath + listCountFileName, to_string(c2) + "\n");
    writeFile(directoryPath + listMsFileName, to_string(ms2) + "\n");
}

int main() {
    //generateData("data", 100, 100, 10000);

    clearResults("results");
    for (int i = 0; i < 100; i++) {
        getResults("results", i);
    }

    return 0;
}
