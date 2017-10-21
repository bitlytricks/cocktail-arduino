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
Actor actors[ACTORS] = { Actor(2), Actor(3), Actor(4), Actor(5), Actor(6), Actor(7), Actor(8), Actor(9), Actor(14), Actor(15), Actor(16), Actor(17), Actor(18), Actor(19), Actor(20), Actor(21) };

int bufferCount;    // Anzahl der eingelesenen Zeichen
char buffer[164];    // Serial Input-Buffer

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  Serial.print("ready");
  Serial.print("here i come");
  
}



void serialEvent() {
  char ch = Serial.read();
  Serial.write(ch);
  buffer[bufferCount] = ch;
  bufferCount++;
  //ende der speicherung des gesendeten strings durch Carriage Return (CR)(13)
  if (ch == 13) {
    evalSerialData();
    // printActors();
  }
}

void evalSerialData()
{
  // Serial.println(buffer); 
  // >sv01=xxxx;sv02=xxxx;sv03=xxxx;sv04=xxxx;sv05=xxxx;sv06=xxxx;sv07=xxxx;sv08=xxxx;sv09=xxxx;sv10=xxxx;sv11=xxxx;sv12=xxxx;sv13=xxxx;sv14=xxxx;sv15=xxxx;sv16=xxxx< <<- Beispiel String
  if ((buffer[0] == '>') && (buffer[bufferCount - 2] == '<')) { //erstes >und vorletztes < zeichen prüfen
    bufferCount = 0;

    long sv01 = (buffer[6] - 48) * 1000 + (buffer[7] - 48) * 100 + (buffer[8] - 48) * 10 + (buffer[9] - 48) * 1 ; //dauer anschalten sv1 in var sv1 abspeichern
    long sv02 = (buffer[16] - 48) * 1000 + (buffer[17] - 48) * 100 + (buffer[18] - 48) * 10 + (buffer[19] - 48) * 1 ;
    long sv03 = (buffer[26] - 48) * 1000 + (buffer[27] - 48) * 100 + (buffer[28] - 48) * 10 + (buffer[29] - 48) * 1 ;
    long sv04 = (buffer[36] - 48) * 1000 + (buffer[37] - 48) * 100 + (buffer[38] - 48) * 10 + (buffer[39] - 48) * 1 ;

    long sv05 = (buffer[46] - 48) * 1000 + (buffer[47] - 48) * 100 + (buffer[48] - 48) * 10 + (buffer[49] - 48) * 1 ; //dauer anschalten sv1 in var sv1 abspeichern
    long sv06 = (buffer[56] - 48) * 1000 + (buffer[57] - 48) * 100 + (buffer[58] - 48) * 10 + (buffer[59] - 48) * 1 ;
    long sv07 = (buffer[66] - 48) * 1000 + (buffer[67] - 48) * 100 + (buffer[68] - 48) * 10 + (buffer[69] - 48) * 1 ;
    long sv08 = (buffer[76] - 48) * 1000 + (buffer[77] - 48) * 100 + (buffer[78] - 48) * 10 + (buffer[79] - 48) * 1 ;

    long sv09 = (buffer[86] - 48) * 1000 + (buffer[87] - 48) * 100 + (buffer[88] - 48) * 10 + (buffer[89] - 48) * 1 ; //dauer anschalten sv1 in var sv1 abspeichern
    long sv10 = (buffer[96] - 48) * 1000 + (buffer[97] - 48) * 100 + (buffer[98] - 48) * 10 + (buffer[99] - 48) * 1 ;
    long sv11 = (buffer[106] - 48) * 1000 + (buffer[107] - 48) * 100 + (buffer[108] - 48) * 10 + (buffer[109] - 48) * 1 ;
    long sv12 = (buffer[116] - 48) * 1000 + (buffer[117] - 48) * 100 + (buffer[118] - 48) * 10 + (buffer[119] - 48) * 1 ;

    long sv13 = (buffer[126] - 48) * 1000 + (buffer[127] - 48) * 100 + (buffer[128] - 48) * 10 + (buffer[129] - 48) * 1 ; //dauer anschalten sv1 in var sv1 abspeichern
    long sv14 = (buffer[136] - 48) * 1000 + (buffer[137] - 48) * 100 + (buffer[138] - 48) * 10 + (buffer[139] - 48) * 1 ;
    long sv15 = (buffer[146] - 48) * 1000 + (buffer[147] - 48) * 100 + (buffer[148] - 48) * 10 + (buffer[149] - 48) * 1 ;
    long sv16 = (buffer[156] - 48) * 1000 + (buffer[157] - 48) * 100 + (buffer[158] - 48) * 10 + (buffer[159] - 48) * 1 ;

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
