#include "Capture.hpp"
#include "string"
#include "fstream"
#include "iostream"
#include "sstream"
#include "webcam_snapshot/TakePicture.hpp"

TakePicture::TakePicture() { }
/**
 * This function checks to see what pictures already exist in the file so that it doesn't
 * overwrite any of them. It then takes a picture using the function getCap of the class Capture
 * in the file Capture.cpp
 */
void TakePicture::snap()
{
    int count = 1;
    std::stringstream file1;
    file1 << "webcam_output" << count << ".jpeg";
    std::ifstream ifile(file1.str().c_str());
    bool found = ifile;
    while (found) {
        std::cout << "The file exists";
        count = count + 1;
        ifile.close();
        file1.str(std::string());
        file1.clear();
        file1 << "webcam_output" << count << ".jpeg";
        std::ifstream ifile(file1.str().c_str());
        found = ifile;
    }

    Capture cap(file1.str());
    /// the function getCap actually takes the picture
    int done = cap.getCap();
}


