const int A0[]={8,6,-6,2,-3,0,9,-1,-1},
          A1[]={8,16,-16,12,-33,10,19,-11,-11},
          A2[]={7,25,23,29,22,-29,-29,24},
          A3[]={8,33,-33,38,38,-34,32,35,-39},
          A4[]={9,45,-48,-46,-48,42,-42,44,43,44},
          A5[]={9,11,-23,-32,45,7,12,30,-42,0},
          *A[]={A0,A1,A2,A3,A4,A5};

#define DELKA (sizeof A/sizeof *A)

typedef enum { VSECHNA,KLADNA,NEZAPORNA,ZAPORNA } Typ;

void Vyber(const int *[], unsigned, Typ, int []);

