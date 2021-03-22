#include <string>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

const int minNumber = 0;
const int maxNumber = 1000;

string getFileName(string folderPath, int index) {
    return folderPath + "/" + to_string(index) + ".txt";
}

void generateData(string folderPath, int dataSetsCount, int minCount, int maxCount) {
    int delta = (maxCount - minCount) / (dataSetsCount - 1);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(minNumber, maxNumber);

    for (int i = 0; i < dataSetsCount; i++) {
        int count = minCount + delta * i;

        ofstream file;
        file.open(getFileName(folderPath, i));
        file << count << endl;

        for (int j = 0; j < count; j++) {
            file << distrib(gen) << " ";
        }

        file.close();
    }
}

vector<int> readGeneratedData(string folderPath, int index, int& count) {
    ifstream file(getFileName(folderPath, index));
    if (!file.is_open()) {
        throw "error reading file";
    }

    file >> count;

    vector<int> data(count);
    for (int i = 0; i < count; i++) {
        file >> data[i];
    }
    file.close();

    return data;
}