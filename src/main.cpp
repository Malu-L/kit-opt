#include "Data.h"
#include "Solution.h"
#include "Construcao.h"
#include "Busca_local.h"
#include "ILS.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int maxIter = 50;

    auto data = Data(argc, argv[1]);
    data.read();
    Solution sol(data.getMatrixCost());
    make_construcao(sol); // Aqui não ocorre segmentation fault
    sol.exibirSolution(sol);
    sol = pertubacao(sol);
    sol.exibirSolution(sol);

    //ILS(argc, argv, maxIter);
    Solution bestOfAll;
    bestOfAll.cost = INFINITY;
    data = Data(argc, argv[1]);
    data.read();
    int maxIterIls = data.getDimension()/2;
    for(int i = 0; i < maxIter; i++){
        Solution sol(data.getMatrixCost());
        cout << "Chegou aqui1";
        make_construcao(sol); // Mas ocorre Segmentation fault aqui
        cout << "Chegou aqui2";
        Solution best = sol;
        int iterILS = 0;
        while (iterILS < maxIterIls){
            BuscaLocal(&sol);
            if (sol.cost < best.cost){
                best = sol;
                iterILS = 0;
            }
            sol = pertubacao(best);
            iterILS += 1;
        }
    }
    return 0;
}
