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
     �
     �
  '     &   =     d     v  $   �     �  .   �  �   �  *   �  ^   �  8   :     s    �  .   �  �   �  	   Q     [     a     g     m     �     �     �     �     �     �     �  	                  ,  	   1  <   ;     x     }     �  �  �     \  T   z  �   �  :   V     �  O   �  "   �  ,     ]  I  6   �  F   �  J   %  '   p  D   �  =   �  G     <   c  
   �  k   �  }     '   �  �   �     �  +   �  H   �  X   ;  X   �     �  N     !   U     w     �  I   �  Q   �  Y   :  #   �     �  G   �  R     j   o  u  �  G   P   �   �   ^   T!  P   �!  �  "  C   �#    �#     %     %  	   7%     A%  "   M%  %   p%  '   �%     �%  #   �%     �%  ,   
&  Z   7&     �&     �&  7   �&     �&     �&  �   �&     �'  /   �'  6   �'     D          '      (                 &   ;                    
       7   >                         %                	      :   *      +                     )   .   2   <      #      $      E   9          4   5   !       8   -      =   /                             F   "   0      C          3          B       ?                  @   ,   1       A      6     (custom)  command not found, cannot proceed  couldn't be executed successfully. You must run this as root!  not found. Is grub2 installed? (new Entries) Add a script to your configuration Add script BURG found! Before you can edit your grub configuration we have to
mount the required partitions.

This assistant will help you doing this.


Please ensure the target system is based on the same cpu architecture
as the actually running one.
If not, you will get an error message when trying to load the configuration. Configuration has been saved Couldn't mount the selected partition Couldn't umount the selected partition Default title:  Do you want to configure BURG instead of grub2? Do you want to save your modifications? Do you want to select another root partition? Edit grub preferences Entry Error while installing the bootloader Grub Customizer is a graphical interface to configure the grub2/burg settings Grub Customizer: Partition chooser Install the bootloader to MBR and put some
files to the bootloaders data directory
(if they don't already exist). Install to MBR Mount failed! Mount selected Filesystem Move down the selected entry or script Move up the selected entry or script Name the Entry No Bootloader found No script found Partition Chooser Preview: Proxy binary not found! Remove a script from your configuration Save configuration and generate a new  Script to insert: Select _partition … Select and mount your root partition Select required submountpoints The bootloader has been installed successfully The generated configuration didn't equal to the saved configuration on startup. So what you see now may not be what you see when you restart your pc. To fix this, click update! The saved configuration is not up to date! These are the mountpoints of your fstab file.
Please select every grub/boot related partition. This seems not to be a root file system (no fstab found) Unmount mounted Filesystem You selected the option for choosing another partition.
Please note: The os-prober may not find your actually running system.
So run Grub Customizer on the target system
again and save the configuration (or run update-grub/update-burg)
to get the entry back! You started Grub Customizer using the live CD. You will see all entries (uncustomized) when you run grub. This error accurs (in most cases), when you didn't install grub gustomizer currectly. _Device:  _Edit _File _Help _Install to MBR … _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  installing the bootloader… is active label loading configuration… name partition reload configuration (same effect as an application restart) type umount failed! updating configuration Project-Id-Version: grub-customizer
Report-Msgid-Bugs-To: FULL NAME <EMAIL@ADDRESS>
POT-Creation-Date: 2010-10-22 20:01+0200
PO-Revision-Date: 2010-10-30 20:51+0000
Last-Translator: Svetoslav Stefanov <svetlisashkov@yahoo.com>
Language-Team: Bulgarian <bg@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2010-11-06 08:32+0000
X-Generator: Launchpad (build Unknown)
  (потребителски)  командата не е открита, не може да се продължи  не можа да се изпълни успешно Това трябва да се пусне като администратор!  не е открит. Инсталиран ли е grub2? (нови записи) Добавяне на скрипт към вашата конфигурация Добавяне на скрипт Открита е програмата BURG! Преди да можете да редактирате вашата grub конфигурация, ние трябва да
монтираме необходимите дялове.

Този помощник ще ви помогне за това.


Моля уверете се, че целевата система е със същата процесорна архитектура
като тази на текущо пусната.
В противен случай при опит за зареждане на конфигурацията ще получите съобщение за грешка. Конфигурацията беше запазена Избраният дял не може да бъде монтиран Избраният дял не може да бъде демонтиран Стандартно заглавие:  Желаете ли да настроите BURG вместо grub2? Желаете ли да запазите промените? Желаете ли да изберете друг главен дял? Редактиране на настройките на grub Запис Грешка при инсталиране на програмата за начално зареждане Grub Customizer е графичен интерфейс за конфигуриране настройките на grub2/burg Grub Customizer: Избор на дял Инсталиране на програмата за начално зареждане в MBR
и поставяне на някои файлове в папката и с данни
(ако те вече не съществуват). Инсталиране в MBR Монтирането се провали! Монтиране на избраната файлова система Преместване надолу на избрания запис или скрипт Преместване нагоре на избрания запис или скрипт Име на записа Не е открита програма за начално зареждане Не е открит скрипт Избор на дял Преглед: Двоичния файл на посредника не е открит! Премахване на скрипт от вашата конфигурация Запазване на конфигурацията и генериране на нов  Скрипт за вмъкване: Избор на _дял … Изберете и монтирайте вашия главен дял Изберете необходимите подточки за монтиране Програмата за начално зареждане беше инсталирана успешно Генерираната конфигурация не е еднаква със запазената при пускане на програмата. Това, което виждате тук не е това, което ще видите при рестартиране на компютъра. За да оправите това натиснете обновяване! Запазената конфигурация не е актуална! Това са точките за монтиране на вашия файл fstab.
Моля изберете всеки дял, свързан с grub/начално зареждане. Изглежда, че това не е главен дял (не открит файл fstab) Демонтиране на монтираната файлова система Вие решихте да изберете друг дял.
Моля забележете: os-prober може да не открие вашата реално пусната система.
Затова отново пуснете Grub Customizer на целевата система
и запазете конфигурацията (или изпълнете update-grub/update-burg)
за да върнете записа отново! Вие стартирахте Grub Customizer от жив диск. Когато пуснете grub ще видите всички записи (непроменени). Тази грешка се получава (в повечето случаи), когато не сте инсталирали правилно grub gustomizer. _Устройство:  _Редактиране _Файл _Помощ _Инсталиране в MBR … _Изход без запазване _Изход без обновяване _Запис и изход _Обновяване и изход _Изглед _използване на друг дял:  Инсталиране на програмата за начално зареждане... е активен етикет зареждане на конфигурацията... име дял презареждане на конфигурацията (същото като рестартиране на приложението) тип Демонтирането се провали! обновяване на конфигурацията 