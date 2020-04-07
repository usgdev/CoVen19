# CoVen19
Project CoVen19 is breathing ventilator developed using standard supply already available in market easily, can be manufactured in large quantities with lowest possible resources in pandemic scenario.

![CoVen19](https://github.com/USGDEV/CoVen19/blob/master/Images/CoVen19_v0.5_01.JPG)

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
## Eaxample Source Code for Arduino UNO

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
