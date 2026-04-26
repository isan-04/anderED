#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrSig;
};

int menu(){
    int op;
    printf("\n Ingrese una opcion \n");
    printf("1: Crear datos\n");
    printf("2: Mostrar datos\n");
    printf("3: Liberar\n");
    printf("0: Salir\n");
    scanf("%d",&op);
    return op;
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

void mostrarDatos(struct Dato **ptr){
    struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
    }else{
        ptrAux = *ptr;
        while(ptrAux != NULL){
            printf("Dato: %d\n",ptrAux->d);
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

int main(){
    struct Dato *ptr=NULL, *ptrTemp=NULL, *ptrAux=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1: 
                /*if(ptr==NULL){
                        ptr=crear();
                    }else{
                        printf("El apuntador ya tiene un valor");
                    }*/
                ptrTemp=nuevoDato();
                if(ptrTemp==NULL){
                    printf("No se creo el nuevo nodo\n");
                }else{
                    if(ptr==NULL){
                        ptr=ptrTemp;
                    }else{
                        ptrAux=ptr;

                        while(ptrAux->ptrSig != NULL){
                            ptrAux = ptrAux->ptrSig;
                        }
                        ptrAux->ptrSig = ptrTemp;
                    }
                }
                break;

            case 2:
                mostrarDatos(&ptr);
                break;

            case 3:
                liberarDato(&ptr);
                break;

            case 0:
                printf("SALIENDO...\n");
                break;

        }
    }while(op!=0);
        return 0;
}  

