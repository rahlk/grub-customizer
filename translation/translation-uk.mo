��    p      �  �         p	  	   q	  8   {	  !   �	     �	     �	  E   �	     8
  "   D
  
   g
  	   r
     |
  1  �
     �  %   �  &   �     $  /   4  '   d  -   �     �     �     �  %   �  M     "   a  q   �     �            &   -  $   T     y     �     �     �     �     �  '   �  &        3     E     M  $   c  .   �  *   �  ^   �  �   A  8   �       G        ^    y  .   |  	   �  	   �     �     �     �     �     �     �               %     4     :  
   S     ^     o     u     z     �     �  	   �     �  
   �     �     �  
   �     �  	                
   &  
   1  
   <     G     S  	   a     k      �     �     �     �     �  	   �     �     �     �     �          "  	   +     5     A     F     U     l  
   r     }     �  �  �     3  t   Q  8   �     �       s   1      �  F   �          +     ;  +  R  +   ~  C   �  G   �  ,   6  A   c  :   �  N   �  2   /     b  #   q  X   �  c   �  *   R  �   }     /  $   M  =   r  O   �  Q          R   .   j   &   �      �   @   �   &   !  H   B!  I   �!  '   �!     �!      "  P   -"  >   ~"  L   �"  ^   
#    i#  d   ~$     �$  �   �$  6   �%  �  �%  M   _'     �'     �'     �'  	   �'     �'     �'      (  '   2(  %   Z(  !   �(     �(     �(  1   �(     )  !   	)     +)  
   8)     C)  #   X)     |)     �)  *   �)     �)  E   �)     .*     =*  0   S*     �*     �*  
   �*     �*     �*     �*     +     ++     K+  4   i+  9   �+     �+     �+  
   ,     ,     ",  ,   /,  9   \,     �,  7   �,     �,     �,     -     .-     C-  *   J-  +   u-     �-     �-  
   �-     �-     '   _           ]   p       K   
   V   T   b             J      [   a         I   g       i   Y   ,                     W   6       j   l   M   *      O           H       A      o   C   `                  9   L   d      /       $       ?   Z             S   3             h                  Q   c   &       "   )       2   !   e             4       5   	   :   N   R   <   f       7           =      \      @   8       (   m   +   0   %               P   k   G   ;      ^                U       B   .   n   X   >   #             F       1       E   -         D     (custom) %1 couldn't be executed successfully. error message:
 %2 %1 not found. Is grub2 installed? (new Entries) (script code) AND: your modifications are still unsaved, update will save them too! A_ppearance Add a script to your configuration Add script BURG Mode BURG found! Before you can edit your grub configuration we have to
mount the required partitions.

This assistant will help you doing this.


Please ensure the target system is based on the same cpu architecture
as the actually running one.
If not, you will get an error message when trying to load the configuration. Configuration has been saved Couldn't mount the selected partition Couldn't umount the selected partition Default title:  Do you want to configure BURG instead of grub2? Do you want to save your modifications? Do you want to select another root partition? Edit grub preferences Entry Entry %1 (by position) Error while installing the bootloader Grub Customizer is a graphical interface to configure the grub2/burg settings Grub Customizer: Partition chooser Install the bootloader to MBR and put some
files to the bootloaders data directory
(if they don't already exist). Install to MBR Mount failed! Mount selected Filesystem Move down the selected entry or script Move up the selected entry or script Name the Entry No Bootloader found No script found Partition Chooser Please type a device string! Preview: Remove a script from your configuration Save configuration and generate a new  Script to insert: Seconds Select _partition … Select and mount your root partition The bootloader has been installed successfully The saved configuration is not up to date! These are the mountpoints of your fstab file.
Please select every grub/boot related partition. This option doesn't work when the "os-prober" script finds other operating systems. Disable "%1" if you don't need to boot other operating systems. This seems not to be a root file system (no fstab found) Timeout To get the colors above working,
you have to select a background image! Unmount mounted Filesystem You selected the option for choosing another partition.
Please note: The os-prober may not find your actually running system.
So run Grub Customizer on the target system
again and save the configuration (or run update-grub/update-burg)
to get the entry back! You started Grub Customizer using the live CD. _Advanced _Device:  _Edit _File _General _Help _Install to MBR … _Quit without saving _Quit without update _Save & Quit _Update & Quit _View _use another partition:  background background image black blue brown custom resolution:  cyan dark-gray default entry font color generate recovery entries green highlight: installing the bootloader… is active kernel parameters label light-blue light-cyan light-gray light-green light-magenta light-red loading configuration… look for other operating systems magenta menu colors name normal: partition pre_defined:  previously _booted entry red reload configuration remove background settings show menu transparent type umount failed! updating configuration value visibility white yellow Project-Id-Version: grub-customizer
Report-Msgid-Bugs-To: FULL NAME <EMAIL@ADDRESS>
POT-Creation-Date: 2011-12-23 17:05+0100
PO-Revision-Date: 2012-02-07 08:23+0000
Last-Translator: Max_ym <kontact.cat@gmail.com>
Language-Team: Ukrainian <uk@li.org>
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit
X-Launchpad-Export-Date: 2012-03-22 07:12+0000
X-Generator: Launchpad (build 14981)
  (користувацьке) %1 не може бути виконаним правильно. Повідомлення про помилку:
 %2 %1 не знайдено. Grub 2 встановлено? (новий Пункт) (код сценарію) ТАКОЖ: Ваші зміни все ще не збережені, оновлення збереже їх теж! Зовнішній _вигляд Додати сценарій до Вашої конфігурації Додати сценарій Режим BURG Знайдено BURG! Перш ніж Ви зможете змінити конфігурацію GRUB, ми повинні
змонтувати необхідні розділи.

Цей помічник допоможе Вам це зробити.


Будь ласка, переконайтеся, що цільова система заснована на тій же архітектурі процесора
що й працює зараз.
Якщо ні, Ви отримаєте помилку коли спробуєте завантажити конфігурацію. Конфігурацію збережено Неможливо змонтувати обраний розділ Неможливо відмонтувати обраний розділ Назва за замовчуванням:  Бажаєте налаштувати BURG замість grub2 ? Бажаєте зберегти внесені зміни? Бажаєте обрати інший кореневий (root) розідл? Редагувати налаштування grub Елемент Запис %1 (по позиції) Виникла помилка при встановленні завантажувача Grub Customizer - це графічна оболонка для конфігурації grub2/burg Grub Customizer: Вибір розділу Встановлення завантажувача до MBR 
та переміщення деяких файлів до
його каталогу (якщо їх ще нема). Встановити до MBR Помилка монтування! Монтувати обрану файлову систему Перемістити вниз обраний пункт чи сценарій Перемістити вгору обраний пункт чи сценарій Назва Пункту Завантажувач не знайдено Сценарій не знайдено Вибір розділу Будь ласка, введіть рядок пристрою! Попередній перегляд: Видалити сценарій з Вашої конфігурації Зберегти конфігурацію та створити нову  Сценарій для вставки: Секунди Оберіть _розділ … Обрати та монтувати ваш основний (root) розділ Завантажувач успішно встановлено Збережена кофігурація застарілої версії! These are the mountpoints of your fstab file.
Please select every grub/boot related partition. Цей параметр не працює коли сценарій "os-prober" знаходить інші операційні системи. Деактивуйте "%1" якщо не потрібно завантажувати інші операційні системи. Це не основна (root) файлова система (файл fstab не знайдено) Час затримки Щоб працювали вище вказані кольори,
Вам потрібно обрати фонове зображення! Відмонтувати файлову систему Ви обрали опцію для вибору іншого розділу.
Зверніть увагу: os-prober може не знайти працюючу систему.
Тому запустіть Grub Customizer на цільовій системі
знову та збережіть конфігурацію (або виконайте update-grub/update-burg)
щоб отримати записи назад! Ви запустили Grub Customizer використовуючи live CD. Д_одатково _Пристрій:  _Правка _Файл _Загальне _Допомога _Встановити в MBR … _Вихід без збереження _Вийти без оновлення _Зберегти та Вийти _Оновити та Вийти _Вигляд _використати інший розділ:  фон фонове зображення чорний синій коричневий власне розширення:  блакитний темно-сірий запис за замовчуванням колір шрифту генерувати запис відновлення системи зелений підсвічено: встановлюю завантажувач... є активним параметри ядра мітка світло-синій світло-блакитний світло-сірий світло-зелений світло-пурпурний світло-червоний Завантаження конфігурації... шукати інші операційні системи пурпурний кольори меню назва нормально: розділ попередньо _визначений:  попередній запис _завантаження червоний перезавантажити конфігурацію видалити фон налаштування показувати меню прозорість тип помилка відмонтування! оновлення конфігурації значення відображення білий жовтий 