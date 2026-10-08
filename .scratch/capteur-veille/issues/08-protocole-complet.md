# 08: Protocole complet

**Spec à lire :** Réseau et protocole serveur ; Matériel ; Persistance

**What to build:**
- Tous les champs v1 : `boot_nonce`, `boot_count`, causes, tension, RSSI, `suppressed`, `charging`, diagnostics structurés.
- Mouvements transmis ; file de 16 événements en RTC avec âges et compteur de pertes.
- Tension batterie mesurée + `battery_low` à 3500 mV.
- Réponse lue et journalisée, sans appliquer la config.
- Sérialisation, lecture de réponse et file testées en `native`.

**Hors périmètre :** Application de la config, horloge, filtre.

**Test matériel :** Test rapide avec le WiFi coupé 10 min au milieu.

**Blocked by:** 07

**Status:** needs-triage

## Critères d'acceptation
- [ ] Champs corrects côté serveur
- [ ] Les événements de la coupure arrivent avec des âges plausibles
- [ ] Aucun doublon
- [ ] Tension à 50 mV près d'un multimètre
