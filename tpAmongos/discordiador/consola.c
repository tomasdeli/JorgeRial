/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "consola.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	int* puerto;
	char* clave;
	int cantTripulantes;
	char* tareas;
	char* posiciones;
	int id;

	t_log* logger;
	t_config* config;

	logger = iniciar_logger();

	log_info(logger,"Soy un tripulante"); //Loggear "Soy un tripulante"

	iniciar_patota(cantTripulantes, tareas, posiciones);
	listar_tripulantes();
	expulsar_tripulante(id);
	iniciar_planificacion();
	pausar_planificacion();
	obtener_bitacora(id);

	config = leer_config();

	clave = config_get_string_value(config, "CLAVE"); //asignar valor de config a la variable valor
	puerto = config_get_string_value(config, "PUERTO_MI_RAM_HQ");
	ip = config_get_string_value(config, "IP_MI_RAM_HQ");

	log_info(logger,"CLAVE: %s // PUERTO MI RAM HQ: %s // IP: %s",clave, puerto, ip);
	//log_info(logger,"PUERTO: %s",puerto);
	//log_info(logger,"IP: %s",ip);

	//Loggear valor de config


	leer_consola(logger);


	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	conexion = crear_conexion(ip, puerto); //crear conexion

	enviar_mensaje(clave, conexion); //enviar CLAVE al servidor

	paquete(conexion);

	terminar_programa(conexion, logger, config);

}

void iniciar_patota(int cantTripulantes, char* tareas, char* posiciones){

}

void listar_tripulantes(){

}

void expulsar_tripulante(int id){

}

void iniciar_planificacion(){

}

void pausar_planificacion(){

}

void obtener_bitacora(int id){

}

t_log* iniciar_logger(void)
{

	log_create("discordiador.log","DISCORDIADOR",1,LOG_LEVEL_INFO); //Creo el logger
}

t_config* leer_config(void)
{
	config_create("./discordiador.config"); //Creo el config
}

void leer_consola(t_log* logger)
{
	char* leido = readline(">"); //El primero te lo dejo de yapa

	while(strcmp(leido, "")) {
		log_info(logger, leido);
		free(leido);
		leido = readline(">");
		}

	free(leido);
	//printf("\nLINEA VACIA.\nPrograma finalizado.");
	//exit(1);
}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido = readline(">");
	t_paquete* paquete;

	paquete = crear_super_paquete(); //Creo el paquete

	while(strcmp(leido, "")) {
		agregar_a_paquete(paquete, leido, strlen(leido) + 1);
		free(leido);
		leido = readline(">");
		}

	free(leido);

	enviar_paquete(paquete, conexion); //Envio el paquete a la conexion

	eliminar_paquete(paquete);

}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger); //Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	config_destroy(config); //Destruyo el config
	liberar_conexion(conexion); //Liberar conexion
}
