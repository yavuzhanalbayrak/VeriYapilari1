/**
* @file         main.cpp
* @description  Düğümü oluşturup ekleme ve silme işlemlerini yaptıktan sonra ekrana yazdırır.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   1. Ödev
* @date         29.10.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include <fstream>
#include "dugum.hpp"
#include "Liste.hpp"
#include <iomanip>
 

using namespace std;
int main()
{
    char test;//veri dosyasından çekilen değerleri test etme amaçlı
    string indeks;//gerekli atamalar yapıldı.
    string deger;
    string bilgi;
    string islem;
    Liste* list=new Liste();
    ifstream Veri(".\\doc.\\Veri.txt");
    
    
        while (!Veri.eof())//döngü ile veri.txt dosyasının her satırı okundu.
        {
            
            getline(Veri,bilgi);//satır okuma.
            if(bilgi.length()==0) break;//son satır boş ise döngü kapanır.
            islem = bilgi.at(0);//E veya S olma durumu.
            indeks=bilgi.at(2);//indeksin ilk hanesi bulundu
           for (int i = 3; i < bilgi.length(); i++)//indeksin çok haneli olma durumuna karşı denetleme yapılıp indeks değişkenine atandı
           {
               test=bilgi.at(i);//tüm karakterler alındı
               
               if((int)test>47 && (int)test<58){//ASCII tablosuna göre karakterler rakam mı değil mi kontrol edildi
                   indeks+=test;//bulunan rakamlar birleştirilip indeks oluşturuldu

               }
               
               
           }
        deger= bilgi.substr(3+indeks.length(),bilgi.length()-4-indeks.length());//veri dosyasındaki veri gerekli gözetmeler yapılıp çekildi
          
           
            if (islem=="E")//Ekleme işlemi
            {
                  
               list->Ekle(deger,stoi(indeks));
                
            }
            else if(islem=="S")//Silme işlemi
            {
                list->Sil(stoi(indeks));
            }
            else break;
            
        }
        Dugum* gec=list->ilk;


         
        
           

        for (int i = 0; i <= list->dugumSayisi-1; i++)//listenin son hali yazdırıldı
        {
           if (i==0)
           {
                cout<<gec->veri;
                gec=gec->sonraki;
           }
           else if (i<list->dugumSayisi)
           {
                cout<<"  <--->  "<<gec->veri;
                gec=gec->sonraki;
           }
           else
           {
                cout<<"  <--->  "<<gec->veri;
                gec=gec->sonraki;
           }
           
           


        }
        delete list;
        
         
    

    return 0;
}

