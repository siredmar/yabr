                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


https://www.thingiverse.com/thing:2350840
Balancing FPV Bot by bitwise is licensed under the Creative Commons - Attribution - Share Alike license.
http://creativecommons.org/licenses/by-sa/3.0/

# Summary

I'm  working on a 3D printable frame for a Balancing Robot.
Also i am going to add FPV to it, just because we can ! :D
This still is a work in progress.
Rims are done. ( 5mm dia. shaft with flattened side )
Put a piece of inner bike tube aroud the rims. 
Working on the frame.
I have build the bot with what i had laying around, could use smaller steppers.
These are Nema 17 steppers. Which fit this frame perfect.
 
The hardware and firmware where designed by Joop Brokking.
You can see his youtube vid here: 
https://www.youtube.com/watch?v=6WWqo-Yr8lA&google_comment_id=z13rvh5wokmixbwkh23ig3ooxtr5f5pg304

The only thing i want to change is the controller.
Joop made it with an Nintendo Wii controller, i 'd like to use a normal analog 2 axis joystick.
Also i want to make it controllable by an RC receiver.
I only changed the transmitter part of the code, not touching the firmware for the bot.
Also i'm going to write an PWM to BOT-Data Converter for the peolple who like to control the bot with their RC remotes. Code will be posted below the transmitter code when i have written it.
Here's the transmitter CoDe:

///////////////////////////////////////////////////////////////////////////////////////
// Balancing Bot Joystick Controller.
// Analog joystick connected to Pin A0 and A1
// Rewriten by Bitwise Operator - 29-5-2017
// Thanks to Joop Brokking for the original source
///////////////////////////////////////////////////////////////////////////////////////
#define JoyA_PIN A0
#define JoyB_PIN A1
int Joystick_A = 0;
int Joystick_B = 0;
int Joystick_A_Center = 520;
int Joystick_B_Center = 514;
int Joystick_A_DeadZone = 260;
int Joystick_B_DeadZone = 260;

void setup(){
    pinMode(JoyA_PIN, INPUT);
    pinMode(JoyB_PIN, INPUT);
    Serial.begin(9600);                                          //Start the serial port at 9600 kbps
    delay(20);                                                     //Short delay
}

void readJoystick(){
    Joystick_A = analogRead(JoyA_PIN);                  // Read analog Pins
    Joystick_B = analogRead(JoyB_PIN);                  // 
//    Serial.println(Joystick_A);                       // this can be used to check center value
//    Serial.println(Joystick_B);                       //  do not use serial comms for anything else but the second last line of the propgram. 
}

void loop(){
    readJoystick();
    send_byte = B00000000;                                            //Set the send_byte variable to 0
    if(Joystick_A < (Joystick_A_Center - (Joystick_A_DeadZone /2))) send_byte |= B00000001;
    if(Joystick_A > (Joystick_A_Center + (Joystick_A_DeadZone /2))) send_byte |= B00000010;
    if(Joystick_B < (Joystick_B_Center - (Joystick_B_DeadZone /2))) send_byte |= B00001000;
    if(Joystick_B > (Joystick_B_Center + (Joystick_B_DeadZone /2))) send_byte |= B00000100;
    if(send_byte) { 
        Serial.print((char)send_byte);                       //Send the send_byte variable if it's value is larger then 0
    }
    delay(40);                                                        //Create a 40 millisecond loop delay
}