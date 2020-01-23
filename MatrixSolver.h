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

class MatrixSolver : public Solver<ISearchable<Point>*, string>{
private:
    Searcher<Point>* searcher;
public:
    explicit MatrixSolver(Searcher<Point> *searcher) : searcher(searcher) {}
    string solve(ISearchable<Point> *problem) override {
        vector<State<Point>*> solution = searcher->search(problem);
        for (auto s: solution) {
            auto point = s->getState();
//            if (point.getI())
        }
    }
};


#endif //EX4_MATRIXSOLVER_H
