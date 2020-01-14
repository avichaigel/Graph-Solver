//
// Created by ofirn93 on 14/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H
#include "Solver.h"
#include <string>


class StringReverser: public Solver <string, string> {
    string solve(string problem) override;
};


#endif //EX4_STRINGREVERSER_H
