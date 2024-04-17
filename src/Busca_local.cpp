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
    
}

bool bestImprovement2Opt(Solution *s){

}

bool bestImprovementOrOpt(Solution *s, int qtd_vertice){

}