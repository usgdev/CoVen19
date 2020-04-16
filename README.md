# CoVen19
Project CoVen19 is breathing ventilator developed using standard supply already available in market easily, can be manufactured in large quantities with lowest possible resources in pandemic scenario.

![CoVen19](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/CoVen19_v0.7_01.JPG)

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
### [Please find full source code here for v0.5](https://github.com/USGDEV/CoVen19/tree/master/SOURCE/Arduino/CoVen19_release_v0.7)

```C++

//Forward/reverse stepping function
void ForwardBackwardStep()
{
  Serial.println("Alternate between stepping forward and reverse.");
  for(x= 1; x<5; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    //Read direction pin state and change it
    state=digitalRead(dir);
    if(state == HIGH)
    {
      digitalWrite(dir, LOW);
    }
    else if(state ==LOW)
    {
      digitalWrite(dir,HIGH);
    }

    for(y=0; y<1000; y++)
    {
      digitalWrite(stp,HIGH); //Trigger one step
      delay(1);
      digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
      delay(1);
    }
  }
  Serial.println("Enter new option:");
  Serial.println();
}

```

# Enclosure
Enclosure design based on laser cutting of 5mm acrylic or pvc sheet, normally available easily in market. 5mm sheet cutting is quick and sturdiness will be good enough to hold ventilator assembly all together, enclosure is essential to handle the ventilator without damaging internal parts.

### [Here is DXF 2D files provided for laser cutting v0.7](https://github.com/USGDEV/CoVen19/tree/master/CoVen19_v0.7/DXF)

![CoVen19 Enclosure](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/all_parts_laser_cut_v0.7.jpg)

Sr.No. | DXF File Name | ID
------------ | ------------- | -------------
1 | actuator_arm_left.DXF | EN01

1. | actuator_arm_left.DXF | EN01
2. actuator_arm_right.DXF
3. actuator_support_plate.DXF
4. ambubag_air_release_plate.DXF
5. body_base_plate.DXF
6. body_enclosure_cover.DXF
7. body_handle_plate.DXF
8. body_safety_plate.DXF
9. electronics_mount_panel.DXF
10. nema_mount_plate.DXF
11. nut_connector_plate.DXF
12. pressure_plate_sloted.DXF
13. side_enclosure_left.DXF
14. side_enclosure_right.DXF
    
# Components Used

Component Name | Ref Links
------------ | -------------
NEMA LGA42 Motor | https://us.nanotec.com/products/2782-lga421s14-a-uiev-038/
Arduino UNO r3 | https://store.arduino.cc/usa/arduino-uno-rev3
SparkFun EasyDriver | https://www.sparkfun.com/products/12779
Generic Power Supply | https://www.amazon.com/MEAN-WELL-RD-65A-Output-Enclosed/dp/B005T7EZM8/
Ambu Bag (BVM) | https://www.amazon.com/Adult-Simple-Breathing-Apparatus-Kit/dp/B085ZLVMZ3/
Mains Power Supply Cable | https://www.secomp-international.com/en_US/roline-power-cable-with-schuko-connector-open-end-ac-230v-bl/i/19.08.1111-10
OLED Display | https://www.amazon.com/dp/B00O2LLT30
Rotary Potentiometer | https://www.amazon.in/pack-potentiometer-single-variable-resistor/dp/B07L3YQ4NT
Black Metal Knob | https://www.sparkfun.com/products/10002
Rocker Switch | https://www.sparkfun.com/products/8837
M3 Screw 8mm | https://www.amazon.com/dp/B01IWUSDYY and https://www.amazon.com/uxcell-M3x8mm-Thread-Button-Socket/dp/B01B1OD62C
90 Degree Bracket Joint | https://www.ebay.com/itm/90-Degree-Right-Angle-Stainless-Steel-Support-Shelf-Bracket-Joint-Corner-Brace-/183693072726
Acrylic sheet | https://www.amazon.com/dp/B07MWXWDKQ


### Important Note:
**Above listed links are just for reference, You can buy components from any where you wish to.**

# Testing Equipments (Not a Part of CoVen19)
You can get a testing lungs that mimics some functions of human lung for testing your ventilator, [here is example link.](https://www.amazon.com/gp/product/B0767RBQ1H)

# Components

![CoVen19 Enclosure](https://github.com/USGDEV/CoVen19/blob/master/CoVen19_v0.7/Images/CoVen19_parts_v0.7.jpg)


