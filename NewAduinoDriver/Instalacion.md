# NUEVO DRIVER Y SISTEMA DE COMUNICACIÓN PARA LA PLATAFORMA URLab
Esta carpeta contiene un nuevo sistema de comunicación para la plataforma URLab. En este caso no se emplea la compatibilidadnativa de Matlab-Simulink para la plataforma Arduino. La nueva comunicación se establece mediante los bloques para la comunicación serie duisponibles en SImulink y un nievo firmware que se ejecuta en el dispositivo

![](https://github.com/jarico/PLATAFORMA-DE-CONTROL-DE-TEMPERATURA/blob/11e754b69ef4e833b7cd2dbf5b96c0ab40f945d2/Dispositivo.jpg)

### Pre-requisitos 📋

El dispositivo trabaja con un microcontrolador ATMEGA 328P-AU (microcontrolador empleado en Arduino Nano) y una interface de comunicación serie CH340C. Para poder operar con el dispositivo será necesario disponer de los _drivers_ necesarios.

#### Drivers para el dispositivo CH340C
Los drivers pueden obtenerse de diferentes fuentes. A continuación, se muestran los enlaces de descarga facilitados por /www.prometec.net

* [Windows](https://www.prometec.net/wp-content/uploads/2015/01/CH341SER.zip) 
* [Mac OSX](https://www.prometec.net/wp-content/uploads/2014/09/ch341ser_mac.zip) 
* [Linux](https://www.prometec.net/wp-content/uploads/2015/10/CH341SER_LINUX.zip) - No debería ser necesario (compatibilidad nativa)

El siguiente vídeo muestra el proceso de instalación: https://youtu.be/MM9Fj6bwHLk

Una vez instalados la maquina deberá detectar el dispositivo cuando este sea conectado empleando el puerto USB A. _No es necesario alimentar el dispositivo a través del puerto USB C para el testeo de los drivers. La alimentación mediante el puerto USB C solo es necesaria cuando se desea activar los transistores._

En el administrador de dispositivos debera observarse que al conectar el dispositivo aparece un nuevo puerto COM virtual. Es recomendable anotar el número de puerto. Ejemplo para Windows 10:
```
USB-SERIAL CH-340 (COM7)
```
### Programación del dispositivo URlab
IMPORTANTE: Este paso solo debe realizarse si el dispositivo no se ha programado previamente.
La carpeta NewArduinoDriver\URlabFirmware contiene el sketch con el que debe programarse el dispositivo. Para ello basta con abrir con el IDE de Arduino dicho fichero programar el microcontrolador. Dento de la sección Tools debe emplearse la configuración:
PORT: COMX (emplear el número de puerto correspondiente) 
BOARD: Arduino Nano 
PROCESSOR: Armega328p (Old Bootloader)


### Instalación 🔧

Para instalar la librería basta con ubicar la capeta con los archivos del proyecto en la ubicación deseada (téngase en cuenta que el directorio no deberá alterarse posteriormente) y ejecutar el archivo Install.m, para ello puede ejecutarse en la línea de comandos 

```
Install
```

El script añadirá al Path la carpeta que contiene las librerías junto con los ejemplos, de forma que estos puedan emplearse desde cualquier ruta. A partir de este momento en el gestor de librerías de Simulink aparecerá la librería TemperatureLabLibrary, que contiene el bloque empleado para trabajar con el dispositivo.

_Además del método anterior puede emplearse cualquier alternativa que se considere oportuna. No es necesario añadir al Path de Matlab los directorios si en el directorio de trabajo se mantiene los archivos empleado por el dispositivo_
