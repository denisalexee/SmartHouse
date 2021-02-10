//Порт подключенный к ST_CP 74HC595
#define latchPin 8
//Порт подключенный к SH_CP  74HC595
#define clockPin 12
//Порт подключенный к DS 74HC595
#define dataPin 10
//Первый регистр приточный вентилятор - быстро
#define fastSupplyFan 0
//Первый регистр приточный вентилятор - медленно
#define slowSupplyFan 1
//Первый регистр вытяжной вентилятор 
#define exhaustFan 2
//Первый регистр заслонки 
#define airDamper 3


unsigned int bitsToSend = 0;       // для хранения 16 битов используем unsigned int

// этот метод отсылает бит на сдвиговый регистр 
void registerWrite(int whichPin, int whichState) {

  digitalWrite(latchPin, LOW);       // выключаем светодиоды на время передачи битов
  bitWrite(bitsToSend, whichPin, whichState);    // устанавливаем HIGH в соответствующий бит
  // разбиваем наши 16 бит на два байта
  // для записи в первый и второй регистр
  byte registerOne = lowByte(bitsToSend);
  byte registerTwo = highByte(bitsToSend);
  // "проталкиваем" байты в регистры
  shiftOut(dataPin, clockPin, MSBFIRST, registerTwo);
  shiftOut(dataPin, clockPin, MSBFIRST, registerOne);
   // "защелкиваем" регистр, чтобы биты появились на выходах регистра
  digitalWrite(latchPin, HIGH);
  Serial.println("Переключили регистр");
  Serial.println("Значение напряжения");
  Serial.println(analogRead(A0));
}

void registerClear(){
  digitalWrite(latchPin, LOW);       // выключаем светодиоды на время передачи битов
  bitsToSend = 0;    // устанавливаем HIGH в соответствующий бит
  // разбиваем наши 16 бит на два байта
  // для записи в первый и второй регистр
  byte registerOne = lowByte(bitsToSend);
  byte registerTwo = highByte(bitsToSend);
  // "проталкиваем" байты в регистры
  shiftOut(dataPin, clockPin, MSBFIRST, registerTwo);
  shiftOut(dataPin, clockPin, MSBFIRST, registerOne);
   // "защелкиваем" регистр, чтобы биты появились на выходах регистра
  digitalWrite(latchPin, HIGH);
  
}
  

void setup() {
 //устанавливаем режим порта выхода
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    
  
  

}
