# Automata 1D

En este proyecto se implemento el modelo de automatas en 1 dimension,
en el que se puede establecer 1 condicion inicial y 1 regla a partir de
la cual el sistema cambia, tambien se tiene un problema resuelto usando
como modelo de computo automatas celulares en 2 dimensiones (se incluyo en
automatas celulares en 1 dimension para reutilizar codigo), este problema
es el de magnetización.


Si se quiere ejecutar el problema de magnetizacion solo se debe cambiar el 
archivo main.cpp, descomentando la linea que corresponde a la funcion de este
problema, lo mismo para el modelo de automatas en 1 dimension. Para el segundo
caso se debe tener en cuenta que hay 2 modos de ejecucion, una en la que se pide
al usuario todo inline (desde la terminal en momento de ejecucion) y otra en la
que el usuario ingresa los parametros al momento de compilacion.

## Ejecución

Para compilar el proyecto ejecute el comando:
```bash
make all
```

Para ejecutar el programa, use el comando:
```bash
./automaton
```

Para limpiar los archivos generados por el proceso de compilacion y ejecucion se debe ejecutar el comando:
```bash
make clean
```

Si solo se quieren limpiar los resultados de ejecucion ejecute el comando:
```bash
make clean_results
```

### Referencias
Se uso como referencia
  
    SPROTT, Julien. Chaos and time series analysis. Oxford University Press. Chapter 15: Spatiotemporal chaos and complexity. 2003.

    WOLFRAM, Stephen. Cellular automata and complexity. 1994.

    KRAUTH, Werner. Statistical mechanics: Algorithms and computations.  Oxford University Press. 2006.
