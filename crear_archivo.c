#include <stdio.h>
#include <stdlib.h>
#include "agendas.h"

int crear_archivo(char nombre_archivo[255]){

//    puts(nombre_archivo);
//    printf("INGRESE UN NOMBRE PARA EL ARCHIVO:");
//    scanf("%s",nombre_archivo);
    FILE *agenda;
    agenda=fopen(nombre_archivo,"wb");
    fclose(agenda);
    printf("ARCHIVO CREADO CON EXITO!!!");
    return 0;
}
