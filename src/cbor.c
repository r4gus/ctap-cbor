#include "cbor.h"

#define MT(x)(x >> 5)
#define ADDITIONAL(x)(x & 0x1F)

int split(uint8_t* mt, uint8_t* ai, uint64_t* data, uint8_t const raw[static 1]) {
    if (mt) *mt = MT(raw[0]);
    uint8_t _ai = ADDITIONAL(raw[0]);
    if (ai) *ai = _ai;
    
    if (!data) return 1;
    switch(_ai) {
        case 31:
        case 30:
        case 29:
        case 28:
            return -1;
        case 27:
            *data = ((uint64_t)raw[1] << 56) + ((uint64_t)raw[2] << 48) + 
                    ((uint64_t)raw[3] << 40) + ((uint64_t)raw[4] << 32) +
                    ((uint64_t)raw[5] << 24) + ((uint64_t)raw[6] << 16) + 
                    ((uint64_t)raw[7] << 8) + (uint64_t)raw[8];
            return 9;
        case 26:
            *data = ((uint64_t)raw[1] << 24) + ((uint64_t)raw[2] << 16) + 
                    ((uint64_t)raw[3] << 8) + (uint64_t)raw[4];
            return 5;
        case 25:
            *data = ((uint64_t)raw[1] << 8) + (uint64_t)raw[2];
            return 3;
        case 24:
            *data = (uint64_t)raw[1];
            return 2;
        default:
            *data = (uint64_t)_ai;
            return 1;
    }
}

//DataItemResult decode_unsigned(uint8_t const data[static 1]) {
//    uint64_t res = 0;
//    switch(ADDITIONAL(data[0])) {
//        case 31:
//        case 30:
//        case 29:
//        case 28:
//            break;
//        case 27:
//            break;
//        case 26:
//            break;
//        case 25:
//            break;
//        case 24:
//            break;
//        default:
//            res = (uint64_t)ADDITIONAL(data[0]);
//            break;
//    }
//}
