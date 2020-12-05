//
// Created by Mac Admin on 2020-11-19.
//


#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "math.h"



void stockerTransactions (char *entree);
void isolerTransactions (char *transaction);
void transac00 ();
void transa01();
void transa02();
void transa03();
void transa04();
void transa05();

int cptERRTH = 0;
int cptERRTA = 0;
int cptERRPUL = 0;

int erreurTH = 0;
int erreurTA = 0;
int erreurPUL = 0;

int invalTH = 0;
int invalTA = 0;
int invalPUL = 0;
int invalSIN = 0;


float moyTH = 0;
float moyTA = 0;
float moyPUL = 0;

int compteMoyenneTH = 0;
int compteMoyenneTA = 0;
int compteMoyennePUL = 0;

int compte = 0;
int compte2 = 0;
char *transactions[100];
char *elements[50];

int compteIDPN = 0;
int idpn [25];
size_t timestamp;
int num;
size_t id;
int puiss;
float distance;
int N;

void stockerTransactions (char *entree) {

    char *transaction;
    char cpy[100];

    strcpy(cpy,entree);
    transaction = strtok(cpy,"\n");

    while (transaction != NULL) {
        transactions[compte] = transaction;
        compte++;
        transaction = strtok(NULL,"\n");
    }
}

void isolerTransactions (char *transaction) {

    char *element;
    char cpy2[200];

    strcpy(cpy2,transaction);
    element = strtok(cpy2," ");

    while (element != NULL) {
        elements[compte2] = element;
        compte2++;
        element  = strtok(NULL," ");
    }
    compte2 = 0 ;
}

void transac00 () {
    if(elements[2]==NULL&&elements[3]==NULL) {
        timestamp = atoi(elements[0]);
        num = 10;
        id = 9999;
        idpn[compteIDPN] =  id;
        compteIDPN++;
        puiss = 3;
        N = puiss;
        printf("%d %zu %zu %d \n",num,timestamp,id,puiss);
    } else if (elements[3]==NULL) {
        timestamp = atoi(elements[0]);
        num = 10;
        id = atoi(elements[2]);
        idpn[compteIDPN] =  id;
        compteIDPN++;
        puiss = 3;
        N = puiss;
        printf("%d %zu %zu %d \n",num,timestamp,id,puiss);
    } else {
        timestamp = atoi(elements[0]);
        num = 10;
        id = atoi(elements[2]);
        idpn[compteIDPN] =  id;
        compteIDPN++;
        puiss = atoi(elements[3]);
        N = puiss;
        printf("10 %zu %zu %d \n",timestamp,id,puiss);
    }
    elements[0]=NULL;
    elements[1]=NULL;
    elements[2]=NULL;
    elements[3]=NULL;
    compte2 = 0;
}

void transa01() {
    compteMoyenneTH++;
    if(strcmp(elements[2],"ERREUR") == 0) {
        cptERRTH++;
        if (cptERRTH % 3 == 0) {
            erreurTH = (int) cptERRTH / 3;
        }
    }else if (compteMoyenneTH == 1) {
        moyTH = atof(elements[2]);
    } else {
        moyTH = (moyTH + atof(elements[2]))/2;
    }
    elements[0]=NULL;
    elements[1]=NULL;
    elements[2]=NULL;
    elements[3]=NULL;
}

void transa02() {
    compteMoyenneTA++;
    if(strcmp(elements[2],"ERREUR") == 0) {
        cptERRTA++;
        if (cptERRTA % 3 == 0) {
            erreurTA = (int) cptERRTA / 3;
        }
    }else if (compteMoyenneTA == 1) {
        moyTA = atof(elements[2]);
    } else {
        moyTA = (moyTA + atof(elements[2]))/2;
    }
    elements[0]=NULL;
    elements[1]=NULL;
    elements[2]=NULL;
    elements[3]=NULL;
}

void transa03() {
    compteMoyennePUL++;
    if(strcmp(elements[2],"ERREUR") == 0) {
        cptERRPUL++;
        if (cptERRPUL % 3 == 0) {
            erreurPUL = (int) cptERRPUL / 3;
        }
    }else if (compteMoyennePUL == 1) {
        moyPUL = atof(elements[2]);
    } else {
        moyPUL = (moyPUL + atof(elements[2]))/2;
    }
    elements[0]=NULL;
    elements[1]=NULL;
    elements[2]=NULL;
    elements[3]=NULL;
}

void transa04() {
    timestamp = atoi(elements[0]);
    id = atoi(elements[3]);
    idpn[compteIDPN] =  id;
    compteIDPN++;
    float rssi = atof(elements[2]);
    distance = pow(10, (-69 - rssi) / (10 * N));
    int essai = 14;
    printf("%d %zu %zu %0.1f \n",essai, timestamp, id, distance);
    elements[0] = NULL;
    elements[1] = NULL;
    elements[2] = NULL;
    elements[3] = NULL;
}

void transa05() {
    timestamp = atoi(elements[0]);
    printf("15 %zu ",timestamp);
    for(int i = 0;i < compteIDPN;i++) {
        printf("%d ",idpn[i]);
    }
    printf("\n");
}




int main(int argc , char *argv[]) {




        stockerTransactions("0 00 1000 3\n5 04 -35 3456\n19388 05 1929292 100100");
        for (int cpt = 0;cpt < compte;++cpt) {
            compte = 0;
            stockerTransactions("0 00 1000 3\n5 04 -35 3456\n19388 05 1929292 100100");
            isolerTransactions(transactions[cpt]);
            if (strcmp(elements[1], "00") == 0) {
                transac00();
            } else if (strcmp(elements[1], "01") == 0) {
                transa01();
            } else if (strcmp(elements[1], "02") == 0) {
                transa02();
            } else if (strcmp(elements[1], "03") == 0) {
                transa03();
            } else if (strcmp(elements[1], "04") == 0) {
                transa04();
            } else if (strcmp(elements[1], "05") == 0) {
                transa05();
            }
        }


    printf("21 %.1f %.1f %.1f\n",moyTH,moyTA,moyPUL);
    printf("22 %d %d %d\n",invalTH,invalTA,invalPUL);
    printf("23 %d %d %d\n",erreurTH,erreurTA,erreurPUL);
    return 0;
}

