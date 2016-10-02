#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen2(char *s) {
    int ret = 0;
    while (*s) {
        ret++;
        s++;
    }
    return ret;
}

char * strcpy2(char dst[], char *src) {//sigh when c doesn't know the sizeof the array from its pointer ;-;
    //if (sizeof(dst) > strlen2(src)) {
        int index = 0;
        int len = strlen2(src);
        while (index < len + 1) {
            dst[index] = src[index];
            index++;
        }
    //}
    return dst;
}

char * strncat2(char *dst, char *src, int n) {
    //if (sizeof(dst) <= strlen2(src) + n) {
        int indexD = strlen2(dst);
        int indexS = 0;
        while (indexS < n) {
            dst[indexD] = src[indexS];
            indexD++;
            indexS++;
        }
        dst[indexD] = '\0';
    //}
    return dst;
}

int strcmp2(char *tim, char *tom) {
    int tum = 0, TIM = strlen2(tim), TOM = strlen2(tom);
    while (tim[tum] == tom[tum] && tum < TIM && tum < TOM) {
        tum++;
    }
    if (tim[tum] == tom[tum]) {
        return 0;
    }
    else {
        if (tim[tum] > tom[tum]) {
            return 1;
        }
        else return -1;
    }
}

char * strchr2(char *dst, char src, int n) {
    if (n > 0) {
        int len = strlen2(dst), dex = 0;
        while ( (*dst != src || n > 1) && dex < len) {
            if (*dst == src) {
                n--;
            }
            dex++;
            dst++;
        }
        if (dex == len) {
            return NULL;
        }
        else return dst;
    }
    else return NULL;
}

int main() {
    char str1[50] = "coffee";
    char str2[50] = "medium mocha frappe";
    printf("[Strings: \"coffee\", \"medium mocha frappe\", and \"bron\"]\n\n");
    
    printf("TESTING strlen:\n");
    printf("strlen(%s): %d\nstrlen(%s): %d\n\n",str1,strlen2(str1),str2,strlen2(str2));

    printf("TESTING strcpy:\n");
    char str3[50];
    strcpy(str3,"coffee");
    printf("str3 = \"%s\"\n",str3);
    printf("strcpy(%s, %s)\n",str1,str2);
    strcpy2(str3,str2);
    printf("str3: \"%s\"\n\n",str3);

    printf("TESTING strncat:\n");
    strcpy2(str3,"bron");
    printf("str3 = \"%s\"\n",str3);
    printf("strncat(\"%s\", \"%s\", 2) --> ",str3,str1);
    strncat2(str3,str1,2);
    printf("\"%s\"\n\n",str3);

    printf("TESTING strcmp:\n");
    printf("strcmp(\"%s\", \"%s\") --> %d\n",str1,str3,strcmp2(str1,str3));
    printf("strcmp(\"%s\", \"%s\") --> %d\n",str1,str2,strcmp2(str1,str2));
    printf("strcmp(\"%s\", \"%s\") --> %d\n\n",str1,"coffee",strcmp2(str1,"coffee"));
    
    printf("TESTING strchr:\n");
    char *one = str1;
    printf("       pointer: character \n%p: %c\n",one++,*one);
    printf("%p: %c\n",one++,*one);
    printf("%p: %c\n",one++,*one);
    printf("%p: %c\n",one++,*one);
    printf("%p: %c\n",one++,*one);
    printf("%p: %c\n",one++,*one);
    printf("%p: %c\n\n",one++,*one);
    printf("strchr(%s,%c) --> %p\n",str1,'c',strchr2(str1,'c',1));
    printf("strchr(%s,%c) --> %p\n",str1,'o',strchr2(str1,'o',1));
    printf("strchr(%s,%c) --> %p\n",str1,'f',strchr2(str1,'f',1));
    printf("strchr(%s,%c) --> %p\n",str1,'f',strchr2(str1,'f',2));
    printf("strchr(%s,%c) --> %p\n",str1,'e',strchr2(str1,'e',1));
    printf("strchr(%s,%c) --> %p\n",str1,'e',strchr2(str1,'e',2));
    printf("strchr(%s,%c) --> %p //Oh wells\n",str1,'\0',strchr2(str1,'\0',1)); 

    return 0;
}