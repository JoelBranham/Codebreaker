![alt text](http://i.imgur.com/b6TzVuR.jpg)
___

##Introduction
Welcome to Codebreaker! The code for this project was written for a C++ programming course. This game is based upon the boardgame "Mastermind".

![alt text](http://i.imgur.com/9WxVzoD.jpg)

##Installation
Click [here](https://github.com/JBranflake/Codebreaker/archive/master.zip) to download the zip folder that contains the program files. If that does not work, click the "Clone or download" button and select the option "Download Zip". Next, find the zip folder in your downloads folder. Unzip the folder to a convenient location. Finally, open the "main" file in a C++ IDE.

##Instructions
The object of this game is to guess the *secret* code in the **fewest** guesses possible. The secret code is generated by running a [random number generator](https://github.com/JBranflake/Codebreaker/blob/master/main.cpp#L151) through a [code generator](https://github.com/JBranflake/Codebreaker/blob/master/main.cpp#L139) function. By default, the secret code is four digits long and the range of digits allowed in the code are 1 through 6. 

![alt text](http://i.imgur.com/AJRivym.jpg)

The player's input shows to the right of the "Enter Code:" text. After the user makes a guess, the computer displays the guess in the "YOUR GUESSES" column. The column under "CORRECT" displays the number of digits that are correct **and** in their correct spots. The column under "MISPLACED" shows the number of digits that are correct but are **not** in their correct positions.

Personal Note: It was difficult to ensure that digits were not counted as both correct and misplaced. Also, it was difficult to ensure that, if a digit in a guess were to be in the secret code more than once, it was not counted as more than one misplaced digit. Ex: player gueses "1234" and the secret code is "5622" At the earlier stages of this code, the single misplaced "2" would be counted as two misplaced digits. 

##Example Gameplay

This gameplay usest the defaults settings of having an allowed digit range of 1 through 6 and a set code length of 4 digits. The example game logic provided would need to be changed if either of these settings were adjusted. See [customizations](https://github.com/JBranflake/Codebreaker/blob/master/README.md#customizations) for information on changing these features.

![alt text](http://i.imgur.com/zm1LqLd.jpg)

In this example, the player's first guess is "1234". This yields 0 correct and 2 misplaced. This means that two of the digits from the guess are in the secret code, but are not in their correct positions. 

![alt text](http://i.imgur.com/sIfAFtM.jpg)

The player swaps the 1 for a 2 and guesses "2234". This yields 1 correct and 0 misplaced. The only digit that was changed was the first one, so having 1 more correct digit means that the changed digit in its correct position. The player can safely assume that the first digit is a "2".

The player can also assume that "1" is in the secret code because there are 0 misplaced digits. If "1" was not in the secret code, the number of misplaced would have instead gone from 2 to 1 because the "2" was put in its correct position. 

![alt text](http://i.imgur.com/qrvRhZD.jpg?1)

The player guesses "2314" to confirm that the first digit is a "2". There is now 1 misplaced, so the "1" is not in the correct position. The "1" should either be in the second or fourth digit's place.

The player also knows that there is neither a "3" nor a "4" in the secret code. If one of them was, there would be *more* than one misplaced digit.

![alt text](http://i.imgur.com/xsgRKsO.jpg?1)

Based on this knowledge that there is neither a "3" nor "4" are in the secret code, the player swaps the "1" and the "3" with the new guess. The player does not have to be concerned that moving the "3" will cause any new correct digits. This makes it easy to discern whether or not the "1" is in its correct position.

The guess of "2134" yields two correct! The player now knows that the second digit of the secret code is a "1".

Tip: If you are certain that one or more digits *are not* in the secret code, include them in your guesses. This technique makes it much easier to figure out which digits *are* in the secret code. If the player had guessed "2135", there could have been a result of  two correct and one misplaced. The player would have no clue which digit (the "1" or the "5") was correct and which was misplaced.

![alt text](http://i.imgur.com/PrkpfRn.jpg)

Because the player knows that neither "3" nor "4" are in the secret code, the player includes the only other two possible digits in the next guess of "2165". This results in 2 misplaced digits. This means that the last two digits of the secret code are "5" and "6". The player simply has to swap the "6" and the "5" to win the game.

![alt text](http://i.imgur.com/nO3Un6i.jpg)

Victory! The secret code was "2156".  The computer displays a congratulatory message and the number of guesses the player made. The player is asked if they would to play another game and prompted to enter "Y" or "N" in response. 

Note: *Most* games require more than 5 guesses.

##Customizations

The length and span of digits of the secret code can be changed in the ["main"] (https://github.com/JBranflake/Codebreaker/blob/master/main.cpp#L9) file. An increase in either of these adds difficulty. Here is a chart displaying various settings and their corresponding difficulties.

| Code Span | Code Length | Difficulty|
|-----------|------------|------------
| 4 digits (1-4)  | 3 digits   | Easy       |
| 6 digits (1-6) | 4 digits   | Medium (Default)    |
| 8 digits (1-8)  | 5 digits   | Hard       |
| 9 digits (1-9)  | 6 digits   | EXTREME    |

##Acknowledgements

The professor of my C++ course provided the random number generator and player input functions for this assignment. I wrote the game logic, secret code generator, and header file. The title was made using a text-to-ASCII-art generator found on  [this](http://patorjk.com/software/taag/#p=display&f=ANSI%20Shadow&t=Type%20Something%20) website.
