# 02: Banc d'essai BLE et LED

**Spec à lire :** Observabilité ; Matériel

**What to build:**
- Firmware qui annonce une ligne BLE toutes les 10 s (compteur, uptime).
- Récepteur Python (bleak) qui tourne en continu, se reconnecte seul, écrit un journal horodaté par jour dans `logs/` (ignoré par git) et signale chaque trou avec sa durée.
- Codes LED définis dans la spec.

**Hors périmètre :** Sommeil, accéléromètre, WiFi.

**Test matériel :** Sur batterie, 10 min de réception, puis capteur éteint 1 min et rallumé.

**Blocked by:** 01

**Status:** needs-triage

## Critères d'acceptation
- [ ] 10 min sans ligne manquante
- [ ] Le trou d'environ 60 s est signalé avec sa durée
- [ ] Codes LED visibles
- [ ] `analyste-logs` rend un verdict exploitable sur ce journal
