��    s      �  �   L      �	  	   �	     �	     �	  E   �	     3
  "   ?
  
   b
  	   m
     w
  1  �
     �  %   �  &   �       /   /  '   _  -   �     �     �     �  %   �  M     "   \  q        �             &   (  $   O     t     �     �     �     �     �     �  '   �  &        F     X     `  $   v     �  .   �  �   �  *   �  ^   �  �   $  8   �     �  G   �     A    \  .   _  �   �  	     	   )     3     9     ?     H     N     b     w     �     �     �     �  
   �     �     �     �     �     �            	   $     .  
   <     G     a  
   g     r  	   �     �     �  
   �  
   �  
   �     �     �  	   �     �           0     8     D     I  	   Q     [     i     �     �     �     �  	   �     �     �     �     �     �  
   �            �       �     �     �  P   �  
   ?  %   J  
   p  	   {     �  L  �     �  &   �  %   !     G  2   ^  /   �  2   �     �       !     5   8  L   n  )   �  s   �     Y     g     ~  .   �  -   �     �  !        /     >     U  
   u  &   �  *   �  '   �     �            .   *  )   Y  #   �  �   �  (   �   d   �   �   '!  =   �!     "  Q   #"     u"  H  �"  ;   �#  �   $     �$  	   �$  	   �$     �$     �$     �$     �$     	%     %     0%     ?%     Q%     ]%     }%     �%     �%     �%  
   �%     �%     �%     �%     �%     �%     &     &     1&     8&     A&     \&     b&     z&     �&     �&  
   �&     �&     �&     �&     �&      �&     '     '     ,'     1'     9'     H'     W'  
   k'     v'     �'     �'     �'     �'     �'     �'     �'     �'     (     (     (         O   N      f       B      !          T   	       s             '   C      F   (   m       ?   g   Q       ;   0   :   K       a   8   I      #   =   L          Z       7          ,      k       J   
   2   3       >   ^       H       %          X   -          $   4   E   U   5                 V   i   W           A           Y   P   G   S           1      _   c   /   o          <                  p   n      h      d   M       b   ]           "           6                R      9   e   `   .          +      )   r   q   *                         D       l   j   @      [       &       \     (custom) (new Entries of %1) (new Entries) AND: your modifications are still unsaved, update will save them too! A_ppearance Add a script to your configuration Add script BURG Mode BURG found! Before you can edit your grub configuration we have to
mount the required partitions.

This assistant will help you doing this.


Please ensure the target system is based on the same cpu architecture
as the actually running one.
If not, you will get an error message when trying to load the configuration. Configuration has been saved Couldn't mount the selected partition Couldn't umount the selected partition Default title:  Do you want to configure BURG instead of grub2? Do you want to save your modifications? Do you want to select another root partition? Edit grub preferences Entry Entry %1 (by position) Error while installing the bootloader Grub Customizer is a graphical interface to configure the grub2/burg settings Grub Customizer: Partition chooser Install the bootloader to MBR and put some
files to the bootloaders data directory
(if they don't already exist). Install to MBR Mount failed! Mount selected Filesystem Move down the selected entry or script Move up the selected entry or script Name the Entry No Bootloader found No script found Partition Chooser Please type a device string! Preview: Proxy binary not found! Remove a script from your configuration Save configuration and generate a new  Script to insert: Seconds Select _partition … Select and mount your root partition Select required submountpoints The bootloader has been installed successfully The generated configuration didn't equal to the saved configuration on startup. So what you see now may not be what you see when you restart your pc. To fix this, click update! The saved configuration is not up to date! These are the mountpoints of your fstab file.
Please select every grub/boot related partition. This option doesn't work when the "os-prober" script finds other operating systems. Disable "%1" if you don't need to boot other operating systems. This seems not to be a root file system (no fstab found) Timeout To get the colors above working,
you have to select a background image! Unmount mounted Filesystem You selected the option for choosing another partition.
Please note: The os-prober may not find your actually running system.
So run Grub Customizer on the target system
again and save the configuration (or run update-grub/update-burg)
to get the entry back! You started Grub Customizer using the live CD. You will see all entries (uncustomized) when you run grub. This error accurs (in most cases), when you didn't install grub gustomizer currectly. _Advanced _Device:  _Edit _File _General _Help _Install to MBR … _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  background background image black blue brown cannot move this entry custom resolution:  cyan dark-gray default entry font color generate recovery entries green highlight: installing the bootloader… is active kernel parameters label light-blue light-cyan light-gray light-green light-magenta light-red loading configuration… look for other operating systems magenta menu colors name normal: partition pre_defined:  previously _booted entry red reload configuration remove background settings show menu transparent type umount failed! updating configuration value visibility white yellow Project-Id-Version: grub-customizer
Report-Msgid-Bugs-To: FULL NAME <EMAIL@ADDRESS>
POT-Creation-Date: 2011-12-23 17:05+0100
PO-Revision-Date: 2011-12-28 18:00+0000
Last-Translator: Mustafa Yılmaz <apshalasha@gmail.com>
Language-Team: Turkish <tr@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2012-02-06 19:12+0000
X-Generator: Launchpad (build 14747)
  (özel) (%1 yeni Kayıt) (yeni Girdiler) VE: değiştirmeleriniz hala kaydedilmedi, güncelleme onları da kaydedecektir! Görünüm Yapılandırmanıza bir betik ekleyin Betik ekle BURG Kipi BURG bulundu! Grub yapılandırmasını düzenlemeden önce
gerekli bölümleri bağlamamız gerekiyor.

Bu yardımcı size bu konuda yardım edecek.


Lütfen hedef sistemin şu anda çalışan sistemle aynı cpu mimarisine
sahip olduğundan emin olun.
Değilse, yapılandırmayı yüklemeye çalıştığınızda bir hata mesajı alacaksınız. Yapılandırma kaydedildi Seçilen disk bölümü bağlanamıyor Seçilen disk bölümü ayrılamıyor Varsayılan seçenek:  grub2 yerine BURG'u yapılandırmak ister misiniz? Değişikliklerinizi kaydetmek istiyor musunuz? Başka bir root bölümü seçmek istiyor musunuz? grub tercihlerini düzenle Giriş Giriş %1 (bulunduğu yere göre) Önyükleyicinin yüklenmesi sırasında hata oluştu Grub Customizer, grub2/burg ayarlarını yapabilen bir grafiksel arayüzdür Grub Düzenleyici: Disk bölümü seçici Önyükleyiciyi MBR'ye yükle ve gerekli
dosyaları önyükleyici veri dizinine yerleştir
(eğer mevcut değilse). MBR'ye yükle Bağlama başarısız! Seçilen dosya sistemini bağla Seçilen girdi ya da betiği aşağıya taşı Seçilen girdi ya da betiği yukarıya taşı Girdiyi Adlandır Hiçbir Önyükleyici bulunamadı Hiç betik yok Disk Bölümü Seçici Lütfen bir cihaz dizisi girin! Önizleme: Proxy ikili kod programı bulunamadı! Yapılandırmanızdan bir betik çıkarın Yapılandırmayı kaydet ve   oluştur  Eklenecek betik: Saniye Disk bölümü seç … Kök disk bölümünüzü seçin ve bağlayın Gereken alt bağlama noktalarını seçin Önyükleyici başarıyla yüklendi Üretilen ayarlama, başlangıçtaki kaydedilmiş ayarlamayla aynı değil. O yüzden; şu an gördüğünüz, bilgisayarınızı yeniden başlattığınızda göreceğinizle aynı olmayabilir. Bunu düzeltmek için, güncelle'yi tıklayın! Kayıtlı yapılandırma güncel değil! Bunlar fstab dosyanızın bağlama noktaları.
Lütfen tüm grub/boot ile alakalı bölümü seçin. Bu seçenek "os-prober" betiği diğer işletim sistemlerini bulduğunda çalışmaz. Diğer işletim sistemlerini önyüklemeye ihtiyaç duymuyorsanız "%1" etkisiz kılın. Bu bir kök dosya sistemi değil (fstab dosyası bulunamadı) Zaman aşımı Yukarıdaki renkleri çalıştırabilmek için,
bir arkaplan resmi seçmelisiniz! Seçilen dosya sistemini ayır Diğer bir bölüm seçme seçeneğini seçtiniz.
Lütfen dikkat: işletim sistemi tanımlayıcısı şu anki çalışan sisteminizi bulamayabilir.
bu durumda Grub Customizer'i hedef sistemde tekrar çalıştırın
ve kaydı geri alabilmek içinyapılandırmayı kaydedin
(veya update-grub/update-burg komutunu çalıştırın)! Grub Düzenleyici'yi Çalışan CD'den çalıştırdınız. grub'ı çalıştırdığınızda tüm girişleri (değiştirilmemiş) bulacaksınız. Bu hata (genelde), grub customizer düzgün kurulamadığı zaman gerçekleşir. _Gelişmiş _Aygıt:  _Düzenle _Dosya _Genel _Yardım MBR'ye yükle... Kaydetmeden çık Güncellemeden çık Kaydet & Çık Güncelle & Çık _Görünüm farklı disk bölümü kullan:  arkaplan arkaplan resmi siyah mavi kahverengi bu kayıt kaldırılamıyor özel çözünürlük:  turkuaz koyu-gri varsayılan girdi yazı tipi rengi kurtarma girdilerini oluştur yeşil vurgulu: önyükleyici kuruluyor… aktif çekirdek parametreleri etiket açık-mavi açık-turkuaz açık-gri açık-yeşil açık-eflatun açık-kırmızı yapılandırma yükleniyor… diğer işletim sistemlerini ara eflatun menü renkleri isim normal: disk bölümü öntanımlı:  son yüklenen girdi kırmızı yapılandırmayı tazele arkaplanı kaldır ayarlar menüyü göster şeffaf tip ayırma başarısız! yapılandırma güncelleniyor değer görünürlük beyaz sarı 