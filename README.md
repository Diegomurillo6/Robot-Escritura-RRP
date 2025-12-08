## Robot RRP Escritor

Este repositorio contiene los códigos del brazo robótico RRP diseñado para escribir letras mediante un sistema de servomotores y comunicación Python–Arduino.

## Contenido
- Código de python para la lectura, procesamiento y envío serial de los ángulos correspondientes a las trayectorias de las letras
- Código de Arduino para lectura serial de los ángulos y control de los actuadores del robot
- .csv de las letras: trayectorias generadas (CSV por letra). Para que el python pueda leer las letras, deben estar en una carpeta llamada "Letras", o hacer cambios en el código.
- El código GeneradorTrayectoriasProyecto.m.txt está diseñado para ser un código de MATLAB. Para correrlo pegar el código en un proyecto de MATLAB. Las trayectorias se generan de manera independiente y una a una, por lo que se debe comentar y descomentar respectivamente, dependiendo de la letra a la que se quiera generar una trayectoria.

## Cómo usar
1. Cargar `ArduinoRobotV1.ino` al Arduino para poner el robot en posición de arranque y esperar las trayectorias.
2. Ejecutar `SerialComCSV.py` 
3. Seleccionar el patrón de letras que se desea utilizar

IMPORTANTE: para efectos de nuestros servomotores, colocamos el origen en 30°. Esto quiere decir que todos los ángulos de los .csv tienen un offset de 30° agregado para que las trayectorias funcionen correctamente. El origen se tomó como posición horizontal para los links con articulaciones rotacionales, y posición retraída en la cremallera de la articulación prismática.
