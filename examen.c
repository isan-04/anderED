#include <stdio.h>

int main(){
    int a,b;
    int *ptr1=NULL;
    int *ptr2=NULL;
    int **pptr=NULL;
    int A[5]={1,2,3,4,5};

    ptr1=&a;
    ptr2=&b;
    //ptr1=5;
    printf("%p\n", ptr1);

    *ptr2=5;
    *ptr1=*ptr2;
    printf("%d\n", a);
    printf("%d\n", b);

    //pptr=ptr1;
    //pptr=&b;
    pptr=&ptr2;
    **pptr+=5;
    printf("%p\n", pptr);
    printf("%p\n", *pptr);
    printf("%d\n", **pptr);

    *pptr=ptr1;
    **pptr+=10;
    printf("%d\n", a);
    printf("%d\n", b);

    *pptr=ptr2;
    ptr2=&a;
    printf("%d\n", *ptr1);
    printf("%d\n", *ptr2+4);

    a=2;
    b=*ptr2+3;
    printf("%p\n", *pptr);
    printf("%d\n", **pptr);
    printf("%p\n", ptr1);
    printf("%p\n", ptr2);

    **pptr+=1;
    printf("%d\n", *ptr1);
    printf("%d\n", *ptr2);

    a=8;
    b=6;
    pptr=&ptr1;
    **pptr-=3;
    printf("%p\n", pptr);
    printf("%d\n", *ptr1);
    printf("%d\n", *ptr2);
    printf("%d\n", b);
    printf("%d\n", a);
    printf("%d\n", **pptr);

    ptr1=A;
    pptr=&ptr1;
    printf("%d\n", *(*pptr+3));
    printf("%d\n", *ptr1);
    printf("%p\n", (ptr1+3));

    for(int i=0; i<5; i++){
        *(*pptr+i)=*(*pptr+i)+1;
    }
    printf("%d\n", *(ptr1+1));
    printf("%d\n", *(*pptr+2));
    printf("%p\n", (*pptr+2));
    printf("%p\n", (ptr1+4));

    return 0;
}
