#include <iostream>
using namespace std;
#define COTASUPERIORN 41
#define COTAINFERIORN 2
#define COTASUPERIORM 21
#define COTAINFERIORM 2
int validarNumero(int numero,int max, int min){
    /*Funcion que verifica si un numero valido en dos rangos 
    *Parametros:
        numero -> Numero a verificar.
        max -> cota superior que se utiliza para verificar.
        min -> cota inferior que se utiliza para verificar.
    *Retorno:
        Numero verificado.
    */
   while(numero<min || numero>max){
       cout << "Error introduzca un valor valido.";
       cout << " El numero debe estar entre " << min << " y " << max << " : " ;
       cin >> numero; 
   }
   return numero;
}
int aleatorio(int limite_superior, int limite_inferior){
    /*Funcion que genera un numero aleatorio entre dos limites */
    return limite_inferior + rand() % (limite_superior + 1 - limite_inferior) ;
}
int **crearMatriz(int N,int M){
    //Funcion que crea la matriz.
    int **puntero_matriz;
    puntero_matriz= new int*[N];
    for(size_t i{};i<N;i++){
        puntero_matriz[i]= new int[M];
    }
    return puntero_matriz;
}
int **inicializarMatriz(int **puntero_matriz,int N,int M){
    //Funcion que inicializa la matriz con valores de cero.
    for(size_t i{}; i<N;i++){
        for(size_t j{};j<M;j++){
           puntero_matriz[i][j]=0;
        }
    }
    return puntero_matriz;
}
void imprimirMatriz(int **puntero_matriz,int N,int M){
    //Funcion que imprime la matriz.
    for(size_t i{}; i<N;i++){
        for(size_t j{};j<M;j++){
            cout << " " << puntero_matriz[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int imove(int k){
    switch (k){
    case 0:
        return -1;
        break;
    case 1:
        return -1;
        break;
    case 2:
        return -1;
        break;
    case 3:
        return 0;
        break;
    case 4: 
        return 0;
        break;
    case 5:
        return 1;
        break;
    case 6:
        return 1;
        break;
    case 7:
        return 1;
        break;
    default:
        break;
    }
    return 0;
}
int jmove(int k){
    switch (k){
    case 0:
        return -1;
        break;
    case 1:
        return 0;
        break;
    case 2:
        return 1;
        break;
    case 3:
        return -1;
        break;
    case 4: 
        return 1;
        break;
    case 5:
        return -1;
        break;
    case 6:
        return 0;
        break;
    case 7:
        return 1;
        break;
    }
    return 0;
}
bool lleno(int **puntero_matriz,int N,int M){
    /*Funcion que verifica que la matriz este llena 
    Parametros:
        puntero_matriz -> puntero de la matriz 
        N -> cantidad de filas de la matriz 
        M -> cantidad de columnas de la matriz
    Retorno : 
        bandera -> si la matriz esta llena tiene valor de true si no esta llena tiene valor false*/
    bool bandera{true};
    for(size_t i{}; i<N;i++){
        for(size_t j{};j<M;j++){
           if(puntero_matriz[i][j]==0){
               bandera=false;
           }
        }
    }
    return bandera;
}
void generarMovimiento(int *fila,int *columna, int limite_filas, int limite_columnas){
    /*Funcion que genera y verifica los movimientos del bicho.
    Parametros: 
        fila -> posicion inicial de fila del bicho
        columna -> posicion inicial de las columnas del bicho 
        limite_filas -> cantidad de filas de la matriz 
        limite_columnas -> cantidad de columnas de la matriz 
    Retorno:
        Ninguno.*/
    int K{};
    int auxfila{*fila};
    int auxcolumna{*columna};
    K=aleatorio(7,0);
    auxfila+=imove(K);
    auxcolumna+=jmove(K);
    while((auxfila<0 || auxfila>limite_filas) ||  (auxcolumna<0 || auxcolumna>limite_columnas)){
        auxfila=*fila;
        auxcolumna=*columna;
        K=aleatorio(7,0);
        auxfila+=imove(K);
        auxcolumna+=jmove(K);
    }
    *fila=auxfila;
    *columna=auxcolumna;
}
void recorrido(int **puntero_matriz,int N,int M){
    /*Funcion que realiza el recorrido del bicho por toda la matriz 
    Parametros:
        puntero_matriz -> puntero de la matriz. 
        N -> cantidad de filas de la matriz. 
        M -> cantidad de columnas de la matriz.
    Retorno: 
        Ninguno. 
    */
    int contador_principal{},contador_secundario{};
    int ibug,jbug;
    cout << "Introduzca una posicion inicial de fila para el bicho: " ;
    cin >> ibug;
    ibug=validarNumero(ibug,N-1,0);
    cout << "Introduzca una posicion inicial de columna para el bicho: " ;
    cin >> jbug;
    jbug=validarNumero(jbug,M-1,0);
    puntero_matriz[ibug][jbug] += 1;
    imprimirMatriz(puntero_matriz,N,M);
    while(contador_principal<25000 && !lleno(puntero_matriz,N,M)){
        ++contador_principal;
        ++contador_secundario;
        generarMovimiento(&ibug,&jbug,N-1,M-1);
        puntero_matriz[ibug][jbug] += 1;
        if(contador_secundario==100){
            cout << "Se realizaron " << contador_principal << " pasos " <<endl;
            imprimirMatriz(puntero_matriz,N,M);
            contador_secundario=0;
        }
    }
    if(contador_principal==25000){
        cout << "El programa termino porque llego a los 25000 pasos. " <<endl;
    }else{
        cout << "El programa termino porque se lleno la matriz. " <<endl;
        cout << "Se realizaron " << contador_principal << " pasos " <<endl;
    }
}
int main(){
    srand(time(NULL));
    int N {};
    int M {};
    int **puntero_matriz{NULL};
    cout << "Introduzca un valor para N : " ;
    cin >> N;
    N=validarNumero(N,COTASUPERIORN,COTAINFERIORN);
    cout << "Introduzca un valor para M : ";
    cin >> M; 
    M=validarNumero(M,COTASUPERIORM,COTAINFERIORM);
    cout << "Los valores de M y N respectivamente son : " << M << " "<< N <<endl;
    puntero_matriz=crearMatriz(N,M);
    puntero_matriz=inicializarMatriz(puntero_matriz,N,M);
    imprimirMatriz(puntero_matriz,N,M);
    recorrido(puntero_matriz,N,M);
    imprimirMatriz(puntero_matriz,N,M);
    //Se libera memoria 
    for(size_t i{0};i<N;i++){
        delete puntero_matriz[i];
    }
    delete puntero_matriz;
    return 0;
}  