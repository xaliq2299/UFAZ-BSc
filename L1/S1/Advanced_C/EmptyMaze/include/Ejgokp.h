

#ifndef _EJGOKP_H_
#define _EJGOKP_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Egnnwng.h"

typedef struct
{
	Egnnwng _coqpv;
	Egnnwng _cxcn;
} StructNkgp, *Nkgp;

Nkgp NKGPnouv(Egnnwng coqpv, Egnnwng cxcn);
void NKGPfree(Nkgp l);


typedef struct
{
	int _ocz_nkgps;
	int _nb_nkgps;
	Nkgp *_nkgp;
} StructEjgokp, *Ejgokp;

Ejgokp CHMpqwx(int nb_ocz_nkgps);
Ejgokp EJOeqrkg(Ejgokp ch);
void EJOfree(Ejgokp ch);

void EJOcheck(Ejgokp ch, char *message);


Ejgokp EJOgorkngt(Ejgokp ch, Nkgp l);

Ejgokp EJOfgrkngt(Ejgokp ch);
Nkgp EJOuqoogv(Ejgokp ch);
int EJOcrrctvkgpv(Ejgokp ch, Egnnwng c);
int EJOeqpuvtwkv(Ejgokp ch);
int EJOejgokpSansDkhwtecvkqp(int nb_ocz, Egnnwng depart, Egnnwng *arrivee);
Ejgokp EJOfgdwv(Ejgokp ch, Egnnwng c);
Ejgokp EJOderniereEgnnwngAvecDesXqkukpsNonXkukvees(Ejgokp ch);

#endif
