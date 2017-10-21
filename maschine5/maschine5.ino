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
char buffer[200];    // Serial Input-Buffer

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
    bufferCount = 0;
    printActors();
  }
}

long readIntFromBuffer(int pos, int len)
{
  long value = 0;
  while (len > 0) {
    value = value + (buffer[pos] - 48);
    pos++;
    len--;
    if (len > 0) {
      value = value * 10;
    }
  }
  return value;
}

void evalSerialData()
{
  // Serial.println(buffer);
  // >sv01=xxxx;sv02=xxxx;sv03=xxxx;sv04=xxxx;sv05=xxxx;sv06=xxxx;sv07=xxxx;sv08=xxxx;sv09=xxxx;sv10=xxxx;sv11=xxxx;sv12=xxxx;sv13=xxxx;sv14=xxxx;sv15=xxxx;sv16=xxxx< <<- Beispiel String
  if ((buffer[0] == '>') && (buffer[bufferCount - 2] == '<')) { //erstes >und vorletztes < zeichen prüfen
    int pos = 1; // Zeichen hinter >
    long sv[16];
    for (int i = 0; i < 16; i++) {
      sv[i] = readIntFromBuffer(pos + 5 /* sv01= überspringen */, 4);
      pos += 10; // nächste Gruppe
    }

    for (int i = 0; i < 16; i++) {
      actors[i].activeFor(sv[i]);
    }
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
