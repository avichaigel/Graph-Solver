//
// Created by avichai on 21/01/2020.
//

#ifndef EX4_MATRIXSOLVER_H
#define EX4_MATRIXSOLVER_H


#include <string>
#include "Solver.h"
#include "Matrix.h"
#include "Searcher.h"

using namespace std;

//Object Adapter

class MatrixSolver : public Solver<ISearchable<Matrix*>*, string>{
private:
    Searcher<Matrix*>* searcher{};
public:
    explicit MatrixSolver(Searcher<Matrix*> *searcher) : searcher(searcher) {}

    string solve(ISearchable<Matrix*> *problem) override {
        searcher->search(problem);
    }
};


#endif //EX4_MATRIXSOLVER_H
