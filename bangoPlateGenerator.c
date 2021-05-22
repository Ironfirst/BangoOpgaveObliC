#ifndef IMPORTS
#define IMPORTS
#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include <time.h>
#endif

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


//
// Created by ironfirst on 22-05-2021.
//
int testOne;
int numberRange=0;
int indexCounter=0;

int numberArr [31];
int ArrayCount = 0;
int currentArrayIndex = 0;



// -- metoderne der skal rulle de forskellige kolonne værdier ville være praktisk at have i et metodekald
//    da værdierne skal gemmes i et array og checkes før de kan andvendes.
int diceroller(int numRange){
    int roller = rand() % 10 + numRange;
    if(roller == 0 && numRange==0){
        // da 0 ikke må opstå laver jeg et check for dette. eneste tilfælde 0 kan være er hvis begge værdier er 0.
        roller = rand() % 9+1 + numRange;
    }

    // går ud fra metodekaldet vil køre 15 gange pr bango plade. og efter 15 kørsler af denne metode starter den på ny
    // på¨denne måde er den "måske" parat til generisk "generator" metode.
    if(currentArrayIndex<=15){
        // her skal der være check i array om int værdien har optrådt indenfor de sidste 15 array pladser.
        // hvis den findes skal der bruges en ny random værdi som så bliver return.
        for(int i=0;i<15;i++){
            // Check på om det rullede random number "roller" matcher på et index i number array.
            // da vi ikke må have gentagne værdier på en bango plade
            if(numberArr[i]==roller){

                roller = rand() % 10 + numRange;
                i = 0;
                continue;
            }
        }

        // hvis den kommer hertil var den ingen match på array og den kan oprettes!
        numberArr[currentArrayIndex] = roller;
        ArrayCount++;
        currentArrayIndex++;
    }

        // hvis else bliver ramt her er arraycount over 15 og en hel bangoplade er blevet oprettet.
        // arraycount sættes til 0 så en ny plade kan genereres.
    else{
        currentArrayIndex=0;
        ArrayCount=0;
    }
    // roller retuneres
    return roller;
}


void BangoGenerateLayerTree(int boards, struct BangoPlate* BangoArrayPointer){
    // BangoPlade construct BangoArr med input (boards) mængde.
    struct BangoPlate *BangoArr = BangoArrayPointer;


    // et forloop med " clean slate" sætter aller værdier i BangoPlade
    for (int y = 0; y < boards-1; ++y) {
        struct BangoPlate *pointy = &BangoArr[y];
        int *pointyTooo = &pointy->bangoFelt1;
        for (int i = 0; i < 27-1; ++i) {

            *pointyTooo = testOne;
            pointyTooo++;
        }
    }

    for(int i=0;i<=boards-1;i++){

        numberRange=0;
        indexCounter=0;

        // pointer til BangoArr index 0.
        int *ptr_board = &BangoArr[i].bangoFelt1;

        // for loop der generere værdier.
        for (int j = 0; j <= 9-1 ; ++j) {

        // hver gang indexCounter rammer 8 skal 3 række af en bangoplade udfyldes.
            if(indexCounter>=8) {


                // dette for loop køre 4 gange

                // denne for loop går igennem den sidste række. køre 4 gange for at tilføje en række.
                for (int k = 0; k <= 6; k++) {

                    // problem når denne forloop iterere fra 0 til 2. så bruger jeg index til at finde index 2 men skal bruge index 3.
                    // lidt tvivl om opsættelse her. skal checke index 0 og 1 og se om en af disse har rowcheck værdi 1. hvis 1 så er der ingen i samler kolonne. og der skal tilføjes en.

                    // ved at have initialiseringen af denne pointer efter forloop sætter den pointer til det valgte array og frisk hver gang den iterere igennem loopen.
                    int *arrayStructCheckPointer1 = &BangoArr[i].bangoFelt1;
                    int *arrayStructCheckPointer10 = &BangoArr[i].bangoFelt10;

                    int *arrayStructCheckPointer3 = &BangoArr[i].bangoFelt3;
                    int *arrayStructCheckPointer12 = &BangoArr[i].bangoFelt12;

                    int *arrayStructCheckPointer5 = &BangoArr[i].bangoFelt5;
                    int *arrayStructCheckPointer14 = &BangoArr[i].bangoFelt14;

                    int *arrayStructCheckPointer7 = &BangoArr[i].bangoFelt7;
                    int *arrayStructCheckPointer16 = &BangoArr[i].bangoFelt16;


                    // opretter 1-2
                    if(k==0){
                        // check på index 1 og 10
                        if(*arrayStructCheckPointer1 ==0 && *arrayStructCheckPointer10 ==0){
                            // opret index 0
                            *ptr_board = diceroller(numberRange);   // generisk random starter på 0
                            numberRange+=20;
                            indexCounter+=1;
                            ptr_board++;
                            *ptr_board = 0;
                            ptr_board++;
                            k++;
                        }
                        else{
                            // opret index 1
                            *ptr_board = 0;
                            ptr_board++;
                            numberRange+=10;
                            *ptr_board = diceroller(numberRange);
                            ptr_board++;
                            numberRange+=10;
                            indexCounter+=1;
                            k++;
                        }

                    }
                        // opretter 3-4
                    else if(k==2){
                        if(*arrayStructCheckPointer3 ==0 && *arrayStructCheckPointer12 ==0){
                            // opret index 0
                            *ptr_board = diceroller(numberRange);   // generisk random starter på 0
                            numberRange+=20;
                            indexCounter+=1;
                            ptr_board++;
                            *ptr_board = 0;
                            ptr_board++;
                            k++;
                        }
                        else{
                            // opret index 1
                            *ptr_board = 0;
                            ptr_board++;
                            numberRange+=10;
                            *ptr_board = diceroller(numberRange);
                            ptr_board++;
                            numberRange+=10;
                            indexCounter+=1;
                            k++;
                        }

                    }
                        // opretter 5-6
                    else if(k==4){
                        if(*arrayStructCheckPointer5 ==0 && *arrayStructCheckPointer14 ==0){
                            // opret index 0
                            *ptr_board = diceroller(numberRange);   // generisk random starter på 0
                            numberRange+=20;
                            indexCounter+=1;
                            ptr_board++;
                            *ptr_board = 0;
                            ptr_board++;
                            k++;
                        }
                        else{
                            // opret index 1
                            *ptr_board = 0;
                            ptr_board++;
                            numberRange+=10;
                            *ptr_board = diceroller(numberRange);
                            ptr_board++;
                            numberRange+=10;
                            indexCounter+=1;
                            k++;
                        }
                    }
                        // opretter felt 7 og 8 samt 9
                    else if(k==6){
                        if(*arrayStructCheckPointer7 ==0 && *arrayStructCheckPointer16 ==0){
                            // opret index 0
                            *ptr_board = diceroller(numberRange);   // generisk random starter på 0
                            numberRange+=20;
                            indexCounter+=1;
                            ptr_board++;
                            *ptr_board = 0;
                            ptr_board++;
                            *ptr_board = diceroller(numberRange);

                            k++;
                            numberRange=0;
                            indexCounter=0;
                        }
                        else{
                            // opret index 1
                            *ptr_board = 0;
                            ptr_board++;
                            numberRange+=10;
                            *ptr_board = diceroller(numberRange);
                            ptr_board++;
                            numberRange+=10;
                            indexCounter+=1;
                            *ptr_board = diceroller(numberRange);

                            numberRange=0;
                            indexCounter=0;
                            k++;
                        }
                    }
                }
            }


                // når indexcounter er 3 og 7 bliver der oprettet de sidste 3 værdier i en række.
            else if(indexCounter ==3 || indexCounter == 7 ){

                int randomNum3 = rand() % 2+1;
                // hvis randomNum3 er 1 så bruges 7
                if(randomNum3==1){
                    *ptr_board = diceroller(numberRange);
                    ptr_board++;

                    // iterere ikke pointer her. gør det i næste if else statement.
                    //  indexCounter+=1;
                }
                    // hvis randomNum3 er 1 så bruges 8
                else if(randomNum3==2){
                    *ptr_board=0;
                    numberRange+=10;
                    ptr_board++;
                    *ptr_board = diceroller(numberRange);

                }
                else{
                    printf("something went wrong and the 7-8 bango fields on 1 row. number was other then 7-8");
                }

                // for at alle felter kan være random er det lidt specialt sidste check her da der kun er 9 felter og man skal udfylde 5.
                int randomNum4 = rand() % 2+1;
                // randomNum3 fra 7-8 check på hvilken der blev brugt så de 2 sidste muligheder kan vælges.

                // ved 1 er 7 brugt og 8 samt 9 er ledig.
                if(randomNum3==1){
                    // random4 er 1 og 8 bruges
                    if(randomNum4==1){
                        numberRange+=10;
                        *ptr_board = diceroller(numberRange);
                        ptr_board++;
                        *ptr_board=0;
                        ptr_board++;
                        numberRange=0;
                        indexCounter+=1;
                    }

                        // randomNr4 er 2 og 9 bruges.
                    else if(randomNum4==2){
                        *ptr_board=0;
                        ptr_board++;
                        numberRange+=20;
                        *ptr_board = diceroller(numberRange);
                        ptr_board++;
                        numberRange=0;
                        indexCounter+=1;
                    }
                    else{
                        // printf("something went wrong and the 8-9 bango fields on 1 row. number was other then 8-9: Line 298 aprox");
                    }
                }


                    // ved 2 er 8 brugt og 7 samt 9 er ledig.
                else if(randomNum3 == 2) {

                    // hvis randomNUm4 er 1 så bruges 7
                    if(randomNum4 == 1){
                        // 8 er brugt og ved randomNum4 sættes 7 til en værdi. så pointer skal iterere en gang tilbage først. samt numberRange -10 så den passer.
                        ptr_board--;
                        numberRange-=10;
                        *ptr_board = diceroller(numberRange);
                        // og så iterere frem til 10 så den har index pointer korrekt til næste række.
                        ptr_board++;
                        ptr_board++;
                        *ptr_board=0;
                        ptr_board++;
                        numberRange=0;
                        indexCounter+=1;
                    }

                        // hvis randomNUm4 er 2 så bruges 9
                    else if(randomNum4==2){
                        ptr_board--;
                        *ptr_board=0;
                        ptr_board++;
                        ptr_board++;
                        numberRange +=10;
                        *ptr_board = diceroller(numberRange);
                        ptr_board++;
                        numberRange =0;
                        indexCounter+=1;

                    }
                    else{
                        printf("something went wrong and the 7 or 9 bango fields on 1 row. the number was not 7 or 9 ");
                    }
                }
                else{
                    printf("Something went wrong with the 1 or 2 og RandomNR4");
                }
            }

                // hvis indexcounter ikke er 4-7 eller over 8 så køre den normale tilføjnings procedure.
            else{
                int randomNum = rand() % 2+1;

                // hvis 1 så bruges felt 1 af de 2 mulige.
                if(randomNum==1){
                    *ptr_board = diceroller(numberRange);
                    numberRange+=20;
                    indexCounter+=1;
                    ptr_board++;
                    *ptr_board = 0;
                    ptr_board++;
                }

                    // ved 2 bruges felt nr 2 af 2 mulige.
                else if(randomNum==2){   //diceroller metoden bruger rand() % 10. som base. så f.eks 10 er 1-9+10
                    *ptr_board = 0;
                    ptr_board++;
                    numberRange+=10;
                    *ptr_board = diceroller(numberRange);
                    ptr_board++;
                    numberRange+=10;
                    indexCounter+=1;
                }
            }
        }
    }

    // test udprint af array af structs.
    int boardCountForUdprint = 0;
    for (int j = 0; j < boards-1; ++j) {
        boardCountForUdprint++;
        printf("\nBoard Nr: %d",boardCountForUdprint);
        printf("\nBangoArr[0]value:%d" ,BangoArr[j].bangoFelt1);
        printf("\nBangoArr[1]value:%d" ,BangoArr[j].bangoFelt2);
        printf("\nBangoArr[2]value:%d" ,BangoArr[j].bangoFelt3);
        printf("\nBangoArr[3]value:%d" ,BangoArr[j].bangoFelt4);
        printf("\nBangoArr[4]value:%d" ,BangoArr[j].bangoFelt5);
        printf("\nBangoArr[5]value:%d" ,BangoArr[j].bangoFelt6);
        printf("\nBangoArr[6]value:%d" ,BangoArr[j].bangoFelt7);
        printf("\nBangoArr[7]value:%d" ,BangoArr[j].bangoFelt8);
        printf("\nBangoArr[8]value:%d" ,BangoArr[j].bangoFelt9);
        printf("\nThis is first row.\n");

        printf("\nBangoArr[9]value:%d" ,BangoArr[j].bangoFelt10);
        printf("\nBangoArr[10]value:%d" ,BangoArr[j].bangoFelt11);
        printf("\nBangoArr[11]value:%d" ,BangoArr[j].bangoFelt12);
        printf("\nBangoArr[12]value:%d" ,BangoArr[j].bangoFelt13);
        printf("\nBangoArr[13]value:%d" ,BangoArr[j].bangoFelt14);
        printf("\nBangoArr[14]value:%d" ,BangoArr[j].bangoFelt15);
        printf("\nBangoArr[15]value:%d" ,BangoArr[j].bangoFelt16);
        printf("\nBangoArr[16]value:%d" ,BangoArr[j].bangoFelt17);
        printf("\nBangoArr[17]value:%d" ,BangoArr[j].bangoFelt18);
        printf("\nThis is second row.\n");

        printf("\nBangoArr[18]value:%d" ,BangoArr[j].bangoFelt19);
        printf("\nBangoArr[19]value:%d" ,BangoArr[j].bangoFelt20);
        printf("\nBangoArr[20]value:%d" ,BangoArr[j].bangoFelt21);
        printf("\nBangoArr[21]value:%d" ,BangoArr[j].bangoFelt22);
        printf("\nBangoArr[22]value:%d" ,BangoArr[j].bangoFelt23);
        printf("\nBangoArr[23]value:%d" ,BangoArr[j].bangoFelt24);
        printf("\nBangoArr[24]value:%d" ,BangoArr[j].bangoFelt25);
        printf("\nBangoArr[25]value:%d" ,BangoArr[j].bangoFelt26);
        printf("\nBangoArr[26]value:%d" ,BangoArr[j].bangoFelt27);
        // printf("\nPlate id:%d" ,BangoArr[j].plate_id);
    }
    int boardCountForUdprint1 = 0;
    for (int j = 0; j < boards-1; ++j) {
        boardCountForUdprint1++;
        printf("\nBoard Nr: %d \n",boardCountForUdprint1);
        printf("\nThis is first row.\n");
        printf("[%d] +" ,BangoArr[j].bangoFelt1);
        printf("[%d] +" ,BangoArr[j].bangoFelt2);
        printf("[%d] +" ,BangoArr[j].bangoFelt3);
        printf("[%d] +" ,BangoArr[j].bangoFelt4);
        printf("[%d] +" ,BangoArr[j].bangoFelt5);
        printf("[%d] +" ,BangoArr[j].bangoFelt6);
        printf("[%d] +" ,BangoArr[j].bangoFelt7);
        printf("[%d] +" ,BangoArr[j].bangoFelt8);
        printf("[%d] " ,BangoArr[j].bangoFelt9);

        printf("\nThis is second row.\n");
        printf("[%d] +" ,BangoArr[j].bangoFelt10);
        printf("[%d] +" ,BangoArr[j].bangoFelt11);
        printf("[%d] +" ,BangoArr[j].bangoFelt12);
        printf("[%d] +" ,BangoArr[j].bangoFelt13);
        printf("[%d] +" ,BangoArr[j].bangoFelt14);
        printf("[%d] +" ,BangoArr[j].bangoFelt15);
        printf("[%d] +" ,BangoArr[j].bangoFelt16);
        printf("[%d] +" ,BangoArr[j].bangoFelt17);
        printf("[%d] " ,BangoArr[j].bangoFelt18);

        printf("\nThis is second row.\n");
        printf("[%d] +" ,BangoArr[j].bangoFelt19);
        printf("[%d] +" ,BangoArr[j].bangoFelt20);
        printf("[%d] +" ,BangoArr[j].bangoFelt21);
        printf("[%d] +" ,BangoArr[j].bangoFelt22);
        printf("[%d] +" ,BangoArr[j].bangoFelt23);
        printf("[%d] +" ,BangoArr[j].bangoFelt24);
        printf("[%d] +" ,BangoArr[j].bangoFelt25);
        printf("[%d] +" ,BangoArr[j].bangoFelt26);
        printf("[%d]  +" ,BangoArr[j].bangoFelt27);
        printf("\n----------------------------------\n");

    }
    int hasNum=0;
    for (int y = 0; y < boards-1; ++y) {
        struct BangoPlate *pointy2 = &BangoArr[y];
        int *pointyTooo2 = &pointy2->bangoFelt1;
        for (int i = 0; i < 27; ++i) {


            if(*pointyTooo2 != 0){
                hasNum++;
            }
            pointyTooo2++;
        }
        printf("\n Value pr row, If this is not 15 we are in touble:%d", hasNum);
        hasNum =0;
    }
}