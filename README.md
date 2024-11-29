# CARRO-FUTBOL-ROBOT ⚽

Carro a control remoto con mecanismo de pateo para impactar una pelota de ping pong, utilizado en competencias de **FUTBOL-ROBOT**.

Para la competencia es neesario la implementación de 2 carros rc.

![carros en cancha](https://github.com/user-attachments/assets/6c64a3f3-58df-4512-a62e-8f9e4a9a27e7)


## Componentes del proyecto.
2x Arduino UNO.

2x Shield Joystick para Arduino UNO.

2x Arduino NANO.

2x LM1117T.

4x Capacitores electroliticos de 10uF.

2x Modulo L298n.

4 Motores N20-30 6V 300rpm.

4x nRF24L01+.

## Arduino NANO
![Arduino NANO](https://github.com/user-attachments/assets/898a8f89-511a-47d0-bf99-3d9cd5ecf519)
## nRF24L01
El nRF24L01+ (de Nordic Semiconductor) es un transceptor RF de 2 Mbps de potencia ultrabaja (ULP) altamente integrado para la banda ISM (industrial, científica y médica) de 2,4 GHz.

![nrf24l01](https://github.com/user-attachments/assets/df9bdd2f-6406-42bb-9b18-c666d369ce44)
![nrf24l01+](https://github.com/user-attachments/assets/755e560f-a14c-4e8a-852c-f8f891db5641)

#### Características:

-Fuente de alimentación: 1,9 ~ 3,6 V.

-Alcance de ~520 m a velocidad de datos de 2 Mbit

-Reconocimiento automático

-Retransmisión automática

-Multireceptor - 6 conductos de datos

-FIFO TX y RX separados de 32 bytes

-Canal seleccionable por software: 2400 MHz a 2525 MHz (125 canales seleccionables)

-Número mínimo de componentes externos

-Pines desglosados: VCC, CE, CSN, SCK, MOSI, MISO, IRQ, GND

nRF24L01+ es un transceptor de banda estrecha (~2 MHz), pero eso funciona a nuestro favor ya que BLE también es de banda estrecha por diseño (~2 MHz).

## Esquemas
- Importante utilizar un reductor de voltaje como por ejemplo el reductor de voltaje lineal LM1117T.

![LM1117T](https://github.com/user-attachments/assets/91465357-7761-4e9a-9a8e-317ac70d04b5)

![Esquematico nano_nrf24l01](https://github.com/user-attachments/assets/b75a1f95-19a6-46dd-ba80-cd47fc84cf41)

## Arduino UNO
![Arduino UNO](https://github.com/user-attachments/assets/43efba03-fb16-4c11-a885-921c84e93d18)

## Shield Joystick Arduino UNO
- Este modulo es comunmente utilizado en proyectos de radio control por su facilidad de implementacion ya que es plug and play.

![shield joystick arduino uno](https://github.com/user-attachments/assets/cb9e746b-7f79-43ea-9384-de43bee48249)

## Modulo L298n
![L298n](https://github.com/user-attachments/assets/4fc1629b-e8e9-48fc-8235-48c61affbcd3)
### Características

- Input Voltage: 3.2V~40Vdc.

- Driver: L298N Dual H Bridge DC Motor Driver

- Power Supply: DC 5 V - 35 V

- Peak current: 2 Amp

- Operating current range: 0 ~ 36mA

- Control signal input voltage range :

- Low: -0.3V ≤ Vin ≤ 1.5V.

- High: 2.3V ≤ Vin ≤ Vss.

- Enable signal input voltage range :

  - Low: -0.3 ≤ Vin ≤ 1.5V (control signal is invalid).

   - High: 2.3V ≤ Vin ≤ Vss (control signal active).

- Maximum power consumption: 20W (when the temperature T = 75 ℃).

- Storage temperature: -25 ℃ ~ +130 ℃.

- On-board +5V regulated Output supply (supply to controller board i.e. Arduino).

- Size: 3.4cm x 4.3cm x 2.7cm 

## Motores motores N20-30
![motor n20](https://github.com/user-attachments/assets/428f9609-6b5f-4b20-9627-035b6011f52b)
### Características
- Material: Metal

- Modelo: N20

- Longitud Total: 36mm

- Tamaño de motor: 12mm(diámetro)*26mm(altura)

- Tamaño de eje: 3mm(diámetro)*10mm(longitud)

- Rango de Voltaje: 3-9VDC

- Voltaje Nominal: 6VDC

- Velocidad sin Carga: 300rpm

- Corriente sin Carga: 30mA

- Corriente a Máxima Eficiencia: 40mA

- Torque de Paro (Stall Torque): 1.6Kg/cm

- Corriente de Paro (Stall Current): 0.4A


## Implementación
### Diseño
#### Carro
![DISEÑO CARRO](https://github.com/user-attachments/assets/435f123a-3d59-4163-ad9c-7ca781ab9808)

#### Control
![control](https://github.com/user-attachments/assets/bdf43acb-c709-439b-b96e-e7dba0fc8870)


### Baquelita
![Baquielita carro](https://github.com/user-attachments/assets/4c96253b-2f41-41fb-b2a3-63b71718f400)
