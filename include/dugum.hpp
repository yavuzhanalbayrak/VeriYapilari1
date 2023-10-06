/**
* @file         dugum.hpp
* @description  Düğüm sınıfının başlık dosyası.
* @courseVeri   Yapıları İkinci Öğretim B Grubu
* @assignment   1. Ödev
* @date         29.10.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

class Dugum
{
private:
    
   
public:
    string veri;
    Dugum (string veri);
    ~Dugum();
    Dugum* sonraki;
    Dugum* onceki;

};







#endif
