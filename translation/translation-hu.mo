��    x      �  �   �      (
  	   )
  8   3
  !   l
     �
     �
     �
  E   �
       "     
   3  	   >     H  1  T     �  %   �  &   �     �  /      '   0  -   X     �     �     �  %   �  M   �  "   -  q   P     �     �     �  &   �  $         E     T     h     x     �     �     �  '   �  &   �          )     1  $   G     l  .   �  �   �  *   k  ^   �  �   �  8   �     �  G   �         -  .   0  �   _  	   �  	   �          
                    3     H     ]     j     y          �  
   �     �     �     �     �     �     �       	          
   -     8     R  
   X     c  	   �     �     �  
   �  
   �  
   �     �     �  	   �     �            !     )     5     :  	   B     L     Z     s     w     �  *   �     �  	   �     �     �     �     �       
        $     *  �  1  
   �  B   �  4        S     g     x  R   �     �  '   �       	   !     +  a  =     �  4   �  3   �        2   8  %   k  -   �  !   �  
   �  !   �  &     F   5  '   |  z   �          2  /   Q  9   �  9   �     �           #      :   )   P      z      �      �   5   �      �      !     !  2   ,!  3   _!  "   �!  �   �!  +   �"  s   �"  �   >#  >   �#     $  R   1$  /   �$  )  �$  5   �%  �   &     �&  
   �&     �&     �&     '     '     '     0'     L'     l'     �'     �'     �'  &   �'     �'     �'     �'     (     (  '   (     9(  	   N(     X(     g(  
   �(  '   �(     �(  
   �(     �(     �(     �(     �(     )     )     %)     5)     C)     T)     b)  #   �)     �)     �)     �)  
   �)  
   �)     �)     �)     	*     *     -*  0   @*     q*     �*     �*     �*     �*     �*     �*     �*     �*     �*        /   1                -              +   c       k       x   A   j          T   "          !   &   `   l   *   C   <       ,       (   m      w   @              i       b   q          
   [       a   ;       o      e   4   .           N           _         F   v   Y   #   s   0   G   I          L   :   6       Q          O   h       ]      K   '   V      \   5   r           E   S       %       7   X   g   H   $       9          Z       D           3   p                 M   U      ^   >   R   n                   2       W   )       P   f   u                          d   	   t          B   =   ?   8       J        (custom) %1 couldn't be executed successfully. error message:
 %2 %1 not found. Is grub2 installed? (new Entries of %1) (new Entries) (script code) AND: your modifications are still unsaved, update will save them too! A_ppearance Add a script to your configuration Add script BURG Mode BURG found! Before you can edit your grub configuration we have to
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
to get the entry back! You started Grub Customizer using the live CD. You will see all entries (uncustomized) when you run grub. This error accurs (in most cases), when you didn't install grub gustomizer currectly. _Advanced _Device:  _Edit _File _General _Help _Install to MBR … _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  add this entry to a new submenu background background image black blue brown cannot move this entry custom resolution:  cyan dark-gray default entry font color generate recovery entries green highlight: installing the bootloader… is active kernel parameters label light-blue light-cyan light-gray light-green light-magenta light-red loading configuration… look for other operating systems magenta menu colors name normal: partition pre_defined:  previously _booted entry red reload configuration remove background remove this entry from the current submenu settings show menu transparent type umount failed! updating configuration value visibility white yellow Project-Id-Version: grub-customizer
Report-Msgid-Bugs-To: FULL NAME <EMAIL@ADDRESS>
POT-Creation-Date: 2011-12-23 17:05+0100
PO-Revision-Date: 2012-03-08 22:05+0000
Last-Translator: Vizion-HUN <Unknown>
Language-Team: Hungarian <hu@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2012-03-22 07:12+0000
X-Generator: Launchpad (build 14981)
  (egyéni) A(z) %1 végrhajtása sikertelen. A hibeüzenet a következő:
 %2 A(z) %1 nem található. Fel van telepítve a grub2? (%1 új Bejegyzés) (új Bejegyzés) Kód írása ÉS: a módosítások még nincsenek mentve, a frissítés menteni is fogja őket! _Megjelenés Script hozzáadása a konfigurációhoz Script hozzáadása BURG Mód BURG megtalálva! Mielőtt szerkeszteni tudja a grub konfigurációját
fel kell csatolnia a szükséges partíciókat.

Ez a varázsló fogja segíteni önt ebben.


Kérem bizonyosodjon meg arról, hogy a cél rendszer ugyan olyan
cpu architektúrán fut, mint amit éppen futtat.
Ha nem, akkor hibaüzenetet fog kapni, mikor megpróbálja betölteni a konfigurációt. Konfiguráció elmentve Nem csatlakoztatható fel a kiválasztott partíció Nem csatlakoztatható le a kiválasztott partíció Alapértelmezett cím:  Szeretné a BURG-ot konfigurálni a grub2 helyett? Szeretné menteni a módosításokat? Szeretne más root partíciót kiválasztani? Grub tulajdonságok szerkesztése Bejegyzés Bejegyzés %1 (pozíció szerint) Hiba a boottöltő telepítése során Grub Customizer egy grafikus interfész a grub2/burg beállításához Grub Customizer: Partíció választás Boottöltő telepítése az MBR-be és néhány
fájl létrehozása a boottöltő adatmappájába
(ha még nem léteznek). MBR-be telepítés Felcsatlakoztatás sikertelen! Kivélasztott Fájlrendszer felcsatlakoztatása A kiválasztott bejegyzés vagy script lejjebb mozgatása A kiválasztott bejegyzés vagy script feljebb mozgatása A bejegyzés neve Nem található boottöltő Script nem található Partíció Választó Kérem gépeljen be egy eszköz stringet! Előnézet: Proxy nem található! Script eltávolítása Konfiguráció mentése és új fájl létrehozása:  Beillesztendő script: Másodpercek _Partició kiválasztása ... Válassza ki és csatolja fe a root partícióját Válassza ki a szükséges alcsatlakozási helyeket A boottöltő sikeresen telepítve A generált konfiguráció nem egyezett meg az elmentett konfigurációval induláskor. Tehát amit most lát nem ugyanaz mit akkor fog látni mikor újra indítja a számítógépét. Hogy javítsa ezt, kattintson a frissítésre! Az elmentett konfiguráció nem naprakész! Ezek az fstab fájlban található csatolási helyek.
Kérem válassza ki a grub/boot-al rendelkező partíciókat. Ez az opció nem működik, amikor az "os-prober" script talál más operációs rendszereket. Tiltsa le "%1", ha nem akar bebootolni más operációs rendszert. Úgy tűnik ez nem root fájl rendszer (fstab nem található) Várakozási idő Ahhoz, hogy a fenti színek működjenek,
ki kell választania egy háttérképet! Felcsatlakoztatott Fájlrendszerek lecsatolása Ön azt az opciót választotta, hogy más partíciót választ.
Megjegyzés: Az os-prober script talán nem találja meg az éppen futó rendszerét.
Ezért futtassa újra a cél rendszeren és
mentse a konfigurációt (vagy futtassa: update-grub/update-burg),
hogy vissza kapja a bejegyzéseket! A Grub Customizer-t live CD használatkor indította. Az összes bejegyzést így fogja látni (nincs testre szabva), amikor futtatja a grub-ot. Ez a hiba akkor fordul elő (a legtöbb esetben), amikor a grub customizer nincs helyesen telepítve. _Speciális _Eszköz:  _Szerkesztés _Fájl Á_ltalános _Súgó _Telepítés az MBR-be... K_ilépés mentés nélkül _Kilépés frissítés nélkül _Mentés @ Kilépés _Frissítés & Kilépés _Nézet _használjon más partíciót:  Bejegyzés hozzáadása az almenühöz háttér háttérkép fekete kék barna Ezt a bejegyzést nem lehet áthelyezni egyéni felbontás:  ciánkék sötétszürke alapértelmezett bejegyzés betűszín helyreállító bejegyzés generálása zöld kiemelés: boottöltő telepítése... aktív kernel paraméterek címke világoskék világos-ciánkék világosszürke világoszöld világos-magenta világospiros konfiguráció betöltése... más operációs rendszer keresése magenta menü színei név normális: partíció előre_definiált:  előzetesen _bootolt bejegyzés piros konfiguráció újratöltése háttér törlése Bejegyzés eltávolítása ebből az almenüből beállítások menü mutatása átlátszó típus lecsatolás sikertelen! konfiguráció frissítése érték láthatóság fehér sárga 