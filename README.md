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





