# Proyecto Final - Cámara Inteligente con IA

**Materia:** Inteligencia Artificial y Redes Neuronales  
**Carrera:** Ingeniería en Mecatrónica  
**Universidad:** FIME - UANL

## Descripción

El proyecto consiste en una cámara inteligente capaz de reconocer y seguir figuras geométricas automáticamente. Para su funcionamiento se utilizaron Python, Google Colab, una red neuronal convolucional (CNN), Arduino Uno y dos servomotores.

## Componentes utilizados

- Cámara web USB.
- Arduino Uno R3.
- Dos servomotores.
- Computadora con conexión a internet.
- Fuente de alimentación de 5 V.
- Protoboard, cables y estructura de madera.

## Funcionamiento

El usuario selecciona una figura geométrica desde un panel desarrollado en Google Colab. La cámara captura las imágenes y el programa las procesa para reconocer círculos, cuadrados, estrellas o triángulos.

El sistema calcula la posición de la figura dentro de la imagen y determina los movimientos necesarios para centrarla.

Google Colab ejecuta el procesamiento de imágenes y mantiene la comunicación con un servidor web. La página de seguimiento permite intercambiar instrucciones con la computadora, que se comunica con Arduino mediante USB.

Arduino recibe las órdenes y controla los dos servomotores: uno para el movimiento horizontal y otro para el vertical.

## Conexiones

- Servomotor horizontal: pin digital 9.
- Servomotor vertical: pin digital 10.
- Comunicación serial: 9600 baudios.
- Alimentación de servomotores: fuente externa de 5 V con tierra común al Arduino.

## Resultados

Durante las pruebas se comprobó el movimiento horizontal y vertical de la cámara. Se realizaron ajustes de los ángulos y movimientos graduales hasta conseguir el centrado de la figura seleccionada.

El prototipo fue presentado físicamente y se verificó su funcionamiento.

## Archivos del proyecto

- `Camara_IA_Figuras (2).ipynb`: código de Python y Google Colab.
- `Camara_IA_arduino.ino`: programa de control de servomotores.
- `README.md`: documentación general.

## Conclusión

Este proyecto permitió integrar inteligencia artificial, visión por computadora, programación y electrónica para desarrollar un sistema mecatrónico capaz de reconocer figuras y realizar movimientos automáticos.
