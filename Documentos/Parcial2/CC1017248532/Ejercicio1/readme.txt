En utils están los headers correspondientes a cada .cpp.
circular.h contiene el prototipo de la clase Circular
espiral.h contiene el prototipo de la clase heredada Espiral.

makefile compila el código y le da el nombre: Exercise1

Si corre el archivo run.sh, este compilará el código, correrá el código compilado y correrá el archivo .py que se encarga de graficar las trayectorias.

Cuando se corra el código compilado se crearan dos .csv.

circular.csv : contiene las posiciones en "x" y "y" para cada tiempo t
espiral.csv : contiene las posiciones en "x", "y", y "z" para cada tiempo t
