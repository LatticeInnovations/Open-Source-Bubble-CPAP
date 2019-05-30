# Open-Source-Bubble-CPAP
This is an open source Bubble CPAP project
# This document is the chronological archive of the open bubble CPAP Design. It shows the working principle of the CPAP system

> ## Iteration 1:

>> This is the first proposed design. It includes industrial grade as well as readily available off-the-shelf materials. 

>>It consists of the basic fundamental parts of the system. I.e.

>> - Air compressor
>> - Flow meter
>> - Humidifier
>> - PEEP bottle
>> - Nasal prong

>>> ![Fig 1: Iteration 1 breathing circuit](https://raw.githubusercontent.com/LatticeInnovations/Open-Source-Bubble-CPAP/master/Images/Fig%201%20-%20Iteration%201%20circuit%20diagram.png)

> ## Iteration 2: 

>> Tests, observations and changes:

>> - Air compressor, alternative enclosure and hardware selection.
>> - Breathing circuit pressure validation: relation between PEEP submersion depth (cm), Flow rate(Lpm) and pressure (manometer reading)
>> - Pressure deviations between bubbling & non-bubbling humidifiers.
>> - Water filling and submersion depth control.

>>> ![Figure 2: Iteration 2 - Flow vs PEEP observed values](https://raw.githubusercontent.com/LatticeInnovations/Open-Source-Bubble-CPAP/master/Images/Fig%202%20-%20Iteration%202%20flow%20vs%20PEEP%20observed%20values.png)

>> ### Iteration 2.0

>>> Gas detection (NH4, CO, CO2, Propane etc.) to identify the reason of smell inside the breathing circuit. 
>>> Effect on humidity with variable surface area inside the humidifier to control humidification.

>> ### Iteration 2.1

>>> Breathing circuit leakage detection technique and results

>> ### Iteration 2.2

>>> Load testing for 3 days & observations on stability of the in-circuit humidification irrespective of ambient temperature & humidity >>> change.

> ## Iteration 3:

>> - Comparison with Pumani and experiments on rebreathing of CO2 in Open bubble CPAP.
>> - Humidifier water filling mechanism with ball valve.
>> - Load testing with the new humidifier setup, continuous run for more than 8 hours
>> - Comparison between looped vs unidirectional (separate inspiratory & expiratory limb) nasal prongs usage

>>> ![Figure 3: Iteration 3 - Humidification chamber modification](https://raw.githubusercontent.com/LatticeInnovations/Open-Source-Bubble-CPAP/master/Images/Fig%203%20-%20Iteration%203%20Humidification%20chamber%20modification.png)

> ## Iteration 4: 

>> - Humidifier selection revised. Medical grade commonly available bottle shaped humidifiers. 
>> - Alternate silicone tubing for the breathing circuit. (ID-8mm, OD-12 mm)
>> - It has advantage of compatibility with a wide range of tube connectors.
>> - Oxygen blending feature addition in CPAP.
>> - 3-Flow-Meter method in contrast with existing pumani 2 FM design.
>> - Oxygen cylinder valve comparison and operating pressure levels selection.

>>> ![Figure 4: Iteration 4 - Iteration 4 - Breathing Circuit](https://raw.githubusercontent.com/LatticeInnovations/Open-Source-Bubble-CPAP/master/Images/Fig%204%20-%20Iteration%204%20Circuit%20Diagram.png)
***
## Development of OpenSource and affordable bubble CPAP system for neonatal respiratory care

.
#### Introduction:

Preterm infants commonly suffer from a respiratory/breathing disorder called neonatal respiratory distress syndrome (RDS) as their lungs are not yet fully developed. The disease is mainly caused by a lack of a slippery substance in the lungs called surfactant that helps the lungs fill with air and keeps the air sacs from deflating. The surfactant is present when the lungs are fully developed. Neonates suffering from RDS often need breathing support until their lungs start making enough surfactant. 

Continuous positive airway pressure (CPAP) as a therapy for respiratory distress syndrome, is the application of positive pressure to the airways of spontaneously breathing neonates throughout their respiratory cycle.

#### Aim:

Conventional CPAP is very expensive and hence not affordable in resource-constrained settings. Locally available hardware such as low-cost plastic bottles, tubing, connectors and air pumps are used in this design to develop an affordable and modular Bubble CPAP device. With the modular CPAP approach, we intend to locally train more people on how to develop and troubleshoot CPAP devices. 

#### Purpose of usage:
- Maintaining both breathing parameters i.e. the volume and the pressure of the inhaled gas to the lungs in order to prevent lung collapse among RDS affected neonates/patients.
- To make sure that the prescribed level of oxygen is supplied to the patient through the air/O2 mixture so that it can take part in the gas exchange process in the alveoli.
- Helping the patient breath by reducing the work of breathing.

### How to use this document: 

This opensource DIY design of this bubble CPAP is module driven. The entire design is divided into three segments: 

** 1. Base Design: **
This is the bare minimum design of the Bubble CPAP system and it represents the updated design guidelines of the latest design iterations.

** 2. Optional Add-ons: **
This section of the document includes all the additional hardware 

** 3. Material Specifications & Testing Protocols:**
In this section, hardware materials, test procedures and outputs are discussed. 

** The idea of the development process is: **
- To build a working CPAP device using the most commonly used & readily available resources.
- To shrink the base design while retaining the robustness, reliability and functionality of the system so that it can be used as a standalone bare minimum design.
- To include more resources, features and test cases in the Optional Add-ons & Testing protocols segments so that it can be further developed with different design approaches.

#### Features and specifications:

    • Flow rate: 1 to 10 lpm
    • PEEP: equivalent to 1 to 10 cm of water column
    • Power input: 220v, 50Hz (inpun is air compressor dependant and entirely flexible)
    • HME filtration (optional) for particulate free clean air.
    • Both valve regulated or disposable humidifier can be used for easy access
    • 3-flowmeter design for better air-oxygen blending and control of the total flow. 
    • Can be built from scratch & easily accessible off-the-shelf components based desig.
    • Max pressure for O2 cylinder interface: 5 PSI
