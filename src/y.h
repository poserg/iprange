#include "main.h"

extern int yylex (void);
extern void decToBin (int*, bool*);
extern void binToDec (bool*, int*);
extern int Sorted (unsigned*, unsigned*);

extern void AddAddress ( unsigned*, unsigned*, int* );
extern unsigned transform (int*);
extern void untransform (unsigned* , int*);
extern int pow (int, int);
extern int find (unsigned*);
