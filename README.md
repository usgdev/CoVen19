# CoVen19
Project CoVen19 is breathing ventilator developed using standard supply already available in market easily, can be manufactured in large quantities with lowest possible resources in pandemic scenario.

![CoVen19](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/CoVen19_render.png)

# Current Development Version CoVen19 v0.7
CoVen19 v0.7 has following changes/updates as per latest commits:
- [x] DIY Actuator Assembly 2D DXF files Included
- [ ] Arduino UNO Firmware .ino file release(Source Code v0.7)
- [ ] Wiring schematics release(v0.7)
- [x] Updated 3D files in .STL file release
- [x] Simplified enclosure assembly design
- [x] Fixed Enclosure assembly Tab and Slot clearance
- [x] Updated BOM release in .xlsx file(v0.7)
- [x] Components reference images included

# Pandemic Ventilator Design Guideline
This is a specification of the minimally (and some preferred options) clinically acceptable ventilator to be
used in UK hospitals during the current SARS-CoV2 outbreak. It sets out the clinical requirements based on the consensus of what is ‘minimally acceptable’ performance in the opinion of the anaesthesia and intensive care medicine professionals and medical device regulators...Read more on official page https://www.gov.uk/government/publications/coronavirus-covid-19-ventilator-supply-specification/rapidly-manufactured-ventilator-system-specification

# Pandemic Ventilator Design Challenge
[![CoVen19 Design Challenge](https://img.youtube.com/vi/7vLPefHYWpY/0.jpg)](https://www.youtube.com/watch?v=7vLPefHYWpY)


# What is PEEP? How to Deal with it!
## Graphics Content Warning: Demonstration video using body parts! Welcome to real medical world!
[![What is PEEP](https://img.youtube.com/vi/Gu4sChU9eBo/0.jpg)](https://www.youtube.com/watch?v=Gu4sChU9eBo)

# How BVM(Bag Valve Mask), PEEP Valves and Diverters works?

[![CoVen19 How BVM Works?](https://img.youtube.com/vi/Douv4EPk_jA/0.jpg)](https://www.youtube.com/embed/Douv4EPk_jA)

# Source Code
### [Please find full source code here for v0.7](https://github.com/USGDEV/CoVen19/tree/master/SOURCE/Arduino/CoVen19_release_v0.7)

```C++

//Ventilator code 
//Version 1.0.0

//Breath Cycle parameters
int Inhalation_time_set[] = {1500, 1380, 1290, 1200, 1130, 1060, 1000, 950, 900}; //in milli seconds
int current_Inhalation_time = Inhalation_time_set[0];
const int current_Hold_Pause_time = 300; //Hold time does not change ever
int Exhalation_time_set[] = {3200, 2930, 2700, 2500, 2330, 2170, 2030, 1910, 1800}; //in milli seconds
int current_Exhalation_time = Exhalation_time_set[0];

//Air Volume control potentiometer parameters
int Actuator_displacement[] = {20, 40, 60, 80, 100}; //in mm
int corrent_Actuator_displacement = Actuator_displacement[0];

//Debug variables
boolean debug_output = true; //If false no serial output, to see output on serial true it


//Pin Definations
const int POT_BTH = A0;
const int POT_AVC = A1;



//Motor Related
//define Pins
int Step   =  6;
int Dir    =  7;
int MS1    =  4;
int MS2    =  5;

//define variables
int   direction        = 0;      //direction is either "0" or "1" to choose direction
float cycle            = 1;      //cycle can be in decimal 1 is 360 rotation and 0.5 is 180 degree
float time_for_cycles  = 0;      //time for total cycle is in milisecond so it can be in decimal

int   SelectResolution = 0;      //Resolution table given below
int   StepsPerRevo     = 0;

```

# Enclosure
Enclosure design based on laser cutting of 5mm acrylic or pvc sheet, normally available easily in market. 5mm sheet cutting is quick and sturdiness will be good enough to hold ventilator assembly all together, enclosure is essential to handle the ventilator without damaging internal parts.

### [Here is DXF 2D files provided for laser cutting v0.7](https://github.com/USGDEV/CoVen19/tree/master/CoVen19_v0.7/DXF)
![CoVen19 Enclosure](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/all_parts_laser_cut_v0.7.jpg)
![CoVen19 Enclosure](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/CoVen19_enclosure_look.png)

No. | ID | DXF File Name
------------ | ------------- | -------------
1 | EN01 | side_enclosure_right.DXF
2 | EN02 | side_enclosure_left.DXF
3 | EN03 | body_base_plate.DXF
4 | EN01 | body_enclosure_cover.DXF
5 | EN05 | nema_mount_plate.DXF
6 | EN06 | ambubag_air_release_plate.DXF
7 | EN07 | electronics_mount_panel.DXF
8 | EN08 | actuator_arm_left.DXF
9 | EN09 | actuator_arm_right.DXF
10 | EN10 | body_handle_plate.DXF
11 | EN11 | actuator_support_plate.DXF
12 | EN12 | pressure_plate_sloted.DXF
13 | EN13 | body_safety_plate.DXF
14 | EN14 | nut_connector_plate.DXF
    
# Components Used

![CoVen19 Enclosure](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/CoVen19_parts_v0.7.jpg)

No. | ID | Part Name | Ref Links/Remarks
------------ | ------------ | ------------- | -------------
1 | PT01 | Arduino UNO R3 | https://store.arduino.cc/usa/arduino-uno-rev3
2 | PT02 | SparkFun EasyDriver | https://www.sparkfun.com/products/12779
3 | PT03 | 12v Power Supply | https://www.amazon.com/MEAN-WELL-RD-65A-Output-Enclosed/dp/B005T7EZM8/
4 | PT04 | NEMA 17 Motor | Link
5 | PT05 | 5mmX8mm Coupler | Link
6 | PT06 | 8mmX100mm Lead Screw | Link
7 | PT07 | OLED 128X64 Display | Link
8 | PT08 | 100K Potentiometer | Link
9 | PT09 | Rocker Switch | Link
10 | PT10 | BVM Ambubag 350~450ml | Link
11 | PT11 | Jumper Wires | Link
12 | PT12 | PCB Self Adhesive Mounts | Link
13 | PT13 | M3X8mm Nema Mount Screw | Link
14 | PT14 | M3X10mm Bracket Nut-Bolt | Link
15 | PT15 | 90 Degree Brackets | Link

## Detailed BOM for v0.7 can be found [HERE](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/BOM/CoVen19_BOM_v0.7_r1.xlsx).

## Important Note:
**Above listed links are just for reference, You can buy components from any where you wish to.**

# Testing Equipments (Not a Part of CoVen19)
You can get a testing lungs that mimics some functions of human lung for testing your ventilator, [here is example link.](https://www.amazon.com/gp/product/B0767RBQ1H)





