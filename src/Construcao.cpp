#include "Construcao.h"

struct inserir_vetor{
    int noInserido; // no k a ser inserido
    int arestaRemovida; // aresta {i,j} na qual o no k sera inserido
    double custo; // delta ao inserir k na aresta {i,j}
};


Construcao::Construcao(Solution* s){
    this->s = s;
    // i começa de 2 pois a lista CL não terá 1
    for (int i=2; i<sizeof(s->matrizAdj[0])+2;i++){
        this->CL.push_back(i);
    }
};

vector<int> Construcao::get_CL(){
    return this->CL;
}

Solution* Construcao::get_solution(){
    return this->s;
}

// add vertice 1 no começo e final + Selecionar 3 vertices aleatorios para fazer parte da solução
void Construcao::random_3(){
    s->sequencia.push_back(1);
    srand (2); // não repetir numeros
    int random_number;
    cout << sizeof(s->matrizAdj[0]) << std::endl;
    for (int i=0; i<3;i++){
        random_number = rand() % sizeof(s->matrizAdj[0])+1;
        s->sequencia.push_back(random_number);
        //this->CL.remover(random_number-1)      -------- falta tirar do CL o vertice escolhido (fazer uma função dentro de Construcao ou Solution?)
    }
    // a Sequencia começa com 1 e termina com 1
    s->sequencia.push_back(1);
    s->exibirSolution(*this->s);
}


// Calcular custo para inserir do CL no vetor solução e criar uma fila de prioridade
vector<inserir_vetor> Construcao::calcular_custo_insercao(){
    int l = 0;
    vector<inserir_vetor> custoInsercao = (vector<inserir_vetor>)* calloc(0, (sizeof(s->sequencia) - 1) * CL.size());  // ----------------- problema para alocar memoria de vetores de struct -> matriz
    for(int a = 0; a < s->sequencia.size() - 1; a++) {
        int i = s->sequencia[a];
        int j = s->sequencia[a + 1];
        for (auto k : CL){
            custoInsercao[l].custo = custoInsercao[i][k] + custoInsercao[j][k] - custoInsercao[i][j];
            custoInsercao[l].noInserido = k;
            custoInsercao[l].arestaRemovida = a;
            l++;

        }
    }

    return custoInsercao;
}

//Falta função para Inserir o vertice da fila de prioridade escolhido conforme o calculo alfa x |omega|

Solution make_construcao(Solution &s){
    Construcao c(&s);
    c.random_3();

    vector<int> custoInsercao;
    while (!c.get_CL().empty()){
        custoInsercao = c.calcular_custo_insercao();
    }
    return s;
}