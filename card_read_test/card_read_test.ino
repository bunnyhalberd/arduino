

#include <SPI.h>
#include <SD.h>
File myFile;

bool test_file(File *file)
{
    // Make sure the first five bytes are our magic number
    uint8_t magic_number[5];
    file->readBytes(magic_number, 5);

    Serial.print(magic_number[0]);
    Serial.print(magic_number[1]);
    Serial.print(magic_number[2]);
    Serial.print(magic_number[3]);
    Serial.print(magic_number[4]);
}

void setup()
{
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.print("Initializing SD card...");
    if (!SD.begin(10))
    {
        Serial.println("initialization failed!");
        while (1)
            ;
    }
    Serial.println("initialization done.");
    // open the file for reading:
    myFile = SD.open("sample.bin");
    if (myFile)
    {
        Serial.println("sample.bin:");

        //test_file(&myFile);

        // read from the file until there's nothing else in it:
        while (myFile.available())
        {

            uint8_t thisByte = myFile.read();
            char letter[2];
            sprintf(letter, "%02X", thisByte);
            Serial.write(thisByte);
            Serial.write(" ");
            Serial.write(letter);
            Serial.write("\n");
        }
        // close the file:
        myFile.close();
    }
    else
    {
        // if the file didn't open, print an error:
        Serial.println("error opening sample.bin");
    }
}
void loop()
{
    // nothing happens after setup
}