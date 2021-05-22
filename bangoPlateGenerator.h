//
// Created by ironfirst on 22-05-2021.
//

#ifndef BANGOBANGO_BANGOPLATEGENERATOR_H
#define BANGOBANGO_BANGOPLATEGENERATOR_H

#ifndef BangoPladeINITCHECK
#define BangoPladeINITCHECK


struct BangoPlate {

    // bangoplader hver række har 9 felter og der er 3 rækker.
    int bangoFelt1;
    int bangoFelt2;
    int bangoFelt3;
    int bangoFelt4;
    int bangoFelt5;
    int bangoFelt6;
    int bangoFelt7;
    int bangoFelt8;
    int bangoFelt9;

    // række 2 - 9 felter
    int bangoFelt10;
    int bangoFelt11;
    int bangoFelt12;
    int bangoFelt13;
    int bangoFelt14;
    int bangoFelt15;
    int bangoFelt16;
    int bangoFelt17;
    int bangoFelt18;

    // række 3 - 9 felter
    int bangoFelt19;
    int bangoFelt20;
    int bangoFelt21;
    int bangoFelt22;
    int bangoFelt23;
    int bangoFelt24;
    int bangoFelt25;
    int bangoFelt26;
    int bangoFelt27;


};

#endif

void BangoGenerateLayerTree(int boards, struct BangoPlate* BangoArrayPointer);
int diceroller(int numRange);



#endif //BANGOBANGO_BANGOPLATEGENERATOR_H
