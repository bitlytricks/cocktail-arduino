class Actor
{
    // Class Member Variables
    // These are initialized at startup
    int actorPin;      // the number of the actor pin


    // These maintain the current state
    int state;                 // ledState used to set the actor
    unsigned long previousMillis;   // will store last time actor was updated

    // Constructor - creates an Actor
    // and initializes the member variables and state
  public:
    long activeUntil;     // milliseconds of on-time

    Actor(int pin)
    {
      actorPin = pin;
      pinMode(actorPin, OUTPUT);
      digitalWrite(pin, LOW);
    }

    void activeFor(long onMillis) {
      if (onMillis > 0) {
        digitalWrite(actorPin, HIGH);
        activeUntil = millis() + onMillis;
      }
    }

    void tick()
    {
      long now = millis();
      if (activeUntil > 0 && now > activeUntil) {
        Serial.print(actorPin);
        Serial.print(" ");
        Serial.print(now);
        Serial.print(" ");
        Serial.print(activeUntil);
        Serial.print(" ");
        Serial.print("PIN tAKTUELL tABCHALT");
        Serial.print(" ");
        Serial.print("[SV");
        Serial.print(actorPin - 1);
        Serial.println("]");

        digitalWrite(actorPin, LOW);
        activeUntil = 0;
      }
    }
};
const int ACTORS = 16;
Actor actors[ACTORS] = { Actor(2), Actor(3), Actor(4), Actor(5), Actor(6), Actor(7), Actor(8), Actor(9), Actor(10), Actor(11), Actor(12), Actor(13), Actor(14), Actor(15), Actor(16), Actor(17) };

int bufferCount;    // Anzahl der eingelesenen Zeichen
char buffer[130];    // Serial Input-Buffer

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
}



void serialEvent() {
  char ch = Serial.read();
  buffer[bufferCount] = ch;
  bufferCount++;
  //ende der speicherung des gesendeten strings durch Carriage Return (CR)(13)
  if (ch == 13) {
    evalSerialData();
    printActors();
  }
}

void evalSerialData()
{
  //alternative Einlesemethode: einzeln:
  // >sv01=xxxx<  <-- Beispiel String
  switch (buffer[3]) {
    case 0:
      switch (buffer[4]) {
        case 0:
          break;
        case 1:
          long sv01 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 2:
          long sv02 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 3:
          long sv03 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 4:
          long sv04 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 5:
          long sv05 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 6:
          long sv06 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 7:
          long sv07 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 8:
          long sv08 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
        case 9:
          long sv09 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
          break;
      }
      break;
    case 0:
      long sv10 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
    case 1:
      long sv11 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
    case 2:
      long sv12 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
    case 3:
      long sv13 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
    case 4:
      long sv14 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
    case 5:
      long sv15 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
    case 6:
      long sv16 = buffer[6] * 1000 + buffer[7] * 100 + buffer[8] * 10 + buffer[9];
      break;
  }

  //Serial.println(buffer); >sv01=xx;sv02=xx;sv03=xx;sv04=xx;sv05=xx;sv06=xx;sv07=xx;sv08=xx;sv09=xx;sv10=xx;sv11=xx;sv12=xx;sv13=xx;sv14=xx;sv15=xx;sv16=xx< <<- Beispiel String
//  if ((buffer[0] == '>') && (buffer[bufferCount - 2] == '<')) { //erstes >und vorletztes < zeichen prüfen
//    bufferCount = 0;
//
//    long sv01 = (buffer[6] - 48) * 10000 + (buffer[7] - 48) * 1000 ; //dauer anschalten sv1 in var sv1 abspeichern
//    long sv02 = (buffer[14] - 48) * 10000 + (buffer[15] - 48) * 1000 ;
//    long sv03 = (buffer[22] - 48) * 10000 + (buffer[23] - 48) * 1000 ;
//    long sv04 = (buffer[30] - 48) * 10000 + (buffer[31] - 48) * 1000 ;
//
//    long sv05 = (buffer[38] - 48) * 10000 + (buffer[39] - 48) * 1000 ;
//    long sv06 = (buffer[46] - 48) * 10000 + (buffer[47] - 48) * 1000 ;
//    long sv07 = (buffer[54] - 48) * 10000 + (buffer[55] - 48) * 1000 ;
//    long sv08 = (buffer[62] - 48) * 10000 + (buffer[63] - 48) * 1000 ;
//
//    long sv09 = (buffer[70] - 48) * 10000 + (buffer[71] - 48) * 1000 ;
//    long sv10 = (buffer[78] - 48) * 10000 + (buffer[79] - 48) * 1000 ;
//    long sv11 = (buffer[86] - 48) * 10000 + (buffer[87] - 48) * 1000 ;
//    long sv12 = (buffer[94] - 48) * 10000 + (buffer[95] - 48) * 1000 ;
//
//    long sv13 = (buffer[102] - 48) * 10000 + (buffer[103] - 48) * 1000 ;
//    long sv14 = (buffer[110] - 48) * 10000 + (buffer[111] - 48) * 1000 ;
//    long sv15 = (buffer[118] - 48) * 10000 + (buffer[119] - 48) * 1000 ;
//    long sv16 = (buffer[126] - 48) * 10000 + (buffer[127] - 48) * 1000 ;


//Aktoren für gewählte Zeit anschalten
    actors[0].activeFor(sv01);
    actors[1].activeFor(sv02);
    actors[2].activeFor(sv03);
    actors[3].activeFor(sv04);
    actors[4].activeFor(sv05);
    actors[5].activeFor(sv06);
    actors[6].activeFor(sv07);
    actors[7].activeFor(sv08);
    actors[8].activeFor(sv09);
    actors[9].activeFor(sv10);
    actors[10].activeFor(sv11);
    actors[11].activeFor(sv12);
    actors[12].activeFor(sv13);
    actors[13].activeFor(sv14);
    actors[14].activeFor(sv15);
    actors[15].activeFor(sv16);

  }
}

void printActors() {
  for (int i = 0; i < ACTORS; i++) {
    Serial.print("Abschaltzeitpunkt SV");
    Serial.print(i + 1);
    Serial.print(" = ");
    Serial.print(actors[i].activeUntil);
    Serial.println(" ms");
  }

  Serial.println();
}

void loop() {

  if (Serial.available()) {
    serialEvent();
  }

  for (int i = 0; i < ACTORS; i++) {
    actors[i].tick();
  }
}
