/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

void DestruirQueue(Queue q) {
    free(q->theQueue);
		free(q);
}

void Enqueue(Queue q, PVertice v) {
    q->tail++;
    q->theQueue[q->tail] = v;
}

PVertice Dequeue(Queue q) {
    PVertice v;
    q->head++;
    v = q->theQueue[q->head];
    return v;
}

u32 isEmpty(Queue q) {
    return (q->head == q->tail);
}
