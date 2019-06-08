#ifndef AGENDAS_H_INCLUDED
#define AGENDAS_H_INCLUDED

int crear_archivo(char nombre_archivo[255]);

void agregar_clientes(char *nombre_archivo);
//
void ver_clientes(char *nombre_archivo);
//
void buscar_clientes(char *nombre_archivo);
//
void mostrar_deudas(char *nombre_archivo);
//
void borrar_cliente(char *nombre_archivo);
//
void modificar_registro(char *nombre_archivo);

#endif // AGENDAS_H_INCLUDED
