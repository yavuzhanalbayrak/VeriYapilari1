/**
* @file         Liste.hpp
* @description  Listeye sınıfının başlık dosyası.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   1. Ödev
* @date         29.10.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#ifndef LISTE_HPP
#define LISTE_HPP
#include "dugum.hpp"
class Liste
{
private:
    
public:
    int dugumSayisi;
    Dugum* ilk;
    Liste();
    ~Liste();
    void Ekle(string veri,int indeks);
    void Sil(int indeks);
};










#endif