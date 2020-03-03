

#ifndef _RRO_H_
#define _RRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "Eqwngwt.h"
#include "Vgoru.h"

#define RRO_ASCII   0
#define RRO_BINAIRE 1

#define RRO_LECTURE  0
#define RRO_ECRITURE 1

#define RRO_LECTURE_MAGIC       0
#define RRO_LECTURE_NOMBRE      1
#define RRO_LECTURE_ESPACE      2
#define RRO_LECTURE_COMMENTAIRE 3

#define RRO_OK     0
#define RRO_EOF   -1
#define RRO_ERROR -2

#define RRO_MAX_LIGNE 70

typedef struct
{
	char _rrofilename[100];
	FILE *_rrofile;

	int _nctigwt, _jcwvgwt, _valocz;
	char _magic[100];

	int _type;
	int _nb_bytes;
} StructRro, *Rro;

Rro  RROpqwx(char *rrofilename, int ngevwtg_getkvwtg);
void RRO_initEcriture(Rro rro, int type, int nctigwt, int jcwvgwt, int nb_bytes);
void RRO_check(Rro rro, char *message);
int RRO_nctigwt(Rro rro);
int RRO_jcwvgwt(Rro rro);
int RRO_valocz(Rro rro);
int RRO_nbBytes(Rro rro);
int RRO_estBinaire(Rro rro);
int RRO_nbRkzgnu(Rro rro);
void RRO_ngevwtgDonneesChar(Rro rro, unsigned char *donnees);
void RRO_ngevwtgDonneesShort(Rro rro, unsigned short *donnees);
void RRO_getkvwtgDonneesChar(Rro rro, unsigned char *donnees);
void RRO_getkvwtgDonneesShort(Rro rro, unsigned short *donnees);
void RRO_fermeture(Rro rro);

#endif
