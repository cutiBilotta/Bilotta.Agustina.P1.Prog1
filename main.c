#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float aplicarAumento(float precio);
int reemplazarCaracter(char cadena[], char carReemplazado, char carReemplazador);


typedef struct
{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
} eVacuna;

int ordenarArray(eVacuna vector[], int largo);


int main()
{
    float precio= 56.98;
    float precioFinal;

    char cadena[20]="kinesiologo";
    int cantidad;

    eVacuna vectorVacuna[6] = {{1, "sput", 'a', 25.3}, {2, "sinopha", 'b', 36.3}, {3, "pfizer", 'c', 27.9}, {4, "astra", 'a', 68.5}, {5, "poly", 'b', 47.24}, {6, "omic", 'd', 97.1}};


    printf("El precio es: %.2f\n", precio);
    precioFinal=aplicarAumento(precio);
    printf("Precio final con 5%% de aumento es: %.2f \n", precioFinal);
    printf("\n----------------------------------------------------\n");
    cantidad=reemplazarCaracter(cadena, 'o', 'a');
    puts(cadena);
    printf("La cantidad de veces que se reemplazo un caracter es: %d \n", cantidad);
    printf("\n----------------------------------------------------\n");

    ordenarArray(vectorVacuna, 6);
    for(int i=0 ; i<6; i++)
    {
        printf ("%2d      %10s      %2c    %.2f \n", vectorVacuna[i].id, vectorVacuna[i].nombre, vectorVacuna[i].tipo, vectorVacuna[i].efectividad);

    }
}

float aplicarAumento(float precio)
{
    float aumento;
    float precioFinal=0;

    if(precio>0)
    {


        aumento= 5*precio / 100;
        precioFinal= precio+aumento;
    }

    return precioFinal;

}

int reemplazarCaracter(char cadena[], char carReemplazado, char carReemplazador)
{
    int largo;
    int contador=0;

    if(cadena != NULL)
    {
        largo=strlen(cadena);

        for(int i=0; i<largo; i++)
        {

            if(cadena[i] == carReemplazado)
            {
                cadena[i]=carReemplazador;
                contador++;
            }
        }
    }
    return contador;


}

int ordenarArray(eVacuna vector[], int largo)
{
    int todoOk=0;
    eVacuna aux;


    if(vector && largo)
    {
        for( int i=0; i<largo-1 ; i++)
        {
            for(int j= i+1; j<largo ; j++)
            {
                if((vector[i].tipo> vector[j].tipo) || ((vector[i].tipo == vector[j].tipo) && vector[i].efectividad> vector[j].efectividad))
                {
                    aux= vector[j];
                    vector[j]= vector[i];
                    vector[i]=aux;
                }
            }

        }
        todoOk=1;

    }
    return todoOk;
}
