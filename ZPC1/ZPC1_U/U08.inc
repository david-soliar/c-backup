const Instr kresba[]={{2,{.y=0}},{1,{.x=0}},{3,{.znak='*'}},{4,{.delka=SLOUPCE-1}},{5,{.smer=1}},{4,{.delka=RADKY-1}},{5,{.smer=2}},
                      {4,{.delka=SLOUPCE-1}},{5,{.smer=-1}},{4,{.delka=RADKY-1}},{5,{.smer=-2}},
                      {2,{.y=8}},{1,{.x=12}},{3,{.znak='.'}},{4,{.delka=9}},{5,{.smer=1}},{4,{.delka=19}},{5,{.smer=2}},
                      {4,{.delka=9}},{5,{.smer=-1}},{4,{.delka=19}},{5,{.smer=-2}},
                      {2,{.y=4}},{1,{.x=8}},{3,{.znak='#'}},{4,{.delka=19}},{5,{.smer=1}},{4,{.delka=9}},{5,{.smer=2}},
                      {4,{.delka=19}},{5,{.smer=-1}},{4,{.delka=9}},{5,{.smer=-2}},
                      {2,{.y=5}},{1,{.x=40}},{3,{.znak='~'}},{4,{.delka=7}},{5,{.smer=1}},{4,{.delka=19}},{5,{.smer=2}},
                      {4,{.delka=7}},{5,{.smer=-1}},{4,{.delka=19}},{5,{.smer=-2}},
                      {2,{.y=10}},{1,{.x=35}},{3,{.znak='+'}},{4,{.delka=14}},{5,{.smer=1}},{4,{.delka=7}},{5,{.smer=2}},
                      {4,{.delka=14}},{5,{.smer=-1}},{4,{.delka=7}},{5,{.smer=-2}}};

#define KRESBA (sizeof kresba/sizeof *kresba)
