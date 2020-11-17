#include "optab.h"
#include <string.h>

Optab OPTAB[] = {
        "LDA",  0x00,1,0,3,     "LDAi", 0x00,1,0,2,     "LDAn", 0x00,1,0,1,     "LDArn", 0x00,1,1,1,
        "LDAW", 0x01,1,0,3,     "LDAWi", 0x01,1,0,2,    "LDAWn", 0x01,1,0,1,    "LDAWrn", 0x01,1,1,1,
        "LDAB", 0x02,1,0,3,     "LDABi", 0x02,1,0,2,    "LDABn", 0x02,1,0,1,    "LDABrn", 0x02,1,1,1,
        "LDB",  0x03,1,0,3,     "LDBi", 0x03,1,0,2,     "LDBn", 0x03,1,0,1,
        "LDX",  0x04,1,0,3,     "LDXi", 0x04,1,0,2,     "LDXn", 0x04,1,0,1,
        "LDU",  0x05,1,0,3,     "LDUi", 0x05,1,0,2,     "LDUn", 0x05,1,0,1,
        "LDP",  0x06,1,0,3,     "LDPi", 0x06,1,0,2,     "LDPn", 0x06,1,0,1,
        "LDQ",  0x07,1,0,3,     "LDQi", 0x07,1,0,2,     "LDQn", 0x07,1,0,1,
        "STA",  0x08,1,0,3,                             "STAn", 0x08,1,0,1,     "STArn", 0x08,1,1,1,
        "STAW", 0x09,1,0,3,                             "STAWn", 0x09,1,0,1,    "STAWrn", 0x09,1,1,1,
        "STAB", 0x0A,1,0,3,                             "STABn", 0x0A,1,0,1,    "STABrn", 0x0A,1,1,1,
        "LDS",  0x0B,1,0,3,     "LDSi", 0x0B,1,0,2,     "LDSn", 0x0B,1,0,1,
        "STX",  0x0C,1,0,3,                             "STXn", 0x0C,1,0,1,
        "STU",  0x0D,1,0,3,                             "STUn", 0x0D,1,0,1,
        "STB",  0x0E,1,0,3,                             "STBn", 0x0E,1,0,1,
        "STP",  0x0F,1,0,3,                             "STPn", 0x0F,1,0,1,
        "ADD",  0x10,1,0,3,     "ADDi", 0x10,1,0,2,     "ADDn", 0x10,1,0,1,     "ADDrn", 0x10,1,1,1,    "ADDR", 0x10,2,2,3,
        "ADDW", 0x11,1,0,3,     "ADDWi", 0x11,1,0,2,    "ADDWn", 0x11,1,0,1,    "ADDWrn", 0x11,1,1,1,
        "ADDB", 0x12,1,0,3,     "ADDBi", 0x12,1,0,2,    "ADDBn", 0x12,1,0,1,    "ADDBrn", 0x12,1,1,1,
        "STQ",  0x13,1,0,3,                             "STQn", 0x13,1,0,1,
        "SUB",  0x14,1,0,3,     "SUBi", 0x14,1,0,2,     "SUBn", 0x14,1,0,1,     "SUBrn",0x14,1,1,1,     "SUBR", 0x14,2,2,3,
        "SUBW", 0x15,1,0,3,     "SUBWi", 0x15,1,0,2,    "SUBWn", 0x15,1,0,1,    "SUBWrn", 0x15,1,1,1,
        "SUBB", 0x16,1,0,3,     "SUBBi", 0x16,1,0,2,    "SUBBn", 0x16,1,0,1,    "SUBBrn", 0x16,1,1,1,
        "MOD",  0x17,1,0,3,     "MODi", 0x17,1,0,2,     "MODn", 0x17,1,0,1,     "MODrn", 0x17,1,1,1,    "MODR", 0x17,2,2,3,
        "AND",  0x18,1,0,3,     "ANDi", 0x18,1,0,2,     "ANDn", 0x18,1,0,1,     "ANDrn", 0x18,1,1,1,    "ANDR", 0x18,2,2,3,
        "OR",   0x19,1,0,3,     "ORi", 0x19,1,0,2,      "ORn", 0x19,1,0,1,      "ORrn", 0x19,1,1,1,     "ORR",  0x19,2,2,3,
        "XOR",  0x1A,1,0,3,     "XORi", 0x1A,1,0,2,     "XORn", 0x1A,1,0,1,     "XORrn", 0x1A,1,1,1,    "XORR", 0x1A,2,2,3,
        "MOVR", 0x1B,2,2,3,
        "SHL",  0x1C,1,0,3,     "SHLi", 0x1C,1,0,2,     "SHLn", 0x1C,1,0,1,     "SHLrn", 0x1C,1,1,1,
        "SHR",  0x1D,1,0,3,     "SHRi", 0x1D,1,0,2,     "SHRn", 0x1D,1,0,1,     "SHRrn", 0x1D,1,1,1,
        "STS",  0x1E,1,0,3,                             "STSn", 0x1E,1,0,1,
        "CLR",  0x1F,1,1,3,
        "CMP",  0x20,1,0,3,     "CMPi", 0x20,1,0,2,     "CMPn", 0x20,1,0,1,     "CMPrn", 0x20,1,1,1,    "CMPR", 0x20,2,2,3,
        "CMPW", 0x21,1,0,3,     "CMPWi", 0x21,1,0,2,    "CMPWn", 0x21,1,0,1,    "CMPWrn", 0x21,1,1,1,
        "CMPB", 0x22,1,0,3,     "CMPBi", 0x22,1,0,2,    "CMPBn", 0x22,1,0,1,    "CMPBrn", 0x22,1,1,1,
        "PUSH", 0x23,1,1,3,
        "IXC",  0x24,1,0,3,     "IXCi", 0x24,1,0,2,     "IXCn", 0x24,1,0,1,     "IXCrn", 0x24,1,1,1,    "IXCR", 0x24,1,1,3,
        "IXWC", 0x25,1,0,3,     "IXWCi", 0x25,1,0,2,    "IXWCn", 0x25,1,0,1,    "IXWCrn", 0x25,1,1,1,   "IXWCR", 0x25,1,1,3,
        "POP",  0x27,1,1,3,
        "JZ",   0x28,1,0,3,     "JZi", 0x28,1,0,2,      "JZn", 0x28,1,0,1,      "JZrn", 0x28,1,1,1,
        "JNZ",  0x29,1,0,3,     "JNZi", 0x29,1,0,2,     "JNZn", 0x29,1,0,1,     "JNZrn", 0x29,1,1,1,
        "JC",   0x2A,1,0,3,     "JCi", 0x2A,1,0,2,      "JCn", 0x2A,1,0,1,      "JCrn", 0x2A,1,1,1,
        "JMP",  0x2B,1,0,3,     "JMPi", 0x2B,1,0,2,     "JMPn", 0x2B,1,0,1,     "JMPrn", 0x2B,1,1,1,
        "GSUB", 0x2C,1,0,3,     "GSUBi", 0x2C,1,0,2,    "GSUBn", 0x2C,1,0,1,
        "RSUB", 0x2D,0,0,3,
        "CALL", 0x2E,1,0,3,
        "RET",  0x2F,0,0,3,
        "CID",  0x30,1,0,3,     "CIDi", 0x30,1,0,2,     "CIDn", 0x30,1,0,1,
        "INCR", 0x31,1,1,3,
        "COD",  0x32,1,0,3,     "CODi", 0x32,1,0,2,     "CODn", 0x32,1,0,1,
        "INCWR", 0x33,1,1,3,
        "IN",   0x34,1,0,3,     "INi", 0x34,1,0,2,      "INn", 0x34,1,0,1,
        "DECR", 0x35,1,1,3,
        "OUT",  0x36,1,0,3,     "OUTi", 0x36,1,0,2,     "OUTn", 0x36,1,0,1,
        "DECWR", 0x37,1,1,3,
        "DMP",  0x39,1,0,3,     "DMPi", 0x39,1,0,2,     "DMPn", 0x39,1,0,1,     "DMPrn", 0x39,1,1,1,    "DMPR", 0x39,1,1,3,
        "DMPW", 0x3A,1,0,3,     "DMPWi", 0x3A,1,0,2,    "DMPWn", 0x3A,1,0,1,    "DMPWrn", 0x3A,1,1,1,   "DMPWR", 0x3A,1,1,3,
        "DMPB", 0x3B,1,0,3,     "DMPBi", 0x3B,1,0,2,    "DMPBn", 0x3B,1,0,1,    "DMPBrn", 0x3B,1,1,1,   "DMPBR", 0x3B,1,1,3,
        "DMPS", 0x3C,1,0,3,
        "INCBR", 0x3D,1,1,3,
        "DECBR", 0x3E,1,1,3,
};

Optab *see_OPTAB(char *opc){
        int i;
        for(i=0;i<MAX_OPTAB;i++){
                if(!strcmp(OPTAB[i].mnemonic, opc))
                        return(&OPTAB[i]);
        }
        return NULL;
}

