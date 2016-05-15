
const int ledPin = 13; //sets ledPin to 13
const int light = A0; //sets analogPin as the input, connected to photoresistor

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(light, INPUT);
  Serial.begin(9600);
}
/*
  checks the voltage of the photoresistor analog pin, if it is high enough
  then it is dark so the device light turns on. If not then it turns the light
  off.
  It waits 1000ms after each check so a random low resistor value doesn't improperly
  knock out the light
*/
void loop() {
  if (lightSamples() < 20){
    digitalWrite(ledPin,HIGH); //turn light on when dark
  }else{
    digitalWrite(ledPin,LOW);  //turn light off when light
  }
  delay(1000); //wait before next sample
}
/*
  This takes 20 samples of the analog pin the photoresistor is connected to
  @return average analog pin value
*/
int lightSamples(){
    long unsigned int lightTotal = 0;
    int i = 0;    
    while(i < 20){ //take 20 samples of photoresistor
      lightTotal += analogRead(light); 
      //Serial.println(lightTotal);
    i++;
  }
  lightTotal = lightTotal / 20; //takes average of pin voltage
  Serial.println(lightTotal);
  return lightTotal;
}
