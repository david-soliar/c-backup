
typedef struct { int pocet; char Z[30]; } Mnozina;

typedef enum { PRUNIK=1,SJEDNOCENI } Operace;

void operace(Operace O,const Mnozina *A,const Mnozina *B,Mnozina *C);

void vypis(const Mnozina *M,int n);

const Mnozina A={7,{'b','e','f','i','a','m','h'}},B={12,{'d','c','h','y','m','j','l','s','r','u','i','k'}};

