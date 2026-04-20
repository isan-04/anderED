#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


struct Alumno{
    char nombre[100];
    int calif[5][5];
};

int main(){
    struct Alumno A[100];  
    int N;

    srand(time(NULL));

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d",&N);
    getchar();


    for(int i = 0; i < N; i++){
        printf("Ingresar nombre del alumno %d: ", i+1);
        fgets(A[i].nombre, sizeof(A[i].nombre), stdin);

        A[i].nombre[strcspn(A[i].nombre, "\n")] = '\0';
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                A[i].calif[j][k] = rand()%5 + 6;
            }
        }
    }

    for(int i = 0; i < N; i++){
        printf("\nAlumno: %s\n", A[i].nombre);
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                printf("calificacion [%d][%d]: %d\n", j, k, A[i].calif[j][k]);
            }
        }
    }

    return 0;
}