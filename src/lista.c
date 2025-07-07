#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

// Crea una lista con un nodo.
void crear(TLista *pLista, char *cadena)
{
  pLista->pPrimero = malloc(sizeof(TNodo));
  strcpy(pLista->pPrimero->cadena, cadena);
  pLista->pPrimero->pSiguiente = NULL;
}

void destruir(TLista *pLista)
{
  TNodo *pAux1;
  struct Nodo *pAux2;

  for (pAux1 = pLista->pPrimero; pAux1 != NULL;)
  {
    pAux2 = pAux1->pSiguiente;
    free(pAux1);
    pAux1 = pAux2;
  }

  free(pLista);
}

// Inserta al ppio de la lista.
void insertar(TLista *pLista, char *cadena)
{
  TNodo *nuevoNodo = malloc(sizeof(TNodo)); // Crear el nuevo nodo
  strcpy(nuevoNodo->cadena, cadena); // Asigna el valor al nuevo nodo
  nuevoNodo->pSiguiente = pLista->pPrimero; // Poner el siguiente al que estaba primero
  pLista->pPrimero = nuevoNodo; // Poner el nuevo nodo como primero de la lista
}

void insertarFinal(TLista *pLista, char *cadena)
{
  TNodo *pAux1;
  TNodo *pAux2;

  for (pAux1 = pLista->pPrimero; pAux1 != NULL;)
  {
    pAux2 = pAux1;
    pAux1 = pAux1->pSiguiente;
  }

  TNodo *nuevoNodo = malloc(sizeof(TNodo)); // Crear el nuevo nodo
  strcpy(nuevoNodo->cadena, cadena); // Asigna el valor al nuevo nodo
  pAux2->pSiguiente = nuevoNodo; // Poner el nuevo nodo al final
  nuevoNodo->pSiguiente = NULL; // Poner el siguiente del nuevo nodo a NULL

}

// Suponemos n = 1, 2, ...
void insertarN(TLista *pLista, int index, char *cadena)
{
  if(index >= 0) {
    // Comprobar que la longitud de la lista es mayor o igual que el índice
    if(longitud(pLista) >= index) {
      if(index == 0) { // Si el índice es 0, insertar al principio
        insertar(pLista, cadena);
      } else {
        TNodo *pAux1;
        TNodo *pAux2;
        int contador = 0;

        for (pAux1 = pLista->pPrimero; contador != index;)
        {
          pAux2 = pAux1;
          pAux1 = pAux1->pSiguiente;
          contador++;
        }

        TNodo *nuevoNodo = malloc(sizeof(TNodo)); // Crear el nuevo nodo
        strcpy(nuevoNodo->cadena, cadena); // Asigna el valor al nuevo nodo
        pAux2->pSiguiente = nuevoNodo; // Poner el nuevo nodo en el siguiente del anterior
        nuevoNodo->pSiguiente = pAux1; // Poner el siguiente del nuevo nodo al siguiente de la lista
      }

    } else {
      printf("No se ha podido insertar el elemento, porque el índice es mayor a la longitud de la lista\n");
    }
  } else {
    printf("El índice debe ser un entero positivo\n");
  }

}

// Elimina el primer elemento de la lista.
void eliminar(TLista *pLista)
{
  TNodo *primero = pLista->pPrimero; // Obtener el primero de la lista
  pLista->pPrimero = primero->pSiguiente; // Poner el segundo como primero de la lista
  free(primero); // Eliminar el primer nodo
}

void eliminarN(TLista *pLista, int index)
{
  if(index >= 0) {
    // Comprobar que la longitud de la lista es mayor o igual que el índice
    if(longitud(pLista) > index) {
      if(index == 0) { // Si el índice es 0, eliminar el primero
        eliminar(pLista);
      } else {
        TNodo *pAux1;
        TNodo *pAux2;
        int contador = 0;

        for (pAux1 = pLista->pPrimero; contador != index;)
        {
          pAux2 = pAux1;
          pAux1 = pAux1->pSiguiente;
          contador++;
        }

        pAux2->pSiguiente = pAux1->pSiguiente; // Poner el siguiente del nodo izquierdo al nodo derecho respecto a que eliminas
        free(pAux1); // Eliminar el nodo seleccionado
      }

    } else {
      printf("No se ha podido eliminar el elemento, porque el índice es mayor a la longitud de la lista\n");
    }
  } else {
    printf("El índice debe ser un entero positivo\n");
  }
}

char *getElementoN(TLista *pLista, int index)
{
  if(index >= 0) {
    // Comprobar que la longitud de la lista es mayor o igual que el índice
    if(longitud(pLista) > index) {
      
        TNodo *pAux;
        int contador = 0;

        for (pAux = pLista->pPrimero; contador != index;)
        {
          pAux = pAux->pSiguiente;
          contador++;
        }

        return pAux->cadena;

    } else {
      printf("No se ha podido eliminar el elemento, porque el índice es mayor a la longitud de la lista\n");
    }
  } else {
    printf("El índice debe ser un entero positivo\n");
  }
  
}

void imprimir(TLista *pLista)
{
  TNodo *pAux;

  for (pAux = pLista->pPrimero; pAux != NULL;)
  {
    printf("%s -> ", pAux->cadena);
    pAux = pAux->pSiguiente;
  }

  printf("NULL\n");
}

int longitud(TLista *pLista)
{
  TNodo *pAux;
  int longitud = 0;

  for (pAux = pLista->pPrimero; pAux != NULL;)
  {
    longitud++;
    pAux = pAux->pSiguiente;
  }

  return longitud;
}