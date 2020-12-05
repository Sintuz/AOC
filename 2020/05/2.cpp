#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

#define SIZE 11

int calc(string str);
int getRow(string str, int min, int max);
int getCol(string str, int min, int max);

int main() {
    vector<int> nums;
    int t;
    char cur[SIZE];

    do {
        cin.getline(cur, 11);
        if(string(cur).length()) {
            t = calc(string(cur));
            nums.push_back(t);
        }
    } while(cur[0]!='\0');

    size_t i;
    for(i=1;i<1500;i++) {
        if(find(nums.begin(), nums.end(), i)==nums.end() && find(nums.begin(), nums.end(), i+1)!=nums.end() && find(nums.begin(), nums.end(), i-1)!=nums.end()) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}

int calc(string str) {
    int row = getRow(str.substr(0, 7), 0, 127);
    int col = getCol(str.substr(7, 3), 0, 7);

    return col+row*8;
}

int getRow(string str, int min, int max) {
    int mid = (max-min)/2+1;
    if(str.length() > 0 && str.at(0)=='F') {
        return getRow(str.substr(1, str.length()-1), min, max-mid);
    } else if (str.length() > 0) {
        return getRow(str.substr(1, str.length()-1), min+mid, max);
    } else {
        return min;
    }
}

int getCol(string str, int min, int max) {  	
    int mid = (max-min)/2+1;
    if(str.length() > 0 && str.at(0)=='L') {
        return getCol(str.substr(1, str.length()-1), min, max-mid);
    } else if (str.length() > 0) {
        return getCol(str.substr(1, str.length()-1), min+mid, max);
    } else {
        return min;
    }
}