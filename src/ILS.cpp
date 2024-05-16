#include "ILS.h"

Solution ILS(int argc, char* argv[1], int maxIter, int maxIterIls){
    Solution bestOfAll;
    bestOfAll.cost = INFINITY;

    auto data = Data(argc, argv[1]);
    data.read();
    for(int i = 0; i < maxIter; i++){
        Solution sol(data.getMatrixCost());
        make_construcao(sol);
        Solution best = sol;
        int iterILS = 0;
        while (iterILS < maxIter){
            BuscaLocal(&sol);
            if (sol.cost < best.cost){
                best = sol;
                iterILS = 0;
            }
            sol = pertubacao(best);
            iterILS += 1;
        }
    }
    return bestOfAll;
}

// Usar algo parecido com a busca local para pertubar
Solution pertubacao(Solution s){
    int num_iter = (s.sequencia.size()-2)/2;

    for(int iter = 0; iter < num_iter; iter++){
        for(int i = 1; i < (s.sequencia.size())/2; i++){
            int vertice_i = s.sequencia[i];
            int vertice_i_next = s.sequencia[i + 1];
            int vertice_i_prev = s.sequencia[i - 1];
            //int j = i + 1; -> se for sóos adjacentes
            for(int j = s.sequencia.size()-2; j > 0; j--){
                int vertice_j = s.sequencia[j];
                int vertice_j_next = s.sequencia[j + 1];
                int vertice_j_prev = s.sequencia[j - 1];
                double cost_swap = -s.matrizAdj[vertice_i_prev][vertice_i] - s.matrizAdj[vertice_i_next][vertice_i] + s.matrizAdj[vertice_i_prev][vertice_j]
                                + s.matrizAdj[vertice_j][vertice_i_next]
                                -s.matrizAdj[vertice_j_prev][vertice_j] - s.matrizAdj[vertice_j_next][vertice_j] + s.matrizAdj[vertice_j_prev][vertice_i]
                                + s.matrizAdj[vertice_i][vertice_j_next];
                
                std::swap(s.sequencia[i], s.sequencia[j]);
                s.cost = s.cost + cost_swap;
            }
        }
    }
    return s;
}