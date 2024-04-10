#ifndef CONSTRUCAO_H
#define CONSTRUCAO_H

#include "Solution.h"

struct inserir_vetor{};

class Construcao{
public:
    vector<int> CL;
    Solution* s;
    Construcao(Solution* s);
    vector<int> get_CL();
    Solution* get_solution();
    void random_3(); // add vertice 1 no começo e final + Selecionar 3 vertices aleatorios para fazer parte da solução
    // Calcular custo para inserir do CL no vetor solução e criar fila de prioridade
    vector<inserir_vetor> calcular_custo_insercao();
};

Solution make_construcao(Solution &s);

#endif