#include "Busca_local.h"

/*
Fazer RVND
    Implementar Best Improvement para as estruturas de vizinhança:
    - Swap
    - 2-opt
    - Reinsertion
    - Or-opt-2
    - Or-opt-3
Como vão ser 5 estruturas de vizinhança, só sai do loop do RVND se não conseguir melhorar o algoritmo 5 vezes seguidas
*/

void BuscaLocal(Solution *s){
    vector<int> NL = {1, 2, 3, 4, 5};
    bool improved = false;

    while(NL.empty() == false){
        int choice = rand() % NL.size();
        switch(NL[choice])
        {
            case 1:
                improved = bestImprovementSwap(s);
                break;
            case 2:
                improved = bestImprovement2Opt(s);
                break;
            case 3:
                improved = bestImprovementOrOpt(s, 1); // Reinsertion
                break;
            case 4:
                improved = bestImprovementOrOpt(s, 2); // Or-opt2
                break;
            case 5:
                improved = bestImprovementOrOpt(s, 3); // Or-opt3
                break;
        }

        if (improved)
            NL = {1, 2, 3, 4, 5};
        else
            NL.erase(NL.begin() + choice);
    }
}

// Troca a posição de dois vértices na sequência
bool bestImprovementSwap(Solution *s){
    double best_swap = 0;
    int best_vi, best_vj;
    for(int i = 1; i < s->sequencia.size() - 1; i++){
        int vertice_i = s->sequencia[i];
        int vertice_i_next = s->sequencia[i + 1];
        int vertice_i_prev = s->sequencia[i - 1];
        //int j = i + 1; -> se for sóos adjacentes
        for(int j = i + 1; j < s->sequencia.size() - 1; j++){
            int vertice_j = s->sequencia[j];
            int vertice_j_next = s->sequencia[j + 1];
            int vertice_j_prev = s->sequencia[j - 1];
            double cost_swap = -s->matrizAdj[vertice_i_prev][vertice_i] - s->matrizAdj[vertice_i_next][vertice_i] + s->matrizAdj[vertice_i_prev][vertice_j]
                            + s->matrizAdj[vertice_j][vertice_i_next]
                            -s->matrizAdj[vertice_j_prev][vertice_j] - s->matrizAdj[vertice_j_next][vertice_j] + s->matrizAdj[vertice_j_prev][vertice_i]
                            + s->matrizAdj[vertice_i][vertice_j_next];
            
            if (cost_swap < best_swap){
                best_swap = cost_swap;
                best_vi = i;
                best_vj = j;
            }
        }
    }
    if (best_swap < 0){
        std::swap(s->sequencia[best_vi], s->sequencia[best_vj]);
        s->cost = s->cost + best_swap;
        return true;
    }
    return false;
}

// Duas arestas não adjacentes da solução são removidas e o
// segmento entre elas é reinserido de maneira invertida, adicionando-se duas
// novas arestas para reconstruir a solução.
// -----> ARESTA, NÃO VÉRTICE
bool bestImprovement2Opt(Solution *s){
    double best_mov = 0;
    int best_ai, best_aj;
    for(int i = 1; i < s->sequencia.size() - 1; i++){
        int vertice_i = s->sequencia[i];
        int vertice_i_next = s->sequencia[i + 1];
        for(int j = i + 3; j < s->sequencia.size() - 1; j++){
            int vertice_j = s->sequencia[j];
            int vertice_j_prev = s->sequencia[j - 1];
            // Levando em consideração que a matriz é simétrica
            double cost_2opt = -s->matrizAdj[vertice_i][vertice_i_next] - s->matrizAdj[vertice_j_prev][vertice_j]
                            + s->matrizAdj[vertice_i][vertice_j_prev] + s->matrizAdj[vertice_i_next][vertice_j];
            if (cost_2opt < best_mov){
                best_mov = cost_2opt;
                best_ai = i;
                best_aj = j;
            }
        }
    }

    // ------------------------------------ essa é a melhor forma de fazer?
    if (best_mov < 0){
        cout << "--> " << (best_aj - best_ai) << std::endl;
        for (int i = 0; i < (best_aj - best_ai)%2+2; i++){
            std::swap(s->sequencia[best_ai+i], s->sequencia[best_aj-i]);
        }
        s->cost = s->cost + best_mov;
        return true;
    }
    
    return false;
}

bool bestImprovementOrOpt(Solution *s, int qtd_vertice){
    return false;
}