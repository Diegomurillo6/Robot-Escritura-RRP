## Robot RRP Escritor

Este repositorio contiene los códigos del brazo robótico RRP diseñado para escribir letras mediante un sistema de servomotores y comunicación Python–Arduino.

## Contenido
- **/python/** – Scripts para envío de trayectorias, procesamiento y comunicación serial.
- **/arduino/** – Código del microcontrolador (servos, protocolo OK, control).
- **/Letras/** – Trayectorias generadas (CSV por letra). Para que el python pueda leer las letras, deben estar en una carpeta llamada "Letras", o hacer cambios en el código.

## Cómo usar
1. Cargar `ArduinoRobotV1.ino` al Arduino para poner el robot en posición de arranque y esperar las trayectorias.
2. Ejecutar `SerialComCSV.py` 
3. Seleccionar el patrón de letras que se desea utilizar

IMPORTANTE: para efectos de nuestros servomotores, colocamos el origen en 30°. Esto quiere decir que todos los ángulos de los .csv tienen un offset de 30° agregado para que las trayectorias funcionen correctamente. El origen se tomó como posición horizontal para los links con articulaciones rotacionales, y posición retraída en la cremallera de la articulación prismática.

