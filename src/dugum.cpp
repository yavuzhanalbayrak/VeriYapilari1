/**
* @file         dugum.cpp
* @description  Duğum sınıfının kurucusunu oluşturur.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   1. Ödev
* @date         29.10.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/

#include "dugum.hpp"

Dugum::Dugum(string veri){
    this->veri=veri;
    this->onceki=0;//düğümün önceki ve sonraki adresleri null olarak atandı.
    this->sonraki=0;
}

Dugum::~Dugum(){
}

