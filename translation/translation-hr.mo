��    v      �  �   |      �	  	   �	  8   �	  !   4
     V
     j
     x
  E   �
     �
  "   �
  
   �
  	          1       N  %   k  &   �     �  /   �  '   �  -         N     d     j  %   �  M   �  "   �  q        �     �     �  &   �  $   �               0     @     R     o     x  '   �  &   �     �     �     �  $        4  .   S  �   �  *   3  ^   ^  �   �  8   Q     �  G   �     �    �  .   �  �   '  	   �  	   �     �     �     �     �     �     �          %     2     A     G  
   `     k     |     �     �     �     �     �  	   �     �  
   �     �     �  
           	   (     2     D  
   J  
   U  
   `     k     w  	   �     �      �     �     �     �     �  	   �     �                    4     F  	   O     Y     e     j     y     �  
   �     �     �  �  �     ]  7   m  )   �     �     �     �  O   �     M  !   U     w     �     �  !  �     �  '   �  )        ,  '   A     i  6   �     �     �     �  .   �  L        i  w   z     �       #     )   @  (   j     �  !   �     �     �     �     	       #   0  !   T     v     �     �  8   �  ,   �  '      �   7   %   !  a   )!  �   �!  O   "     o"  8   }"  %   �"    �"  5   �#  �   #$  	   �$  
   �$     �$  	   �$  
   �$     �$     �$     %     !%     9%     J%     ^%     f%     �%     �%     �%     �%     �%      �%     �%     �%  
   �%     �%  
   &     &     1&  
   8&      C&     d&     l&     ~&     �&     �&     �&     �&     �&     �&     �&  !   '     ''     9'     H'  	   N'  	   X'     b'     t'     �'     �'     �'     �'     �'     �'     �'     �'     �'  
   (  
   (     ((     /(     #   R   Q      i       E   
   $          W          v          "   *   F      I   +   p       B      T       >   3   =   N       d   ;   L      &   @   O          ]       :          /      n       M      5   6       A   a       K       (          [   0          '   7   H   X   8       !          Y   l   Z       j   D           \   S   J   V           4      b   f   2   r          ?                   s   q      k   	   g   P      e   `   c       %           9                U      <   h      1          .      ,   u   t   -                         G       o   m   C      ^       )       _     (custom) %1 couldn't be executed successfully. error message:
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
to get the entry back! You started Grub Customizer using the live CD. You will see all entries (uncustomized) when you run grub. This error accurs (in most cases), when you didn't install grub gustomizer currectly. _Advanced _Device:  _Edit _File _General _Help _Install to MBR … _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  background background image black blue brown cannot move this entry custom resolution:  cyan dark-gray default entry font color generate recovery entries green highlight: installing the bootloader… is active kernel parameters label light-blue light-cyan light-gray light-green light-magenta light-red loading configuration… look for other operating systems magenta menu colors name normal: partition pre_defined:  previously _booted entry red reload configuration remove background settings show menu transparent type umount failed! updating configuration value visibility white yellow Project-Id-Version: grub-customizer
Report-Msgid-Bugs-To: FULL NAME <EMAIL@ADDRESS>
POT-Creation-Date: 2011-12-23 17:05+0100
PO-Revision-Date: 2011-12-28 18:00+0000
Last-Translator: nafterburner <nafterburner@gmail.com>
Language-Team: Croatian <hr@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2012-03-22 07:12+0000
X-Generator: Launchpad (build 14981)
  (prilagođeno) %1 ne može se izvršiti uspješno. Poruka greške:
 %2 %1 nije pronađen. Jeli grub2 instaliran? (novi unosi od %1) (novi unosi) (kod skripte) I: vaše promjene još uvijek nisu spremljene, ažuriranje će spremiti i njih! I_zgled Dodajte skriptu vašim postavkama Dodaj skriptu BURG način BURG pronađen! Prije uređivanja vaših Grub postavki morate
montirati sve potrebne particije.
Ovaj pomoćnik će vam pomoći da to učinite.


Osigurajte da je željeni sustav temeljen na istoj cpu arhitekturi
kao trenutno pokrenuti.
Ako nije, dobit ćete poruku o grešci prilikom učitavanja postavki. Postavke su spremljene Nemoguće montiranje odabrane particije Nemoguće demontiranje odabrane particije Uobičajeni naslov:  Želite li podesiti BURG umjesto Grub2? Želite li spremiti izmjene? Želite li odabrati drugu korijensku (root) particiju? Uredi grub postavke Unos Unos %1 (po položaju) Pogreška tijekom instalacije boot učitavača Grub Prilagoditelj je grafičko sučelje za podešavanje Grub2/Burg postavki Odabir particija Instaliraj boot učitavač u MBR i stavi nešto
datoteka u boot učitavačov direktorij podataka
(ako već ne postoje). Instaliraj u MBR Montiranje nije uspjelo! Montiraj odabrani datotečni sustav Pomaknite dolje odabrani unos ili skriptu Pomaknite gore odabrani unos ili skriptu Naziv unosa Nema pronađenih boot učitavača Nema pronađenih skripti Odabir particija Molim utipkajte niz uređaja! Pregled: Proxy binaran nije pronađen! Uklonite skriptu iz vaših postavki Spremi postavke i generiraj novi  Ubacivanje skripte: sekundi Odaberi _particiju … Odaberite i montirajte vašu korijensku (root) particiju Odaberite odgovarajuću točku podmontiranja Boot učitavač je instaliran uspješno Generirane postavke nisu jednake spremljenim postavkama prilikom pokretanja. Stoga ono što vidite sada možda nećete vidjeti nakon ponovnog pokretanja računala. Da bi to popravili, kliknite ažuriraj! Spremljene postavke nisu ažurirane!! Ovo su točke montiranja vaše fstab datoteke.
Odaberite svaku odgovarajuću Grub/Boot particiju. Ova mogućnost ne radi dok "os-prober" skripta traži ostale operativne sustave. Onemogući "%1" ako ne trebate pokrenuti ostale operativne sustave Čini se da ovo nije korijenski (root) datotečni sustav (fstab nije pronađen) Istek vremena Da bi boje iznad radile, morate
odabrati sliku pozadine! Demontiraj odabrani datotečni sustav Odabrali ste mogućnost odabira druge particije.
Imajte na umu: OS-prober možda neće pronaći trenutno pokrenuti sustav.
Stoga ponovno pokrenite Grub Prilagoditelja na željenom sustavu
i spremite postavke (ili pokrenite ažuriraj-grub/ažuriraj-burg)
za povratak unosa! Pokrenuli ste Grub Prilagoditelja koristeći live CD. Vidjet ćete sve unose (neprilagođene) kada pokrenete Grub. Ova greška nastaje (u većini slučaja), kada ne instalirate Grub Prilagoditelja ispravno. _Napredno _Uređaj:  _Uredi _Datoteka _Općenito _Pomoć _Instaliraj u MBR … _Izađi bez spremanja _Izađi bez ažuriranja _Spremi i izađi _Ažuriraj i izađi _Prikaz _upotrijebi drugu particiju:  Pozadina Slika pozadine crna plava smeđa nemoguće je pomaknuti ovaj unos prilagođena rezolucija:  modra tamno-siva Uobičajeni unos Boja slova generiraj unos obnavljanja zelena Istaknuto: Instaliranje boot učitavača... Aktivno Parametri kernela Naziv svijetlo-plava svijetlo-modra svijetlo-smeđa svijetlo-zelena svijetlo-ljubičastocrvena svijetlo-crvena Učitavanje postavki... potraži druge operativne sustave ljubičastocrvena Boje izbornika Naziv Normalno: Particija pred_definirano:  prije _učitan unos crvena ponovno učitaj postavke ukloni pozadinu postavke prikaži izbornik prozirno Vrsta demontiranje nije uspjelo! Ažuriranje postavki Vrijednost Vidljivost bijela žuta 