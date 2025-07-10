This is a program for a customizable pomodoro timer.
The user is able to adjust: 
    * work time in minutes and seconds
    * break time in minutes and seconds
    * the number of pomodoro intervals to run before closing the program
    * the sound to play: either a beep-tone or scoreboard buzzer

This program was originally compiled using the GNU C++ compiler with the SFML Library.
Linux command to install SFML
    sudo-apt-get install libsfml-dev
Linux command to compile this program
    g++ pomodoro.cpp -o pomodoro -lsfml-audio -lsfml-system
