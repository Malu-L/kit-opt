#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using std::vector;
using std::cout;

class Solution{
    public:
        double **matrizAdj;
        vector<int> sequencia;
        double cost;

        Solution(double **matrizAdj);
        Solution();
        //~Solution();
        Solution(double **matrizAdj, vector<int> clients);

        void add_vertice_sequencia(int vertice, int posicao);
        void exibirSolution(Solution &s);
        void calcularCost(Solution &s);
};


#endif
