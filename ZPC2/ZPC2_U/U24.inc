
typedef struct { char den,mesic; short rok; } Datum;

Datum D[]={{1,10,2012},{15,11,1990},{26,5,1982},{22,1,2010},{12,1,2019},
 {12,11,2005},{31,12,1999},{3,10,2012},{12,4,1999},{8,8,2017},{31,10,2010},
 {30,9,2014},{1,11,2019},{21,9,1954},{10,7,2002},{10,2,2017},{8,12,2014},{5,11,2009},
 {26,9,1960},{19,11,1958},{1,5,2000},{23,3,2003},{17,9,2016}};

#define POCET (sizeof D/sizeof *D)

void Tridit(Datum [],int,char (*)(Datum,Datum));

char Vetsi(Datum,Datum); 

char Mensi(Datum,Datum);

void Vypsat(const Datum [],int);

