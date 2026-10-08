# 07: WiFi et premier POST

**Spec à lire :** Réseau et protocole serveur ; Persistance

**What to build:**
- Chemin rapide (canal, BSSID, IP en RTC), repli scan + DHCP, borne de 8 s.
- Identifiants depuis le fichier local.
- HTTPS avec racine épinglée, requête minimale selon le contrat.
- WiFi arrêté avant le sommeil ; durée de chaque phase journalisée.

**Hors périmètre :** Charge utile complète, file d'attente, horloge, filtre.

**Test matériel :** Test de 40 min, avec un redémarrage du routeur au milieu.

**Blocked by:** 05, 06

**Status:** needs-triage

## Critères d'acceptation
- [ ] Chaque heartbeat arrive au serveur
- [ ] Chemin rapide dès le 2e cycle
- [ ] Repli après le redémarrage du routeur, puis remémorisation
- [ ] Durées des phases consignées MESURÉ
