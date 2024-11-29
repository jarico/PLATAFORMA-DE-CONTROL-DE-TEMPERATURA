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

IMPORTANTE: Este paso no es necesario se ya se ha instalado la librería del sistema de comunicación anterior.

1. Copie la carpeta del proyecto en la ubicación deseada. **Tenga en cuenta que el directorio no debe modificarse posteriormente.**  
2. Ejecute el archivo `Install.m` desde la línea de comandos de MATLAB:  

   ```
   Install
   ```  

El script añadirá al _path_ de MATLAB la carpeta que contiene las librerías y el ejemplos, de forma que puedan utilizarse desde cualquier ubicación.  

_Nota: Si prefiere, puede usar cualquier otro método para configurar la librería. No es necesario añadir los directorios al _path_ de MATLAB si los archivos necesarios para el dispositivo permanecen en el directorio de trabajo._  

---

Aquí tienes un nuevo apartado "Empleo del dispositivo" basado en tu texto original, mejorado y estructurado para mayor claridad:  

---

## Empleo del dispositivo ⚙️  

El dispositivo incluye un ejemplo práctico para el control en lazo cerrado, proporcionado en el archivo **URLabControlLC**. Este ejemplo puede utilizarse como punto de partida para desarrollar aplicaciones específicas.  

### Pasos para usar el ejemplo:  
1. **Abrir el archivo:**  
   Localice y abra el archivo `URLabControlLC.slx` en Simulink.  

2. **Configurar los parámetros:**  
   Antes de ejecutar el modelo, asegúrese de que:  
   - El puerto COM asignado al dispositivo está correctamente configurado en el los bloques (**Serial configuration, Serial Send y Serial Recibe**) de comunicación serie del modelo. Estos se encuentran dentro del bloque URlab v2 
   - El dispositivo está conectado al puerto USB A de su ordenador y detectado correctamente.  

3. **Ejecutar el simulador:**  
   Una vez configurado, ejecute el modelo en Simulink. Este control en lazo cerrado puede ajustarse o ampliarse según las necesidades del usuario.  

4. **Personalización:**  
   Puede utilizar este ejemplo como base para crear sus propios diseños de control. Simplemente modifique los bloques y parámetros según los requisitos específicos de su proyecto.  

### Notas importantes:  
- Asegúrese de que los drivers del dispositivo CH340C estén instalados y que el firmware correcto haya sido programado previamente.  
- Si encuentra problemas de comunicación, verifique que el puerto COM configurado en el modelo coincida con el asignado al dispositivo en su sistema operativo.  

---

Si necesitas más detalles o una ampliación del contenido, ¡hazmelo saber! 😊
