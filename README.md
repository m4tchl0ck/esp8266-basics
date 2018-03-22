# luad-button

## 
W nawiązaniu do Gali IoT, która odbyła się 2017-12-02 na Błatniej, chciałbym rozwinąć temat i przedstawić przykładowe składowe rozwiazania problemu (tresc zadania: [tutaj](https://gitlab.jcommerce.pl/IoT/blatnia-2017-zadanie)). Tak, Tak nie zobaczycie tu całego rozwiązania, jedynie klocki z których możecie je poskładać :)
Poniżej przedstawię tochę informacji na temat samego sprzętu oraz jak rozwiązać poszczególne problemy zadania. Po przeanalizowaniu wszystkich elemetów będziecie w stanie samemu rozwiązać zadanie.

## Troche o hardware
Łukasz udostępnił wam urządzenie posiadające płyte główną [D1-Mini](https://wiki.wemos.cc/products:d1:d1_mini) oraz przycisk umieszczony w shield 1-BUTTON Shield v2.0.0. Sercem płyty głównej, z która mogliście się zmierzyć jest mikrokontroler [ESP8266](esp8266.md)

## Co musimy zrobić
* W wersji podstawowej zadania musimy:
0. [Uruchomić środowisko deweloperskie](#Dev)
1. [Zapalić diodę na urządzeniu](#Led)
2. [Podjać akcję po zdarzeniu double click](#Button)
3. [Podłączyć się do sieci WiFi](#WiFi)
4. [Wysłać request https](#Http)

## <a name="Dev"></a>Srodowisko developerskie
Rozwiązanie przedstawię przy użyciu [Atom](https://atom.io/)(alternatywnie można wybrać [VS Code](https://code.visualstudio.com/), jednak zdarzają się problemy) oraz [PlatformIO](http://platformio.org/).

Instalacja jest szybka i bezbolesna :D

- Instalujemy [Atom](https://atom.io/)
- Instalujemy [PlatformIO](http://docs.platformio.org/en/latest/ide/atom.html)

    ![atom_package_install](img/atom_package_install.png)
    ![platformio_install](img/atom_platformio_install.png)

- Restart [Atom](https://atom.io/)

    ![platformio_install_reload](img/atom_platformio_install_reload.png)

- Po restarcie i chwili ładowania powinniśmy zobaczyć ekran domowy [PlatformIO](http://docs.platformio.org/en/latest/ide/vscode.html)

    ![platformio_home](img/atom_platformio_home.png)

- Tworzymy nowy projekt [PlatformIO](http://docs.platformio.org/en/latest/ide/atom.html)

    ![platformio_newproject](img/atom_platformio_newproject.png)

- Wybieramy płytę [D1-Mini](https://wiki.wemos.cc/products:d1:d1_mini) oraz framework [Arduino](https://www.arduino.cc)

    ![platformio_newproject_params](img/atom_platformio_newproject_params.png)

- <a name="Devices"></a>Podłączamy urządzenie (mrugnie niebieska dioda na urzadzeniu) i na liscie urządzeń możemy sprawdzić pod jakim portem COM nasze urządzenie jest dostępne

    ![platformio_devices](img/atom_platformio_devices.png)

- Kompilujemy projekt, tak na wszelki wypadek żeby dociągnąć wszystkie zalećności i upewnić się, że wszystko działa

    ![platformio_build](img/atom_platformio_build.png)
