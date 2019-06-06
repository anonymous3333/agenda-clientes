#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  char nombre[50];
  char telefono[10];
  char direccion[100];
  char sexo;
  float estado_pagos;
  int activo;
}cliente;

int main(){
    char nombre_archivo[255];
    int Nclientes;
    int i;
    FILE *agenda;
    int tArchivo,nRegistros;
    int regMod;
    int opcion;

    printf("QUE DESEA HACER?:\n");
    printf("1) Modificar un registro existente\n");
    printf("2) Activar un registro existente\n");
    scanf("%d",&opcion);

    system("ls *.bin");
    printf("INGRESE EL NOMBRE DEL ARCHIVO:");
    scanf("%s",nombre_archivo);

    agenda=fopen(nombre_archivo,"r+b");

    fseek(agenda,0L,SEEK_END);
    tArchivo=ftell(agenda);
    nRegistros=tArchivo/sizeof(cliente);
    cliente agenda_leer[nRegistros];

    system("cls");
    printf("-----REGISTROS ACTUALES-----\n");
    rewind(agenda);
    for(i=0;i<nRegistros;i++){
        fread(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
            if(agenda_leer[i].activo>0)
                printf("%d) %s\n",i+1,agenda_leer[i].nombre);
            else
                printf("%d) %s (INACTIVO)\n",i+1,agenda_leer[i].nombre);
    }

    switch(opcion){

        case 1:

            printf("\nQUE REGISTRO DESEA MODIFICAR?>");
            scanf("%d",&regMod);
            regMod-=1;

            printf("NOMBRE>");
            fflush(stdin);
            gets(agenda_leer[regMod].nombre);
            printf("DIRECCION>");
            gets(agenda_leer[regMod].direccion);
            printf("TELEFONO>");
            scanf("%s",agenda_leer[regMod].telefono);
            fflush(stdin);
            printf("SEXO (M/F)>");
            agenda_leer[regMod].sexo=getchar();
            printf("ESTADO DE DE PAGO>");
            scanf("%f",&agenda_leer[regMod].estado_pagos);

            rewind(agenda);
            for(i=0;i<nRegistros;i++){
                fwrite(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
            }

            printf("\nREGISTRO MODIFICADO CON EXITO");
            break;
        case 2:
            printf("\nQUE REGISTRO DESEA ACTIVAR?>");
            scanf("%d",&regMod);
            regMod-=1;
            if(agenda_leer[i].activo<=0){
                agenda_leer[regMod].activo=1;
                printf("\nREGISTRO ACTIVADO CON EXITO");
            }
            else
                printf("ESE REGISTRO YA ESTA ACTIVO");

            break;

        default:
            printf("OPCION INVALIDA, SALIENDO...");
            break;
    }

    fclose(agenda);
    return 0;
}
