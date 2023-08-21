#ifndef TORRE_H
#define TORRE_H
#include <stdbool.h>
//essa struct repressenta o prato
typedef struct{
	int valor;
	struct prato * proximo;
}prato;
//essa struct repressenta o preto
typedef struct{
	prato * topo;
}torre;0

struct prato* createPrato();

#endif