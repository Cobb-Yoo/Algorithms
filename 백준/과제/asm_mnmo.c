#include <string.h>
#include <stdio.h>
#include "main_pass1.h"
#include "cal_mnmo.h"
#include "optab.h"
#include "asm_mnmo.h"

int asm_mnemonic(Optab *op){
        unsigned char *obp = OBJC;
        unsigned long long obc = 0;
        int i;
        char *tmp;

        obc = (op->opcode << 24);

        if(op->n_operand){
                if(!OPerand) fprintf(stderr,"%s --> Operand is not defined ...\n",LBUF), exit(10);
                if(!strcmp(op->mnemonic, "DMPR")) obc |= cal_nm_dmpr(OPerand);
                if(op->n_register > 0){
                        obc |= 9 << 20;// x=1, r=1
                        if(op->n_register == 1){ // b,c = 0
                                obc |= (get_rgstno(OPerand) << 16);
                        }
                        else if(op->n_register == 2){ // b = 1, c = 0
                                obc |= 1 << 21;
                                tmp = strtok(OPerand, ", ");
                                for(i=16 ; i>=12 ; i-=4){
                                        obc |= (get_rgstno(tmp) << i);
                                        tmp = strtok(NULL, ", ");
                                }
                        }
                }
                else { //non_register
                        if(OPerand[0] == '@'){
                                obc |= (6 << 29);
                                tmp = strtok(tmp, "@");
                                obc |= cal_nm_oprnd(OPerand+1);
                        }
                        else{
                                obc |= (14 << 29);
                                if(strcmp(op->mnemonic, "END"))
                                        obc |= cal_nm_oprnd(op->n_operand);
}
                }
        }

        OBJC[0] = 4;// length len_mnmo();
        OBJC[1] = obc >> 32;
        OBJC[2] = obc >> 24;
        OBJC[3] = obc >> 16;
        OBJC[4] = obc >> 8;
        OBJC[5] = obc >> 0;

        return(OBJC[0]);
}

