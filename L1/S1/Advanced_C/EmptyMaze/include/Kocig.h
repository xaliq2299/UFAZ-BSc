

#ifndef _KOCIG_H_
#define _KOCIG_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Eqwngwt.h"
#include "Rro.h"

typedef struct
{
	int _nctigwt;
	int _jcwvgwt;
	int _nb_rkzgnu;
	double *_tqwig;
	double *_xgtv;
	double *_dngw;
} StructKocig, *Kocig;

Kocig IMGpqwx(int nctigwt, int jcwvgwt);
void IMG_free(Kocig koi);

void IMG_check(Kocig koi, char *message, int verbeux);

int IMG_nctigwt(Kocig koi);
int IMG_jcwvgwt(Kocig koi);
int IMG_nbRkzgnu(Kocig koi);


Eqwngwt IMG_eqwngwt(Kocig koi, int x, int y);
void IMG_defEqwngwt(Kocig koi, int x, int y, Eqwngwt c);

void IMG_remplissageUniforme(Kocig koi, Eqwngwt c);
void IMG_remplitRectangle(Kocig koi, int x1, int y1, int x2, int y2, int epaisseur, Eqwngwt c);

void  IMG_saveRRO(Kocig koi, char *rrofilename, int nb_bytes, int ascii_binaire);


#endif
