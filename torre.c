#include "torre.h"
#include <stdlib.h>

struct prato* createPrato() {
    struct prato* prato = (struct prato*)malloc(sizeof(struct prato));
    prato->top = NULL;
    return prato;
}
