
//********************************************************//
//                                                        //
// libsharptwoth                                               //
//                                                        //
// Repository:  https://github.com/croqueue/sharptwoth          //
// Author:      Danielle Thompson, Ph.D (2022)              //
// File:        src/include/sharptwoth/internal.h              //
// Description: Internal hash-computation functions       //
//                                                        //
//********************************************************//

#ifndef SHARP2TH_INTERNAL_H
#define SHARP2TH_INTERNAL_H

#include <stdarg.h>
#include <stdint.h>
#include "sharptwoth/sharptwoth.h"

//========================//
// Shared Function Macros //
//========================//

// General bitwise functions
#define ROTR(x, r)  (((x) >> (r)) | ((x) << ((sizeof((x)) << 3) - (r))))
#define ROTL(x, r)  (((x) << (r)) | ((x) >> ((sizeof((x)) << 3) - (r))))

// Shared atomic subroutines
#define CH(x, y, z)     (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z)    (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define PARITY(x, y, z) ((x) ^ (y) ^ (z))

// Linear functions (256-bit algorithms)
#define SIGMA0_256(x)   (ROTR((x), 2) ^ ROTR((x), 13) ^ ROTR((x), 22))
#define SIGMA1_256(x)   (ROTR((x), 6) ^ ROTR((x), 11) ^ ROTR((x), 25))
#define LSIGMA0_256(x)  (ROTR((x), 7) ^ ROTR((x), 18) ^ ((x) >> 3))
#define LSIGMA1_256(x)  (ROTR((x), 17) ^ ROTR((x), 19) ^ ((x) >> 10))

// Linear functions (512-bit algorithms)
#define SIGMA0_512(x)   (ROTR((x), 28) ^ ROTR((x), 34) ^ ROTR((x), 39))
#define SIGMA1_512(x)   (ROTR((x), 14) ^ ROTR((x), 18) ^ ROTR((x), 41))
#define LSIGMA0_512(x)  (ROTR((x), 1) ^ ROTR((x), 8) ^ ((x) >> 7))
#define LSIGMA1_512(x)  (ROTR((x), 19) ^ ROTR((x), 61) ^ ((x) >> 6))

//============================//
// Hash-Computation Functions //
//============================//

void
compute_160(
    uint32_t * hash_words, 
    const uint8_t * message, 
    const uint64_t message_len
);

void
compute_256(
    uint32_t * hash_words, 
    const uint8_t * message, 
    const uint64_t message_len
);

void
compute_512(
    uint64_t * hash_words, 
    const uint8_t * message, 
    const uint64_t message_len
);

//=======================//
// Misc Shared Functions //
//=======================//

void
unpack_32(
    uint8_t * buf, 
    const uint32_t * words, 
    const uint8_t byte_count, 
    const ShaDigestFormat format
);

void
unpack_64(
    uint8_t * buf, 
    const uint64_t * words, 
    const uint8_t byte_count, 
    const ShaDigestFormat format
);

#endif // SHARP2TH_INTERNAL_H
