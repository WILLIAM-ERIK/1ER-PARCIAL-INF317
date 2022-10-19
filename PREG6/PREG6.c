#include "stdio.h"
#include "mpi.h"

int main()
{
	MPI_Status status;
  	int numero, numejec, numproc; 
  	int tag, next, from; 
  	int x, y, z;
  	x = 1;
  	y = 1;
  	z = 0;

  	MPI_Init(NULL, NULL);
 	MPI_Comm_rank(MPI_COMM_WORLD, &numejec);
	MPI_Comm_size(MPI_COMM_WORLD, &numproc);
 
  	tag = 201;
	next = (numejec + 1) % numproc;
  	from = (numejec + numproc - 1) % numproc;

  	if (numejec == 0) {
		printf("ESCRIBE UN NUMERO PARA GENERAR EL FIBONACCI: ");
    		scanf("%d", &numero);

    		MPI_Send(&z, 1, MPI_INT, next, tag, MPI_COMM_WORLD); //encia c al siguiente proceso inicio
  	}

  	do{    		//los procesos pasan el numero de vueltas y s calcula l siguiente fibonacci
		MPI_Recv(&z, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);
    		printf("Proceso %d --> %d\n", numejec, z);

    		if(numejec == 0) {
      			numero = numero - 1;
      			x = y;
      			y = z;
      			z = x + y;
    		}

    		MPI_Send(&z, 1, MPI_INT, next, tag, MPI_COMM_WORLD); //en via c al siguiente proceso
  	} while(numero > 0);
  
  	if (numejec == 0)
    		MPI_Recv(&z, 1, MPI_INT, from, tag, MPI_COMM_WORLD, &status);

  	MPI_Finalize;
  	return 0;
}
