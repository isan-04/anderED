//Examen Luis Ander Mejia Vazquez
#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int n;
    struct Dato *ptrSig;
    struct Dato *ptrAnt;
};

int menu(){
    int op;
    printf("\n Ingrese una opcion \n");
    printf("1: Insertar\n");
    printf("2: Mostrar\n");
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
        ptrTemp->n=dato;
        ptrTemp->ptrSig=NULL;
        ptrTemp->ptrAnt=NULL;
        return ptrTemp;
    }
}

void eliminar(struct Dato **ptr){
     struct Dato *ptrAux;

    if(*ptr == NULL){
        printf("No hay nodos\n");
        return;
      }

     if((*ptr)->ptrSig == *ptr){
        free(*ptr);
        *ptr = NULL;
        }else{

            (*ptr)->ptrAnt->ptrSig=NULL;
            
             while(*ptr != NULL){
                ptrAux = *ptr;
                *ptr=(*ptr)->ptrSig;
                free(ptrAux);
        }

        }
         *ptr= NULL;
    printf("Nodos eliminados\n");
                
}

int main(){
    struct Dato *ptr=NULL, *ptrNew=NULL, *ptrUlt=NULL,*ptrTemp=NULL, *ptrAux=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1:
                ptrNew=nuevoDato();
                if(ptrNew==NULL){
                    printf("No se creo el nuevo nodo\n");
                }else{
                    if(ptr==NULL){
                        ptr=ptrNew;
                        ptr->ptrSig=ptr;
                        ptr->ptrAnt=ptr;
                    }else{
                        ptrUlt = ptr->ptrAnt;

                        ptrNew->ptrSig = ptr;
                        ptrNew->ptrAnt = ptrUlt;

                        ptrUlt->ptrSig = ptrNew;
                        ptr->ptrAnt = ptrNew;
                    }
                }
                break;

            case 2:
                if(ptr == NULL){
                    printf("No hay nodos\n");
                }else{
                    ptrAux = ptr;

                    do{
                        printf("%d <-> ", ptrAux->n);
                        ptrAux = ptrAux->ptrSig;
                    }while(ptrAux != ptr);

                    printf("(inicio)\n");
                }
                break;

            case 3:
                if(ptr == NULL){
                    printf("No hay nodos\n");
                    break;
                }

                if((ptr)->ptrSig == ptr){
                    free(ptr);
                    ptr = NULL;
                }else{
                    ptrAux = ptr;

                    while(ptrAux->ptrSig->ptrSig != ptr){
                        ptrAux = ptrAux->ptrSig;
                    }

                    ptrTemp = ptrAux->ptrSig;

                    ptrAux->ptrSig = ptr;
                    ptr->ptrAnt = ptrAux;

                    free(ptrTemp);
                }
                printf("Nodo eliminado\n");
                
                break;

            case 0:
                eliminar(&ptr);
                printf("SALIENDO...\n");
                break;

            default:
                printf("Opcion invalida\n");

        }
    }while(op!=0);
        return 0;
}  