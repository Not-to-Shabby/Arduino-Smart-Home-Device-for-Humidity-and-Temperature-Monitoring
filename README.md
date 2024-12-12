# Arduino-Smart-Home-Device-for-Humidity-and-Temperature-Monitoring


This Arduino project creates an intelligent environmental monitoring system that uses a DHT11 sensor to measure temperature and humidity, providing visual feedback through an RGB LED.
Hardware Requirements

    Arduino board (Uno, Nano, or similar)
    DHT11 temperature and humidity sensor
    RGB LED (common cathode)
    Resistors for RGB LED (220Ω recommended)
    Jumper wires
    Breadboard

Pin Connections

    DHT11 Data Pin → Arduino Digital Pin 5
    RGB LED Red Pin → Arduino Digital Pin 9
    RGB LED Green Pin → Arduino Digital Pin 10
    RGB LED Blue Pin → Arduino Digital Pin 11

Features

    Real-time temperature and humidity monitoring
    Visual feedback through RGB LED colors:
        Green: Comfortable conditions (20-25°C, 40-60% humidity)
        Red-Yellow: Warm conditions (25-32°C)
        Blinking Red: Very hot conditions (>32°C)
        Blue-Green: Cool conditions (20-25°C)
        Blinking Blue: Very cold conditions (<20°C)
    LED intensity varies based on temperature and humidity levels
    Serial output for monitoring values

Installation

    Install the DHT library in Arduino IDE:
        Go to Sketch → Include Library → Manage Libraries
        Search for "DHT"
        Install the "DHT sensor library" by Adafruit

    Connect the hardware according to the pin configuration

    Upload the provided code to your Arduino

How It Works

The system operates in the following ways:

    Takes temperature and humidity readings every 2 seconds
    Maps temperature (15-35°C) and humidity (30-90%) to LED intensities
    Changes LED colors based on environmental conditions:
        Optimal conditions: Steady green light
        Hot conditions: Red to yellow gradient
        Cold conditions: Blue to green gradient
        Extreme conditions: Blinking indicators

Serial Monitor Output

Connect to the serial monitor at 9600 baud to view:

    Temperature readings in Celsius
    Humidity percentage readings

Customization

You can modify these parameters in the code:

    Temperature thresholds (currently 20-25°C for comfort zone)
    Humidity thresholds (currently 40-60% for comfort zone)
    LED update intervals (currently 2000ms for normal, 500ms for blinking)
    Pin assignments for different Arduino board layouts

Troubleshooting

If you encounter issues:

    Check all wire connections
    Verify the DHT library is properly installed
    Ensure the RGB LED is properly oriented (common cathode)
    Check serial monitor for "Failed to read from DHT sensor!" messages
