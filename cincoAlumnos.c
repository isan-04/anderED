#include <stdio.h>
#include <time.h>
#include <string.h>

struct Alumno{
    char nombre[100];
    int calif[5][5];
};

int main(){
    struct Alumno A[5]; 

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        printf("Ingresar nombre del alumno %d: ", i+1);
        fgets(A[i].nombre, sizeof(A[i].nombre), stdin);
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                A[i].calif[j][k] = rand()%5 + 6;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        printf("\nAlumno: %s", A[i].nombre);
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                printf("calificacion [%d][%d]: %d\n", j, k, A[i].calif[j][k]);
            }
        }
    }

    return 0;
}