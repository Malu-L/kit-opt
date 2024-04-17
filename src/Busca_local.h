#ifndef BUSCA_LOCAL_H
#define BUSCA_LOCAL_H

#include "Solution.h"

void BuscaLocal(Solution *s);
bool bestImprovementSwap(Solution *s);
bool bestImprovement2Opt(Solution *s);
bool bestImprovementOrOpt(Solution *s, int qtd_vertice);

#endif