#include <iostream>
#include <chrono>
#include <thread>
#include <SFML/Audio.hpp>
using namespace std;

void timer(int duration_ms) 
{
    // Function takes millisecond input and 
    // pauses the program for that amount of time.
    // Utilizes the chrono and thread headers
    chrono::milliseconds duration_time(duration_ms);
    thread t([&]() {
        this_thread::sleep_for(duration_time);
    });
    t.join();
}

void beepTone(sf::SoundBuffer* buffer)
{
    // Function takes a pointer to an SF Sound Buffer
    // and plays the associated file
    sf::Sound sound;
    sound.setBuffer(*buffer);
    
    sound.play();

    /* Wait until sound finishes playing */
    while (sound.getStatus() == sf::Sound::Playing) {
        sf::sleep(sf::milliseconds(100));
    }
}


int main() {
    
    /* Define the Pomodoro Parameters */
    int work_min, work_s, break_min, break_s; 
    int work_ms, break_ms;
    int pomodoro;
    
    cout << "What is the duration of the work interval?" << endl;
    cout << "minutes ";
    cin >> work_min;
    cout << "seconds ";
    cin >> work_s;
    
    cout << "What is the duration of the break interval?" << endl;
    cout << "minutes ";
    cin >> break_min;
    cout << "seconds ";
    cin >> break_s;

    cout << "How many pomodoro intervals? ";
    cin >> pomodoro;

    /* Convert Times into Milliseconds for timer function */
    work_ms = 1000*(work_min*60 + break_s);
    break_ms = 1000*(break_min*60 + break_s);



    /* Select & Load the Sound File Into a SF Buffer */
    int noiseSelection;
    cout << "What sound would you prefer?" << endl;
    cout << "1) Buzzer" << endl << "2) Beep Tone" << endl;
    cin >> noiseSelection;

    string soundFile;
    if (noiseSelection == 1) {
        soundFile = "Buzzer.wav";
    } else if (noiseSelection == 2) {
        soundFile = "Beep-09.ogg";
    } else {
        soundFile = "Beep-09.ogg";
    }

    /* Create the SF Buffer */
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(soundFile)) {
        std::cerr << "Failed to load Sound" << soundFile << "\n";
        return 1;
    }

    
    /* Pomodoro Loop */
    beepTone(&buffer);
    cout << "Start working!" << endl << "Pomodoro: 1" << endl;
    
    for (int p = 2; p <= pomodoro; p++) {
        timer(work_ms);
        beepTone(&buffer);
        cout << "Take a break!" << endl;
        
        timer(break_ms);
        beepTone(&buffer);
        cout << "Pomodoro: " + to_string(p) << endl << "Get back to work!" << endl;
    }
    
    timer(work_ms);
    beepTone(&buffer);
    cout << "You're finished! Congratulations!" << endl;
    
    return 0;
}
/*
    linux command to install SFML
    sudo-apt-get install libsfml-dev

    linux command to compile this program
    g++ 2025.06.21b_pomodoro.cpp -o pomodoro_beep -lsfml-audio -lsfml-system

*/