/* syntorxgen.h, Boone, 06/30/02
   Global definitions for syntorxgen
   Copyright (C) 2002, Dennis Boone, East Lansing, MI */

/* Modifications:
   06/30/02 Boone      Initial coding
   End Modifications */

#ifdef INSTANTIATE
#define EXTERN
#else
#define EXTERN extern
#endif

#define MAXMODES 256
#define YYERROR_VERBOSE 1

#define MAXSTR 256

#define MODEBITSIZE 16

#define HEX 1
#define SRECORD 2

/* Guesses as to the upper frequency limits various models of Syntor could
   be hacked to do; used to decide for which band of radio this mode def is
   targeted.  This is primitive; turning a high-band rig into a 220 rig
   might require changing things around from high- to low-side injection
   for example; the program isn't that smart.  The main hope is that these
   are wide enough for normal use, without overlapping. */

#define MAXLOWBAND 100.0L
#define MAXHIGHBAND 250.0L
#define MAXUHFBAND 550.0L
#define MAX800BAND 950.0L

/* UHF Range 1 radios use high-side injection, all others low-side, so
   we need to be able to tell the difference.  This definition assumes
   that anyone programming an R1 frequency will be using an unmodified
   radio in a factory-approved way. */

#define MAXUHFR1BAND 420.0L

typedef struct
{
	int defined;
	int scanlistsize;
	int npscanlist[MAXMODES];
	int txdplflag;
	int txdpl;
	int txdplinv;
	int txplflag;
	double txpl;
	int txmpl;
	int rxdplflag;
	int rxdpl;
	int rxdplinv;
	int rxplflag;
	double rxpl;
	int rxmpl;
	int timeout;
	int txpower;
	int refreq;
	int scantype;
	int tbscan;
	int p2scanmode;
	int npscansource;
	int squelchtype;
	int p1scanmode;
	double txfreq;
	double rxfreq;
} Modestruct;

EXTERN double greffreq;
EXTERN double gsplitfreq;
EXTERN Modestruct gmodedef[MAXMODES];
EXTERN Modestruct gscratchmodedef;
EXTERN int gscratchlist[MAXMODES];
EXTERN int gscratchlistsize;
EXTERN int glineno;
EXTERN int gnmodes;
EXTERN int gdebug;

