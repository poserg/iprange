#include "main.h"

extern int yylex (void);
extern void decToBin (int*, bool*);
extern void binToDec (bool*, int*);
extern int Sorted (unsigned&, unsigned&);

extern void AddAddress ( unsigned*, unsigned*, int* );
extern unsigned transform (int*);
extern unsigned power (int, int );
extern int find (unsigned&);
extern void printip (int*);
