#include "Construcao.h"

Construcao::Construcao(Solution &s){
    this->s = s;
    // i começa de 2 pois a lista CL não terá 1
    for (int i=2; i<sizeof(s.matrizAdj[0])+2;i++){
        this->CL.push_back(i);
    }
};
// add vertice 1 no começo e final + Selecionar 3 vertices aleatorios para fazer parte da solução
void Construcao::random_3(){
    s.sequencia.push_back(1);
    srand (2); // não repetir numeros
    int random_number;
    cout << sizeof(s.matrizAdj[0]) << std::endl;
    for (int i=0; i<3;i++){
        random_number = rand() % sizeof(s.matrizAdj[0])+1;
        s.sequencia.push_back(random_number);
    }
    // a Sequencia começa com 1 e termina com 1
    s.sequencia.push_back(1);
    s.exibirSolution(s);
}

// Calcular custo para inserir do CL no vetor solução e criar um tipo de fila de prioridade
void Construcao::calcular_custo_insercao(){};

// Inserir o vertice da fila de prioridade escolhido conforme o calculo alfa x |omega|
void Construcao::inserir_na_sol(){};


Solution make_construcao(Solution &s){
    Construcao c(s);
    c.random_3();

    return s;
}