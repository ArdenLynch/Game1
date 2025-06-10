#include <Adafruit_CircuitPlayground.h>
int roomSelect;
int encounterSelect;
int monsterSelect;
int score = 0;
int life = 3;
int monsterDelay;
int monsterChance;


void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  Serial.println("Welcome explorer, before you lies a trecherous dungeon. Good Luck!");
  delay(2000);
}

void loop() {
  // randomly select a room and type the description
  roomSelect = random(1,15);
  room(roomSelect);
  delay(3000);

  // set monster difficulty according to score
  
  if (score < 10) {
    monsterDelay = 2;
  }
  if (10 <= score < 20) {
    monsterDelay = 4;   
  } 
  if (20 <= score < 30) {
    monsterDelay = 6;
  }
  if (30 <= score) {
    monsterDelay = 8;
  }

  //random monster encounter
  monsterChance = random(1, 3);
  if (monsterChance == 1) {
    for (int i = 0; i < 10; ++i) {
      sparcleCycle(100);
    }
    monsterSelect = random(1, 5);
    monster(monsterSelect);
    Serial.println("Do you ...");
    Serial.println("[RUN] [FIGHT]");
    while (!CircuitPlayground.leftButton() && !CircuitPlayground.rightButton()) {}
      if (CircuitPlayground.leftButton()) {
        int survivalChance = random(1-20);
        if (survivalChance > monsterDelay) {
          Serial.println("You WON!! (Score +2)");
          score += 2;
        }
        else {
          Serial.println("You LOST! (Life -1)");
          life -=1;
        }
      }
      else{
        int survivalChance = random(1-10)+1;
        if (survivalChance > monsterDelay) {
          Serial.println("You Escaped!");
          score += 2;
        }
        else {
          Serial.println("You Got Wounded (Life -1)");
          life -=1;
        }
      }
  }

  if ((life > 0)&&(roomSelect < 6)) {
    encounter(roomSelect);
  }

  score += 1;

  if (life == 0) {
    Serial.println("GAME OVER");
    Serial.print("Your Score Was:  ");
    Serial.println(score);
    Serial.println("Play Again?");
    Serial.println("[yes]  [no]");
    while (!CircuitPlayground.leftButton() && !CircuitPlayground.rightButton()) {}
    if (CircuitPlayground.leftButton()) {
      score = 0;
      Serial.println("Welcome explorer, before you lies a trecherous dungeon. Good Luck!");
    }
    else {
      Serial.println("Thanks for playing");
      while(true) {}
    }
  }

  Serial.println("press any button to continue");
  while (!CircuitPlayground.leftButton() && !CircuitPlayground.rightButton()) {}
  Serial.println(" ");
  delay(1000);

}


void room(int input0) {
  Serial.println("You walk into a ...");
  if (input0 == 1){
    Serial.println("Mossy Chapel ~ Crumbled pews face a shattered altar. Green light pulses from vines overtaking the walls. A whispering voice tempts intruders to kneel in forgotten worship.");
  }
  if (input0 == 2){
    Serial.println("Bone Pit ~ A shallow pit filled with humanoid bones and rusted weapons. One skull hums softly, vibrating with latent necromantic energy.");
  }
  if (input0 == 3){
    Serial.println("Black Garden ~ Pale mushrooms glow beneath a dead tree. Sweet-smelling spores hang heavy in the air. Breathing too deeply makes thoughts blur and warp.");
  }
  if (input0 == 4){
    Serial.println("Time-Lost Atrium ~ Dust hangs motionless midair. Footsteps echo seconds late. Your reflection in a shattered window shows an older, wearier version of yourself.");
  }
  if (input0 == 5){
    Serial.println("Whispering Well ~ A dry well in the center of the room hums softly. Listening closely reveals overlapping voices speaking your name, over and over.");
  }  
  if (input0 == 6){
    Serial.println("Empty Chamber ~ Stone walls, dusty floor. Nothing inside but silence and old footprints.");
  }  
  if (input0 == 7){
    Serial.println("Barracks Room ~ Four rotting bunk beds, broken weapons on the ground. Smells faintly of mildew.");
  }  
  if (input0 == 8){
    Serial.println("Storage Closet ~ Crates stacked high. Some are smashed open, revealing moldy supplies and chewed rope.");
  }  
  if (input0 == 9){
    Serial.println("Collapsed Hall ~ Rubble blocks most of the room. A narrow crawlspace leads into darkness.");
  }  
  if (input0 == 10){
    Serial.println("Guard Post ~ Two overturned chairs, a rusted bell, and a long-dead torch sconce.");
  }  
  if (input0 == 11){
    Serial.println("Dining Room ~ A long table with broken plates and toppled chairs. Rats scatter as you enter.");
  }  
  if (input0 == 12){
    Serial.println("Locked Cell ~ Iron bars, straw bedding. The door is ajar, and the cell is empty.");
  }  
  if (input0 == 13){
    Serial.println("Trophy Room ~ Heads of strange beasts mounted on the walls. Dust covers everything.");
  } 
  if (input0 == 14){
    Serial.println("Kitchen ~ Pots and pans still hang. A large cauldron is crusted with something black and long-dried.");
  }  
  if (input0 == 15){
    Serial.println("Well Room ~ A stone well sits in the center. The rope is snapped and the bucket missing.");
  }


}


void monster(int input1) {
  Serial.println("Lurking in the room is a ...");
  if (input1 == 1){
    Serial.println("Skeleton Warrior ~ Rattling bones held together by dark magic. Wields rusted weapons with unnatural precision, eyes glowing faintly red in empty sockets.");
  }
  if (input1 == 2){
    Serial.println("Goblin Scout ~ Small, wiry, and sneaky. It darts between shadows with a dagger in hand, always looking for an ambush or easy loot.");
  }
  if (input1 == 3){
    Serial.println("Zombie Brute ~ A rotting corpse with swollen muscles and slow, relentless movements. Strikes with crushing force, ignoring pain or injury.");
  }
  if (input1 == 4){
    Serial.println("Orc Berserker ~ Towering and furious, with jagged armor and a massive axe. Its roar echoes through the halls before it charges blindly into battle.");
  }
  if (input1 == 5){
    Serial.println("Giant Rat ~ Filthy and aggressive, with diseased fur and yellow teeth. Often found in swarms, gnawing on anything soft—or slow.");
  }
}

void encounter(int input2) {
  if (input2 == 1){
    Serial.println("As you walk past the mossy pew, you feel a benevolent spirit touch your soul (+2 life!)");
    life += 2;
  }
  if (input2 == 2){
    Serial.println("As you walk past the skull, it lurches through the air and bites you (-1 life!)");
    life -= 1;
  }
  if (input2 == 3){
    Serial.println("Eating one of these might be quite the good time, do you eat it?");
    Serial.println("[yes]  [no]");
    while (!CircuitPlayground.leftButton() && !CircuitPlayground.rightButton()) {}
    if (CircuitPlayground.leftButton()) {
      life = 0;
    }
  }
  if (input2 == 4){
    Serial.println("As you look into your reflection, you the world swirls and you're looking at a spry version of yourself. You feel as if youre deeper into the dungeon (score +5!)");
    score += 5;
  }
  if (input2 == 5){
    Serial.println("The whispering starts to become painful, and your ears begin to bleed (-1 life!)");
    life -= 1;
  }

}


void sparcleCycle(int sparcleSpeed) {
  // set random led to white
  int ledSelect = random(0, 9);
  CircuitPlayground.setPixelColor(ledSelect, 255,   0,   0);
  delay(sparcleSpeed);
  // set all leds to black
  for (int i = 0; i < 10; ++i) {
  CircuitPlayground.setPixelColor(i, 0, 0, 0);
  }
}
