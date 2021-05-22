#ifndef IMPORTS
#define IMPORTS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#endif


#include "bangoPlateGenerator.h"


int main()
{

    // malloc main hukommelse initialisering.
    struct BangoPlate *BangoArr = malloc(12*sizeof(struct BangoPlate));


    // dette laver bedre random.
    srand(time(NULL));


    BangoGenerateLayerTree(12,BangoArr);

    free(BangoArr);
    return 0;
}
