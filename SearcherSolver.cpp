
#include "SearcherSolver.h"
#include "AStar.h"
#include "MatrixFactory.h"

string SearcherSolver::solve(string problem) {
    string solution;
    ISearchable<MatrixEntry> *matrix = MatrixFactory::GenerateMatrix(problem);
    AStar<MatrixEntry> astar;
    solution=astar.search(*matrix);
    delete matrix;
    return solution;
}
