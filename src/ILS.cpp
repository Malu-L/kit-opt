#include "ILS.h"

Solution ILS(int argc, char** argv, int maxIter){
    Solution bestOfAll;
    bestOfAll.cost = INFINITY;
    auto data = Data(argc, argv[1]);
    data.read();
    int maxIterIls = data.getDimension()/2;
    for(int i = 0; i < maxIter; i++){
        Solution sol(data.getMatrixCost());
        cout << "Chegou aqui2";
        make_construcao(sol);
        cout << "Chegou aqui3";
        Solution best = sol;
        int iterILS = 0;
        while (iterILS < maxIterIls){
            BuscaLocal(&sol);
            if (sol.cost < best.cost){
                best = sol;
                iterILS = 0;
            }
            cout << "Chegou aqui4";
            sol = pertubacao(best);
            iterILS += 1;
        }
    }
    return bestOfAll;
}

// Usar algo parecido com a busca local para pertubar
Solution pertubacao(Solution s){
    int segmento_1_tam;
    int segmento_2_tam;

    // Criando a nova solução
    Solution new_sol(s.matrizAdj);

    srand(time(NULL));

    int divisao_segmentos = sizeof(s.matrizAdj[0])/2 - 1;
    int tam_segmento = sizeof(s.matrizAdj[0])/10; // Tamanho max do segmento
    // Escolhendo segmento 1
    int segmento_1_pos = 1 + rand() % (divisao_segmentos);
    if (tam_segmento == 0){
        segmento_1_tam = 2;
    }
    else{
        segmento_1_tam = 2 + (rand() % tam_segmento);
    }

    // Escolhendo Segmento 2
    int segmento_2_pos = segmento_1_pos + segmento_1_tam + rand() % (divisao_segmentos); //  segmento_1_pos + segmento_1_tam para não pegarem mesmo numeros
    if (tam_segmento == 0){
        segmento_2_tam = 2;
    }
    else{
        segmento_2_tam = 2 + (rand() % tam_segmento);
    }

    // Fazendo a pertubação
    int qtd_segmento_1 = 0;
    int qtd_segmento_2 = 0;
    for(int i = 0; i < s.sequencia.size(); i++){
        if ((i >= segmento_1_pos) && ((i <= (segmento_1_pos + segmento_1_tam)))){
            new_sol.add_vertice_sequencia(s.sequencia[segmento_2_pos + qtd_segmento_1], i);
            qtd_segmento_1++;
        }
        else if ((i >= segmento_2_pos) && (i <= (segmento_2_pos + segmento_2_tam))){
            new_sol.add_vertice_sequencia(s.sequencia[segmento_1_pos + qtd_segmento_2], i);
            qtd_segmento_2++;
        }
        else{
            new_sol.add_vertice_sequencia(s.sequencia[i], i);
        }
    }
    new_sol.calcularCost(new_sol);

    /*
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
    */
    return new_sol;
}