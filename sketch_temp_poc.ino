#define tempSensor A0
#define lightSensor A1

String dataLabel1 = "Temperatura";
String dataLabel2 = "Luminosidade";
bool label = true;

int data1, data2, curr1, curr2;

float percent = 0.05;
int threshold = 1024 * percent;
unsigned long timer;
unsigned long previousTimer;
int freq = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  timer = millis();
  while(label) {
    Serial.print(dataLabel1);
    Serial.print(",");
    Serial.println(dataLabel2);
    label = false;
  }

  data1 = analogRead(tempSensor);
  data2 = analogRead(lightSensor);

  if(timer - previousTimer > 5000) {
    previousTimer += 5000;
    Serial.print(data1);
    Serial.print(",");
    Serial.println(data2);
    curr1 = data1;
    curr2 = data2;
  }
}
