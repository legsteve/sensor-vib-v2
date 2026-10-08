# Capteur de veille — firmware XIAO ESP32-C6

Capteur d'activité sur batterie : deep sleep, réveil minuteur ou
mouvement (LIS2DW12 sur GPIO2), transmission HTTPS. Spec : docs/SPEC.md.
Vocabulaire : CONTEXT.md — utiliser ses termes, éviter ceux qu'il écarte.
Décisions structurantes : docs/adr/ — ne pas les défaire sans en discuter.

## Avant toute tâche
1. Lire docs/PROGRESS.md (ticket courant, prochaine action).
2. Lire le ticket courant dans .scratch/capteur-veille/issues/.
3. Ne lire de docs/SPEC.md que les sections citées par le ticket.
4. Proposer un plan et attendre l'accord avant de coder.
5. Logique pure : tests d'abord en env native, un à la fois, rouge
   puis vert. Code matériel : préparer le test matériel du ticket.
6. Avant de commit : pio test -e native et pio run -e test passent ;
   relire le diff contre les Règles absolues et les Interdits de la
   spec. Puis dire exactement quoi flasher et quoi observer.

## Règles absolues
- Un seul chemin d'endormissement : go_to_sleep(). Aucun mode debug
  qui modifie le cycle. Le debug observe, il ne change rien.
- LIS2DW12 : soft reset avant toute config ; CTRL4 écrit en entier.
- Avant le sommeil : INT1 lue par rtc_gpio_get_level(), jamais
  digitalRead(). INT1 haute -> minuteur 5 s seul.
- Dans le doute (heure inconnue, delta négatif) : transmettre.
- Seuil batterie faible : 3500 mV. Ne pas l'abaisser.
- Toute conclusion dans DECISIONS.md : MESURÉ ou SUPPOSÉ, avec date et
  env de build. Lecture de code = SUPPOSÉ.
- Ne jamais conclure sur le sommeil depuis un build CDC actif ou un
  capteur branché en USB.
- Rester dans le périmètre du ticket courant. Un problème hors
  périmètre se note dans PROGRESS.md, il ne se corrige pas.

## Commandes
- Tests natifs  : pio test -e native
- Build test    : pio run -e test
- Build prod    : pio run -e prod
- Upload        : fait par l'humain, selon le protocole (SPEC § Protocole)
- Journal BLE   : logs/ble-AAAAMMJJ.log, à analyser via l'agent
                  analyste-logs, jamais en entier ici.

## Fin de ticket
Après le test matériel fait par l'humain : consigner le résultat dans
DECISIONS.md (MESURÉ, date, env de build), cocher les critères atteints
dans le ticket, mettre PROGRESS.md sur le ticket suivant, commit (un
commit par ticket, résultat du test dans le message). Ensuite
l'humain lance /clear.

## Cache
Ne jamais modifier ce fichier pendant un ticket : il fait partie du
préfixe mis en cache. Une règle à ajouter se note dans PROGRESS.md et
s'applique entre deux tickets.

## Compaction
En cas de compaction, conserver : ticket courant, fichiers modifiés,
dernier résultat de test, hypothèses ouvertes.
