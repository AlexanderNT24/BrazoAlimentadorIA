# Brazo Alimentador con Inteligencia Artificial 
El proyecto se basa en un brazo alimentador controlado con inteligencia artificial y gestionado en arduino, esto con la ayuda de la librería mediapipe, la cual reconoce y brinda puntos especiales en un rostro.
Nuestro proyecto crea una comunicación entre python y arduino, con la finalidad de que si python detecta que la boca del usario se cierra o abre, este se lo comunicará a arduino que a su vez iniciará un protocolo.
## Sobre El Proyecto
Para el desarrollo de nuestro proyecto usamos una placa Arduino UNO, el IDE de Arduino y Visual Studio Code.
### El proyecto hace uso de las siguentes tecnologías.
#### Para Arduino UNO:
```
C++
```
#### Para la detección del rostro:
```
Python 
Mediapipe
OpenCV
```
#### Para la comunicación entre Python y Arduino:
```
Threading
Pyserial
```
