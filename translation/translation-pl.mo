��    F      L  a   |         	     "     >   .     m     �  "   �  
   �     �  1  �       %   $  &   J     q  /   �  '   �  -   �     	     	  %   #	  M   I	  "   �	  q   �	     ,
     ;
     I
  &   c
  $   �
     �
     �
     �
     �
     �
            '   2  &   Z     �     �  $   �     �  .   �  �     *   �  ^   �  8   W     �    �  .   �  �   �  	   n     x     ~     �     �     �     �     �     �     �     �       	         *     0     I  	   N     X     ]     l  �  �  
   *  2   5  B   h  *   �     �     �                    /  -   F  (   t     �  !   �     �     �            0     K   O      �  o   �     ,     =  $   \  -   �  .   �     �  $   �          &     6  	   V     `     �  '   �     �     �  !   �  (     3   <  �   p  )   0  `   Z  6   �     �  �     0   �  �        �     �     �     �     �     �          "     4     J     Q  #   i     �     �     �     �     �     �      �     �     D          (      )                 '   <                    
       8   ?                         &                	      ;   +      ,                     *   /   3   =      $      %      E   :          5   6   "       9   .      >   0                             F   #   1      !          4          C       @                  A   -   2       B      7     (custom)  command not found, cannot proceed  couldn't be executed successfully. You must run this as root!  not found. Is grub2 installed? (new Entries) Add a script to your configuration Add script BURG found! Before you can edit your grub configuration we have to
mount the required partitions.

This assistant will help you doing this.


Please ensure the target system is based on the same cpu architecture
as the actually running one.
If not, you will get an error message when trying to load the configuration. Configuration has been saved Couldn't mount the selected partition Couldn't umount the selected partition Default title:  Do you want to configure BURG instead of grub2? Do you want to save your modifications? Do you want to select another root partition? Edit grub preferences Entry Error while installing the bootloader Grub Customizer is a graphical interface to configure the grub2/burg settings Grub Customizer: Partition chooser Install the bootloader to MBR and put some
files to the bootloaders data directory
(if they don't already exist). Install to MBR Mount failed! Mount selected Filesystem Move down the selected entry or script Move up the selected entry or script Name the Entry No Bootloader found No script found Partition Chooser Please type a device string! Preview: Proxy binary not found! Remove a script from your configuration Save configuration and generate a new  Script to insert: Select _partition … Select and mount your root partition Select required submountpoints The bootloader has been installed successfully The generated configuration didn't equal to the saved configuration on startup. So what you see now may not be what you see when you restart your pc. To fix this, click update! The saved configuration is not up to date! These are the mountpoints of your fstab file.
Please select every grub/boot related partition. This seems not to be a root file system (no fstab found) Unmount mounted Filesystem You selected the option for choosing another partition.
Please note: The os-prober may not find your actually running system.
So run Grub Customizer on the target system
again and save the configuration (or run update-grub/update-burg)
to get the entry back! You started Grub Customizer using the live CD. You will see all entries (uncustomized) when you run grub. This error accurs (in most cases), when you didn't install grub gustomizer currectly. _Device:  _Edit _File _Help _Install to MBR … _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  installing the bootloader… is active label loading configuration… name partition type umount failed! updating configuration Project-Id-Version: grub-customizer
Report-Msgid-Bugs-To: FULL NAME <EMAIL@ADDRESS>
POT-Creation-Date: 2010-11-21 12:13+0100
PO-Revision-Date: 2010-10-25 00:48+0000
Last-Translator: Adam Czabara <kolofaza@o2.pl>
Language-Team: Polish <pl@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2010-11-22 21:40+0000
X-Generator: Launchpad (build Unknown)
  (dowolny)  polecenie nieodnalezione, nie można kontynuować  nie udało się wykonać pomyślnie. Musisz uruchomić jako root!  nie znaleziono. Grub2 jest zainstalowany? (nowe wpisy) Dodaj skrypt do konfiguracji Dodaj skrypt Znaleziono BURG! Przed edycją konfiguracji grub należy
zamontować wymagane partycje.

Asystent pomoże Ci to zrobić.

Upewnij się że system docelowy ma tą samą architekturę procesora
jak aktualnie używany
Jeżeli nie, zostanie wyświetlony błąd podczas ładowania konfiguracji. Zapisano konfigurację Nie udało się zamontować wybranej partycji Nie można odmontować wybranej partycji Domyślny tytuł:  Skonfigurować BURG zamiast grub2 Zapisać zmiany? Wybrać inną partycję root? Edycja preferencji grub Wpis Błąd w czasie instalacji programu rozruchowego Grub Customizer to graficzny interfejs do konfiguracji ustawień grub2/burg Grub Customizer: wybór partycji Instaluje program rozruchowy i umieszcza
pliki w katalogu danych programu rozruchowego
(jeżeli nie istnieją). Instalacja w MBR Montowanie nie powiodło się! Montowanie wybranego systemu plików Przenieś w dół wybraną pozycji lub skrypt Przenieś w górę wybraną pozycji lub skrypt Nazwij wpis Nie znaleziono programu rozruchowego Nie znaleziono skryptu Wybór partycji Prosze wpisać ciąg urzadzenia Podgląd: Nie znaleziono binarnego Proxy! Usuń skrypt z konfiguracji Zapisz konfigurację i wygeneruj nową  Skrypt do wstawienia: Wybierz _partycję ... Wybierz i zamontuj partycję root Wybór wymaganych punktów podmontowania Program rozruchowy został zainstalowany pomyślnie Wygenerowana konfiguracja jest inna niż konfiguracja zapisana podczas uruchomienia. Widniejąca konfiguracja może być inna podczas restartu komputera. W celu naprawy kliknij aktualizację! Zapisana konfiguracja jest przestarzała! To są punkty montowania pliku fstab.
Proszę wybrać każdą partycję powiązaną z grub/boot. To nie jest system plików root (nie znaleziono fstab) Odmontowanie systemu plików Wybrano inną partycję.
Można nie odnaleźć aktualnie używanego systemu.
Uruchom Grub Customizer na docelowym systemie
ponownie i zapisz konfigurację (lub uruchom update-grub/update-burg)
do odzyskania wpisów! Uruchomiono Grub Customize przy użyciu Live CD. Zobaczysz wszystkie wpisy (niedostosowane), gdy uruchomisz grub. Ten błąd występuje (najczęściej), jeżeli nie zainstalowano poprawnie grub customizer. _Urządzenie:  _Edycja _Plik _Pomoc _Instalacja w MBR _Zamknięcie bez zapisywania _Zamknij bez aktualizacji _Zapisz i zamknij _Aktualizuj i zamknij _Widok _Użyj innej partycji:  Instalacja programu rozruchowego... jest aktywne etykieta ładowanie konfiguracji... nazwa partycja typ Odmontowanie nie powiodło się! Aktualizacja konfiguracji 