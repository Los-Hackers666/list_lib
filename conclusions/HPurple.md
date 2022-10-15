# Héctor Aguilar Gómez Exp.734952

## Conclusiones

El proceso de construcción de la segunda parte de la librería de listas, que, en el caso de nuestro equipo
buscaba eliminar los valores repetidos que pudieran existir en un lista de enteros mediante la función
`delete_duplicates()`, resultó en un interesante reto a la hora de incluir lectura y escritura de archivos 
en nuestro proceso de manipular listas ligadas simples.

Buscamos que la metodología de implementación  manipulación de las listas ligada fuera bastante similar al que implementamos
en clase y al parecer es la manera estándar de trabajar con este tipo de contenedores: a través de estructuras
y nodos con memoria asignada por `malloc()` según se requieran, mismos que serán los elementos de la lista y que nos 
permitirá recorrerlos.

De nuestra implementación original realizada en clase, decidimos quedarnos solamente con funciones específicas 
que se vuelven útiles en el objetivo de nuestra pequeña librería, entre ellas `list_new()` y `list_append()`;
pues solamente nos interesa crear listas, mostrarlas y ser capaces de agregarles elementos previo a que validemos
si existen valores repetidos en la lista.

Ahora bien, la lógica sobre la cual se desarolla el proceso de eliminación de duplicados, realmente se basa en comparar dos 
valores de la lista y comprobar si los valores de cada uno de estos nodos son equivalentes, en caso de serlo, el valor más reciente 
dentro de la lista será guardado en un temporal, eliminando de dicho nodo con la función `free()` y reconectamos la lista con el 
nodo siguiente. Realmente nos costó un tanto acercarnos a esta lógica, sin embargo fue cuestión de abstraer los conceptos y 
realmente moldear y mejorar nuestra propuesta inicial que básciamente se reducía a: "recorrer la lista y hacer NULL dicha posición".

Para efectos de implementar una solución optimizada y sencilla de comprender y utilizar, decidimos agregar un par de 
funciones específicas que nos permitieran manipular el archivo segun se necesitara. La primera de estas, `lread()`, abrirá 
el archivo, lo leerá, extraerá la información y utilizará `list_append()` para ir llenando de nodos nuestra lista con los valores obtenidos.

En este particular paso, tuvimos que hacer una investigación un tanto profunda para lograr convertir los datos recibidos a la hora de leer el archivo de entrada en formato string, a enteros que podamos comparar con `delete_duplicates()`. La solución fue el uso de la función `strtol()` que hace "parse" de ese string a un valor entero dada una base, en este caso 11, considerando los 10 números del rango que comprende el valor int, mas el posible signo que pueda existir. De esta manera, `lwrite()`, simplemente se encargará de visitar cada nodo de nuestra lista y de integrar el valor de este en el archivo de resultados.

Particularmente esta implementación de actividad asíncrona me pareció una muy buena manera de poder rescatar y sobre 
todo poner en práctica los últimos y más complejos temas vistos en el curso: la implementación completa de una librería, 
el uso de listas ligadas y el manejo e intervención en archivos. Fue un proceso retador y que requirió de análisis e 
investigación, sobre todo a la hora de poder interpretar los strings resultantes de la lectura de archivos como enteros. 
Durante un par de sesiones de equipo fuimos capaces de completar el algoritmo que contiene la función 
`remove_duplicates()` y posteriormente la manera de manipular los datos del archivo, para convertirlos en una lista,
eliminar sus duplicados y escribir la nueva lista en el archivo de resultados.
