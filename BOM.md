## Bill of Materials (BOM)

### 1. Electronics

| Component | Specifications / Reference | Qty | Notes & Compatibility |
| :--- | :--- | :---: | :--- |
| **Arduino Nano** | ATmega328P microcontroller board | 1 | Runs [`color_pulse_arduino_code.ino`](Code/color_pulse_arduino_code/color_pulse_arduino_code.ino). Direct wire soldering is recommended to guarantee a reliable connection that will not come loose over time, though there is enough internal clearance to use Dupont jumper wires if preferred. |
| **Pushbuttons** | **Ø 7 mm** panel-mount momentary pushbutton (NO) | 5 | Threaded body (**Ø 7 mm**), supplied with mounting nut. 4 buttons are used for color inputs (Pins D3–D6) and 1 central button for Start (Pin D7). |
| **Toggle Switch** | **Ø 6 mm** panel-mount mini toggle switch (SPST or SPDT, ON/OFF) | 1 | Threaded body (**Ø 6 mm**), mounted on the side of the enclosure to cut the 9V battery positive (`VIN`) line. |
| **5 mm LEDs** | **Ø 5 mm** standard through-hole LEDs:<br>- 1× Red<br>- 1× Green<br>- 1× Yellow<br>- 1× Blue | 4 | Press-fitted into the top faceplate corners and secured with hot glue:<br>- Red: Pin D9<br>- Green: Pin D10<br>- Yellow: Pin D11<br>- Blue: Pin D12 |
| **Passive Buzzer** | **5V Passive** piezo buzzer (no internal oscillator) | 1 | Mounted under the top faceplate (Pin D8). Driven at specific musical frequencies using Arduino's `tone()` function. *(Note: Must be a passive buzzer without an internal oscillator; an active buzzer will not produce the varying game pitches).* |
| **Resistors** | Through-hole resistors (1/4W):<br>- **5× 10 kΩ**<br>- **1× 1 kΩ**<br>- **1× 220 Ω** | 7 | - **5× 10 kΩ:** External pull-down resistors for the 5 pushbuttons (Pins D3–D7).<br>- **1× 1 kΩ:** Inline current-limiting resistor for the passive buzzer (Pin D8).<br>- **1× 220 Ω:** Common current-limiting resistor on the shared LED cathode line (`GND`). |
| **9V Battery Connector** | Standard 9V (PP3) snap connector clip with lead wires | 1 | Red wire wired through the toggle switch to `VIN`; black wire connected to common `GND`. |
| **9V Battery** | *(Alkaline or Rechargeable 6LR61 / PP3 battery)* | *(1)* | *(Required to power and run the game once assembled)* |

> **Wiring & Schematic Reference:** For full pin-to-pin wiring details and inline resistor placement, refer to the wiring diagram in the `Media/` folder.

---

### 2. Hardware & Fasteners

| Component | Dimensions / Specifications | Qty | Usage |
| :--- | :--- | :---: | :--- |
| **M3 Machine Screws** | **M3 × 12 mm** Socket Head Cap Screws (CHC / DIN 912) | 4 | Fasten the enclosure from the outer side walls through `BOX` into the embedded nuts inside `TOP`. |
| **M3 Hex Nuts** | Standard **M3** Hex Nuts (DIN 934) | 4 | Inserted into the inner pockets of the `TOP` part and locked in place with a drop of hot glue. |
| **Panel Hardware** | Included with switches | 1 set | Hex mounting nuts used to secure the 5× Ø 7 mm pushbuttons and the 1× Ø 6 mm toggle switch onto the enclosure walls. |
| **Mounting, Insulation & Cable Management** | Hot glue and solder | As needed | Hot glue is used extensively inside the enclosure: fixing the LEDs, securing the buzzer, fastening the Arduino Nano and 9V battery inside the bottom shell (no molded brackets), locking the M3 hex nuts in their slots, fully insulating all exposed solder joints/inline resistors, and managing loose wiring. |

---

### 3. 3D-Printed Parts

The two enclosure parts below are the **only custom parts to be fabricated by the user**. 

The original parts were printed in **TPU 64D** to ensure high structural rigidity while remaining completely shock-resistant — an ideal choice for a portable, battery-powered handheld game. **More rigid filaments (such as PLA, PETG, or ABS) should also work in theory, although they have not been tested. Softer/more flexible filaments (below 64D) are strongly discouraged, as the enclosure will flex too much and internal components will not stay securely in place.**

| File | Qty | Notes |
| :--- | :---: | :--- |
| `BOX.3mf` | 1 | Bottom enclosure housing (has a cutout for the side toggle switch, with interior clearance to hot-glue the 9V battery and Arduino Nano). |
| `TOP.3mf` | 1 | Top control faceplate (features mounting holes for the 5 pushbuttons, 4 corner LEDs, internal mounting area for the buzzer, and side nut pockets for the 4× M3 nuts). |

---

### 4. Required Tools

| Tool | Usage |
| :--- | :--- |
| **Soldering Iron** | Soldering wires, inline resistors, switches, LEDs, buzzer, and Arduino connections. |
| **Wire Strippers & Flush Cutters** | Cutting and stripping electrical hook-up wires and trimming component leads. |
| **Hot Glue Gun** | Fastening components (Nano, battery, LEDs, buzzer), locking M3 nuts in place, potting/insulating bare solder joints, and cable management. |
| **2.5 mm Hex Key (Allen Wrench)** | Driving the 4× M3 × 12 mm socket head screws to secure the enclosure. |
| **Small Wrench / Pliers** | Tightening the mounting nuts on the Ø 7 mm pushbuttons and Ø 6 mm toggle switch. |
| **USB Cable (Mini-B or Type-C depending on your Nano board)** | Flashing [`color_pulse_arduino_code.ino`](Code/color_pulse_arduino_code/color_pulse_arduino_code.ino) onto the Arduino Nano. |
