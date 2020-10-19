# Arduino-WMR-Bluetooth-Remote-XY
Control-WMR-Bluetooth
![](https://github.com/s1mpleton/Arduino-WMR-Bluetooth-Remote-XY/blob/master/WMR.jpg)
## Hardware
Main Component

x1 Arduino UNO\
x1 [Motor Driver L298n H-bridge PWM](https://images-na.ssl-images-amazon.com/images/I/71kN49AetUL._SL1000_.jpg)\
x4 [TT Motor](https://images-na.ssl-images-amazon.com/images/I/418YctAC26L.jpg)\
x3 [Battery 4v](https://images-na.ssl-images-amazon.com/images/I/51bsYiilQvL._SL1100_.jpg)\
x1 [Battery 9v](https://images-na.ssl-images-amazon.com/images/I/61HWb-9fu5L._SL1500_.jpg)\
x1 [REES52 Bluetooth Transceiver Module HC05](https://images-na.ssl-images-amazon.com/images/I/61hSbYc%2BXeL._SL1100_.jpg)

## Connection
![](https://github.com/s1mpleton/Arduino-WMR-Bluetooth-Remote-XY/blob/master/Diagram.png?raw=true)
| Arduino_pin | L298n_pin |
| :---:       |     :---: |
|A0           |        EnA|
|8            |        In1|
|7            |        In2|
|5            |        In3|
|4            |        In4|
|3            |        EnB|
|GND          |        GND|

|Arduino_pin  |    HC5_pin|
| :---:       |  :---:    |
|TX           |         RX|
|RX           |         TX|
|3.3v or 5v   |        VCC|
|GND          |        GND|

|L298n_pin    |  Motor_pin|
| :---:       |  :---:    |
|Output 1 +   |  Motor1 + & Motor2 -|
|Output 1 -   |  Motor1 - & Motor2 +|
|Output 2 +   |  Motor3 + & Motor4 -|
|Output 2 -   |  Motor3 - & Motor4 +|

|Battery      |  Component|
| :---:       |  :---:    |
|Battery 9v   |  Arduino Power Port|
|Battery 4v x3 connect together in serie to create 12v          |     L298n 12v Port & GND|
## Software
```
Step 1 : Upload RemoteXY.zip Library to Arduino IDE Library Folder
Step 2 : Upload Remote Controller Remote_Vx.ino into the Arduino
```
## Initiate Stage
```
Step 1 : Connect 5v Battery to Power Jack Port of Arduino UNO
Step 2 : Connect 12v Battery to Power Jack Port of Motor Driver
Step 3 : Open RemoteXY app on Smartphone
Step 4 : Connect to Bluetooth Device with password 1234
Step 5 : Have Fun :)
```
