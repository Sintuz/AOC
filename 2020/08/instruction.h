#pragma once

enum INSTRUCTION_CODE {ACC, JMP, NOP};

class Instruction {
    private:
        INSTRUCTION_CODE command;
        int argument;
        bool executed;

    public:
        Instruction(INSTRUCTION_CODE cmd, int arg);
        void setExecuted(bool s);
        bool getExecuted();
        void setInsCode(INSTRUCTION_CODE cmd);
        INSTRUCTION_CODE getInsCode();
        int getArgument();
};