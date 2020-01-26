//
// Created by ofirn93 on 14/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
using namespace std;

// an interface that represent every solver that could be used in the program (in our case solves matrices)
template <typename P, typename S>
class Solver {
public:
    virtual S solve(P problem) = 0;
};



#endif //EX4_SOLVER_H
