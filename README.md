simpletron.c: Código fuente con el ciclo de búsqueda, decodificación, ejecución y vaciado de memoria.
README.md :casos de prueba
Casos de Prueba y Evidencias
Ejecución Correcta (Suma de dos números)
Entrada introducida:
1007
1008
2007
3008
2109
1109
4300
9999

Explicación:

Read (10): Lee el primer número y lo guarda en la posición 07.

Read (10): Lee el segundo número y lo guarda en la posición 08.

Load (20): Carga el contenido de la posición 07 al acumulador.

Add (30): Suma el contenido de la posición 08 al acumulador.

Store (21): Almacena la suma resultante en la posición 09.

Write (11): Muestra en pantalla el valor guardado en la posición 09.

Halt (43): Finaliza la ejecución de forma normal y muestra el volcado de registros y memoria.

Centinela (9999): Termina la fase de carga.

Error Fatal (División por Cero)
Entrada introducida:
1005
2005
3206
4300
9999
Explicación:

Read (10): Pide un número y lo guarda en la posición 05.

Load (20): Carga el número de la posición 05 en el acumulador.

Divide (32): Intenta dividir el acumulador entre el valor de la posición 06 (la cual vale 0 por defecto).

El programa detecta la división entre cero, detiene la ejecución inmediatamente, muestra el mensaje de error fatal y despliega el volcado de memoria.
