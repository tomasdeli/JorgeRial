/*
 * Cliente.h
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#ifndef CONSOLA_H_
#define CONSOLA_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include "utils.h"


t_log* iniciar_logger(void);
t_config* leer_config(void);
void leer_consola(t_log*);
void paquete(int);
void terminar_programa(int, t_log*, t_config*);
void iniciar_patota(int cantTripulantes, char* tareas, char* posiciones);
void listar_tripulantes();
void expulsar_tripulante(int id);
void iniciar_planificacion();
void pausar_planificacion();
void obtener_bitacora(int id);

#endif /* CONSOLA_H_ */
