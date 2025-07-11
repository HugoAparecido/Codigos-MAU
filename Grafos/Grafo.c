typedef struct grafo Grafo;
#include <stdio.h>
#include <stdlib.h>

struct grafo
{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int **arestas;
    float **pesos;
    int *grau;
};

Grafo *cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado)
{
    Grafo *gr = (Grafo *)malloc(sizeof(struct grafo));
    if (gr != NULL)
    {
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0) ? 1 : 0;
        gr->grau = (int *)callloc(nro_vertices, sizeof(int));
        gr->arestas = (int **)malloc(nro_vertices * sizeof(int *));
        for (int i = 0; i < nro_vertices; i++)
            gr->arestas[i] = (int *)malloc(grau_max * sizeof(int));
        if (gr->eh_ponderado)
        {
            gr->pesos = (float **)malloc(nro_vertices * sizeof(float *));
            for (int i = 0; i < nro_vertices; i++)
                gr->pesos[i] = (float *)malloc(grau_max * sizeof(float));
        }
    }
    return gr;
}

void libera_Grafo(Grafo *gr)
{
    if (gr == NULL)
        return;

    // Free memory for pesos (if weighted)
    if (gr->eh_ponderado)
    {
        for (int i = 0; i < gr->nro_vertices; i++)
        {
            free(gr->pesos[i]); // Free each row of weights
        }
        free(gr->pesos); // Free the array of weight pointers
    }

    // Free memory for arestas
    for (int i = 0; i < gr->nro_vertices; i++)
    {
        free(gr->arestas[i]); // Free each row of adjacencies
    }
    free(gr->arestas); // Free the array of adjacency pointers

    // Free memory for grau
    free(gr->grau);

    // Free the Grafo structure itself
    free(gr);
}

int insereAresta(Grafo *gr, int orig, int dest, int eh_digrafo, float peso)
{
    if (gr == NULL)
        return 0;
    if (orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if (dest < 0 || dest >= gr->nro_vertices)
        return 0;
    gr->arestas[orig][gr->grau[orig]] = dest;
    if (gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;
    if (eh_digrafo == 0)
        insereAresta(gr, dest, orig, 1, peso);
    return 1;
}

int removeAresta(Grafo *gr, int orig, int dest, int eh_digrafo)
{
    if (gr == NULL)
        return 0;
    if (orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if (dest < 0 || dest >= gr->nro_vertices)
        return 0;
    int i = 0;
    while (i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if (i == gr->grau[orig]) // elemento não encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if (gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if (eh_digrafo == 0)
        removeAresta(gr, dest, orig, 1);
    return 1;
}

int main()
{
    Grafo *gr = cria_Grafo(10, 7, 0);
    insereAresta(gr, 0, 1, 0, 0);
    insereAresta(gr, 1, 3, 0, 0);
    removeAresta(gr, 0, 1, 0);

    libera_Grafo(gr); // Free the allocated memory
    gr = NULL;        // It's good practice to set the pointer to NULL after freeing
    return 0;
}