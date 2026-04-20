#include<stdio.h>
#include<math.h>
#include<time.h>

struct Punto{
    int x,y;
};

void guardar(struct Punto *p){
    for(int i=0;i<5;i++){
        (*(p+i)).x=rand()%11;
        (*(p+i)).y=rand()%11;
    }
}

void mostrar(struct Punto *p){
    for(int i=0;i<5;i++){
        printf("Punto %d: (%d,%d\n)",i,(*(p+i)).x,(*(p+i)).y);
    }
}

void distancia(){
    int rx,ry,px,py,sum;
    float d;

     for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            rx=(*(p+i)).x-(*(p+j)).x;
            ry=(*(p+i)).y-(*(p+j)).y;

            px=pow(rx,2);
            py=pow(ry,2);
            sum=px+py;
            d=sqrt(sum);

            printf("(%d,%d) con (%d,%d): %f\n",(*(p+i)).x,(*(p+j)).x,(*(p+i)).y,(*(p+j)).y,d);
        }
    }

}

int main(){

    struct Punto punto[5];

    srand(time(NULL));

    guardar(punto);

    printf("Puntos:\n");
    mostrar(punto);

    printf("\nDistancia:\n");
    distancia(punto);

   

    return 0;

}