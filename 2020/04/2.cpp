#include <iostream>
#include <vector>
#include <cctype>
#include <string.h>

using namespace std;

/*
byr (Birth Year)
iyr (Issue Year)
eyr (Expiration Year)
hgt (Height)
hcl (Hair Color)
ecl (Eye Color)
pid (Passport ID)
cid (Country ID)        optional
*/

#define MAX 300

bool validate(string str);
bool c(string str, int prop, int lenProp, int min, int max);
bool h(string str);
bool e(string str);
bool p(string str);

vector<string> fields {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

vector<string> colors {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

int main() {
	int tot=0;
    char cur_in[MAX];
    char cur_str[MAX];


    string str,t;
    do {
        cur_str[0]=0;
        do {
            cin.getline(cur_in, MAX);
            if (cur_in[0] == '0') {
                break;
            }
            strcat(cur_str, cur_in);
            strcat(cur_str, " ");
        } while (cur_in[0] != '\0');
        if (validate(string(cur_str))) {
            cout << cur_str << endl;
            tot++;
        }
    } while (cur_in[0] != '0');
    
    cout << tot;

    return 0;
}

bool validate(string str) {
    int pos[7], prop_idx=0;
    for (string i : fields) {
        pos[prop_idx] = str.find(i);
        
        if (pos[prop_idx] == -1) {
            return false;
        }
        prop_idx++;
    }

    if (!c(str, pos[0], 4, 1920, 2002)) {
        return false;
    }
    if (!c(str, pos[1], 4, 2010, 2020)) {
        return false;
    }
    if (!c(str, pos[2], 4, 2020, 2030)) {
        return false;
    }
    if(str.find("cm")!=string::npos) {
        if (!c(str, pos[3], 3, 150, 193)) {
            return false;
        }
    } else if (str.find("in")!=string::npos){
        if (!c(str, pos[3], 2, 59, 76)) {
            return false;
        }
    } else {
        return false;
    }
    if (!h(str.substr(pos[4]+4, 7))) {
        return false;
    }
    if (!e(str.substr(pos[5]+4, 3))) {
        return false;
    }
    if (str[pos[6]+13] != ' ' || !p(str.substr(pos[6]+4, 9))) {
        return false;
    }

    return true;
}

bool c(string str, int pos, int lenProp, int min, int max) {
    int num = atoi(str.substr(pos+4, lenProp).c_str());
    if (num == 0 || num < min || num > max) {
        return false;
    }
    return true;
}

bool h(string str) {
    if (str[0] != '#') {
        return false;
    }
    for(char c : str.substr(1, 6)) {
        if (!isxdigit(c)) {
            return false;
        }
    }
    return true;
}

bool e(string str) {
    for (string col : colors) {
        if (str == col) {
            return true;
        }
    }
    return false;
}

bool p(string str) {
    char c;
    for(size_t i = 0; i < str.length(); i++) {
        c = str[i];
        if(!isdigit(c)) {
            return false;
        }
    }
    return true;
}