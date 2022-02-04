# PLATAFORMA PARA EL CONTROL DE TEMPERATURA
Este repositorio contiene los archivos necesarios para trabajar con la plataforma didáctica para la docencia en la ingeniería de control implementada en la Universidad de La Rioja.

Este dispositivo consiste en una revisión de la plataforma TCLab (Temperature Control Lab) desarrollada por John D. Hedengren.

En este repositorio se incluyen los archivos necesarios para el empleo del dispositivo junto con Matlab Simulink, así como algunos ejemplos de aplicación. El proyecto se encuentra abierto para que los interesados puedan colaborar con las modificaciones/ampliaciones que considere oportunas.

![](https://github.com/jarico/PLATAFORMA-DE-CONTROL-DE-TEMPERATURA/blob/11e754b69ef4e833b7cd2dbf5b96c0ab40f945d2/Dispositivo.jpg)

## Comenzando 🚀

Estas instrucciones te permitirán obtener una copia del proyecto en funcionamiento en tu maquina local para propósitos de desarrollo y pruebas.


### Pre-requisitos 📋

El dispositivo trabaja con un microcontrolador ATMEGA 328P-AU (microcontrolador empleado en Arduino Nano) y un interface de comunicación serie CH340C. Para poder operar con el dispositivo será necesario disponer de los _drivers_ necesarios.

#### Drivers para el dispositivo CH340C
Los drivers pueden obtenerse de diferentes fuentes. A continuación se muestran los enlaces de descarga facilitados por /www.prometec.net

* [Windows](https://www.prometec.net/wp-content/uploads/2015/01/CH341SER.zip) 
* [Mac OSX](https://www.prometec.net/wp-content/uploads/2014/09/ch341ser_mac.zip) 
* [Linux](https://www.prometec.net/wp-content/uploads/2015/10/CH341SER_LINUX.zip) - No debería ser necesario (compatibilidad nativa)

El siguiente vídeo muestra el proceso de instalación: https://youtu.be/MM9Fj6bwHLk

Una vez instalados la maquina deberá detectar el dispositivo cuando este sea conectado empleando el puerto USB A. _No es necesario alimentar el dispositivo a través del puerto USB C para el testeo de los drivers. La alimentación mediante el puerto USB C solo es necesaria cuando se desea activar los transistores._

En el administrador de dispositivos debera observarse que al conectar el dispositivo aparece un nuevo puerto COM virtual. Es recomendable anotar el número de puerto. Ejemplo para Windows 10:
```
USB-SERIAL CH-340 (COM7)
```

#### Compatibilidad nativa para Arduino en Matlab
El dispositivo emplea la compatibilidad nativa que incorpora Matlab Simulink para trabajar con dispositivos del ecosistema Arduino. Antes de emplear el dispositivo debe verificarse que dichos paquetes se encuentran instalado y en caso contrario añadirlos al sistema.

Pulsar en el icon ADD-ON de Matlab y en el explorador buscar: _"Arduino"_. Debe instalarse el paquete:

```
MATLAB Support Package for Arduino Hardware
```


### Instalación 🔧

Para utilizar ..... Falta por hacer



## Ejecutando la primera prueba de funcionamiento ⚙️

Para verificar el funcionamiento del dispositivo se recomienda emplear el Ejemplo 1, que realiza una prueba de control en lazo cerrado. Para ello debe abrirse el archivo _EJ1_LazoCerradoSISO.slx_ bien desde el explorador de archivos o ejecutando  

```
open EJ1_LazoCerradoSISO
```
Para ejecutar el experimento del ejemplo basta con darle al Play en Simulink. La primera vez que se trabaje con el dispositivo en una máquina, esta buscará el dispositivo en el equipo, emitiendo el siguiente mensaje (este procedimiento tarda unos pocos segundos): 

```
Unable to connect, user input required
For Windows:
Open device manager, select "Ports (COM & LPT)"
Look for COM port of Arduino such as COM4

For MacOS:
Open terminal and type: ls /dev/*.')
Search for /dev/tty.usbmodem* or /dev/tty.usbserial*. The port number is *.

For Linux')
Open terminal and type: ls /dev/tty*
Search for /dev/ttyUSB* or /dev/ttyACM*. The port number is *.

Specify port (e.g. COM4 for Windows or /dev/ttyUSB0 for Linux):
```

Seguir los pasos e indicarr el puerto adecuado. Siguiendo el ejemplo anterior COM7
```
Specify port (e.g. COM4 for Windows or /dev/ttyUSB0 for Linux): COM7
```
El sistema detectará el dispositivo como un dispositivo de la familia Arduino y el experimento se ejecutará de forma habitual. Este procedimiento deberá realizarse solo cuando se realice una nueva asignación al puerto COM por parte del SO de la máquina.


## Contribuyendo 🖇️

El proyecto se encuentra abierto al desarrollo de nuevas herramientas y recursos. Por el momento no se ha establecido una política para el desarrollo de colaboraciones (se establecerá en un futuro en función del desarrollo del mismo). Se anima a los usuarios a abrir nuevas ramas en las que desarrollar las funciones que puedan ser de utilidad para la comunidad.