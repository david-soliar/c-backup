#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "U29.inc"

#define IN_RANGE(c, lower, upper) ((c-48 >= lower) && (c-48 <= upper))

int h(char *s){
    if (strlen(s)==1){
        if (IN_RANGE(s[0], 0, 9)){
            return 1;
        }
        return 3;
    }
    if (strlen(s)==2){
        if ((s[0]-48==1 && IN_RANGE(s[1], 0, 9)) || (s[0]-48==2 && IN_RANGE(s[1], 0, 3))){
            return 1;
        }
        if ((s[0]-48==2 && IN_RANGE(s[1], 4, 9)) || (s[0]-48!=1 && IN_RANGE(s[1], 0, 9))){
            return 2;
        }
        return 3;
    }
    return 3;
}

int hh(char *s){
    if (strlen(s)==1){
        if (IN_RANGE(s[0], 0, 9)){
            return 1;
        }
        return 3;
    }
    if (strlen(s)==2){
        if ((IN_RANGE(s[0], 0, 1) && IN_RANGE(s[1], 0, 9)) || (s[0]-48==2 && IN_RANGE(s[1], 0, 3))){
            return 1;
        }
        if ((s[0]-48==2 && IN_RANGE(s[1], 4, 9)) || (s[0]-48!=1 && IN_RANGE(s[0], 0, 9))){
            return 2;
        }
        return 3;
    }
    return 3;
}

int mm_ss(char *s){
    if (IN_RANGE(s[0], 0, 5) && IN_RANGE(s[1], 0, 9)){
        return 1;
    }
    if (IN_RANGE(s[0], 6, 9) && IN_RANGE(s[1], 0, 9)){
        return 2;
    }
    if (s[0]=='.' || s[1]=='.'){
        return 3;
    }
    if (s[0]==':' || s[1]==':'){
        return 3;
    }
    if (IN_RANGE(s[0], 0, 9) || IN_RANGE(s[1], 0, 9)){
        return 2;
    }
    return 3;
}

char* check_format(char *time, int n, char deli){
    int res;
    char c[3];

    for (int i = 0; i < n; i++){
        c[i] = time[i];
    }
    c[n] = 0;

    res = (deli=='.') ? h(c) : hh(c);
    switch (res){
        case 2:
            return "zle hodnoty";
        case 3:
            return "zly format";
        default:
            break;;
    }

    if (time[n]!=deli){ return (IN_RANGE(time[n], 0, 9)) ? "zle hodnoty" : "zly format"; }

    c[0] = time[n+1];
    c[1] = time[n+2];
    c[2] = 0;

    if (c[0]==0 || c[1]==0){ return "zle hodnoty"; }

    switch (mm_ss(c)){
        case 2:
            return "zle hodnoty";
        case 3:
            return "zly format";
        default:
            break;
    }

    if (time[n+3]==0){ return NULL; }
    
    if (time[n+3]!=deli){ return (IN_RANGE(time[n+3], 0, 9)) ? "zle hodnoty" : "zly format"; }

    c[0] = time[n+4];
    c[1] = time[n+5];
    c[2] = 0;

    if (c[0]==0 || c[1]==0){ return "zle hodnoty"; }
    
    switch (mm_ss(c)){
        case 2:
            return "zle hodnoty";
        case 3:
            return "zly format";
        default:
            break;
    }
        
    if (time[n+6]==0){
        return NULL;
    }

    if (deli=='.'){
        return "zly format";
    }

    if (time[n+6]!=',' && time[n+6]!='.'){
        return "zly format";
    }

    int x = n+7;
    if (time[x]==0){ return "zly format"; }
    
    while (time[x]!=0){
        if (0>time[x]-48 || time[x]-48>9){
            return "zly format";
        }
        x++;
    }
    return NULL;
}

char* is_valid(char *time) {
    if (strcmp(time, "00:00")==0 || strcmp(time, "24:00")==0){
        return NULL;
    }

    if (strlen(time)<=2){
        if (time[0]==0){
            return "zly format";
        }
        switch (h(time)){
            case 1:
                return NULL;
            case 2:
                return "zle hodnoty";
            case 3:
            default:
                return "zly format";
        }
    }

    if (time[1]=='.' || time[1]==':') {
        return check_format(time, 1, time[1]);
    }

    if (time[2]=='.' || time[2]==':') {
        return check_format(time, 2, time[2]);
    }

    return (IN_RANGE(time[2], 0, 9)) ? "zle hodnoty" : "zly format";
}

void main(){
    char c[100];
    char *m;

    for (int i = 0; i < 58; i++){
        memcpy(c, cas[i], strlen(cas[i])+1);
        
        m = is_valid(c);
        if (m==NULL){
            printf("%-25s %15s\n", cas[i], "dobre");
        }
        else {
            printf("%-25s %15s\n", cas[i], m);
        }
        printf("\n");
    }
    return;
}

