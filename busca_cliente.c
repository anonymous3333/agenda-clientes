#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendas.h"

typedef struct{
  char nombre[50];
  char telefono[10];
  char direccion[100];
  char sexo;
  float estado_pagos;
  int activo;
}cliente;

void buscar_clientes(char *nombre_archivo){
    int i;
    FILE *agenda;
    int tArchivo,nRegistros;
    char telBuscar[10];
    int iguales;
    int incidencias=0;

//    system("ls *.bin");
//    printf("\nINGRESE EL NOMBRE DEL ARCHIVO>");
//    gets(nombre_archivo);

    agenda=fopen(nombre_archivo,"rb");
    if(agenda==NULL){
        printf("EL ARCHIVO NO EXISTE, SALIENDO...");
        exit(1);
    }
    else{
        printf("INGRESE EL TELEFONO A BUSCAR>");
        scanf("%s",telBuscar);

        fseek(agenda,0L,SEEK_END);
        tArchivo=ftell(agenda);
        nRegistros=tArchivo/sizeof(cliente);

        cliente agenda_leer[nRegistros];

        rewind(agenda);
        for(i=0;i<nRegistros;i++){
            fread(&agenda_leer[i],sizeof(agenda_leer[i]),1,agenda);
            iguales=strcmp(telBuscar,agenda_leer[i].telefono);
            if(iguales==0 && agenda_leer[i].activo>0){
                printf("NOMBRE: %s\n",agenda_leer[i].nombre);
                printf("DIRECCION: %s\n",agenda_leer[i].direccion);
                printf("TELEFONO: %s\n",agenda_leer[i].telefono);
                printf("SEXO: %c\n",agenda_leer[i].sexo);
                printf("ESTADO DE DE PAGO: %.2f\n",agenda_leer[i].estado_pagos);
                puts("--------------------------------------------------------");
                incidencias++;
            }
        }

        if(incidencias==0){
            printf("No hay clientes registrados con ese numero de telefono\n");
        }

        fclose(agenda);
    }
}
