#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
bool lighten;
unsigned char image[SIZE][SIZE][RGB];
void loadImage ();
void saveImage ();
void darken_lighten ();
bool check_state();
void start();
int main()
{
    start();
}
//------------------------------------------------
void loadImage () {
    char imageFileName[100];

    // Get RGB scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
//------------------------------------------------
void saveImage () {
    char imageFileName[100];

    // Get RGB scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}
//------------------------------------------------

void darken_lighten() {
    int amount = 64;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {
                if(lighten) {
                    image[i][j][k] = min(255, image[i][j][k] + amount);
                }else{
                    image[i][j][k] = max(0, image[i][j][k] - amount);
                }
            }
        }
    }
}

void take_choice(){
    char tmp;
    cout << "Do you want to (d)arken or (l)ighten? ";
    cin >> tmp;
    if(tmp != 'd' && tmp != 'l'){
        cout << "Please enter the correct choice\n";
        take_choice();
        return;
    }
    if(tmp == 'd'){
        lighten = false;
    }else{
        lighten = true;
    }
}

bool check_state(){
    char tmp;
    cout << "Do you want to do another filter? (y)es or (n)o: ";
    cin >> tmp;
    if(tmp != 'y' && tmp != 'n'){
        cout << "Please enter correct choice.\n";
        check_state();
    }
    if(tmp == 'y'){
        return true;
    }
    return false;
}

void start(){
    loadImage();
    take_choice();
    darken_lighten();
    saveImage();
    if(check_state()){
        start();
    }
}