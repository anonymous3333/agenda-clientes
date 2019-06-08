#include <stdio.h>
#include <stdlib.h>
#include "agendas.h"

typedef struct{
  char nombre[50];
  char telefono[10];
  char direccion[100];
  char sexo;
  float estado_pagos;
  int activo;
}cliente;

void ver_clientes(char *nombre_archivo){
    int i;
    FILE *agenda;
    int tArchivo,nRegistros;

//    system("ls *.bin");
//    printf("INGRESE EL NOMBRE DEL ARCHIVO:");
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
        rewind(agenda);
        for(i=0;i<nRegistros;i++){
            fread(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
            if(agenda_leer[i].activo>0){
                printf("NOMBRE: %s\n",agenda_leer[i].nombre);
                printf("DIRECCION: %s\n",agenda_leer[i].direccion);
                printf("TELEFONO: %s\n",agenda_leer[i].telefono);
                printf("SEXO: %c\n",agenda_leer[i].sexo);
                printf("ESTADO DE DE PAGO: %.2f\n",agenda_leer[i].estado_pagos);
                puts("--------------------------------------------------------");
            }
        }
        fclose(agenda);
    }
}
