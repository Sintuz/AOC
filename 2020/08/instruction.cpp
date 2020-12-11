#include "./instruction.h"

Instruction::Instruction(INSTRUCTION_CODE cmd, int arg) {
    command=cmd;
    argument=arg;
}

void Instruction::setExecuted(bool s) {
    executed=s;
}

bool Instruction::getExecuted() {
    return executed;
}

void Instruction::setInsCode(INSTRUCTION_CODE cmd) {
    command = cmd;
}

INSTRUCTION_CODE Instruction::getInsCode() {
    return command;
}

int Instruction::getArgument() {
    return argument;
}