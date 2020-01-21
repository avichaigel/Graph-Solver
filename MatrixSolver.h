//
// Created by avichai on 21/01/2020.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H


#include <string>
#include "Solver.h"
#include "Matrix.h"

using namespace std;

class MatrixSolver : public Solver<Matrix*, string>{
public:
    string solve(Matrix *problem) override;
};


#endif //EX4_MATRIXSOLVER_H
