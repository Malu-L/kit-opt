#ifndef ILS_H
#define ILS_H

#include "Busca_local.h"
#include "Construcao.h"
#include "Data.h"
#include "Solution.h"

#include "ILS.h"

Solution ILS(int argc, char* argv[1], int maxIter, int maxIterIls);
Solution pertubacao(Solution s);

#endif