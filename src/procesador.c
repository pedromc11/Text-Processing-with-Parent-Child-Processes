#include <errno.h>
#include <linux/limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void buscarPatronLinea(const char *linea, const char *patron, int contador_linea);

int main(int argc, char *argv[])
{
  /*
  argv[0] = CLASE_PROCESADOR
  argv[1] = nombre_fichero
  argv[2] = patron
  */

  FILE *fp;
  char linea[PATH_MAX];
  int contador_linea = 1;

  // Abrimos el fichero solution.txt en modo lectura
  if ((fp = fopen(argv[1], "r")) == NULL)
  {
    fprintf(stderr, "Error al abrir el fichero %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Obtenemos cada línea y buscamos alguna coincidencia con el patrón
  while (fgets(linea, sizeof(linea), fp) != NULL)
  {
    buscarPatronLinea(linea, argv[2], contador_linea);
    contador_linea++;
  }

  return EXIT_SUCCESS;
}

/*
** Función buscarPatronLinea. Función que divide una línea en palabras (separadas por espacios) y muestra si
** si encuentra alguna coincidencia con el patrón.
*/
void buscarPatronLinea(const char *linea, const char *patron, int contador_linea) {

  char *token;

  token = strtok(linea, " ");
  while (token != NULL)
  {
    if(strcmp(patron, token) == 0) {
      printf("[PROCESADOR %d] Patron '%s' encontrado en la línea %d\n", getpid(), patron, contador_linea);
    }
    token = strtok(NULL, " ");
  }

}