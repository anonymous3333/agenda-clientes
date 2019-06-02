#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nombre[50];
  char direccion[100];
  unsigned int telefono;
  char sexo;
  float estado_pagos;
}cliente;

int main(int argc, char const *argv[]) {
  char cont; //BANDERA DE CONTINUACIÓN DEL PROGRAMA
  int opcion;
  printf("-----INGRESE UNA OPCION-----\n", );
  printf("1) Agregar un cliente\n", );
  printf("2) Ver datos de los clientes\n", );
  scanf("%d",&opcion);


  return 0;
}
