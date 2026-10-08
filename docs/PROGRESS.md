# Avancement

Message d'ouverture de chaque session (toujours identique, après /clear) :
« Implémente le ticket indiqué dans docs/PROGRESS.md. »

## Ticket courant
02 — .scratch/capteur-veille/issues/02-banc-dessai-ble-et-led.md
Statut : à démarrer (le ticket est marqué needs-triage)

## Prochaine action
Proposer le plan du ticket 02 et attendre l'accord.

## En parallèle (humain)
06 — contrat de protocole avec l'agent serveur. Bloque seulement le 07.

## Hypothèses ouvertes
- URL de plateforme non figée : `stable` résolue en espressif32 55.3.312
  le 2026-10-08 ; nom exact de la release à confirmer pour la figer.
- CDC USB réellement inactif sur la carte en `test` et `prod` : SUPPOSÉ
  (seuls les drapeaux de compilation ont été vérifiés).

## Problèmes hors périmètre notés
- Poste de build Windows (constaté au ticket 01) : builds ESP32 depuis
  PowerShell, pas Git Bash (dépendances Python) ; `pio` dans
  `~/.platformio/penv/Scripts`, hors PATH ; `pio test -e native` exige
  `~/.platformio/packages/toolchain-gccmingw32/bin` dans le PATH ;
  WatchGuard bloquait esptool. À reporter dans CLAUDE.md § Commandes
  entre deux tickets, si l'humain le souhaite.

## Tickets terminés
- 01 — Ossature du dépôt (2026-10-08) : native PASSED 1/1, test et prod
  SUCCESS.
