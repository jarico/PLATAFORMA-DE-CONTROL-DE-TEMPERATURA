function T = DriverTemperatureLab(heater)

Q1=heater(1);
Q2=heater(2);
maxQ1=heater(3)/100;
maxQ2=heater(4)/100;
maxT1=heater(5);
maxT2=heater(6);
uLED=heater(7);


persistent icount a

% Detección del dispositivo. Dado que el SO no lo detecta como un 
% dispositivo, la primera vez que se utilice deberá introducirse el número 
% de puerto de forma manual

if (isempty(icount))
   try
      a = arduino;
      disp(a)
   catch
      warning('Unable to connect, user input required')
      disp('For Windows:')
      disp('  Open device manager, select "Ports (COM & LPT)"')
      disp('  Look for COM port of Arduino such as COM4')
      disp('For MacOS:')
      disp('  Open terminal and type: ls /dev/*.')
      disp('  Search for /dev/tty.usbmodem* or /dev/tty.usbserial*. The port number is *.')
      disp('For Linux')
      disp('  Open terminal and type: ls /dev/tty*')
      disp('  Search for /dev/ttyUSB* or /dev/ttyACM*. The port number is *.')
      disp('')
      com_port = input('Specify port (e.g. COM4 for Windows or /dev/ttyUSB0 for Linux): ','s');
      %a = arduino(com_port,'Nano');
      a = arduino(com_port,'ProMini328_5V');
      disp(a)
   end
   icount = 0;
end 
% Contador detector de deispositivo
icount = icount + 1;

%----------------------------
% Funciones anonimas empleadas por el script    

% Funciones para la lectura de entradas analógicas 
v1 = @() readVoltage(a, 'A0');
v2 = @() readVoltage(a, 'A1');

% Funciones para calcular temperaturas con el sensor TMP36
TC = @(V) (V - 0.5)*100.0;          % Celsius
%TK = @(V) TC(V) + 273.15;           % Kelvin
%TF = @(V) TK(V) * 9.0/5.0 - 459.67; % Fahrenheit

% Funciones para los LED indicadores (0 <= level <= 1)
ledT1 = @(level) writePWMDutyCycle(a,'D10',level);  % ON
ledT2 = @(level) writePWMDutyCycle(a,'D9',level);  % ON

% Funciones para los calefactores (0 <= level <= 100)
% limit to 0-0.9 (0-100%)
h1 = @(level) writePWMDutyCycle(a,'D6',max(0,min(100,level))*maxQ1/100);
% limit to 0-0.5 (0-100%)
h2 = @(level) writePWMDutyCycle(a,'D5',max(0,min(100,level))*maxQ2/100);
%----------------------------


% Lectura de las temperaturas
T1 = TC(v1());
T2 = TC(v2());
T = [T1,T2];

% Activación de LEDs indicadores 
if T1 > uLED
    ledT1(1)
else
    ledT1(0)
end

if T2 > uLED
    ledT2(1)
else
    ledT2(0)
end



% Escritura de temperaturas en los calefactores
if T1<maxT1
    h1(Q1);
else
    h1(0);
end
if T2<maxT2
    h2(Q2);
else
    h2(0);
end




end







