# KlopsDuelity
Game with very simple target: Shoot your opponent dead!

# Note: This project has been scrapped due to issues related with standard IO stream and Ncurses one.

![KlopsLogo](https://github.com/WTCa100/KlopsDuelity/assets/93256649/80850e81-2b9b-4a86-84b4-31a45c152dd1) <br>
<p> Klops is an single-player side-viewed shooter game, where your primary objective is to win as many duels as possbile! Gather exp, level up, buy new weapons and fight against uniquely generated enemies, to become an ultimate duelist that would be 
known for the entirety of our planet!</p>

## The Game
![KlopsArena](https://github.com/WTCa100/KlopsDuelity/assets/93256649/8e1a039e-c2d4-49b3-bcba-3673b72d14a8)
<p> Core gameplay is centered around dueling, where you face your generated enemies. Here you can choose which weapon to use adjust distance, and see how the arena is changing dynamically while you manouver your fighter. This is my very first attempt on creating a graphical component into a game, and I was made possbile because of <strong>NCurses</strong> library.</p>

### Main Menu
<p> As in every game player is prompt to choose name of a hero and a origin story that slighlty impact the gameplay - as different origins gives different starting stats. After giving the necessery input player enter the town and is presented with 4 options which are: </p>
<ol>
  <li>Cabin</li>
  <li>Arena</li>
  <li>Shop</li>
  <li>Exit</lo>
</ol>

![Klopstown](https://github.com/WTCa100/KlopsDuelity/assets/93256649/8943e0ba-aad9-4f5f-bd05-25dc05612816)

#### Cabin
<p> While entering the Cabin, player is presented with all selected stats that were obtained during the gameplay, as well as every weapon that the player has. Additionally it provieds exp requirements to get to the next level, and current stats.</p>
<span>Stats:</span>
<ul>
  <li>Vitality - give more max health</li>
  <li>Accuracy - gives better odds on hitting the enemy</li>
  <li>Charisma - Increases monetary rewards after fight and decreases weapon prices</li>
</ul>

### Arena
<p> When entering Arena a prompt will ask the player to choose on of 3 previously generated enemies. Position here matters as the higher the number the tougher the enemy when it comes to both power and dueling weaponry. The behavour of generator can be found and changed at: </br></p>

`./application/code/game/Session/session.cpp`
In: 
```C++
entities::HEUTypes::Shooter* Session::generateOponent(oponentDifficulty difLvl)
```

<p> For now the most important information is that, every enemy is generated with regard of players power. These values depend with enemy position and are from 65% of player power (at position 1) to 250% (at position 3). After choosing enemy, you player has to choose weapon to shoot with.</br> </p>
<p>After choosing the weapon the round counter starts and will stop at 20 where the duel will be concluded. At the beggining monetary reward called 
'stake' is created and will depend based on player charisma and enemy power. In order to check or modify rewarad calculating proces you can refer to: </p>

`application/code/game/Modifiers/Modifier.cpp`

Calculations looks as follows:

```C++
int calculateDuelReward(const double& enemyWeaponDmg, const double& enemyWeaponAccuracy, 
                        const double& distance, const int& playerCharisma,
                        const double& baseReward)
{
  int enemyMod = enemyWeaponDmg + (enemyWeaponAccuracy * 100);
  int distanceMod = distance * 2;
  int charismaMod = 1 + (static_cast<double>(playerCharisma) / 10);

  return (baseReward + enemyMod + distanceMod) * charismaMod;
}
```
<p> Now the real fight starts and player is presented with this screen which is self-explainatory: </p>

![image](https://github.com/WTCa100/KlopsDuelity/assets/93256649/e4f0c488-7b61-488a-867c-81fc20f9d6ab)

<p> After dealing with selected enemy, the end screen will appear showing who won the duel. In order to win duel one of the participants has to either die, loose conciousness or deal more dmg to enemy. Depending on the outcome as well as many other factors that happened during the match player is given either reward and exp (if won duel) or exp (if lost the duel). The exp reward can also be 
find in: </p>

`application/code/game/Modifiers/Modifier.cpp`

Here is an example end screen:

![image](https://github.com/WTCa100/KlopsDuelity/assets/93256649/266c0941-9c23-4354-aec7-1e5c538d37b7)

<p>After this screen if conditions are met player may choose which stats to level up. As of now stats are: Vitality, Accuracy and Charisma. </p>

### Shop

<p>As one may think, store is a place where the player can buy weapons. The store offers to buy every game weapon except ones that player has.
Every weapon price is reduced depending on player charisma.</p> 

## Code info
This game was created primarly to get some experiance with object oriented programming (inheritance, polymorphism etc.), and thus is not too complex. I also tried to implement some of the design patterns into the game but mainly used Singleton to initialize the game.
### Building
To build the project navigate to `./build` and type `make` in order to execute makefile. <br>
NOTE!: The game runs with programming library ncurses and it's required to build the project.
### Ncurses and it's limitations
During development of the game I realised that there is no `getch()` function on Linux as there is no `conio.h` library. This forced me to seek alternatives and eventually I found about Ncurses. Eager to get back to codding I noticed that using Ncurses library makes using standard iostream impossible as buffers colided with each other. Thus I decided to not only to switch every iostream standard function but also implement those that were not in ncurses library such as getline thus you may encounter `NI::getline(std::string)` here and there. It took me some time to understand how the original getline worked but I finally managed to write it on my own. It can be located in: 
`application/code/utilities/IOStream/NIO.cpp`

However operating on different iostream buffer eventually led this project to dead-end since I haven't found any option to save files with ncurses on - thus I could not implement custom configurations and saving into the game. That's the reason why I've ended fruther development of this project.
### Weapons
Every specified weapon that player can buy or use are children of main Weapon class that has functionality defined (such as presentation and shooting) but also holds uninitialized values that children then initialize upon creation. If you want to add weaponry to the game make sure to follow the following format:
In header files:
```C++
namespace entities::weapons::YourWeaponType // Currently implemented are Muskets and Pistols
{
  class DummyWeapon : public Weapon
  {
    // Your custom functions
    public:
      DummyWeapon();
      ~DummyWeapon(); // Preferably ~DummyWeapon() = default;
  }
}
```
In source files define constructor as follows:
``` C++
DummyWeapon() : Weapon("DummyWeapon")
{
  basePrice_ = <base_price>;
  baseDmg_ = <base_dmg>;
  baseAccuracy_ = <base_accuracy>
}
```
### Human Entity Unit (HEU)
Each NPC and Player is defined as HEU, which is a base class for every "living" entity. 
An HEU holds only information about `hId_` which is an unique identifier I used for debbuging. 
Defined HEU types are:
#### Shooter
This entity stres most information about enemies but it also had few elements that are usefull in implementind `Player` class. Basically it hold information on:
- Stats 
- Health/Max Health
- power
- currently held weapon
- dead/concious/alive status

Every time a `Shooter` instance is created a function called `assignDefaultParameters` is called which creates a basic dummy that later can be edited via setters. This allowed me to avoid the need to include tons of constructors, and gives a greater freedom on modifying current shooter instance.
Additionally `Shooter` class is responsible for calculating it's power and max health.
##### Player
As mentioned earlier `Player` class is a child of `Shooter` thus it has access to `Shooter` private members. In addition to inherited members and methods it also implements it's own.
It contains basic stat counters such as `moneyWon_` or `playerGlobalShotCount_`, leveling handles as well as money handle along with weapon mainpulation and origin. 
When creating `Player` instance, additionaly parameter can be passed into `HEU` constructor that will assign default name into an entity.
#### Shopkeeper
This entity only displays items, and try to sell them to player, weapon prices changes depending on player charisma stats. In order to make shopkeeper show items `entities::HEUTypes::Shopkeeper::act()` has to be called.
#### Adding new HEUTypes
If you would like to add additional HEU entity please do it under `namespace entities::HEUTypes`.
### Modifiers
Most of the calculations done in the game are explicitly made inside `Modifiers.cpp`, if any of the default rules are annoying or painful to get along with, you can modify them there.

### Final words
Thank you for stopping by and reading all of this! If you decide to play this game have a good time :)
If you spot any but or would like to share a feedback feel free to do it - I would greatly appreciate that.
