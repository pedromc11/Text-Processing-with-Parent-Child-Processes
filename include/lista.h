#ifndef _LISTA_
#define _LISTA_

typedef struct Nodo
{
  char cadena [20];
  struct Nodo *pSiguiente;
} TNodo;

typedef struct
{
  TNodo *pPrimero;
} TLista;

void crear(TLista *pLista, char *cadena);
void destruir(TLista *pLista);

// 'insertar' inserta al ppio de la lista.
void insertar(TLista *pLista, char *cadena);
void insertarFinal(TLista *pLista, char *cadena);
void insertarN(TLista *pLista, int index, char *cadena);

// 'elimina' elimina el último de la lista.
void eliminar(TLista *pLista);
void eliminarN(TLista *pLista, int index);

char *getElementoN(TLista *pLista, int index);

void imprimir(TLista *pLista);
int longitud(TLista *pLista);

#endif
