#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
vector<vector<char>> map;
char tmp[100];


int main() {
	int hits=0;
	size_t j=0;

	do {
        vector<char> in;
		cin.getline(tmp, MAX);
        for (int i = 0; tmp[i] != '\0'; i++) {
            in.push_back(tmp[i]);
        }
        map.push_back(in);
    } while (tmp[0] != '\0');
	
    size_t sz = map.at(0).size();

    for (size_t i = 0; i < (map.size()-1); i++, j+=3) {
        if(j>=sz) {
            j = j-sz;
		}
        
        char cur_tree = map.at(i).at(j);

        if (cur_tree == '#') {
            hits++;
        }
    }
    
    cout << hits;

    return 0;
}
