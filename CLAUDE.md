# Capteur de veille — firmware XIAO ESP32-C6

Capteur d'activité sur batterie : deep sleep, réveil minuteur ou
mouvement (LIS2DW12 sur GPIO2), transmission HTTPS. Spec : docs/SPEC.md.

## Avant toute tâche
1. Lire docs/PROGRESS.md (palier courant, prochaine action).
2. Lire la fiche docs/paliers/PN.md du palier courant.
3. Ne lire de docs/SPEC.md que les sections citées par la fiche.
4. Proposer un plan et attendre l'accord avant de coder.

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
- Rester dans le périmètre du palier courant. Un problème hors
  périmètre se note dans PROGRESS.md, il ne se corrige pas.

## Commandes
- Tests natifs  : pio test -e native
- Build test    : pio run -e test
- Build prod    : pio run -e prod
- Upload        : fait par l'humain, selon le protocole (SPEC § Protocole)
- Journal BLE   : logs/ble-AAAAMMJJ.log, à analyser via l'agent
                  analyste-logs, jamais en entier ici.

## Fin de palier
/palier-fin met à jour PROGRESS.md et DECISIONS.md et commit.
Ensuite l'humain lance /clear.

## Compaction
En cas de compaction, conserver : palier courant, fichiers modifiés,
dernier résultat de test, hypothèses ouvertes.
