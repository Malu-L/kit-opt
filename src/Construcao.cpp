#include "Construcao.h"

struct inserir_vetor;


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
    cout << std::endl;
    s->sequencia.push_back(1);
    srand (2); // não repetir numeros
    int random_number;
    cout << sizeof(s->matrizAdj[0]) << std::endl;
    for (int i=0; i<3;i++){
        random_number = rand() % sizeof(s->matrizAdj[0])+1;
        s->sequencia.push_back(random_number);

        auto ptrcl = this->CL.begin();
        for (int i = 0; i < this->CL.size(); i++){
            if (*ptrcl == random_number){
                this->CL.erase(ptrcl);
            }
            std::advance(ptrcl, 1);
        }
    }
    // a Sequencia começa com 1 e termina com 1
    s->sequencia.push_back(1);
    s->exibirSolution(*this->s);
}


// Calcular custo para inserir do CL no vetor solução e criar uma fila de prioridade
vector<inserir_vetor> Construcao::calcular_custo_insercao(){
    int l = 0;
    vector<inserir_vetor> custoInsercao;
    for(int a = 0; a < s->sequencia.size() - 1; a++) {
        int i = s->sequencia[a];
        int j = s->sequencia[a + 1];
        for (auto k : CL){
            custoInsercao.resize(l+1);
            custoInsercao[l].custo = s->matrizAdj[i][k] + s->matrizAdj[j][k] - s->matrizAdj[i][j];
            custoInsercao[l].noInserido = k;
            custoInsercao[l].arestaRemovida = a;
            //std::cout << "Custo: " << custoInsercao[l].custo << std::endl;
            //std::cout << "noInserido: " << custoInsercao[l].noInserido << std::endl;
            //std::cout << "arestaRemovida: " << custoInsercao[l].arestaRemovida << std::endl;
            l++;
        }
    }

    return custoInsercao;
}

void Construcao::inserirNaSolucao(inserir_vetor inserido, Solution *s){
    auto ptrcl = this->CL.begin();
    for (int i = 0; i < this->CL.size(); i++){
        if (*ptrcl == inserido.noInserido){
            this->CL.erase(ptrcl);
        }
        std::advance(ptrcl, 1);
    }
    s->add_vertice_sequencia(inserido.noInserido, inserido.arestaRemovida + 1);
}

vector<inserir_vetor> ordenarEmOrdemCrescente(vector<inserir_vetor> custoInsercao){
    std::sort( custoInsercao.begin(), custoInsercao.end(),
              []( const inserir_vetor &left, const inserir_vetor &right )
                 { return ( left.custo < right.custo ); } );
    return custoInsercao;
}

//Falta função para Inserir o vertice da fila de prioridade escolhido conforme o calculo alfa x |omega|

Solution make_construcao(Solution &s){
    Construcao c(&s);
    c.random_3();

    vector<inserir_vetor> custoInsercao;
    while (!c.get_CL().empty()){
        custoInsercao = c.calcular_custo_insercao();
        ordenarEmOrdemCrescente(custoInsercao);
        double alpha = (double) rand() / RAND_MAX;
        int selecionado = rand() % ((int) ceil(alpha * custoInsercao.size()));
        c.inserirNaSolucao(custoInsercao[selecionado], &s);
        //s.add_vertice_sequencia(custoInsercao[selecionado].noInserido, custoInsercao[selecionado].arestaRemovida + 1);
        
        s.exibirSolution(s);
    }
    return s;
}