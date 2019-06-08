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

void borrar_cliente(char *nombre_archivo){
    int i;
    FILE *agenda;
    int tArchivo,nRegistros;
    int regMod;

//    system("ls *.bin");
//    printf("INTRODUCE EL NOMBRE DEL ARCHIVO:");
//    scanf("%s",nombre_archivo);

    agenda=fopen(nombre_archivo,"rb");
    if(agenda==NULL){
        printf("EL ARCHIVO NO EXISTE, SALIENDO...");
        exit(1);
    }
    else{
        fseek(agenda,0L,SEEK_END);
        tArchivo=ftell(agenda);
        nRegistros=tArchivo/sizeof(cliente);
        cliente agenda_leer[nRegistros];

        system("cls");
        printf("-----REGISTROS ACTUALES-----\n");
        rewind(agenda);
        for(i=0;i<nRegistros;i++){
            fread(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
            if(agenda_leer[i].activo>0){
                printf("%d) %s\n",i+1,agenda_leer[i].nombre);
            }
        }

        printf("\nQUE REGISTRO DESEA BORRAR?>");
        scanf("%d",&regMod);
        regMod-=1;

        agenda_leer[regMod].activo=0;
        freopen(nombre_archivo,"wb",agenda);
        rewind(agenda);
        for(i=0;i<nRegistros;i++){
            fwrite(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
        }

        fclose(agenda);
    }
}
