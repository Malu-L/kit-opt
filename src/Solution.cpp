#include "Solution.h"

Solution::Solution(){}

Solution::Solution(double **matrizAdj){
    this->matrizAdj = matrizAdj;
    this->cost = 0.0;
}

Solution::Solution(double **matrizAdj, vector<int> clients):sequencia(clients), matrizAdj(matrizAdj){}

void Solution::add_vertice_sequencia(int vertice, int posicao){
    this->sequencia.insert(this->sequencia.begin() + posicao, vertice);
}

void Solution::exibirSolution(Solution &s){
    for(int i = 0; i < s.sequencia.size() - 1; i++){
        cout << s.sequencia[i] << " -> ";
    }
    cout << s.sequencia.back() << "\n";
}

void Solution::calcularCost(Solution &s){
    s.cost = 0;
    for(int i = 0; i < s.sequencia.size() - 1; i++){
        s.cost += matrizAdj[s.sequencia[i]][s.sequencia[i+1]];
    }
}