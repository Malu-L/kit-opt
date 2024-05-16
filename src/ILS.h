#ifndef ILS_H
#define ILS_H

#include "Busca_local.h"
#include "Construcao.h"
#include "Data.h"
#include "ILS.h"

Solution ILS(int argc, char** argv, int maxIter);
Solution pertubacao(Solution s);

#endif