// Section 1.6 Exercise 1 : Defs.h
// [Author] Cliff Chen
// [Description] Create two marcos, PRINT1 and PRINT2
//               The first prints only a.
//               The second prints a and b.
// Preprocessor directive

// implement the mechanism to avoid multiple inclusion of the header file.
#ifndef DEFS_H
#define DEFS_H

#define PRINT1(a) ( printf("a = %c\n", a) )
// [Description] Print one variable.
// [Input] a : a character.
// [Output] None.

#define PRINT2(a, b) ( printf("a = %c, b = %c\n", a, b) )
// [Description] Print two variables.
// [Input] a : a character.
//  	   b : a character.
// [Output] None.

#endif




