# Arduino CLI

## Adding 3th party boards (ESP8266)

```bash
nano arduino-cli.yaml 
arduino-cli core update-index
arduino-cli core install esp8266:esp8266
```

arduino-cli.yaml config file content

```yaml
# arduino-cli.yaml
board_manager:
  additional_urls:
    - http://arduino.esp8266.com/stable/package_esp8266com_index.json
    - https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
```
