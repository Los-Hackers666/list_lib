# Dan Israel Vázquez Rentería Exp.734769

## Conclusiones

En lo personal uno de los mayores retos que afronte en esta primer actividad asincronica fue el de usar un pensamiento logico
para diseñar la solucion del problema al que nos enfrentabamos, diseñar el algoritmo no fue tan complicado porque 
entre todos aportamos un paso para llegar a la solucion, aunque si llegamos a topar pared en un paso de la solucion, el 
cual era el de movernos de nodos ya una vez que habiamos eliminado los duplicados de la primer iteracion.

La logica que utilizamos para diseñar el algoritmo consistio en realizar la comparacion del elemento que queremos remover sus duplicados
por todos los elementos de la lista, cuando eliminamos el duplicado de la lista solo realizamos las reconexiones pertinentes entre los nodos. 

El funcionamiento de `remove_duplicates` consiste en comenzar a comparar el head de la lista, en donde lo vamos a guaradar en la variable `value_to_compare`, el 
`current_position` va a tener por valor el `value_to_compare`; el primer ciclo While va a llevarnos al final de la lista y el segundo while nos va a ayudar a realizar las comparaciones entre los nodos, si se cumple la condicion `if(value_to_compare->value == current_position->next->value)` procedemos a guardar         `current_position->next` en tmp para liberar ese nodo que se repite con  `free(tmp)`, despues de liberar esa posicion nos movemos al siguiente nodo incluso si no entra a la condicion if nos movemos a la siguiente posicion (eso quiere decir que no se repite nuestro value_to_compare).

Para la parte de la lectura de archivos fue algo complicado en lo personal y tuvimos que recurrir a investigar
por otros medios para poder implementar la solucion, sinceramente este punto me resulta frustrante a nivel personal mas sin embargo siento 
que verme en esta situacion me ayuda a desarrollar habilidades de investigacion y comprension de librerias que en un futuro me ayudaran a 
tener mejores habilidades de trabajo.

Los aprendizajes que me llevo de esta actividad asincronica son bastantes, ya que pude comprender mejor el funcionamiento
de las listas en C, el como implementar la lectura de archivos y el como realizar las practicas adecuadas de
diseño de librerias en C.
