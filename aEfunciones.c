#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

int menu(){
    int op;
    printf("\n----MENU PRINCIPAL----\n");
    printf("Ingrese una opcion \n");
    printf("1: Crear datos\n");
    printf("2: Funciones\n");
    printf("3: Mostrar datos\n");
    printf("4: Liberar\n");
    printf("0: Salir\n");
    scanf("%d",&op);
    return op;
}

int menuFunciones(){
    int op2;
    printf("\n----MENU FUNCIONES----\n");
    printf("Ingrese una opcion \n");
    printf("1.-Buscar\n");
    printf("2.-Contar\n");
    printf("3.-Remplazar\n");
    printf("3.-Ordenar\n");
    printf("0: Regresar al menu principal\n");
    scanf("%d",&op2);
    return op2;
}

struct Dato *nuevoDato(void){
   struct Dato *ptrTemp=NULL;
    int dato;
    ptrTemp = (struct Dato *) malloc(sizeof(struct Dato));

    if(ptrTemp==NULL){
        printf("No se reservo memoria\n");
        return NULL;
    }else{
        printf("Ingrese el dato: ");
        scanf("%d", &dato);
        ptrTemp->d=dato;
        ptrTemp->ptrSig=NULL;
        return ptrTemp;
    }
}

void insertar(struct Dato **ptr){
    struct Dato *ptrTemp;
    struct Dato *ptrAux;

    ptrTemp=nuevoDato();
    if(ptrTemp==NULL){
        printf("No se creo el nuevo nodo\n");
    }else{
        if(*ptr==NULL){
            *ptr=ptrTemp;
        }else{
                ptrAux=*ptr;

                while(ptrAux->ptrSig != NULL){
                ptrAux = ptrAux->ptrSig;
                }
                ptrAux->ptrSig = ptrTemp;
            }
        }

}

void mostrarDatos(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
    }else{
        ptrAux = *ptr;
        while(ptrAux != NULL){
            printf(" %d -> ",ptrAux->d);
            ptrAux = ptrAux->ptrSig;
        }
    }
}

void liberarDato(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
        return;
    }

    if((*ptr)->ptrSig == NULL){
        free(*ptr);
        *ptr = NULL;
    }else{
        ptrAux = *ptr;

        while(ptrAux->ptrSig->ptrSig != NULL){
            ptrAux = ptrAux->ptrSig;
        }

        free(ptrAux->ptrSig);
        ptrAux->ptrSig = NULL;
    }
    printf("Nodo eliminado\n");
    
}

void eliminarTodos(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
        return;
      }

    if((*ptr)->ptrSig == NULL){
        free(*ptr);
        *ptr = NULL;
    }else{

        while(*ptr != NULL){
            ptrAux = *ptr;
            *ptr=(*ptr)->ptrSig;
            free(ptrAux);
        }
    }
    *ptr= NULL;
    printf("Nodos eliminados\n");

}

void contar(struct Dato *ptr) {
    struct Dato *ptrAux;
    int cont = 0;

    if (ptr == NULL) {
        printf("No hay nodos\n");
    } else {
        ptrAux = ptr;
        while (ptrAux != NULL) {
            printf(" %d -> ", ptrAux->d);
            cont++;
            ptrAux = ptrAux->ptrSig;
        }
        printf("\nTotal de nodos: %d\n", cont);
    }
}

int buscar(struct Dato *ptr, int busc) {
    struct Dato *ptrAux;
    int b = 0;

    if (ptr == NULL) {
        printf("No hay nodos\n");
    } else {
        ptrAux = ptr;
        while (ptrAux != NULL) {
            if (ptrAux->d == busc) {
                b++;
            }
            ptrAux = ptrAux->ptrSig;
        }
    }

    return b;
}

void remplazar(struct Dato *ptr) {
    int datoViejo, datoNuevo,total=0;
    int opcion, posicion;
    int contador = 0;
    struct Dato *ptrAux;

    if (ptr == NULL) {
        printf("No hay nodos\n");
        return;
    }

    printf("Ingrese el dato a reemplazar: ");
    scanf("%d", &datoViejo);

    total = buscar(ptr, datoViejo);
    if (total == 0) {
        printf("El dato no existe\n");
        return;
    }

    printf("Ingrese el nuevo dato: ");
    scanf("%d", &datoNuevo);

    printf("Desea reemplazar:\n");
    printf("1) Todas las coincidencias\n");
    printf("2) Solo una posicion especifica\n");
    scanf("%d", &opcion);

    ptrAux = ptr;

    if (opcion == 1) {
        while (ptrAux != NULL) {
            if (ptrAux->d == datoViejo) {
                ptrAux->d = datoNuevo;
            }
            ptrAux = ptrAux->ptrSig;
        }
        printf("Se reemplazaron todas las coincidencias\n");

    } else if (opcion == 2) {
        printf("Hay %d coincidencias cual desea reemplazar (1,2,3...)? ", total);
        scanf("%d", &posicion);

        if (posicion < 1 || posicion > total) {
            printf("Posicion invalida\n");
            return;
        }

        while (ptrAux != NULL) {
            if (ptrAux->d == datoViejo) {
                contador++;
                if (contador == posicion) {
                    ptrAux->d = datoNuevo;
                    printf("posicion %d reemplazada\n", posicion);
                    return;
                }
            }
            ptrAux = ptrAux->ptrSig;
        }

    } else {
        printf("Opcion invalida\n");
    }
}

int main(){
    struct Dato *ptr=NULL, *ptrTemp=NULL, *ptrAux=NULL;
    int op,valor,veces,busc,op2=0;

    do{
        op=menu();
        switch(op){
            case 1:
                insertar(&ptr);
                break;

            case 2:
                do{
                    op2=menuFunciones();

                    switch(op2){
                        case 1: 
                            printf("Ingrese el dato que desea buscar: ");
                            scanf("%d", &busc);

                            veces = buscar(ptr, busc);
                            if (veces != 0) {
                                printf("El dato %d existe %d veces\n",busc, veces);
                            } else {
                                printf("El dato no existe\n");
                            }
                            break;

                         case 2: 
                            contar(ptr);
                            break;

                        case 3:
                            remplazar(ptr);
                            break;

                        case 0:
                            printf("Regresando al menu principal...\n");
                            break;

                        default:
                            printf("Opcion invalida\n");
                            break;
                    }

                }while(op2 != 0);
        
                break;

            case 3:
                mostrarDatos(&ptr);
                break;

            case 4:
                liberarDato(&ptr);
                break;

            case 0:
                eliminarTodos(&ptr);
                printf("SALIENDO...\n");
                break;

            default:
                printf("Opcion invalida\n");
                break;

        }
    }while(op!=0);
        return 0;
}  

