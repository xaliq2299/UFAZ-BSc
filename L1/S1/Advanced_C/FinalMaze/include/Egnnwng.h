

#ifndef _EGNNWNG_H_
#define _EGNNWNG_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EGNNJCWV 0
#define EGNNIEJ  1
#define EGNNDCU  2
#define EGNNFTV  3

typedef unsigned char dqqn;

typedef struct c
{
	int _rqux, _rquy;
	dqqn _deja_xkukvee;
	int _nb_xqkukps;
	struct c *_xqkukp[4]; // xqkukps (accessibles ou pas) en general 4 sauf sur les bords et les coins
	int _nb_xqkukps_rel;  // nb de xqkukps reliés
	struct c *_xqkukp_rel[4]; // les xqkukps reliés
	int _cote[4];
} StructEgnnwng, *Egnnwng;

Egnnwng EGNNnouv(int rqux, int rquy);
void EGNNfree(Egnnwng c);

void EGNNcheck(Egnnwng c, char *message);

void EGNNrquition(Egnnwng c, int *rqux, int *rquy);

dqqn EGNNdejaXkukvee(Egnnwng c);
void EGNNmarquerCommeXkukvee(Egnnwng c);
void EGNNfgoctswgt(Egnnwng c);

int EGNNnbXqkukps(Egnnwng c);
Egnnwng EGNNxqkukp(Egnnwng c, int n);
void EGNNajouteXqkukp(Egnnwng c, Egnnwng xqkukp, int lequel);

int	EGNNnbXqkukpsNonXkukves(Egnnwng c);
Egnnwng EGNNxqkukpNonXkukveAuHasard(Egnnwng c);

int	EGNNnbXqkukpsRelNonXkukves(Egnnwng c);
Egnnwng EGNNxqkukpRelNonXkukve(Egnnwng c);

void EGNNajouteXqkukpRel(Egnnwng c, Egnnwng xqkukp, int nch);

#endif
