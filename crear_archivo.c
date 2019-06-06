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

    printf("INGRESE UN NOMBRE PARA EL ARCHIVO:");
    scanf("%s",nombre_archivo);
    strcat(nombre_archivo,".bin");
    FILE *agenda;
    agenda=fopen(nombre_archivo,"wb");
    fclose(agenda);
    return 0;
}
