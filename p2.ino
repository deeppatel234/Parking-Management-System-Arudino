int sensor1Port = 3;
int sensor2Port = 4;
int sensor3Port = 5;
int sensor4Port = 6;

int EntryGateSensor1 = 8;
int EntryGateSensor2 = 9;
int ExitGateSensor1 = 10;
int ExitGateSensor2 = 11;

int FullParkingLED = 7;

int GroundFloorLED1 = A0;
int GroundFloorLED2 = A1;
int EntryGateLED = 12;
int ExitGateLED = 13;

int Sensor1Maintenance=A2;
int Sensor2Maintenance=A3;
int Sensor3Maintenance=A4;
int Sensor4Maintenance=A5;

int Sensor1Temp = 0;
int Sensor2Temp = 0;
int Sensor3Temp = 0;
int Sensor4Temp = 0;

int EntryGateSensor1Temp = 0;
int EntryGateSensor2Temp = 0;

int ExitGateSensor1Temp = 0;
int ExitGateSensor2Temp = 0;

int FullTemp = 0;
int FullCount = 0;
int FullMaxValue = 4;

int FullCountSendValue = 0;
int FullMaxValueSendValue = 0;

int Sensor1on = 0;
int Sesnor2on = 0;
int Sensor3on = 0;
int Sesnor4on = 0;

int ManualyEntryGate = 0;
int ManualyExitGate = 0;


int Sensor1MaintenanceTemp = 0;
int Sensor2MaintenanceTemp = 0;
int Sensor3MaintenanceTemp = 0;
int Sensor4MaintenanceTemp = 0;

int INFromAPPData;


void setup() {

 pinMode(sensor1Port,INPUT);
 pinMode(sensor2Port,INPUT);
 pinMode(sensor3Port,INPUT);
 pinMode(sensor4Port,INPUT);
 
 pinMode(EntryGateSensor1,INPUT);
 pinMode(EntryGateSensor2,INPUT);
 
 pinMode(ExitGateSensor1,INPUT);
 pinMode(ExitGateSensor2,INPUT);
 

 pinMode(GroundFloorLED1,OUTPUT);
 pinMode(GroundFloorLED2,OUTPUT);
 pinMode(EntryGateLED,OUTPUT);
 pinMode(ExitGateLED,OUTPUT);
 
 pinMode(FullParkingLED,OUTPUT);
 
 Serial.begin(9600);
}


void loop() {

    FullCountSendValue = FullCount;
    FullMaxValueSendValue = FullMaxValue;

    if(Sensor1MaintenanceTemp == 0)
    {
    		// Sensor 1 Code 
      		if( digitalRead(sensor1Port) == HIGH)
        	{
                if(Sensor1Temp == 1)
                {
                    Serial.println("Sensor1-ON");
                    Sensor1on = 1;
                    Sensor1Temp = 0;
                }
    		  }
          else
          {
                if(Sensor1Temp == 0 )
                {
                    Serial.println("Sensor1-OFF");
                    Sensor1on = 0;
                    Sensor1Temp = 1;
                }
          }
     }

      if(Sensor2MaintenanceTemp == 0)
      {
          // Sensor 2 Code 
          if( digitalRead(sensor2Port) == HIGH )
        	{
                if(Sensor2Temp == 1)
                {
                    Serial.println("Sensor2-ON");
                    Sesnor2on = 1;
                    Sensor2Temp = 0;
                }
    		  }
          else
          {
                if(Sensor2Temp == 0 )
                {
                    Serial.println("Sensor2-OFF");
                    Sesnor2on = 0;
                    Sensor2Temp = 1;
                }
          }
      }

      if(Sensor3MaintenanceTemp == 0)
      {
          // Sensor 3 Code 
          if( digitalRead(sensor3Port) == HIGH )
        	{
                if(Sensor3Temp == 1)
                {
                    Serial.println("Sensor3-ON");
                    Sensor3on = 1;
                    Sensor3Temp = 0;
                }
    		   }
           else
           {
                if(Sensor3Temp == 0 )
                {
                    Serial.println("Sensor3-OFF");
                    Sensor3on = 0;
                    Sensor3Temp = 1;
                }
           }
       }

    if(Sensor4MaintenanceTemp == 0)
    {
      		// Sensor 4 Code 
            if( digitalRead(sensor4Port) == HIGH )
          	{
                  if(Sensor4Temp == 1)
                  {
                      Serial.println("Sensor4-ON");
                      Sesnor4on = 1;
                      Sensor4Temp = 0;
                  }
      		  }
            else
            {
                  if(Sensor4Temp == 0 )
                  {
                      Serial.println("Sensor4-OFF");
                      Sesnor4on = 0;
                      Sensor4Temp = 1;
                  }
            }
     }

    if(Sesnor4on== 0 || Sensor1on==0)
    {
       digitalWrite(GroundFloorLED1,HIGH);
    }
    else
    {
      digitalWrite(GroundFloorLED1,LOW);
    }

    if(Sesnor2on== 0 || Sensor3on==0)
    {
      digitalWrite(GroundFloorLED2,HIGH);
    }
    else
    {
      digitalWrite(GroundFloorLED2,LOW);
    }

		if(FullCount >= FullMaxValue)
		{
    			if(FullTemp == 0)
    			{
    				digitalWrite(FullParkingLED,HIGH);
    				FullTemp = 1;
    			}
		}
		else
		{
          FullTemp = 0;
    			digitalWrite(FullParkingLED,LOW);
		}


    if(ManualyEntryGate == 0)
    {
        if(FullCount < FullMaxValue)
        {
            // Entry Gate Sensor 1 Code 
            if( digitalRead(EntryGateSensor1) == HIGH )
            {
                 if(EntryGateSensor1Temp == 0)
                 {
                     Serial.println("EntryGateOpen-ON");
                     digitalWrite(EntryGateLED,HIGH);
                     EntryGateSensor1Temp = 1;
                 }
        		}
        		else
        		{
        			  EntryGateSensor1Temp = 0;
        		}
    
           // Entry Gate Sensor 2 Code 
           if( digitalRead(EntryGateSensor2) == HIGH )
           {
                  if(EntryGateSensor2Temp == 0)
                  {
                      FullCount++;
                      Serial.println("EntryGateClosed-ON");
                      digitalWrite(EntryGateLED,LOW);
                      EntryGateSensor2Temp = 1;
                  }
            }
            else
            {
              EntryGateSensor2Temp = 0;
            }
        }
        else
        {
           FullCount = FullMaxValue;
        }
    }
		
    if(ManualyExitGate == 0)
    {
       		// Exit Gate Sensor 1 Code 
          if( digitalRead(ExitGateSensor1) == HIGH )
          {
                  if(ExitGateSensor1Temp == 0)
                  {
                      Serial.println("ExitGateOpen-ON");
                      digitalWrite(ExitGateLED,HIGH);
                      ExitGateSensor1Temp = 1;
                  }
      		}
      		else
      		{
      			ExitGateSensor1Temp = 0;
      		}
      
      		// Exit Gate Sensor 2 Code 
          if( digitalRead(ExitGateSensor2) == HIGH )
          {
                  if(ExitGateSensor2Temp == 0)
                  {
                  	  FullCount--;
                      Serial.println("ExitGateClosed-ON");
                      digitalWrite(ExitGateLED,LOW);
                      ExitGateSensor2Temp = 1;
                  }
      		}
      		else
      		{
      			ExitGateSensor2Temp = 0;
      		}
      
      
          if(FullCount < 0)
          {
            FullCount = 0;
          }
    }
    
  if(Serial.available() > 0)
  {
    if(Serial.peek() == 'G')
    {
      Serial.read();
      INFromAPPData = Serial.parseInt();

      if(INFromAPPData == 10)
      {
        ManualyEntryGate = 1;
        digitalWrite(EntryGateLED,HIGH);
      }

      else if(INFromAPPData == 11)
      {
        ManualyEntryGate = 0;
        digitalWrite(EntryGateLED,LOW);
      }

      else if(INFromAPPData == 20)
      {
        ManualyExitGate = 1;
        digitalWrite(ExitGateLED,HIGH);
      }

      else if(INFromAPPData == 21)
      {
        ManualyExitGate = 0;
        digitalWrite(ExitGateLED,LOW);
      }
    }
    if(Serial.peek() == 'S')
    {
      Serial.read();
      INFromAPPData = Serial.parseInt();
      
      if(INFromAPPData == 10)
      {
        Sensor1MaintenanceTemp = 1;
        digitalWrite(Sensor1Maintenance,HIGH);
        FullMaxValue--;
      }
      else if(INFromAPPData == 11)
      {
        Sensor1MaintenanceTemp = 0;
        digitalWrite(Sensor1Maintenance,LOW);
        FullMaxValue++;
      } 
      
      else if(INFromAPPData == 20)
      {
        Sensor2MaintenanceTemp = 1;
        digitalWrite(Sensor2Maintenance,HIGH);
        FullMaxValue--;
      }
      else if(INFromAPPData == 21)
      {
        Sensor2MaintenanceTemp = 0;
        digitalWrite(Sensor2Maintenance,LOW);
        FullMaxValue++;
      }

      else if(INFromAPPData == 30)
      {
        Sensor3MaintenanceTemp = 1;
        digitalWrite(Sensor3Maintenance,HIGH);
        FullMaxValue--;
      }
      else if(INFromAPPData == 31)
      {  
        Sensor3MaintenanceTemp = 0;
        digitalWrite(Sensor3Maintenance,LOW);
        FullMaxValue++;
      }

      else if(INFromAPPData == 40)
      {
        Sensor4MaintenanceTemp = 1;
        digitalWrite(Sensor4Maintenance,HIGH);
        FullMaxValue--;
      }
      else if(INFromAPPData == 41)
      {
        Sensor4MaintenanceTemp = 0;
        digitalWrite(Sensor4Maintenance,LOW);
        FullMaxValue++;
      }
    }
  }

    if(FullCountSendValue != FullCount)
    {
      Serial.print("CarCount-");
      Serial.print(FullCount);
      Serial.println();
    }
    
    if(FullMaxValueSendValue != FullMaxValue)
    {
      Serial.print("FULLCount-");
      Serial.print(FullMaxValue);
      Serial.println();
    }  
}
