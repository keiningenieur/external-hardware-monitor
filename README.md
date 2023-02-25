<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

![Showcase](pictures/top_showcase.jpg?raw=true) 

<h1 align="center">external hardware monitor</h1>

  <p align="center">
    A program which displays the most important sensor data captured with OpenHardwareMonitor via an 0.96 inch OLED Display connected to a microcontroller.
    <br />
    <a href="https://github.com/keiningenieur/external-hardware-monitor"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/keiningenieur/external-hardware-monitor">View Demo</a>
    ·
    <a href="https://github.com/keiningenieur/external-hardware-monitor/issues">Report Bug</a>
    ·
    <a href="https://github.com/keiningenieur/external-hardware-monitor/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#supplies">Supplies</a></li>
    <li><a href="#wiring">Wiring</a></li>
    <li><a href="#prerequisites">Prerequisites</a></li>
    <li><a href="#configuration">Configuration</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

<!-- Usage -->
## Usage
The application cycles between three windows indicating temperature and workload for CPU and GPU as well as workload and memory usage for the RAM.
 
### CPU:
![Showcase](pictures/CPU_Showcase.jpg?raw=true)
### GPU:
![Showcase](pictures/GPU_Showcase.jpg?raw=true)
### RAM:
![Showcase](pictures/RAM_Showcase.jpg?raw=true)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- Supplies -->
## Supplies
* microcontroller like an [arduino nano clone](https://www.amazon.de/AZDelivery-Atmega328-gratis-Arduino-kompatibel/dp/B01LWSJBTD/ref=asc_df_B01LWSJBTD/?tag=googshopde-21&linkCode=df0&hvadid=310491639325&hvpos=&hvnetw=g&hvrand=449149806729429256&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9068343&hvtargid=pla-654302475800&psc=1&th=1&psc=1&tag=&ref=&adgrpid=59900935617&hvpone=&hvptwo=&hvadid=310491639325&hvpos=&hvnetw=g&hvrand=449149806729429256&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9068343&hvtargid=pla-654302475800)
* [0.91 inch OLED display](https://www.amazon.de/Seamuing-OLED-Anzeigemodul-I2C-Bildschirm-Tiny-Modul-Arduino/dp/B09BF7SQHS/ref=sr_1_1?__mk_de_DE=ÅMÅŽÕÑ&crid=2XERDY5GAMADR&keywords=OLED+0.91&qid=1677270192&s=industrial&sprefix=oled+0.91%2Cindustrial%2C103&sr=1-1)
* usb-cable compatible with the microcontroller of your choice [(For arduino nanos & clones)](https://www.amazon.de/PremiumCord-Kabel-USB-Mini-5Pins/dp/B07NSQ511V/ref=sr_1_3?__mk_de_DE=ÅMÅŽÕÑ&crid=TTJ0S29PKF4M&keywords=usb+mini-b+kabel&qid=1677270349&s=industrial&sprefix=usb+mini-b+kabel%2Cindustrial%2C92&sr=1-3)

### optional
* 3D-printed holder
  * [the one I used](https://www.thingiverse.com/thing:5788490)
  * [all in one solution with an esp](https://www.thingiverse.com/thing:4550044)
  * [another frame solution](https://www.thingiverse.com/thing:3514326)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- Wiring -->
## Wiring

### computer - microcontroller

Connect your microcontroller via usb to your pc. Use an usb-port which you don't use often, as you will need to maintain this connection, for the applications to work. Every time you switch to an different usb-port, you'll have to change the port-number accordingly in the python application. 

### microcontroller - oled display

For the connection between the microcontroller and oled display use the following wiring:

| microcontroller | oled display |
| ------------- | ------------- |
| 5V  | VIN  |
| GND  | GND  |
| A4(SDA)  | SDA  |
| A5(SCL)  | SCL |

![Fritzing](pictures/fritzing.png?raw=true)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- Prerequisites -->
## Prerequisites

For the application to work, you'll need to install [Open Hardware Monitor](https://openhardwaremonitor.org/downloads/).
To install, just unpack the zip archive and run OpenHardwareMonitor.exe with Administrator rights. Otherwise, some hardware sensors are not accessible and could lead to errors.

<p align="right">(<a href="#readme-top">back to top</a>)</p>
 
<!-- Configuration -->
## Configuration
    
### python code 

The project contains two different python application versions. [ehm_without_caps_detection.py](https://github.com/keiningenieur/external-hardware-monitor/blob/main/ehm_without_caps_detection.py) is the basic version, which collects sensor data from OpenHardwareMonitor and sends this data to the microcontroller. 
For your setup, you'll have to find out the usb-port your microcontroller is connected to, e.g. via the device-manager -> connections (COM & LPT).
<br>
Now in line 6 change the com-port to the port your mircocontroller is connected to:
   ```sh
   arduino = serial.Serial(port='COM7', baudrate=115200, timeout=.1)
   ```




[ehm_with_caps_detection.py](https://github.com/keiningenieur/external-hardware-monitor/blob/main/ehm_with_caps_detection.py) contains a section which detects if caps is active and sets a led strip ([WLED](https://kno.wled.ge)) into a different color-mode. For this feature, you will need a [WLED](https://kno.wled.ge)-Strip and configure the following lines (39-46) with the according ip-address:
   ```sh
     if GetKeyState(VK_CAPITAL) == 1:
        caps = str(1)
        current = requests.get('http://0.0.0.0/json/state')
        backup = current.text
        response = requests.post('http://0.0.0.0/json', "{'on':  true, 'bri': 127, 'seg':[{'col':[[220,229,255],[0,0,0],[0,0,0]], 'fx':63,'sx':50}]}")
        while GetKeyState(VK_CAPITAL) == 1:
            time.sleep(1)
        response = requests.post('http://0.0.0.0/json', backup)
   ```
   
### arduino code 

[ehm_microcontroller.ino](https://github.com/keiningenieur/external-hardware-monitor/blob/main/ehm_microcontroller.ino) don't need any configuration. Just upload the code via the arduino ide to your microcontroller.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Philipp Schulz - m0l0t0w@web.de

Project Link: [https://github.com/keiningenieur/external-hardware-monitor](https://github.com/keiningenieur/external-hardware-monitor)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/keiningenieur/external-hardware-monitor.svg?style=for-the-badge
[contributors-url]: https://github.com/keiningenieur/external-hardware-monitor/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/keiningenieur/external-hardware-monitor.svg?style=for-the-badge
[forks-url]: https://github.com/keiningenieur/external-hardware-monitor/network/members
[stars-shield]: https://img.shields.io/github/stars/keiningenieur/external-hardware-monitor.svg?style=for-the-badge
[stars-url]: https://github.com/keiningenieur/external-hardware-monitor/stargazers
[issues-shield]: https://img.shields.io/github/issues/keiningenieur/external-hardware-monitor.svg?style=for-the-badge
[issues-url]: https://github.com/keiningenieur/external-hardware-monitor/issues
[license-shield]: https://img.shields.io/github/license/keiningenieur/external-hardware-monitor.svg?style=for-the-badge
[license-url]: https://github.com/keiningenieur/external-hardware-monitor/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/philipp-schulz-930279201/
[product-screenshot]: pictures/main_showcase.jpg
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
