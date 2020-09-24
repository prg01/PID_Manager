/*
 * bitmap_ops.h
 */

#ifndef BITMAP_OPS_H_
#define BITMAP_OPS_H_

/* The quotient represents the integer position(index of array i.e arr[i]) in the given array,
 * since each integer is represented by 32 bits so the divisor is 32.
 * The remainder represents the bit position in the referenced integer above.
 */
#define SetBit(arr,bit_pos) (arr[(bit_pos/32)] |= (1 << (bit_pos%32)))
/* To set the bit position in the integer we use constant'1' (32 bit representation 000...001)
 * left shift the bit 1 by the remainder to set the bit position.
 * Now we OR the 32 bit arr[i] with the left shifted 32 bit value we got above.
 * By doing this the bit position in arr[i] is set and other bits are not affected.
 */
#define ClearBit(arr,bit_pos) (arr[(bit_pos/32)] &= ~(1 << (bit_pos%32)))
/* To clear the bit position in the integer we use constant'1' (32 bit representation 000...001)
 * left shift the bit 1 by the remainder to set the bit position.
 * Now we invert the 32 bits of the left shifted constant'1' to
 * un-set the required bit while forcing all the bits to be '1'
 * Now we AND the 32 bit arr[i] with the inverted left shifted 32 bit value we got above
 * By doing this, the bit position in the integer is cleared(set to 0) and other bits are not affected
 */
#define CheckBit(arr,bit_pos) (arr[(bit_pos/32)] & (1 << (bit_pos%32)))
/* To set the bit position in the integer we use constant'1' (32 bit representation 000...001)
 * left shift the bit 1 by the remainder to set the bit position.
 * Now we AND the 32 bit arr[i] with the left shifted 32 bit value we got above.
 * If the arr[i] bit position is '1' the AND operation will return a non-zero value, indicating bit is already set
 * If the arr[i] bit position is '0' the AND operation will return zero, indicating bit is available.
*/
#endif /* BITMAP_OPS_H_ */
