//
// Created by ofirn93 on 14/01/2020.
//

#include "StringReverser.h"
#include<bits/stdc++.h>
// a problem that could be solved in our program, used here as a test
string StringReverser::solve(string problem) {
    reverse(problem.begin(), problem.end());
    return problem;
}