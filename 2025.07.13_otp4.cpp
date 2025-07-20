#include<iostream>
#include<fstream>
#include<unordered_map>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;


// Utility Functions
std::string readTextFile(std::string filename);
void readTextFile(std::string filename, std::string &textfile);
void writeTextFile(std::string outFileName, std::string textfile);
std::vector<int> random_vector(int minimum, int maximum, int length);

// Mathemematical Operations needed for Functions below
std::vector<int> addVectors(std::vector<int> x, std::vector<int> y);
void addVectors(std::vector<int> x, std::vector<int> y, ::std::vector<int> &z);
std::vector<int> subtractVectors(std::vector<int> x, std::vector<int> y);
void subtractVectors(std::vector<int> x, std::vector<int> y, std::vector<int> &z);
std::vector<int>string2int(std::string message);
std::string int2string(std::vector<int> nums);

// Functions specific for the program
std::string generateOTP(int padsize);
std::string encrypt_message(std::string message_string, std::string otp_string);
void encrypt_message(std::string message_string, std::string otp_string, std::string &cipher_string);
std::string decrypt_message(std::string cipher_string, std::string otp_string);
void decrypt_message(std::string cipher_string, std::string otp_string, std::string &decipher_string);


// Encoder/Decoder Function to generate 
// the unordered_maps used throught the program
std::unordered_map<char, int> generateEncoder();
std::unordered_map<int, char> generateDecoder();
std::unordered_map<char, int> encoder = generateEncoder();
std::unordered_map<int, char> decoder = generateDecoder();

int main()
{
    bool running = true;
    std::string filename, encrypted, decrypted, otpName; // filenames
    std::string textFile, otpFile, encrypted_text, decrypted_text; // files to read/write
    std::string line;
    int numPads, padsize, choice; // integers
    
    cout << "Welcome to this One-Time Pad Program" << endl;
    do {
        choice = 0;
        cout << "What do you need to do? " << endl;
        cout << "(1) Generate One-Time Pad" << endl;
        cout << "(2) Encrypt Message" << endl;
        cout << "(3) Decrypt Message" << endl;
        cout << "(4) End Program" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                numPads = 0;
                cout << "How many pads do you need? ";
                cin >> numPads;
                cout << "How many characters for each pad? ";
                cin >> padsize;
                for (int i = 0; i <= numPads; ++i) {
                    otpFile = generateOTP(padsize);
                    writeTextFile("OneTimePad_" + std::to_string(i) + ".txt", otpFile);
                    otpFile.erase(otpFile.begin(), otpFile.end());
                    cout << "Pad " << i << " generated" << endl;
                }
                break;
            case 2:
                cout << "What is the name of the file to be encrypted? ";
                cin >> filename;
                cout << "Which one-time pad to use? ";
                cin >> otpName;

                cout << "Importing Text File to Encrypt" << endl;
                readTextFile(filename, textFile);
                cout << "Importing One Time Pad" << endl;
                readTextFile(otpName, otpFile);
                
                // cout << "Importing Text File to Encrypt" << endl;
                // textFile = readTextFile(filename);
                // cout << "Importing One Time Pad" << endl;
                // otpFile = readTextFile(otpFile);
                
                // encrypt_message(textFile, otpFile encrypted_text);
                encrypted_text = encrypt_message(textFile, otpFile);
                encrypted = filename.substr(0, filename.length()-4) + "_encrypted.txt";
                writeTextFile(encrypted, encrypted_text);

                textFile.erase(textFile.begin(), textFile.end());
                otpFile.erase(otpFile.begin(), otpFile.end());
                encrypted_text.erase(encrypted_text.begin(), encrypted_text.end());
                cout << "File " << encrypted << " Encrypted." << endl;
                break;
            case 3:
                cout << "What is the name of the file to be decrypted? ";
                cin >> filename;
                cout << "Which one-time pad to use? ";
                cin >> otpName;

                cout << "Importing Encrypted Text File" << endl;
                readTextFile(filename, textFile);
                cout << "Iporting One Time Pad" << endl;
                readTextFile(otpName, otpFile);
                
                // cout << "Importing Encrypted Text File" << endl;
                // textFile = readTextFile(filename);
                // cout << "Iporting One Time Pad" << endl;
                // otpFile = readTextFile(otpFile);

                // decrypt_message(textFile, otpFile decrypted_text);
                decrypted_text = decrypt_message(textFile, otpFile);
                decrypted = filename.substr(0, filename.length()-4) + "_decrypted.txt";
                writeTextFile(decrypted, decrypted_text);                


                textFile.erase(textFile.begin(), textFile.end());
                otpFile.erase(otpFile.begin(), otpFile.end());
                decrypted_text.erase(decrypted_text.begin(), decrypted_text.end());
                cout << "File " << decrypted << " Decrypted." << endl;
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Incorrect Choice" << endl;
                break;
        }
        cout << endl;
    } while (running);
    return 0;
}


std::string readTextFile(std::string filename)
{
    std::string textFile, line;
    std::ifstream inputfile(filename);
    if (inputfile.is_open()) {
        while (std::getline(inputfile, line))
        {
            textFile += line;
        }
        inputfile.close();  
    } else {
        cout << "Incorrect Text File Name." << endl;
        textFile = "XXX";
    }
    return textFile;
}
void readTextFile(std::string filename, std::string &textFile)
{
    std::ifstream inputfile(filename);
    std::string line;
    if (inputfile.is_open()) {
        while (std::getline(inputfile, line))
        {
            textFile += line;
        }
        inputfile.close();  
    } else {
        cout << "Incorrect Text File Name." << endl;
        textFile = "XXX";
    }
}
void writeTextFile(std::string outFileName, std::string textfile)
{
    std::ofstream outputFile;
    outputFile.open(outFileName, std::ios::out);
    outputFile << textfile;
    outputFile.close();
}

/*
    Generate a random vector of integers
    arguments
        minimum: smallest value for the integers
        maximum: largest value for the integers
        vector_size: length of the vector
*/
std::vector<int> random_vector(int minimum, int maximum, int vector_size)
{
    // 1. Create a random device to seed the engine
    std::random_device rd;

    // 2. Create a Mersenne Twister engine, seeded by the random device
    //    std::mt19937 is a high-quality pseudo-random number generator
    std::mt19937 gen(rd());

    // 3. Define a uniform integer distribution for the desired range
    //    This distribution ensures numbers are evenly distributed between 1 and 100 (inclusive)
    std::uniform_int_distribution<> distrib(minimum, maximum);

    // 4. Create a vector to store the random numbers
    std::vector<int> random_numbers(vector_size);

    // 5. Fill the vector with random numbers using std::generate
    //    The lambda function calls the distribution with the engine to get a random number
    std::generate(random_numbers.begin(), random_numbers.end(), [&]() {
        return distrib(gen);
    });

    return random_numbers;
}


/*
    Function to generate
    Encoder map converting letters to integers and vice versa
    A = 0, B = 1,..., Z=25, ' '=26, '.'=27
*/
std::unordered_map<char, int> generateEncoder()
{
    std::unordered_map<char, int> encoder;
    std::unordered_map<int, char> decoder;

    int i = 0;
    for (char letter = 'A'; letter <='Z'; ++ letter) {
        encoder[letter] = i;
        decoder[i] = letter;
        ++i;
    }
    encoder[' '] = 26;
    encoder['.'] = 27;
    decoder[26] = ' ';
    encoder[27] = '.';

    return encoder;
}
std::unordered_map<int, char> generateDecoder()
{
    std::unordered_map<char, int> encoder;
    std::unordered_map<int, char> decoder;

    int i = 0;
    for (char letter = 'A'; letter <='Z'; ++letter) {
        encoder[letter] = i;
        decoder[i] = letter;
        ++i;
    }
    encoder[' '] = 26;
    encoder['.'] = 27;
    decoder[26] = ' ';
    encoder[27] = '.';

    return decoder;
}

// uses encoder map to tranlate between characters of a string to a vector of integers
// and vice versa
std::vector<int>string2int(std::string message_string)
{
    std::transform(message_string.begin(), message_string.end(), message_string.begin(),
        [](unsigned char c){return std::toupper(c); });
    std::vector<int> nums;
    for (char x: message_string) {
        nums.push_back(encoder[x]);
    }
    return nums;
}
std::string int2string(std::vector<int> nums)
{
    std::string message;
    for (int num : nums)
        message += decoder[num];
    return message;
}
// element by element arithmetic specific for this program.
// includes a modulo operation to keep numbers within the bounds of
// encoder
std::vector<int> addVectors(std::vector<int> x, std::vector<int> y)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    std::vector<int> z;
    for (int i = 0; i < iter_end; ++i) {
        int j = x[i] + y[i];
        j = j%27;
        z.push_back(j);
    }
    return z;
}
void addVectors(std::vector<int> x, std::vector<int> y, std::vector<int> &z)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        int j = x[i] + y[i];
        j = j%27;
        z.push_back(j);
    }
}
std::vector<int> subtractVectors(std::vector<int> x, std::vector<int> y)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    std::vector<int> z;
    for (int i = 0; i < iter_end; ++i) {
        int j = 27 + x[i] - y[i];
        j = j%27;
        z.push_back(j);
    }
    return z;
}
void subtractVectors(std::vector<int> x, std::vector<int> y, std::vector<int> &z)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        int j = 27 + x[i] - y[i];
        j = j%27;
        z.push_back(j);
    }
 }

// Generate a One-Time Pad String of length padsize
std::string generateOTP(int padsize)
{
    std::vector<int> otp_int = random_vector(0,27,padsize);
    std::string otp_string;
    for (int i = 0; i < padsize; ++i)
        otp_string += decoder[otp_int[i]];

    return otp_string;
}
// Encrypt Message message_string using One-Time Pad otp_string
std::string encrypt_message(std::string message_string, std::string otp_string)
{
    std::transform(message_string.begin(), message_string.end(), message_string.begin(),
        [](unsigned char c){return std::toupper(c); });

    if (message_string.length() < otp_string.length()) {
        std::string filler_string;
        for (int i = 0; i <= otp_string.length() - message_string.length(); ++i)
            filler_string += 'X';
        message_string += filler_string;
        filler_string.erase(filler_string.begin(), filler_string.end());
    }
    
    std::vector<int> message_int = string2int(message_string);
    std::vector<int> otp_int = string2int(otp_string);

    std::vector<int> cipher_int;
    addVectors(otp_int, message_int, cipher_int);
    std::string cipher_string = int2string(cipher_int);
    
    message_int.clear();
    otp_int.clear();
    cipher_int.clear();
    return cipher_string;
}
void encrypt_message(std::string message_string, std::string otp_string, std::string &cipher_string)
{
    std::transform(message_string.begin(), message_string.end(), message_string.begin(),
        [](unsigned char c){return std::toupper(c); });

    if (message_string.length() < otp_string.length()) {
        std::string filler_string;
        for (int i = 0; i <= otp_string.length() - message_string.length(); ++i)
            filler_string += 'X';
        message_string += filler_string;    
        filler_string.erase(filler_string.begin(), filler_string.end());
    }
    
    std::vector<int> message_int = string2int(message_string);
    std::vector<int> otp_int = string2int(otp_string);
    
    std::vector<int> cipher_int;
    addVectors(otp_int, message_int, cipher_int);
    cipher_string = int2string(cipher_int);
    
    message_int.clear();
    otp_int.clear();
    cipher_int.clear();
}
// Decrypt message cipher_string with one-time pad otp_string
std::string decrypt_message(std::string cipher_string, std::string otp_string)
{
    std::vector<int> otp_int = string2int(otp_string);
    std::vector<int> cipher_int = string2int(cipher_string);
    
    std::vector<int> decipher_int;
    subtractVectors(cipher_int, otp_int, decipher_int);
    std::string decipher_string = int2string(decipher_int);

    otp_int.clear();
    cipher_int.clear();
    decipher_int.clear();
    
    return decipher_string;
}
void decrypt_message(std::string cipher_string, std::string otp_string, std::string &decipher_string)
{
    std::vector<int> otp_int = string2int(otp_string);
    std::vector<int> cipher_int = string2int(cipher_string);

    std::vector<int> decipher_int;
    subtractVectors(cipher_int, otp_int, decipher_int);
    decipher_string = int2string(decipher_int);
    
    otp_int.clear();
    cipher_int.clear();
    decipher_int.clear();
}
