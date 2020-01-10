# Moisture Sensor

Bought the kuman SPCS Soil Moisture Sensor Kit, which came with sensor probes and an amplifier.

Followed the Instructables guide and code, which can be found [here](https://www.instructables.com/id/Arduino-Soil-Moisture-Sensor/).

## Schematic

- Connect the sensor probe to the amplifier using two cables.
- Connect the amplifier to the Arduino:
  - VCC: 3.3V power
  - GND: Ground
  - A0: Analog output (instead of D0, see *)
  - D0: Digital output (instead of A0, see *)

*Amplifier possibly also has digital output (D0), but this is untested

## Images

![alt text](connection_image.jpg "Connection Image")
