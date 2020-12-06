#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void cleanCharArr(char *arr, size_t size) {
    memset(arr, 0, size);
}

int findCharOccurrencesInVector(vector<char> v, char c) {
    int co = 0;
    for (size_t i = 0; i < v.size(); i++) {
        if (v.at(i) == c) co++;
    }
    return co;
}

void printCharVector(vector<char> v) {
    cout << string(v.begin(), v.end()) << endl;
}