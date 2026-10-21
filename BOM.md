## Bill of Materials (BOM)

### 1. Electronics

| Component | Specifications / Reference | Qty | Notes & Compatibility |
| :--- | :--- | :---: | :--- |
| **Arduino Nano** | ATmega328P microcontroller board | 1 | Runs [`color_pulse_arduino_code.ino`](color_pulse_arduino_code.ino). Direct wire soldering is recommended to guarantee a reliable connection that will not come loose over time, though there is enough internal clearance to use Dupont jumper wires if preferred. |
| **Pushbuttons** | **Ø 7 mm** panel-mount momentary pushbutton (NO) | 5 | Threaded body (**Ø 7 mm**), supplied with mounting nut. 4 buttons are used for color inputs (Pins D3–D6) and 1 central button for Start/Reset (Pin D7). |
| **Toggle Switch** | **Ø 6 mm** panel-mount mini toggle switch (SPST or SPDT, ON/OFF) | 1 | Threaded body (**Ø 6 mm**), mounted on the side of the enclosure to cut the 9V battery positive (`VIN`) line. |
| **5 mm LEDs** | **Ø 5 mm** standard through-hole LEDs:<br>- 1× Red<br>- 1× Green<br>- 1× Yellow<br>- 1× Blue | 4 | Press-fitted into the top faceplate corners and secured with hot glue:<br>- Red: Pin D9<br>- Green: Pin D10<br>- Yellow: Pin D11<br>- Blue: Pin D12 |
| **Passive Buzzer** | **5V Passive** piezo buzzer (no internal oscillator) | 1 | Mounted under the top faceplate (Pin D8). Driven at specific musical frequencies via the Arduino `tone()` function. |
| **Resistors (10 kΩ)** | **10 kΩ**, 1/4W through-hole resistors | 5 | Pull-down resistors for the 5 pushbuttons (wired between Pins D3–D7 and `GND`). |
| **Resistor (1 kΩ)** | **1 kΩ**, 1/4W through-hole resistor | 1 | Current-limiting resistor wired in series with the passive buzzer (Pin D8). |
| **Resistor (220 Ω)** | **220 Ω**, 1/4W through-hole resistor | 1 | Shared current-limiting resistor wired on the common cathode (`GND`) return line of the 4 LEDs. |
| **9V Battery Clip** | Standard 9V snap connector with 2 wire leads | 1 | Soldered to the toggle switch / Arduino `VIN` and `GND`. |
| **9V Battery** *(optional)* | *(Standard 9V 6LR61 / PP3 battery)* | *(1)* | *(Not required to build the project, but needed to power and run the game autonomously).* |
| **Cables & Wiring** | - Electrical hook-up wires (for internal point-to-point soldering)<br>- *(USB Mini-B or USB-C cable, depending on your Nano board, for initial code upload)* | 1 set | Internal wiring according to the wiring diagram. |

> **Important Note on the Buzzer:** Make sure to use a **passive** buzzer (without an built-in oscillator) and **not** an active buzzer. The game relies on the Arduino's `tone()` function to generate distinct musical notes for each color (262 Hz, 330 Hz, 392 Hz, 523 Hz) as well as victory and game-over melodies.

---

### 2. Hardware & Fasteners

| Component | Dimensions / Specifications | Qty | Usage |
| :--- | :--- | :---: | :--- |
| **M3 Machine Screws** | **M3 × 12 mm** (Socket Head Cap Screws) | 4 | Inserted through the side holes of the enclosure to lock the `BOX` and `TOP` parts together. |
| **M3 Hex Nuts** | **M3** standard hex nuts | 4 | Inserted into the 4 internal nut traps located under the `TOP` faceplate. |
| **Panel Switch Fasteners** | Included with the pushbuttons and toggle switch | 1 set | Hex mounting nuts used to secure the 5× Ø 7 mm pushbuttons and the 1× Ø 6 mm toggle switch onto the enclosure. |
| **Mounting, Insulation & Cable Management** | Hot glue and solder | As needed | Hot glue is used extensively inside the enclosure to hold the LEDs, buzzer, Arduino Nano, and 9V battery in place, to fully encase and insulate exposed solder joints/resistors, and to keep internal wiring secure. |

---

### 3. 3D-Printed Parts

The two enclosure parts below are the **only custom parts to be fabricated by the user**. 

The original parts were printed in **TPU 64D** to ensure high structural rigidity while remaining completely shock-resistant — an ideal choice for a portable, battery-powered handheld game. **More rigid filaments (such as PLA, PETG, or ABS) should also work in theory, although they have not been tested. Softer/more flexible filaments (below 64D) are strongly discouraged, as the enclosure will flex too much and internal components will not stay securely in place.**

| File | Qty | Notes |
| :--- | :---: | :--- |
| `BOX.3mf` | 1 | Bottom enclosure housing (features dedicated internal slots for the 9V battery, Arduino Nano, and side toggle switch). |
| `TOP.3mf` | 1 | Top control faceplate (features cutouts for the 5 pushbuttons, 4 corner LEDs, internal buzzer slot, and 4× M3 nut traps). |

---

### 4. Required Tools

| Tool | Usage |
| :--- | :--- |
| **Soldering Iron** | Soldering wires, inline resistors, switches, LEDs, buzzer, and Arduino connections. |
| **Wire Strippers & Flush Cutters** | Cutting and stripping the electrical hook-up wires and trimming component leads. |
| **Hot Glue Gun** | Securing components, potting/insulating exposed solder joints, and cable management. |
| **Hex Key (Allen Wrench)** | Driving the 4× M3 × 12 mm screws to close the enclosure. |
| **Small Wrench / Pliers** | Tightening the mounting nuts on the Ø 7 mm pushbuttons and Ø 6 mm toggle switch. |
