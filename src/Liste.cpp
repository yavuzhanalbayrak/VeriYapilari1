/**
* @file         Liste.cpp
* @description  Listeye Düğüm ekleme ve çıkarma işlemlerini gerçekleştirir.
* @course       Veri Yapıları İkinci Öğretim B Grubu
* @assignment   1. Ödev
* @date         29.10.2021
* @author       Yavuzhan ALBAYRAK --- yavuzhan.albayrak@ogr.sakarya.edu.tr
*/

#include "Liste.hpp"


Liste::Liste(){
    ilk=0;
    dugumSayisi=0;
}
Liste::~Liste(){
    Dugum*gec=ilk;
    while(gec!=0){
        Dugum*sil=gec;
        gec=gec->sonraki;
        delete sil;
    }
    
}
void Liste::Ekle(string veri,int indeks){
    Dugum* yeni=new Dugum(veri);
    if(ilk==0)//ilk düğüm
        {
            ilk=yeni;//düğüm yoksa direkt ilk değer olarak atandı
            dugumSayisi++;
        
        }
    else{  
       
    if(indeks==0){  //ilk düğüm değişmesi durumu

       
         
            Dugum* gec=ilk;//geçici düğüm tanımlandı
            while(gec->sonraki!=0){//son düğüme gidildi
                gec=gec->sonraki;

            }  

            gec->sonraki=yeni;//son düğümün sonraki değerine yeni düğüm atandı
            yeni->onceki=gec;//yeni düğümün önceki değerine bi önceki düğüm atandı
            gec=gec->sonraki;//yeni düğüme geçildi
            string eskideger=yeni->veri;//eklenecek düğümün değeri tutuldu
            while(gec->onceki!=0){

                gec->veri=gec->onceki->veri;//ilk düğüme kadar veriler bi sağa kaydırılarak gidildi
                gec=gec->onceki;
                

            }
            ilk->veri=eskideger;//ilk düğüme eklenecek düğüm değeri atandı
        

        
        dugumSayisi++;//düğüm sayıcı

    }
    else if(indeks<=dugumSayisi-1)//Araya düğüm ekleme.
    {
        Dugum* gec=ilk;
            while(gec->sonraki!=0){//son düğüme gidildi
                gec=gec->sonraki;

            }
            
            gec->sonraki=yeni;//yeni düğüm sonda oluşturulup bağlandı
            yeni->onceki=gec;//bi öncekine bağlandı
            gec=gec->sonraki;
            string eskideger=yeni->veri;//eklenecek değer tutuldu
            for (int i = 0; i < dugumSayisi-indeks; i++)//eklenecek indekse kadar değerler sağa kaydırılarak gidildi
            {
                 gec->veri=gec->onceki->veri;
                gec=gec->onceki;
                
            }
            
            gec->veri=eskideger;//ilgili indekse gelinip değer atandı
            dugumSayisi++;
    }
    else{//indeks dışı düğüm ekleme
         Dugum* gec=ilk;
            while(gec->sonraki!=0){//son düğüme gelindi
                gec=gec->sonraki;

            }
            
            gec->sonraki=yeni;//yeni düğüm bağlama işlemi
            yeni->onceki=gec;
            dugumSayisi++;
    }
    }

   

}
void Liste::Sil(int indeks){
    Dugum* gec=ilk;
    if (ilk==0)//eleman yoksa silme işlemi yapılmadan fonksiyon bitirilir
    {
        return;
    }
    
    if(dugumSayisi==1){//tek düğüm varsa direkt silinir
        ilk=0;
        delete gec;
        dugumSayisi--;
    }
    else if(indeks<=dugumSayisi-2){//aradaki düğümü silme
        for (int i = 0; i < indeks; i++)//silinecek düğüme gidildi
        {
            gec=gec->sonraki;
        }
        while(gec->sonraki!=0){//sağdaki değerler sola doğru kaydırıldı ve son düğüme gidildi
            gec->veri=gec->sonraki->veri;
            gec=gec->sonraki;
        }
        delete gec;//son düğüm silindi
        gec->onceki->sonraki=0;//son düğümün adresi bi önceki düğümden silindi

        
        
        dugumSayisi--;
    }
    else{
         while(gec->sonraki!=0){//sondaki düğümü silme
            gec=gec->sonraki;
        }
       delete gec;//son düğüm silindi
       gec->onceki->sonraki=0;//son düğümün adresi bi önceki düğümden silindi
       dugumSayisi--;
        
    }
}