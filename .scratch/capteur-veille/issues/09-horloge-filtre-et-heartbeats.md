# 09: Horloge, filtre et heartbeats

**Spec à lire :** Horloge, filtre et heartbeats ; Persistance

**What to build:**
- Horloge reconstruite + `settimeofday()` + TZ ; 0 avant la première synchro.
- Filtre : âges de la première et de la dernière suppression, transmission forcée après 5, transmettre si heure inconnue ou delta négatif, `last_tx` après ré-ancrage.
- Heartbeats jour et nuit, avec repli.
- Tests natifs, y compris les changements d'heure.

**Hors périmètre :** Config persistante.

**Test matériel :** Fenêtre 30 s : test rapide + rafale de 5 mouvements en 1 min ; puis 24 h pour les bascules 23 h / 7 h.

**Blocked by:** 08

**Status:** needs-triage

## Critères d'acceptation
- [ ] Rafale → 1 transmission, puis compteur et âges
- [ ] Sommeils rapportés à ±2 s
- [ ] Aucun delta négatif en 24 h
- [ ] Bascules à la bonne heure
