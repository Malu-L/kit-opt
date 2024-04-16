#ifndef CONSTRUCAO_H
#define CONSTRUCAO_H

#include "Solution.h"

struct inserir_vetor{
    int noInserido; // no k a ser inserido
    int arestaRemovida; // aresta {i,j} na qual o no k sera inserido
    double custo; // delta ao inserir k na aresta {i,j}
};

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
    void inserirNaSolucao(inserir_vetor inserido, Solution *s);
};

vector<inserir_vetor> ordenarEmOrdemCrescente(vector<inserir_vetor> custoInsercao);
Solution make_construcao(Solution &s);

#endif