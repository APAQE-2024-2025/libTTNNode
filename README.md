# libTTNNode
A basic abstraction layer for ABP (and OTAA [WIP]) LoRaWAN communication with the TTN (The Things Network) to be used with Arduino

# Features
* less braindamage trying to send data to the TTN
* can send data to the TTN...
* ABP & OTAA (though OTAA is WIP an may not work properly)
* send any datatype/struct (whose size is known at compile-time) to the TTN

# How to use
1. Clone the repo
2. Open the project in PlatformIO (arduino IDE may work, but you'll have to mess around with the platform.txt file)
3. Input your TTN keys and pin config into **Config.h**
4. Modify the example in **main.ino** to do whatever you want.
5. Profit 🥳🥳

# Has this abomination been tested?
...</br>
yes</br>
on a **DFDroid Firebeetle32** and a **Lilygo T-Beam (v1.2)**

# How do i get my pin config?
idk, google around took me ages to find working ones aswell. When in doubt look at the schematic of your board

# Notes
This lib won't be updated regularly or properly, it's part of the larger AQDar project. I'm just making this public so anyone looking to send data to the TTN doesn't have multiple brain aneurysms like me trying to figure this all out.