# NUEVO DRIVER Y SISTEMA DE COMUNICACIÓN PARA LA PLATAFORMA URLab  

Esta carpeta contiene un nuevo sistema de comunicación para la plataforma URLab. En este caso, no se emplea la compatibilidad nativa de Matlab-Simulink para la plataforma Arduino. La nueva comunicación se establece mediante los bloques de comunicación serie disponibles en Simulink y un nuevo firmware que se ejecuta en el dispositivo.  

![](https://github.com/jarico/PLATAFORMA-DE-CONTROL-DE-TEMPERATURA/blob/11e754b69ef4e833b7cd2dbf5b96c0ab40f945d2/Dispositivo.jpg)  

## Pre-requisitos 📋  

El dispositivo utiliza un microcontrolador **ATMEGA 328P-AU** (microcontrolador empleado en Arduino Nano) y una interfaz de comunicación serie **CH340C**. Para operar con el dispositivo, será necesario instalar los _drivers_ correspondientes.  

### Drivers para el dispositivo CH340C  

Los drivers pueden obtenerse de diversas fuentes. A continuación, se proporcionan enlaces de descarga facilitados por [Prometec](https://www.prometec.net):  

- [Windows](https://www.prometec.net/wp-content/uploads/2015/01/CH341SER.zip)  
- [Mac OSX](https://www.prometec.net/wp-content/uploads/2014/09/ch341ser_mac.zip)  
- [Linux](https://www.prometec.net/wp-content/uploads/2015/10/CH341SER_LINUX.zip) - No debería ser necesario (compatibilidad nativa).  

El siguiente vídeo muestra el proceso de instalación: [Instalación de drivers CH340](https://youtu.be/MM9Fj6bwHLk).  

Una vez instalados los drivers, el sistema debería detectar el dispositivo al conectarlo mediante el puerto USB A. **No es necesario alimentar el dispositivo a través del puerto USB C para probar los drivers.** La alimentación por USB C solo es requerida cuando se desea activar los transistores.  

En el Administrador de Dispositivos (Windows), debería aparecer un nuevo puerto COM virtual al conectar el dispositivo. Se recomienda anotar el número del puerto. Por ejemplo, en Windows 10:  

```
USB-SERIAL CH-340 (COM7)
```

## Programación del dispositivo URLab  

**IMPORTANTE:** Este paso solo debe realizarse si el dispositivo no ha sido programado previamente.  

En la carpeta `NewArduinoDriver\URlabFirmware` se encuentra el _sketch_ que debe programarse en el dispositivo. Para ello:  

1. Abra el archivo correspondiente con el IDE de Arduino.  
2. Configure el microcontrolador en la sección **Tools**:  
   - **PORT:** COMX (reemplace "X" por el número de puerto detectado).  
   - **BOARD:** Arduino Nano.  
   - **PROCESSOR:** ATmega328P (Old Bootloader).  
3. Programe el microcontrolador con este _sketch_.  

## Instalación 🔧  

Para instalar la librería:  

1. Copie la carpeta del proyecto en la ubicación deseada. **Tenga en cuenta que el directorio no debe modificarse posteriormente.**  
2. Ejecute el archivo `Install.m` desde la línea de comandos de MATLAB:  

   ```
   Install
   ```  

El script añadirá al _path_ de MATLAB la carpeta que contiene las librerías y los ejemplos, de forma que puedan utilizarse desde cualquier ubicación.  

Una vez instalada, en el gestor de librerías de Simulink aparecerá la librería **TemperatureLabLibrary**, que incluye el bloque necesario para trabajar con el dispositivo.  

_Nota: Si prefiere, puede usar cualquier otro método para configurar la librería. No es necesario añadir los directorios al _path_ de MATLAB si los archivos necesarios para el dispositivo permanecen en el directorio de trabajo._  

---

