// Section 1.6 Exercise 2 : Defs.h
// [Author] Cliff Chen
// [Description] Create two macros,
//				 1. MAX2(x, y) return the max number between x and y.
//				 2. MAX3(x, y, z) return the max number among x, y, z.

// Conditional Compilation to avoid multiply 'include'.
#ifndef DEFS_H
#define DEFS_H

#define MAX2(x, y) ((x) > (y)? (x) : (y))
// [Description] The max number between x and y.
// [Input] x, y : two numbers.
// [Output]  max(x, y)

#define MAX3(x, y, z) (MAX2(MAX2((x), (y)), (z))) // max(x, y, z) = max( max(x, y), z )
// [Description] The max number among x, y, z.
// [Input] x, y, z : three numbers.
// [Output]  max(x, y, z)

#endif