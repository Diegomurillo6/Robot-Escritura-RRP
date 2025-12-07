import serial
import time
import csv
import os

#Input del patrón, el usuario selecciona el patrón de letras que quiere que ejecute el robot.
#Si no existe el patrón ingresado, genera un mensaje de error
patron = input("Patrón de letras (SVC / DMQ / DGA): ").strip().upper()
if patron not in ["SVC", "DMQ", "DGA"]:
    raise ValueError("Patrón inválido. Usa SVC, DMQ o DAG.")

letras = list(patron)  #Por ejemplo "SVC" → ['S','V','C']

#Ruta base, los .csv deben estar en una carpeta llamada "Letras"
BASE = "Letras"

#Comunicación serial con el arduino. Se debe verificar que el puerto serial sea el correcto
ser = serial.Serial('COM6', 115200, timeout=1)
time.sleep(2) #Espera 2 segundos

#Función para leer una letra
def cargar_trayectoria(nombre_letra):
    archivo = os.path.join(BASE, f"{nombre_letra}.csv") #leer el .csv de una letra específica

    trayectoria = []

    with open(archivo) as file:
        reader = csv.reader(file, delimiter=',')


        for row in reader: #lee todas las columnas y filas del archivo
            if len(row) < 3:
                continue
            try:
                q1 = float(row[0])
                q2 = float(row[1])
                q3 = float(row[2])
                trayectoria.append((q1, q2, q3))
            except:
                continue

    return trayectoria

#Procesar letra por letra
for letra in letras:

    print(f"\n===== LETRA {letra} =====\n")

    trayectoria = cargar_trayectoria(letra) #lee el csv de la letra

    for q1, q2, q3 in trayectoria: 

        msg = f"{q1:.3f},{q2:.3f},{q3:.3f}\n" #codifica el mensaje y lo envía al arduino como 3 valores separados
        ser.write(msg.encode())

        #Debug de comunicación con arduino
        while True:
            line = ser.readline().decode().strip()
            if line:
                print("[ARDUINO]:", line)
            if line == "OK":
                break

#Termina el programa al terminar el patrón de letras elegido, cierra comunicación serial
ser.close()
