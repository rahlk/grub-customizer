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
        $     *  �  1     �  9   �  )   (     R     j     |  S   �     �  &   �       
        )  +  :     f  *   }  -   �     �  +   �  %     *   >     i     �      �  (   �  O   �  &   #  �   J     �     �  %   �  1   $  /   V     �  #   �     �     �      �     
         %   6   3   \      �   	   �      �   '   �   )   �   -   !  �   M!  ,   ""  x   O"  �   �"  C   l#     �#  D   �#  (   $  %  +$  1   Q%  �   �%     &&  	   2&     <&     E&  	   Q&  	   [&     e&     v&     �&     �&     �&     �&     �&  &   �&     '     '     4'     ;'     B'     J'     e'     �'  
   �'     �'     �'     �'     �'     �'  "   �'     (     (     3(     ;(  
   G(  
   R(     ](     i(     w(     �(     �(     �(     �(     �(     �(  	   �(     �(     )      )     ')     @)  #   T)  	   x)     �)     �)     �)     �)     �)     �)     �)     �)     �)        /   1                -              +   c       k       x   A   j          T   "          !   &   `   l   *   C   <       ,       (   m      w   @              i       b   q          
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
PO-Revision-Date: 2012-03-10 21:19+0000
Last-Translator: Asier Iturralde Sarasola <Unknown>
Language-Team: Basque <eu@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2012-03-22 07:12+0000
X-Generator: Launchpad (build 14981)
  (pertsonalizatua) Ezin izan da %1 behar bezala exekutatu. errore mezua:
 %2 %1 ez da aurkitu. grub2 instalatuta dago? (%1-en sarrera berriak) (sarrera berriak) (script kodea) ETA: zure aldaketak oraindik gorde gabe daude, eguneraketak gordeko ditu hauek ere! _Itxura Gehitu script bat zure konfigurazioari Gehitu script-a BURG modua BURG aurkitu da! Grub konfigurazioa editatu ahal izateko lehenik
beharrezko partizioak muntatu behar dira.

Laguntzaile honek lagunduko dizu.

Mesedez, ziurtatu helburuko sistemaren cpu arkitektura
unean martxan dagoenaren berdina dela. Horrela ez bada,
errore mezu bat jasoko duzu konfigurazioa kargatzen saiatzean. Konfigurazioa gorde da Ezin izan da muntatu hautatutako partizioa Ezin izan da desmuntatu hautatutako partizioa Izenburu lehenetsia:  BURG konfiguratu nahi duzu grub2-ren ordez? Egindako aldaketak gorde nahi dituzu? Beste root partizio bat hautatu nahi duzu? Editatu grub hobespenak Sarrera %1 sarrera (posizioaren arabera) Errorea abioko kargatzailea instalatzean Grub Customizer grub2/burg-en ezarpenak konfiguratzeko interfaze grafiko bat da Grub Customizer: Partizio hautatzailea Instalatu abioko kargatzailea MBR-n eta jarri zenbait
fitxategi abioko kargatzailearen datu direktorioan
(dagoeneko existitzen ez badira). Instalatu MBR-n Muntaketak huts egin du! Muntatu hautatutako fitxategi-sistema Mugitu beherantz hautatutako sarrera edo script-a Mugitu gorantz hautatutako sarrera edo script-a Izendatu sarrera Ez da abioko kargatzailerik aurkitu Ez da script-ik aurkitu Partizio hautatzailea Mesedez, idatzi gailuaren izena! Aurrebista: Ez da proxy binariorik aurkitu! Kendu script bat zure konfiguraziotik Gorde konfigurazioa eta sortu horrelako berri bat:  Txertatu beharreko script-a: Segundoak Hautatu _partizioa... Hautatu eta muntatu zure root partizioa Hautatu beharrezko muntaketa azpi-puntuak Abioko kargatzailea behar bezala instalatu da Sortutako konfigurazioa ez da abioan gordetako konfigurazioaren berdina. Ondorioz, baliteke orain ikusten duzuna eta ordenagailua berrabiaraztean ikusiko duzuna bat ez etortzea. Hau konpontzeko, sakatu eguneratu! Gordetako konfigurazioa ez dago eguneratuta! Hauek dira zure fstab fitxategiko muntaketa-puntuak.
Mesedez, hautatu grub/boot-arekin erlazionatutako partizio guztiak. Aukera honek ez du funtzionatzen "os-prober" script-ak beste sistema eragileak aurkitzen dituenean. Desgaitu "%1" beste sistema eragilerik erabili behar ez baduzu. Hau root fitxategi-sistema bat dela dirudi (ez da fstab-ik aurkitu) Denbora-muga Goiko koloreak erabiltzeko atzeko
planoko irudia hautatu behar duzu! Desmuntatu muntatutako fitxategi-sistema Beste partizio bat aukeratzeko aukera hautatu duzu.
Kontutan izan os-prober-ek behar bada ez duela aurkituko unean martxan duzun sistema.
Beraz, exekutatu berriz Grub Customizer helburuko sisteman
eta gorde konfigurazioa (edo exekutatu update-grub/update-burg)
sarrera berriz ere agertu dadin! Live CD-a erabiliz abiarazi duzu Grub Customizer. Sarrera guztiak ikusiko dituzu (pertsonalizatu gabe) grub abiatzean. Errore hau gertatzen da (kasu gehienetan) Grub Customizer behar bezala instalatzen ez denean. _Aurreratua _Gailua:  _Editatu _Fitxategia _Orokorra _Laguntza _Instalatu MBR-n _Irten gorde gabe _Irten eguneratu gabe _Gorde eta irten _Eguneratu eta irten _Ikusi _erabili beste partizio bat:  gehitu sarrera hau azpimenu berri bati atzeko planoa atzeko planoko irudia beltza urdina marroia ezin da sarrera hau mugitu bereizmen pertsonalizatua:  ziana gris iluna sarrera lehenetsia letra-tipoaren kolorea sortu berreskuratze sarrerak berdea nabarmendua: abioko kargatzailea instalatzen... aktibo dago nukleoaren parametroak etiketa urdin argia zian argia gris argia berde argia magenta argia gorri argia konfigurazioa kargatzen... bilatu beste sistema eragileak magenta menuaren koloreak izena normala: partizioa aurre_definitua:  aurretik _kargatutako sarrera gorria birkargatu konfigurazioa kendu atzeko planoa kendu sarrera hau uneko azpimenutik ezarpenak erakutsi menua gardena mota desmuntaketak huts egin du! konfigurazioa eguneratzen balioa ikusgarritasuna zuria horia 