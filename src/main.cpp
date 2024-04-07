#include "Data.h"
#include "Solution.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    auto data = Data(argc, argv[1]);
    data.read();
    // O tipo size_t armazena o tamanho de qualquer tipo de objeto, em bytes
    size_t n = data.getDimension(); // É  a dimensão dos problemas -> quantidade de coordenadas
    /*
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << data.getDistance(i,j);
        } 
    }
    */
    Solution sol(data.getMatrixCost(), {1,5,2,1});
    sol.exibirSolution(sol);
    
    /*
    cout << "Dimension: " << n << endl;
    cout << "DistanceMatrix: " << endl;
    data.printMatrixDist();


    cout << "Exemplo de Solucao s = ";
    double cost = 0.0;
    for (size_t i = 1; i < n; i++) {
        cout << i << " -> ";
        cost += data.getDistance(i, i+1);
    }
    cost += data.getDistance(n, 1);
    cout << n << " -> " << 1 << endl;
    cout << "Custo de S: " << cost << endl;
    */
    return 0;
}
