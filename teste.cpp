#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "src/Data.h"
#include "src/Solution.h"
using std::vector;
using std::iterator;

typedef struct Solution{
    vector<int> sequencia;
    double cost;
} Solution;

// Exemplo de inicializacao
int matrizAdj[5][5] = {
    {0,100,50,5,25},
    {100,0,85,5,90},
    {50,85,0,25,10},
    {5,5,25,0,15},
    {25,90,10,15,0}
};
Solution s1 = {{1,3,2,5,4,1}, 0};

// Iterando pelos vertices da Solution
void exibirSolution(Solution *s)
{
    for(int i = 0; i < s->sequencia.size() - 1; i++)
    std::cout << s->sequencia[i] << " -> ";
    std::cout << s->sequencia.back() << std::endl;
}

void calcularCost(Solution *s){
    s->cost = 0;
    for(int i = 0; i < s->sequencia.size() - 1; i++)
    s->cost += matrizAdj[s->sequencia[i]][s->sequencia[i+1]];
}

Solution Construcao(Data* info, size_t n, Solution *s){
    // C++ Sort -> IntroSort: O(n^2) e Alpha(log n)
    // Intro Sort é Quick Sort + HeapSort
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << info->getDistance(i,j);
        } 
    }
    return *s;
}

Solution ILS(int maxIter, int maxIterIls, Data info, size_t n)
{
    Solution bestOfAll;
    bestOfAll.cost = INFINITY;

    double array[n][n] = info->getMatrixCost();
    Solution s = Construcao(&info, n, &bestOfAll); // Algoritmo Guloso -> Solução provavelmente temporaria feita de forma "rápida"
    Solution best = s;
    /*
    for(int i = 0; i < maxIter; i++)
    {
        Solution s = Construcao(info, n, &bestOfAll); // Algoritmo Guloso -> Solução provavelmente temporaria feita de forma "rápida"
        Solution best = s;

        int iterIls = 0;
        /*
        while(iterIls <= maxIterIls)
        {
            BuscaLocal(&s); // Tentar melhorar solução
            if(s.cost < best.cost)
            {
                best = s;
                iterIls = 0;
            }
            s = Perturbacao(best); // Para sair de um ótimo local para outro ótimo local a fim de melhorar a solução
            iterIls++;
        }
        if (best.cost < bestOfAll.cost)
            bestOfAll = best;
        
    }
    */
    return bestOfAll;
}

int main(int argc, char** argv){
    auto data = Data(argc, argv[1]);
    data.read();
    size_t n = data.getDimension(); // É  a dimensão dos problemas -> quantidade de coordenadas
    /*
    exibirSolution(&s1);
    // RESULTADO: "1 -> 6 -> 3 -> 2 -> 5 -> 4 -> 1"

    // Inicializando uma Solution vazia
    Solution s2 = {{}, 0.0};
    // Adicionando vertices na Solution
    s2.sequencia.push_back(1);
    s2.sequencia.push_back(3);
    s2.sequencia.push_back(1);
    exibirSolution(&s2);
    // RESULTADO: "1 -> 3 -> 1"
    s2.sequencia.insert(s2.sequencia.begin() + 1, 4);
    s2.sequencia.insert(s2.sequencia.end() - 1, 5);
    s2.sequencia.insert(s2.sequencia.begin() + 2, 2);
    exibirSolution(&s2);
    // RESULTADO: "1 -> 4 -> 2 -> 3 -> 5 -> 1"

    calcularcost(&s1);
    std::cout << s1.cost;
    */
    return 0;
}
