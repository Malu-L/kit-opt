#ifndef CONSTRUCAO_H
#define CONSTRUCAO_H

#include "Solution.h"

class Construcao{
public:
    vector<int> CL;
    Solution s;
    Construcao(Solution &s);
    void random_3(); // add vertice 1 no começo e final + Selecionar 3 vertices aleatorios para fazer parte da solução
    void calcular_custo_insercao(); // Calcular custo para inserir do CL no vetor solução e criar um tipo de fila de prioridade
    void inserir_na_sol(); // Inserir o vertice da fila de prioridade escolhido conforme o calculo alfa x |omega|
};

Solution make_construcao(Solution &s);

#endif