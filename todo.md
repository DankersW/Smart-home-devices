# To-Do

## Documentation

- Update architectural overview

- Change repo to be for more specifik, climate_sensor 

## Logging

- Configurable logging class that logs to console, and remote logging using the communication layer

## Dev-env

- Testing framework, local and on github
- Code coverage, local and on github
- Cmake for arduino (AVR platform)

## System

- Cleaning up memory, because of the keywork new when we create objects we have to delete memory. Every hour delete each object and re-create the system.
- Communication layer
- Configurable base layer
- Generic base that each unit relies on with additional product functions (temperature reading, acting to events, etc)
- Sensor reading layer
- Actor layer
- Radio layer
- hardware configuration: based on hardwired io pins setup type of device, e.q. 0101 = weather station
- software configuration: using a header file contataining a struct to hold device data
- publish device information to framework on startup

- good pattern holder inter layer communication
- setup basic layers (communication, actor, enegery managment, processing, sensor, logging)
- Systemconfig header file

### Radio

- Reconnect to mqtt broker or wifi if any of the connections if lost
- listen to messages over mqtt and implement a command factory

### Sensor

- Poll sensors (DHT11) in a non delay controlled way every 2 seconds.
- Update sensor data struct with different extra parameters

### System.ino

- Seting device name
- Publising sensor data correctly
- To publish queue

