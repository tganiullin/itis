#ifndef STOOGE_SORT_DATAGENERATOR_H
#define STOOGE_SORT_DATAGENERATOR_H

#include <string>
#include <vector>

using namespace std;

void generateData(string folderPath, int dataSetsCount, int minCount, int maxCount);
vector<int> readGeneratedData(string folderPath, int index, int& count);

#endif //STOOGE_SORT_DATAGENERATOR_H