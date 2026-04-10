# Akıllı [README.md](https://github.com/user-attachments/files/26632292/README.md)
Sınıf/Laboratuvar-Ortam-Kontrol-Sistemi-
ESP32 tabanlı, sıcaklık, nem ve ışık verilerini izleyen ve otomatik kontrol sağlayan IoT akıllı sınıf/laboratuvar sistemi.
# 🧠 Akıllı Sınıf / Laboratuvar Ortam Kontrol Sistemi

## 📌 Proje Hakkında
Bu proje, IoT tabanlı bir akıllı ortam kontrol sistemidir. ESP32 kullanılarak sıcaklık, nem ve ışık ölçülür ve otomatik kontrol sağlanır.

## ⚙️ Özellikler
- DHT22 ile sıcaklık & nem
- LDR ile ışık ölçümü
- Röle ile fan ve ışık kontrolü
- Web arayüzü + login sistemi

## 🔐 Giriş
Kullanıcı: admin  
Şifre: 1234

## 🚀 Kurulum
1. Arduino IDE aç
2. ESP32 seç
3. main.ino yükle
4. IP adresi ile tarayıcıdan gir# Donanım Bağlantı Listesi - Akıllı Sınıf / Laboratuvar Ortam Kontrol Sistemi

## Kullanılan Bileşenler
- ESP32
- DHT22 (Sıcaklık ve Nem Sensörü)
- LDR (Işık Sensörü)
- 2 Kanal Röle Modülü
- 10k direnç
- Breadboard
- Jumper kablolar

## 1) DHT22 Bağlantısı
- DHT22 VCC -> ESP32 3.3V
- DHT22 DATA -> ESP32 GPIO4
- DHT22 GND -> ESP32 GND
- DATA ile 3.3V arasına 10k pull-up direnç bağlanır

## 2) LDR Bağlantısı
- LDR'nin bir ucu -> ESP32 3.3V
- LDR'nin diğer ucu -> ESP32 GPIO34
- GPIO34 ile GND arasına 10k direnç bağlanır

### LDR mantığı
Bu bağlantı bir gerilim bölücü oluşturur. ESP32, GPIO34 üzerinden analog ışık değerini okur.

## 3) Röle Modülü Bağlantısı
### Röle giriş pinleri
- Röle IN1 -> ESP32 GPIO18  (Işık kontrolü)
- Röle IN2 -> ESP32 GPIO19  (Fan / klima kontrolü)
- Röle VCC -> 5V
- Röle GND -> GND

## 4) Röle Çıkış Bağlantısı
### Işık için
- COM -> güç hattı
- NO -> lamba / ışık çıkışı
- NC -> kullanılmaz

### Fan için
- COM -> güç hattı
- NO -> fan / klima çıkışı
- NC -> kullanılmaz

## 5) ESP32 Genel Pin Özeti
- GPIO4 -> DHT22 DATA
- GPIO34 -> LDR analog giriş
- GPIO18 -> Işık rölesi
- GPIO19 -> Fan rölesi
- 3.3V -> Sensör besleme
- GND -> Ortak toprak

## Kritik Notlar
- ESP32 3.3V ile çalışır
- Tüm GND uçları ortak olmalıdır
- DHT22 veri hattında pull-up direnç kullanılmalıdır
- LDR tek başına bağlanmaz, gerilim bölücü şeklinde bağlanmalıdır
- Röle modülü çoğu durumda 5V ile beslenir

## Kısa Özet
- DHT22 -> GPIO4
- LDR -> GPIO34
- Işık rölesi -> GPIO18
- Fan rölesi -> GPIO19

