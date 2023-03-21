# Ball-following-bot


The ball following bot is an innovative technology that works by combining Arduino, Raspberry Pi, and YOLO algorithm with OpenCV. It uses a USB webcam to capture the live video feed, which is then sent to the Raspberry Pi. The Raspberry Pi uses the OpenCV library and YOLO algorithm to detect the ball in the video feed. Once the ball is detected, the Raspberry Pi calculates the position of the ball relative to the center of the video frame and sends the position data to the Arduino Uno. The Arduino Uno controls the DC motors through the L298N motor driver module, which moves the bot in the required direction to keep the ball in the center of the video frame.

The ball following bot has various potential applications in different industries. In sports, it can be used as a training aid for athletes to improve their ball control, speed, and agility. In the entertainment industry, it can be designed to follow a specific color or pattern, allowing children to play various games with it. Additionally, the bot can be programmed to perform various dance moves, making it an entertaining robot for parties and events.

To build this project, we will need the following components:

Arduino Uno
Raspberry Pi 4
USB webcam
DC motors with wheels
L298N motor driver module
Ultrasonic sensor
9V battery
Breadboard
Jumper wires
The following software is also required:

Python 3.7 or above
OpenCV library
YOLO algorithm


The ball following bot works in the following way:

The USB webcam captures the live video feed and sends it to the Raspberry Pi.
The Raspberry Pi uses the OpenCV library to detect the ball in the video feed using the YOLO algorithm. YOLO (You Only Look Once) is a real-time object detection algorithm that can detect multiple objects in an image or video feed.
Once the ball is detected, the Raspberry Pi calculates the position of the ball relative to the center of the video frame.
The Raspberry Pi then sends the position data to the Arduino Uno, which controls the DC motors.
The Arduino Uno uses the position data to calculate the direction in which the bot needs to move to keep the ball in the center of the video frame.
The Arduino Uno controls the DC motors through the L298N motor driver module, which moves the ball following bot in the required direction.



To improve the accuracy of the ball following bot, more advanced computer vision and machine learning algorithms can be incorporated. Furthermore, its mobility can be enhanced by using more powerful motors and wheels, enabling it to move faster and more efficiently. Additionally, sensors and navigation systems can be added to make the bot work in various environments, such as on uneven terrain.

In conclusion, the ball following bot is a promising technology that can be used in various industries. Its components, such as the Arduino, Raspberry Pi, and motor driver module, work together to detect and follow the ball. With advancements in technology, the bot can be further developed to perform more complex tasks and work in different environments.
