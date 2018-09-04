//
//  main.c
//  Thread
//
//  Created by José Luiz Junior on 04/09/18.
//  Copyright © 2018 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREAD 4

void delay(){
    
    int i, j, k, valor = 1000;
    
    for (i = 0; i < valor; i++)
        for (j = 0; j < valor; j++)
            for (k = 0; k < valor; k++)
                valor = valor;
    
}


void funcao(void *arg){
    int *pvalor;
    
    pvalor = arg;
    
    printf("Thread %i executando... \n", *pvalor);
    delay();
    printf("Thread %i executando... \n", *pvalor);
    
}


int main(int argc, const char * argv[]) {
    pthread_t threads[N_THREAD];//criamos um vetor com a quantidade
    int i, arg[N_THREAD];
    
    for (i = 0; i < N_THREAD; i++) {
        arg[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&arg[i]);
        
    }
    
    for (i = 0; i < N_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("/n");
    
    return 0;
}
