#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct ring_buffer_
{
    uint8_t *buffer;
    uint32_t mask;
    uint32_t read_index;
    uint32_t write_index;
} ring_buffer_t;

void ring_buffer_setup(ring_buffer_t *ring_buffer, uint8_t *buffer, uint32_t size);
bool ring_buffer_empty(ring_buffer_t *ring_buffer);
bool ring_buffer_write(ring_buffer_t *ring_buffer, uint8_t byte);
bool ring_buffer_read(ring_buffer_t *ring_buffer, uint8_t *byte);

/*

Suppose u want to do n % 8, i.e, you want the remainder
when n is divided by 8; Let n in binary be some 11111001
which is 8k + 001; the last three bits will at most make seven and
all the upper bits are divisible by 8; thus, it's of the form 8k + r where
0<=r<=7 and thus this r, or the lower 3 bits is the remainder of n when divided by eight;

In generator if we want to do n % 2^j for any j >= 1; we just take the lower j - 1 bits of n as the remainder;
i.e we do n & 111...1(j-1 times), which is literally n & (2^j - 1) since 111...1(j-1 times) is (2^j - 1)

*/

#endif