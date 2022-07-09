# proyecto_compiladores

Proyecto Final Compiladores; Lenguajes y Traductores

Alumnos:
Alan Alberto Cruz García A01733377
Emmanuel Ramírez Reyes A01733357
Óscar Francisco López Carrasco A01732691

Código documentado en herramienta (github: https://github.com/ALANCRUZ96942/proyecto_compiladores)

El presente reconocedor léxico y sintáctico LR basa su funcionamiento en 
un arbol sintáctico reducido y una tabla de símbolos en nuestro caso implementado en una tabla hash, donde 
los nodos de cada arbol de definición tienen un apuntador hacia ellos.
Finalmente se elaboró un interprete para cada una de las funciones de la gramatica establecida.

Para compilarlo es necesario seguir los siguientes pasos:

1) En el directorio de los archivos se debe ingresar el comando:

flex reconocedor.lex

2) Posteriormente el comando que compila el reconocedor sintactico de bison

bison -d reconocedor.y

3) Enseguida se compila el programa en c y el archivo generado por los reconocedores con el comando:

gcc lex.yy.c reconocedor.tab.c -lfl

4) Finalmente el comando 

./a.out program.txt

Donde el elemento "program.txt" es el programa de entrada a reconocer.
