#ifndef CTAP_CBOR
#define CTAP_CBOR

#include <stddef.h>
#include <stdint.h>

typedef struct {
    char const* const raw;
    size_t len;
    size_t max;
} DataItemEncoding;

typedef enum {
    Unsigned = 0,
    Signed = 1,
    ByteString = 2,
    TextString = 3, 
    Array = 4,
    Map = 5,
    Tagged = 6,
    Simple = 7,
} DataItemType;

typedef struct {
    DataItemType di_type;
    union {
        uint64_t di_unsigned;
        int64_t di_signed;
    };
} DataItem;

typedef enum {
    Ok,
    Error,
} ResultType;

typedef struct {
    ResultType dir_type;
    union {
        DataItem di;
    }; 
} DataItemResult;

int split(uint8_t* mt, uint8_t* ai, uint64_t* data, uint8_t const raw[static 1]);

#endif

