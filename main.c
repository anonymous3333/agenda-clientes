#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendas.h"

int main()
{
    int op1,op2;    //OPCIONES PARA LOS MENÚS
    char cont='s',cont2='s';
    char nombre_archivo[255];

    while(cont=='S' || cont=='s'){
        system("cls");
        printf("-----QUE OPERACION DESEA REALIZAR?-----\n");
        printf("1) Crear una agenda nueva\n");
        printf("2) Trabajar con una agenda existente\n");
        printf("3) Salir\n");
        printf("INGRESE OPCION>");
        scanf("%d",&op1);

        //PRIMER MENÚ
        switch(op1){

        case 1:
            printf("INGRESE UN NOMBRE PARA EL ARCHIVO:");
            scanf("%s",nombre_archivo);
            strcat(nombre_archivo,".bin");
            crear_archivo(nombre_archivo);
            fflush(stdin);
            printf("DESEA CONTINUAR? (S/N)>");
            scanf("%c",&cont);
            break;

        case 2:
            break;

        case 3:
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("\nOPCION INVALIDA, SALIENDO...\n");
            system("pause");
            exit(EXIT_FAILURE);
            break;

        }
    }
    return 0;
}
