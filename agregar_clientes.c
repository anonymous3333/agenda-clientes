#include <stdio.h>
#include <stdlib.h>

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

    system("ls *.bin");
    printf("CON QUE ARCHIVO DESEA TRABAJAR?:");
    scanf("%s",nombre_archivo);

    printf("Cuantos clientes desea agregar?:");
    scanf("%d",&Nclientes);
    cliente agenda_guardar[Nclientes];
    agenda=fopen(nombre_archivo,"a+b");
    for(i=0;i<Nclientes;i++){
        system("cls");
        printf("NOMBRE>");
        fflush(stdin);
        gets(agenda_guardar[i].nombre);
        printf("DIRECCION>");
        gets(agenda_guardar[i].direccion);
        printf("TELEFONO>");
        scanf("%s",agenda_guardar[i].telefono);
        fflush(stdin);
        printf("SEXO (M/F)>");
        agenda_guardar[i].sexo=getchar();
        printf("ESTADO DE DE PAGO>");
        scanf("%f",&agenda_guardar[i].estado_pagos);
        agenda_guardar[i].activo=1;
        fwrite(&agenda_guardar[i],sizeof(agenda_guardar[i]),1,agenda);
    }
    fclose(agenda);

    return 0;
}
