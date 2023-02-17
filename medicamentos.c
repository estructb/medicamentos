/*
En una farmacia se venden 2 tipos de medicamentos: genéricos y de patente. 
Los datos de los tipos genéricos son: el precio, sustancia activa, 
si requiere receta médica (“s” o “n”), porcentaje de descuento 
(si no hay se asigna un cero) y precio final. 
Los datos para los medicamentos de patente son: precio, nombre comercial 
(por ejemplo “aspirina”), sustancia activa 
(por ejemplo “ácido acetilsalicílico”), 
laboratorio (por ejemplo “Bayer”) y si requiere receta médica (“s” o “n”).
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    PATENTE,
    GENERICO
} TipoMedicamento;

typedef struct {
    float precio;
    char sustancia_activa[30];
    char requiere_receta;
    void *info_adicional;
    TipoMedicamento tipo;
} Medicamento;

typedef struct {
    char laboratorio[30];
    char nombre_comercial[30];
} Patente;

typedef struct {
    float porcentaje_descuento;
    float precio_final;
} Generico;

/*
Escriba una función para reservar memoria para el arreglo de medicamentos. 
La función recibe dos parámetros: el tamaño del arreglo y un apuntador por 
referencia donde se asignará la memoria dinámica para el arreglo.
*/

void crear_arreglo_medicamentos(int tam, Medicamento **arreglo)
{
    *arreglo = (Medicamento*)malloc(tam * sizeof(Medicamento));
}


/*
Escribir una función para capturar la información medicamentos 
genéricos y/o de patente. La función recibe dos parámetros: 
un apuntador al arreglo de medicamentos y un entero con el tamaño del arreglo. 
Utilice notación/aritmética de apuntadores para acceder a los elementos 
del arreglo.
*/
void capturar_medicamentos(Medicamento *arreglo, int tam)
{
    for (int i = 0; i < tam; i++)   {
        printf("Precio del medicamento: ");
        scanf("%f", &(arreglo+i)->precio);
        printf("Sustancia activa: ");
        scanf("\n%s", (arreglo+i)->sustancia_activa);
        printf("Requiere receta (S/N): ");
        scanf("\n%c", &(arreglo+i)->requiere_receta);
    }
}

void imprimir_medicamentos(Medicamento *arreglo, int tam)
{
    for (int i = 0; i < tam; i++)   {
        printf("Precio del medicamento: %f\n", (arreglo+i)->precio);
        printf("Sustancia activa: %s\n", (arreglo+i)->sustancia_activa);
        printf("Requiere receta (S/N): %c\n", (arreglo+i)->requiere_receta);
    }
}

int main()
{
    Medicamento *arreglo;
    int tam;

    printf("Tamaño del arreglo: ");
    scanf("%d", &tam);
    crear_arreglo_medicamentos(tam, &arreglo);
    capturar_medicamentos(arreglo, tam);
    imprimir_medicamentos(arreglo, tam);
}

