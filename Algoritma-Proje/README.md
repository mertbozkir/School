# Algoritma ve Programlama Projesi 

## **Projenin Genel Özeti**
    1- Kullanıcıdan bir metin alınır
    2- Alınan metin yabancı karakterlerden temizlenir.
    3- Metindeki bigram ve trigramların sayısı hesaplanır.
    4- Belirtilen frekans değerleri yardımıyla metnin dilinin hangi dil olduğu bulunur.





## Proje Boyunca Uygulanan Adımlar

Kullanıcıdan girdi almak için gets fonksiyonunu dahil ederek başladık.

Alınan girdide geçen bigram ve trigramların frekansını hesapladık.

Alınan girdide void filter_str(char str[]) fonksiyonu kullanarak yabancı karakterlerin yerine boşluk karakteri yerleştirerek alınan girdideki yabancı kelimeleri görünmez kıldık.Girdiyi yabancı karakterlerden arındırdıktan sonra bütün karakterleri küçük harfe çevirerek bigram ve trigramlar hesaplanırken sorun çıkmamasını sağladık

Alınan girdide void calculate_frequencies_bi(char str[]) fonksiyonu kullanarak
 her bir bigramın metinde kaç kez tekrar ettiğini hesapladık ve sonra bu frekansları calculated_frequencies[l] dizisine sırasıyla yerleştirdik.
 
 void calculate_distances() fonksiyonu ile İngilizce ve Almanca dillerine sayısal değerler verdik  ve Distances[0] dizisine İngilizce için hesaplanan sayısal değeri atamış olduk. Distances[1] dizisi ise Almanca için hesaplanan sayısal değeri atadık.

void detect_lang fonksiyonu ile yazının hangi dile daha yakın olduğunu ve bu sayede hangi dilde olduğunu anlamış olduk.



**Projeyi Hazırlayanlar:**
    
    Enes Tektaş: 19360859003
    Mert Bozkır: 19360859007





**Kaynaklar:**
 
    1. Murat Yücedağ
    2. Bilgisayar Kavramları
    3. Ergün Hoca  
