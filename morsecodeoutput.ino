
#define DOT 0.25*1000 
#define DASH 0.75*1000
#define SPACE DASH
#define TRUE 1
#define FALSE 0

/* pin number */
#define LED 2

void setup() {
  Serial.begin(9600); //setup of serial monitor
  pinMode(LED, OUTPUT); 
  Serial.println("Type in message to be converted into morse code.");
}

/*
 * Purpose: checks if the inputted message is valid for translation
 * Input: String str -- message to be checked
 * Return: TRUE if message is valid, FALSE otherwise
 */
int checkIfValid(String str){
  int result = 0;
  int str_length = str.length()+1;
  char messageArr[str_length];
  
  str.toCharArray(messageArr, str_length);

  // Using ASCII table
  for (int index = 0; index < str_length; index++){
    if (messageArr[index] >= 33 && messageArr[index] <= 47 || messageArr[index] >= 58 && messageArr[index] <= 63 || messageArr[index] >= 91 && messageArr[index] <= 96 || messageArr[index] >= 123){
      result++;
    }
  }

  if (result != 0){
    return FALSE;
  }
  else {
    return TRUE;
  }
}

/* 
 *  Purpose: outputs inputted string as morse code by flashing LED
 *  Input: String, message to be converted
 *  Return: none
 */
void convertToMorse(String str){
  int str_length = str.length()+1; 
  char messageArr[str_length];

  str.toCharArray(messageArr, str_length);
  
  for (int i = 0; i < str_length; i++){
    outputLED(messageArr[i]);
  }
}

/*
 * Purpose: outputs "dot" morse code; flashes LED for 0.25 seconds
 * Return: none
 */
void dot(){
  digitalWrite(LED, HIGH);
  delay(DOT);
  digitalWrite(LED, LOW);
  delay(DOT);
  Serial.print(".");
}

/*
 * Purpose: outputs "dash" morse code; flashes LED for 0.75 seconds
 * Return: none
 */
void dash(){
  digitalWrite(LED, HIGH);
  delay(DASH);
  digitalWrite(LED, LOW);
  delay(DOT);
  Serial.print("-");
}

/*
 * Purpose: check what letter/symbol/number the element is and outputs morse code representation
 * Input: element -- character type to be checked
 * Return: none
 */
void outputLED(char element){
  if (element == ' '){
    delay(SPACE);
    Serial.print(" ");
  }
  if (element == 'a' || element =='A'){
    dot();
    dash();
  }
   if (element == 'b' || element =='B'){
    dash();
    dot();
    dot();
    dot();
  }
   if (element == 'c' || element =='C'){
    dash();
    dot();
    dash();
    dot();
  }
   if (element == 'd' || element =='D'){
    dash();
    dot();
    dot();
  }
   if (element == 'e' || element =='E'){
    dot();
  }
   if (element == 'f' || element =='F'){
    dot();
    dot();
    dash();
    dot();
  }
   if (element == 'g' || element =='G'){
    dash();
    dash();
    dot();
  }
   if (element == 'h' || element =='H'){
    dot();
    dot();
    dot();
    dot();
   }
   if (element == 'i' || element =='I'){
    dot();
    dot();
  }
   if (element == 'j' || element =='J'){
    dot();
    dash();
    dash();
    dash();
  }
   if (element == 'k' || element =='K'){
    dash();
    dot();
    dash();
  }
   if (element == 'l' || element =='L'){
    dot();
    dash();
    dot();
    dot();
  }
   if (element == 'm' || element =='M'){
    dash();
    dash();
  }
   if (element == 'n' || element =='N'){
    dash();
    dot();
  }
   if (element == 'o' || element =='O'){
    dash();
    dash();
    dash();
  }
   if (element == 'p' || element =='P'){
    dot();
    dash();
    dash();
    dot();
  }
   if (element == 'q' || element =='Q'){
    dash();
    dash();
    dot();
    dash();
  }
   if (element == 'r' || element =='R'){
    dot();
    dash();
    dot();
  }
   if (element == 's' || element =='S'){
    dot();
    dot();
    dot();
  }
   if (element == 't' || element =='T'){
    dash();
  }
   if (element == 'u' || element =='U'){
    dot();
    dot();
    dash();
  }
   if (element == 'v' || element =='V'){
    dot();
    dot();
    dot();
    dash();
  }
   if (element == 'w' || element =='W'){
    dot();
    dash();
    dash();
  }
   if (element == 'x' || element =='X'){
    dash();
    dot();
    dot();
    dash();
  }
   if (element == 'y' || element =='Y'){
    dash();
    dot();
    dash();
    dash();
  }
   if (element == 'z' || element =='Z'){
    dash();
    dash();
    dot();
    dot();
  }
  if (element == '0'){
    dash();
    dash();
    dash();
    dash();
    dash();
  }
  if (element == '1'){
    dot();
    dash();
    dash();
    dash();
    dash();
  }
  if (element == '2'){
    dot();
    dot();
    dash();
    dash();
    dash();
  }
  if (element == '3'){
    dot();
    dot();
    dot();
    dash();
    dash();
  }
  if (element == '4'){
    dot();
    dot();
    dot();
    dot();
    dash();
  }
  if (element == '5'){
    dot();
    dot();
    dot();
    dot();
    dot();
  }
  if (element == '6'){
    dash();
    dot();
    dot();
    dot();
    dot();
  }
  if (element == '7'){
    dash();
    dash();
    dot();
    dot();
    dot();
  }
  if (element == '8'){
    dash();
    dash();
    dash();
    dot();
    dot();
  }
  if (element == '9'){
    dash();
    dash();
    dash();
    dash();
    dot();
  }
}

/*
 * Program loop 
 */
void loop() {
  while (Serial.available() > 0) {
    String message = Serial.readString();
    Serial.println();
    Serial.print("Recieved: ");
    Serial.print(message);
    
    int check = checkIfValid(message);
    
    // checks if message valid -- no symbols
    if (check != FALSE){
      Serial.println("Translating...");
      convertToMorse(message);
    }
    else {
      Serial.println("Error. Please try again.");
    }
  
  }
}
