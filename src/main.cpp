#include <mpi.h>


//******************************************************************************
int main (int argc, char* argv[]) {

    // Initialize MPI 
    MPI_Init(&argc,&argv);

    char messagercvd[100];

    // Stores the rank and the size
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    cout << "Hi! I am " << rank << " out of " << size << endl;

    if (rank == 0) {
        MPI_Send(argv[1], strlen(argv[1]) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);

    } else {
        MPI_Recv(messagercvd, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << messagercvd << endl;
    }

    MPI_Finalize();

    return 0;
}


/**

MPI_Send
MPI_Recv​

MPI_Init(...);
MPI_Comm_rank(...);
MPI_Send(...);
MPI_Recv(...);
WHAT?        buffer // qual mensagem (mas tem que ser qual argv)
HOW MANY?    count
WHAT TYPE?   datatype
TO WHOM?     destination // deve ser o rank, nao o address to rank
WHICH TAG?   tag 
WHICH GROUP? communicator // MPI_COMM_WORLD


**/ 

