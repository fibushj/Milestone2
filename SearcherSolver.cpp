
#include "SearcherSolver.h"
#include "BestFirstSearch.h"
#include "MatrixFactory.h"

string SearcherSolver::solve(string problem) {
    string solution;
    ISearchable<MatrixEntry> *matrix = MatrixFactory::GenerateMatrix(problem);
    BestFirstSearch<MatrixEntry> bfs; //TODO ASTAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    solution=bfs.search(*matrix);
    return solution;
}
