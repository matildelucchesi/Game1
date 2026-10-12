# Game — Castle\r
\r
**Progetto universitario realizzato nel 2022**, sviluppato in C++ con SFML. È un gioco di ruolo 2D dedicato alla creazione di un personaggio, all'esplorazione di un castello e ai combattimenti a turni.\r
\r
Il repository conserva il progetto a scopo didattico e dimostrativo. Il codice e le risorse sono stati riorganizzati per rendere più chiara la struttura e facilitare la compilazione, mantenendo le meccaniche originali.\r
\r
## Il gioco\r
\r
Il protagonista deve entrare nel castello del mindflayer Ronkahudroth e salvare la principessa Metalyn. Prima di iniziare l'esplorazione, il giocatore sceglie razza, classe, arma e armatura del proprio eroe.\r
\r
Le funzionalità presenti nel codice comprendono:\r
\r
- Cinque razze: umano, dragonborn, tiefling, elfo e nano.\r
- Quattro classi: barbaro, druido, guerriero e mago.\r
- Selezione di armi e armature con caratteristiche differenti.\r
- Una mappa iniziale e tre livelli del castello.\r
- Movimento, collisioni, interazione con statue e tesori, raccolta e utilizzo di pozioni.\r
- Combattimenti a turni con iniziativa, tiri di dado, punti vita e classe armatura.\r
- Inventario, schermata di pausa e achievement.\r
\r
L'interfaccia e i messaggi del gioco sono in inglese.\r
\r
## Anteprima\r
\r
### Creazione del personaggio\r
\r
![Creazione del personaggio](docs/images/Choose_hero_features.gif)\r
\r
### Ingresso nel castello\r
\r
![Ingresso nel castello](docs/images/Enter_in_the_castle.gif)\r
\r
### Interazione con gli oggetti\r
\r
![Interazione con gli oggetti](docs/images/Interaction_with_object.gif)\r
\r
### Combattimento\r
\r
![Combattimento](docs/images/Fight.gif)\r
\r
## Struttura del repository\r
\r
```text\r
Game/\r
├── src/\r
│   ├── main.cpp           Punto di ingresso\r
│   ├── core/              Finestra e ciclo di gioco\r
│   ├── states/            Menu, esplorazione, livelli, pausa e combattimento\r
│   ├── characters/        Personaggi, eroe e nemici\r
│   ├── items/             Armi, armature, pozioni e relativi creator\r
│   ├── animation/         Animazioni e rappresentazione grafica\r
│   ├── world/             Tile, mappe e oggetti interattivi\r
│   ├── achievements/      Achievement e notifiche Observer\r
│   └── utils/             Dadi\r
├── assets/\r
│   ├── images/            Sprite, texture, interfaccia e tile set\r
│   ├── Font/              Font e informazioni originali sulla licenza\r
│   └── mapXML/            Le quattro mappe XML\r
├── test/                  Test del progetto\r
│   └── lib/               Submodule GoogleTest\r
├── docs/images/           GIF dimostrative\r
├── vcpkg/                 Submodule per le dipendenze C++\r
├── CMakeLists.txt         Configurazione di compilazione\r
├── CMakeSettings.json     Configurazione per Visual Studio\r
├── .gitmodules            Definizione dei submodule\r
├── .gitignore             Esclusione di build e file locali\r
└── README.md\r
```\r
\r
Header e implementazioni sono affiancati per responsabilità. Gli include del progetto sono relativi a `src/`.\r
\r
La libreria statica `core` contiene il codice condiviso dal gioco e dai test. L'eseguibile `Game` utilizza `src/main.cpp`; l'eseguibile `runAllTests` esegue la suite GoogleTest. Gli stati derivano da `GameState`; `Playable` raccoglie funzionalità comuni all'esplorazione. I creator costruiscono armi e armature, mentre `Observable` e `Observer` gestiscono le notifiche degli achievement.\r
\r
## Requisiti\r
\r
- Git, per clonare il repository e inizializzare i submodule.\r
- Un compilatore con supporto C++11.\r
- CMake 3.16 o successivo. Per le dipendenze storiche del progetto è consigliato CMake 3.x.\r
- SFML **2.x**, con i componenti `system`, `window`, `graphics` e `network`.\r
- tinyxml2, disponibile a CMake tramite il relativo package di configurazione.\r
- GoogleTest, incluso come submodule in `test/lib`, se si compilano i test.\r
- Una sessione grafica per eseguire il gioco e i test che creano finestre SFML.\r
\r
Il progetto nasce in ambiente Windows/Visual Studio. Le istruzioni principali qui sotto usano PowerShell e una compilazione x64. Il codice usa l'API di SFML 2 e non è compatibile direttamente con SFML 3. Il port SFML del submodule vcpkg incluso dichiara la versione 2.5.1.\r
\r
## Preparazione del repository\r
\r
Dopo aver clonato il repository, aprire un terminale nella sua cartella principale ed eseguire:\r
\r
```sh\r
git submodule update --init --recursive\r
```\r
\r
Questo comando recupera GoogleTest e vcpkg nelle revisioni registrate dal repository. Un archivio ZIP di GitHub non contiene il codice dei submodule: per seguire questa procedura utilizzare un clone Git.\r
\r
## Compilazione su Windows con vcpkg\r
\r
Installare Visual Studio o i Build Tools con il carico di lavoro **Sviluppo di applicazioni desktop con C++**, un Windows SDK e CMake. Eseguire i comandi seguenti in PowerShell dalla radice del repository.\r
\r
### 1. Preparare le dipendenze\r
\r
```powershell\r
.\vcpkg\bootstrap-vcpkg.bat\r
.\vcpkg\vcpkg.exe install sfml:x64-windows tinyxml2:x64-windows\r
```\r
\r
Mantenere coerenti l'architettura del compilatore e il triplet vcpkg. Questa procedura usa `x64-windows`.\r
\r
### 2. Configurare e compilare\r
\r
```powershell\r
cmake -S . -B build -A x64 -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows -DBUILD_TESTING=ON\r
cmake --build build --config Debug\r
```\r
\r
L'opzione `-A x64` è destinata al generatore Visual Studio. Con Ninja utilizzare un ambiente di sviluppo MSVC x64, omettere `-A x64` e impostare `-DCMAKE_BUILD_TYPE=Debug` durante la configurazione.\r
\r
Per compilare soltanto il gioco, sostituire `-DBUILD_TESTING=ON` con `-DBUILD_TESTING=OFF`. In questo caso GoogleTest non è necessario.\r
\r
Il toolchain e il generatore vanno scelti alla prima configurazione. Se si cambia toolchain, generatore o architettura, utilizzare una nuova directory, per esempio `build-x64`, al posto di `build`.\r
\r
### 3. Avviare il gioco\r
\r
Con il generatore Visual Studio, dalla radice del repository:\r
\r
```powershell\r
.\build\Debug\Game.exe\r
```\r
\r
Con Ninja l'eseguibile si trova normalmente in `build/Game.exe`.\r
\r
**La directory di lavoro deve essere la radice del repository**, dove si trova `assets/`. Avviare il programma dal terminale come indicato, evitando di cambiare directory nella cartella dell'eseguibile. Il target CMake configura anche questa directory per il debugger di Visual Studio.\r
\r
Per una build Release, usare `--config Release` e avviare `build/Release/Game.exe`.\r
\r
## Compilazione con dipendenze già installate\r
\r
Se SFML 2 e tinyxml2 sono già disponibili al compilatore, vcpkg è facoltativo:\r
\r
```sh\r
cmake -S . -B build -DBUILD_TESTING=ON\r
cmake --build build --config Debug\r
```\r
\r
Se CMake non trova le librerie, aggiungere `-DCMAKE_PREFIX_PATH=<directory-di-installazione>` alla configurazione, sostituendo il segnaposto con il percorso effettivo. Le librerie devono essere compatibili con compilatore e architettura scelti.\r
\r
Con un generatore a configurazione singola impostare anche `-DCMAKE_BUILD_TYPE=Debug`; il parametro `--config` serve ai generatori con più configurazioni. Su Linux l'eseguibile si trova normalmente in `build/Game` e va avviato dalla radice con `./build/Game`. L'esecuzione su piattaforme diverse da Windows non è stata verificata in questa riorganizzazione.\r
\r
## Comandi di gioco\r
\r
I comandi dipendono dalla schermata corrente; i messaggi a video indicano l'azione disponibile.\r
\r
| Contesto | Tasto | Azione |\r
| --- | --- | --- |\r
| Schermata iniziale | Invio | Inizia il gioco |\r
| Selezione di razza, arma o armatura | Frecce sinistra/destra | Scorre le opzioni |\r
| Selezione della classe | Frecce su/giù | Scorre le classi |\r
| Menu di selezione | Invio | Conferma la scelta |\r
| Esplorazione | Frecce direzionali | Muove il personaggio |\r
| Area iniziale | W | Apre la scelta dell'equipaggiamento |\r
| Esplorazione | A | Interagisce, entra nel castello, usa le scale o avvia un combattimento quando richiesto |\r
| Statue e tesori | S | Raccoglie la pozione o chiude il messaggio dopo l'apertura |\r
| Esplorazione | Invio | Apre pausa e inventario |\r
| Inventario | Frecce direzionali | Seleziona una pozione |\r
| Inventario | Invio | Usa la pozione selezionata |\r
| Pausa | Backspace | Torna al gioco |\r
| Combattimento | A | Avvia o conclude lo scontro quando richiesto |\r
| Turno dell'eroe | S | Esegue l'attacco dell'eroe |\r
| Turno del nemico | D | Esegue l'attacco del nemico |\r
| Notifica di achievement | Z | Chiude la notifica |\r
\r
## Test\r
\r
I test coprono costruzione e caratteristiche di eroi e nemici, armi e armature, attacchi, pozioni, collisioni e achievement.\r
\r
Dopo una compilazione con `BUILD_TESTING=ON`:\r
\r
```sh\r
ctest --test-dir build -C Debug --output-on-failure\r
```\r
\r
CTest imposta la radice del repository come directory di lavoro. È possibile avviare direttamente la suite da PowerShell:\r
\r
```powershell\r
.\build\test\Debug\runAllTests.exe\r
```\r
\r
Con un generatore a configurazione singola, il percorso è normalmente `build/test/runAllTests.exe` su Windows o `build/test/runAllTests` su Linux.\r
\r
Alcuni test creano finestre SFML e caricano mappe e texture già durante l'inizializzazione: richiedono le risorse in `assets/` e una sessione grafica, quindi la suite non è predisposta per un ambiente senza display.\r
\r
## Risorse e stato del progetto\r
\r
In `assets/` sono presenti **47 immagini**, le risorse del font TaylorGothic e **quattro mappe XML**: `PLMap.xml`, `FLMap.xml`, `SLMap.xml` e `TLMap.xml`. Le risorse sono state recuperate dalla precedente cartella `out/build/` e collocate fuori dalle directory di compilazione.\r
\r
I percorsi nel codice e nelle mappe XML iniziano con `assets/` e vengono risolti rispetto alla directory di lavoro. Conservare i nomi e le maiuscole dei file, soprattutto su filesystem sensibili alle maiuscole.\r
\r
Mancano ancora due immagini referenziate dal codice:\r
\r
| File | Utilizzo |\r
| --- | --- |\r
| `assets/images/other/potion.png` | Rappresentazione grafica delle pozioni |\r
| `assets/images/fight/background.png` | Sfondo della schermata di combattimento |\r
\r
Per completare le risorse, ripristinare i file originali in questi percorsi. La loro assenza può produrre errori di caricamento e una rappresentazione grafica incompleta.\r
\r
Durante la riorganizzazione sono stati verificati gli include interni e i riferimenti alle risorse disponibili. **La compilazione e l'esecuzione completa non sono state verificate**: nell'ambiente usato per la riorganizzazione CMake non ha trovato il package SFML. Le GIF mostrano il funzionamento del progetto originale e non certificano una nuova esecuzione della versione riorganizzata.\r
\r
## Problemi comuni\r
\r
| Problema | Verifica o soluzione |\r
| --- | --- |\r
| CMake non trova `SFMLConfig.cmake` o `sfml-config.cmake` | Installare SFML 2 per il compilatore scelto e configurare il toolchain vcpkg o `CMAKE_PREFIX_PATH`. |\r
| CMake non trova tinyxml2 | Installare tinyxml2 e rendere disponibile a CMake la sua configurazione. |\r
| Manca `test/lib/googletest/CMakeLists.txt` | Eseguire `git submodule update --init --recursive`, oppure compilare con `BUILD_TESTING=OFF`. |\r
| CMake recente rifiuta le policy delle vecchie dipendenze | Utilizzare CMake 3.x, oppure aggiornare e verificare separatamente le dipendenze storiche. |\r
| L'avvio segnala DLL mancanti | Rendere accessibili le DLL SFML e delle relative dipendenze, accanto all'eseguibile o tramite `PATH`, usando la stessa architettura e configurazione della build. |\r
| Non vengono caricati font, texture o mappe | Avviare dalla radice del repository e controllare i percorsi in `assets/`; le due immagini elencate sopra sono ancora mancanti. |\r
| I test non funzionano su un server senza display | Eseguire la suite in una sessione grafica compatibile con SFML. |\r
\r
## Crediti e licenze\r
\r
Il font TaylorGothic è attribuito a **Thor Christopher Arisland**. Le condizioni originali conservate in [assets/Font/TaylorGothic.txt](assets/Font/TaylorGothic.txt) indicano uso personale gratuito e una licenza da acquistare per l'uso commerciale.\r
\r
Le dipendenze SFML, tinyxml2, GoogleTest e vcpkg mantengono le rispettive licenze. Non è presente un file `LICENSE` per il codice del progetto. Provenienza e condizioni di utilizzo delle immagini devono ancora essere documentate; il contesto universitario non costituisce una licenza delle risorse.\r
\r
## Note per la pubblicazione su GitHub\r
\r
Le cartelle da versionare comprendono `src/`, `assets/`, `test/` e `docs/`, insieme ai file di configurazione. `test/lib` e `vcpkg` sono submodule: Git registra i riferimenti ai repository delle dipendenze.\r
\r
`.gitignore` esclude `build/`, `out/`, `.vs/`, binari e impostazioni locali dell'IDE. Le risorse da pubblicare sono quelle in `assets/`; le copie rimaste in `out/build/` non sono necessarie nel repository. L'esclusione dei file generati dai nuovi commit non li rimuove dalla cronologia Git esistente.\r
