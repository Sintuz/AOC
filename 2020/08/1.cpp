#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <string.h>

#include "./instruction.h"

using namespace std;

#define LMAX 9

INSTRUCTION_CODE getInsCode(string ins_code);

vector<Instruction> buffer;

int main() {
    char line[LMAX];
    int counter=0;

    do {
        cin.getline(line, LMAX);
        
        if (line[0] != '\0') {
            string l = string(line);
            INSTRUCTION_CODE ins_code = getInsCode(l.substr(0, l.find(" ")));
            int argument = atoi(l.substr(l.find(" ")+1, l.length()).c_str());
            
            buffer.push_back(*new Instruction(ins_code, argument));
        }
    } while (line[0] != '\0');

    for (auto i = buffer.begin(); i != buffer.end(); i++) {
        if (i->getExecuted()) {
            break;
        } else {
            i->setExecuted(true);
            switch (i->getInsCode()) {
                case INSTRUCTION_CODE::ACC: {
                    counter += i->getArgument();
                    break;
                };
                case INSTRUCTION_CODE::JMP: {
                    advance(i, i->getArgument());
                    i--;
                    break;
                };
                case INSTRUCTION_CODE::NOP: {
                    break;
                };
                default: {
                    throw "Invalid instruction code";
                }
            }
        }
    }

    cout << counter;

    return 0;
}

INSTRUCTION_CODE getInsCode(string ins_code) {
    if (ins_code == "acc") {
        return INSTRUCTION_CODE::ACC;
    } else if (ins_code == "jmp") {
        return INSTRUCTION_CODE::JMP;
    } else if (ins_code == "nop") {
        return INSTRUCTION_CODE::NOP;
    }

    throw "Invalid instruction " + ins_code;
}

/*
nop +0
acc +1
jmp +4
acc +3
jmp -3
acc -99
acc +1
jmp -4
acc +6
*/