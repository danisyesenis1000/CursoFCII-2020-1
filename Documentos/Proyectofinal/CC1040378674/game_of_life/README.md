# Juego de la vida

El juego de la vida es un automata celular de una especie creado por John Horton Conway. En este proyecto
se hizo una pequeña variacion, en la que se incluye una segunda especie y las reglas son:

    1 si la celda no tiene una célula viva y no tiene mas de 3 vecinos con vida:
        a. si los vecinos en el estado 1 son mayores que los vecinos en el estado 2 y tiene mas de 2 vecinos en el estado 1 la celda cambia al estado 1.
        b. si los vecinos en el estado 2 son mayores que los vecinos en el estado 1 y tiene mas de 2 vecinos en el estado 2 la celda cambia al estado 2.
    2. si la celda se encuentra en el estado 1:
        a. si tiene 4 o mas vecinos con vida cambia su estado a muerta
        b. si la celda tiene mas vecinos en el estado 1 que en el estado 2 y respeta la regla 2.a mantiene su estado en 1
        c. si la celda tiene mas vecinos en el estado 2 que en el estado 1, respeta la regla 2.a y la cantidad de vecinos 2 es mayor que unos, Cambia su estado a 2.
    3. si la celda se encuentra en el estado 2:
        a. si tiene 4 o mas vecinos con vida, cambia su estado a muerta
        b. si la celda tiene mas vecinos en el estado 1 que en el estado 2, respeta la regla 3.a y la cantidad de vecinos 1 es mayor que uno, Cambia su estado a 1.
        c. si la celda tiene mas vecinos en el estado 2 que en el estado 1, respeta la regla 3.a y la cantidad de vecinos 2 es mayor que uno, mantiene su estado en 2.
    4. De lo contrario la celda permanece en su estado.

## Ejecución

Para compilar el proyecto ejecute el comando:
```bash
make all
```

Para ejecutarlo una vez se ha compilado, ejecute el comando:
```bash
./game_of_life
```

Para eliminar todos los archivos generados en el proceso de compilacion ejecute el comando:
```
make clean
```
