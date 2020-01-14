//
// Created by ofirn93 on 14/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
using namespace std;


template <typename P, typename S>
class Solver {
    virtual S solve(P problem) = 0;
};



#endif //EX4_SOLVER_H
