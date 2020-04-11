//  Processos.c
//  Created by José Luiz Junior on 22/08/18.
//  Copyright © 2018 José Luiz Junior. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) {
    int pid = 0;
    pid = fork();//Cria processo A
    int i;
    
    if (pid != 0 ) {//Processo Pai

        int pfb = 0;//Cria processo B
        pfb = fork();
        
        if (pfb != 0) {//Atividades do processo Pai
            for (i = 0; i<=999; i++) {
                printf("%d\n",i);
            }
            
        }else{//Atividades do processo B
            for (i = 2000 ; i<= 2999; i++) {
                printf("%d\n",i);
            }
            
        }
        
    }else {//Sendo o processo A

        int pfa = 0;//Cria processo C
        pfa = fork();
        
        if (pfa != 0) {//Atividades do processo A

            int pfd = 0;//Cria D
            pfd = fork();
            
            if (pfd != 0) {//Contagem do A
                for (i = 1000; i<=1999; i++) {
                    printf("%d\n",i);
                }
                
            }else{//Atividades do processo D
                for (i = 4000 ; i<= 4999; i++) {
                    printf("%d\n",i);
                }
            }
            
        }else{//Atividades do processo C
            for (i = 3000 ; i<= 3999; i++) {
                printf("%d\n",i);
            }
        }
        
    }
    
    
    return 0;
}
