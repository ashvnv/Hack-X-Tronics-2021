// C++ code
//
int people = 0;
int max2 = 3;
int ledPin = 13;                // LED 
int pirPin1 = 4;                 // PIR Out pin 
int pirPin2 = 8;
int pirStat1 = 0;                   // PIR status
int pirStat2 = 0;                   // PIR status
String sequence="";
int timeoutCounter = 0;
void setup() {
 pinMode(ledPin, OUTPUT);     
 pinMode(pirPin1, INPUT);
 pinMode(pirPin2, INPUT);     
 Serial.begin(9600);
}
void loop()
{	pirStat1 = digitalRead(pirPin1); 
    pirStat2 = digitalRead(pirPin2); 
 if(pirStat1 == HIGH  && sequence.charAt(0) != '1'){
    sequence += "1";
  }else if(pirStat2 == HIGH && sequence.charAt(0) != '2'){
    sequence += "2";
  }
  
  if(sequence.equals("12")){
    
    people = (people + 1);
    Serial.print(sequence);
    Serial.print("People inside:");
    Serial.println(people);
    sequence="";
    delay(550);
  }else if(sequence.equals("21") && people > 0){
	people = (people - 1);
    Serial.print(sequence);
    Serial.print("People inside");
    Serial.println(people);
    sequence="";
    delay(550);
  }

  //Resets the sequence if it is invalid or timeouts
  if(sequence.length() > 2 || sequence.equals("11") || sequence.equals("22") || timeoutCounter > 200){
    sequence="";  
  }

  if(sequence.length() == 1){ //
    timeoutCounter++;
  }else{
    timeoutCounter=0;
  }
  
  delay(500); // Wait for 500 millisecond(s)
  if (people >= max2) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}