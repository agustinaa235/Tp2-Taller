# Tp2-hilos

# Informacion estudiante

    Nombre: Agustina segura

    Padron: 104222

#Introduccion

El tp consta de verificar si un programa bpf tiene ciclos o isntrucciones
de uso. Para eso se modelara el programa con un grafo donde sus nodos
seran las instrucciones Y para detectar estas condiciones se hara uso del
la busqueda dfs. A su vez, estas vericicacones seran realizadas de forma
paralela con una serie de hilos.

#Diseño del tp

El diseño del tp consta en tener un hilo prinipal (main) donde se
instanciara los correspondientes objetos y luego se crearan una serie de
threads en donde luego seran lanzados y ellos seran los encargados de ejecutar
la verificacion.
En el tp se decidio modelar las distintas clases:

  * Parceador

    Esta clase se encarga de leer un archivo en donde se encuentran los
    programas bpf y luego esta sera la encargada de ir cargando las
    instrucciones al grafo dirigido.

  * Grafo

    Esta clase se encarga de guardar las instrucciones del programa bpf como
    nodos. A su vez es la que realiza el recorrido dfs

  * Nodo

    Esta clase forma como atributo del grafo. Esta se encarga de almacenar a sus
    nodos vecinos, ya que el grafo due modelado como una lista de adyacencia.

  * Verificador

    Esta clase se encarga de verificar el programa bfs, Si se trata de que hay
    un ciclo, o si hay instrucciones sin usar y en caso de que no suceda
    ninguna devuleve que el prograba esta bien.

  * Thread

      Esta clase modelaria lo que haria cada hilo, en este caso cuando se
      ejecuta el metodo start esta clase ira procesando a cada programa. Cada
      hilo deberá pedir un archivo a este objeto, parsearlo, modelarlo y
      analizarlo para luego volver a pedir otro archivo y repetir la operación.
      Para ello, la clase interactua con dos clases ( contenedor de archivos y
      contenedor de resultados) que son objetos compartidos.

  * Contenedor de Archivos

      Esta clase es la encarga de almacenar los archivos que le llega por
      consola y es la encargada de darlos. Para ello tiene como atributo
      un monitor que en este caso es una cola Protegida donde se protege a la
      cola en esa clase.

  * Contenedor de respuestas

      Esta clase se encarga de ir guardando a los archivos con lo que devolvio
      la clase verificacion. Esta clase tiene como atributo un monitor
      que es un vector protegido donde este sera el encargado de proteger al
      vector

  * Cola Protegida

      Esta clase se trata de un monitor en donde se encarga de proteger a
      a la cola cuando esta quiere deencolar un archivo y devolverlo.

  * Vector protegido

      Esta clase al igual que la anterior es un monitor donde en este caso
      portege al vector a la hora de guardar un resultado en el.

  *   Lock
      Esta clase se creo para poder cumplir con RAII y que se encarga de
      lockear y desloquear el mutex.


Decisiones de implementacion

Para el grafo se decicio hacerlo como una lista de adyacencia en donde este
se guarda en una vector priicpal a todos los nodos y luego cada nodo tiene
una referencia a sus vecinos.
A su vez, para mayor facilidad se decicio otorgarles a cada nodo un orden
que es con el que fueron agregados al vector prinipal. Esto fue porque asi era
mas sencillo poder conectar las aristas ya que la posicion con las que fueron
agregadas coincide con la lista de instrucciones que se guarda la clase
parceador. Tambien porque era mas sencillo a la hora de verificar ciclos
con dfs.

A su vez, decidi tener una clase instruccion donde sea ella como debe
agregarse al grafo con respecto a las aristas. Y que sea ellas quien sabe
si se trata de una etiqueta o una isntruccionescomun o un salto, etc,
logrando asi encapsulamiento.

Para el thread decidi no utilizar herencia y que sea la misma clase thread
la que se encargue de pedir el archivo porcesarlo verificador y mandarle
el resultado al contendor de resultados.

Se modelaron dos clases por serparado, contendor de archivos y contendor de
resultados, que serian los objetos compartidos para poder aislar mejor el
comportamiento de cada una y asu vez aislar por separa cada posible
raice condition. En donde cada una tiene como atributo su correspondiente
monitor en donde su monitor se encarga de porteger al objeto en particular.
