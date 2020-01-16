//
// Created by ofirn93 on 14/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
using namespace std;


template <typename P, typename S>
class Solver {
public:
    virtual S solve(P problem);
};



#endif //EX4_SOLVER_H
